cmake_minimum_required(VERSION 3.28)
include(CMakeDependentOption)
include(TestBigEndian)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "请务必别在源代码构建捏，亲。")
endif()

project(OpenGame VERSION 0.1.0)
option(EnableLibdwarf "Use libdwarf to get debug information." TRUE)
option(EnableUnicode "Use libdwarf to get debug information." TRUE)
option(EnableSseAndSse2 "支持 MMX、SSE 和 SSE2 内建函数及代码生成" TRUE)
option(EnableSse42 "支持 SSE4.2 内建函数及代码生成" TRUE)
option(EnableAvx "支持 AVX 内建函数及代码生成" FALSE)
option(EnablePrecompilationHeaders "启用预编译头文件" TRUE)
option(
    EnableNonstandardFixedWidthIntegerTypes
    "<stdint.h> in C99 standard (ISO/IEC 9899:1999) is optional."
    FALSE
)
option(EnableUnitTest "启用单元测试。" TRUE)
option(EnableAnalyzer "启用静态检测" FALSE)

find_package(PkgConfig QUIET)
if(EnableLibdwarf)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 4.1)
        cmake_pkg_config(IMPORT libdwarf REQUIRED PREFIX Libdwarf)
    elseif(PkgConfig_FOUND)
        pkg_check_modules(Libdwarf QUIET IMPORTED_TARGET "libdwarf")
    else()
        message(FATAL_ERROR "Libdwarf not found.")
    endif()
endif()
if(EnableUnicode)
    if(WIN32)
        find_package(ICU REQUIRED COMPONENTS dt in io uc)
    else()
        find_package(ICU REQUIRED COMPONENTS data i18n io uc)
    endif()
endif()
if(LoaderArchitecture AND NOT (LoaderArchitecture STREQUAL "Auto"))
    if(NOT (LoaderArchitecture MATCHES [=[^(MicrokernelLike|OneProcess)$]=]))
        message(
            FATAL_ERROR
                "Invaild value '${LoaderArchitecture}' for 'LoaderArchitecture'."
        )
    endif()
else()
    if(CMAKE_SYSTEM_NAME MATCHES [=[^(CYGWIN|MSYS|Windows|WindowsPhone)$]=])
        set(LoaderArchitecture OneProcess)
    else()
        set(LoaderArchitecture MicrokernelLike)
    endif()
endif()
if(ThreadLibrary AND NOT (ThreadLibrary STREQUAL "Auto"))
    if(NOT (ThreadLibrary MATCHES [=[^(C11Threads|Pthread|McfGThread)$]=]))
        message(
            FATAL_ERROR "Invaild value '${ThreadLibrary}' for 'ThreadLibrary'"
        )
    endif()
    if(ThreadLibrary STREQUAL "McfGThread")
        if(CMAKE_VERSION VERSION_GREATER_EQUAL 4.1)
            cmake_pkg_config(IMPORT mcfgthread REQUIRED PREFIX "McfGThread")
        elseif(PkgConfig_FOUND)
            pkg_check_modules(
                McfGThread
                REQUIRED
                QUIET
                IMPORTED_TARGET "mcfgthread"
            )
        endif()
    elseif(ThreadLibrary STREQUAL "Pthread")
        find_package(Threads REQUIRED)
    elseif(ThreadLibrary STREQUAL "C11Threads")
    else()
        message(
            FATAL_ERROR "Invaild value '${ThreadLibrary}' for 'ThreadLibrary'."
        )
    endif()
else()
    find_package(Threads)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 4.1)
        cmake_pkg_config(IMPORT mcfgthread QUIET PREFIX "McfGThread")
    elseif(PkgConfig_FOUND)
        pkg_check_modules(McfGThread QUIET IMPORTED_TARGET "mcfgthread")
    endif()
    if(McfGThread_FOUND)
        set(ThreadLibrary McfGThread)
    elseif(Threads_FOUND)
        set(ThreadLibrary Pthread)
    else()
        set(ThreadLibrary C11Threads)
    endif()
endif()
if(CMAKE_SYSTEM_PROCESSOR MATCHES [=[^(i[3456]86|x86_64|X86|AMD64)$]=])
    if(EnableSseAndSse2)
        set(EnableSseAndSse2 TRUE)
    else()
        set(EnableSseAndSse2 FALSE)
    endif()
    if(EnableSse42)
        set(EnableSse42 TRUE)
    else()
        set(EnableSse42 FALSE)
    endif()
    if(EnableAvx)
        set(EnableAvx TRUE)
    else()
        set(EnableAvx FALSE)
    endif()
endif()
test_big_endian(IsBigEndian)
include(Source.BuildScripts/CMake/SetGlobalProperties.cmake)

message(STATUS "Configuration option:")
message(STATUS "\tEnableLibdwarf=${EnableLibdwarf}")
message(STATUS "\tEnableUnicode=${EnableUnicode}")
message(STATUS "\tLoaderArchitecture=${LoaderArchitecture}")
message(STATUS "\tThreadLibrary=${ThreadLibrary}")
message(STATUS "\tEnableSseAndSse2=${EnableSseAndSse2}")
message(STATUS "\tEnableSse42=${EnableSse42}")
message(STATUS "\tEnableAvx=${EnableAvx}")
message(STATUS "\tEnablePrecompilationHeaders=${EnablePrecompilationHeaders}")
message(STATUS "\tIsBigEndian=${IsBigEndian}")
message(STATUS "\tEnableUnitTest=${EnableUnitTest}")
message(STATUS "\tEnableAnalyzer=${EnableAnalyzer}")

add_library(OpenStgBase SHARED)
target_sources(
    OpenStgBase
    PRIVATE
        Source.CAndCpp/OpenStgBase/String/StringGetLength.c
        Source.CAndCpp/OpenStgBase/String/StringAppend.c
        Source.CAndCpp/OpenStgBase/Momery/MemoryCopy.c
)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.23)
    target_sources(
        OpenStgBase
        PUBLIC
        FILE_SET HEADERS
            FILES Source.CAndCpp/Include/OpenStg/Base/Base.h
                  Source.CAndCpp/Include/OpenStg/Base/String.h
    )
endif()
if(EnablePrecompilationHeaders)
    target_precompile_headers(
        OpenStgBase
        PRIVATE
            $<BUILD_INTERFACE:<OpenStg/Base/Base.h$<ANGLE-R>>
            $<BUILD_INTERFACE:<OpenStg/Base/Memory.h$<ANGLE-R>>
            $<BUILD_INTERFACE:<OpenStg/Base/String.h$<ANGLE-R>>
    )
endif()
target_include_directories(OpenStgBase SYSTEM PUBLIC Source.CAndCpp/Include)
target_compile_definitions(
    OpenStgBase
    PRIVATE
        "OgMacroOptionsEnablePrecompilationHeader=$<BOOL:${EnablePrecompilationHeaders}>"
        "OgMacroOptionsEnableSseAndSse2=$<BOOL:${EnableSseAndSse2}>"
        "OgMacroOptionsEnableSse42=$<BOOL:${EnableSse42}>"
        "OgMacroOptionsEnableAvx=$<BOOL:${EnableAvx}>"
        "OgMacroOptionsIsBigEndian=$<BOOL:${IsBigEndian}>"
        "OgMacroOptionsIsLittleEndian=$<NOT:$<BOOL:${IsBigEndian}>>"
    PUBLIC
        "$<$<CONFIG:Debug>:_DEBUG=0;DEBUG=1>"
        "$<$<AND:$<C_COMPILER_ID:MSVC,CLANG>,$<PLATFORM_ID:Windows>>:_CRT_SECURE_DEPRECATE_MEMORY>"
        "$<$<AND:$<C_COMPILER_ID:MSVC,CLANG>,$<PLATFORM_ID:Windows>>:_CRT_SECURE_NO_WARNINGS>"
        "OgMacroOptionsEnableLibdwarfComponent=$<BOOL:${EnableLibdwarf}>"
        "OgMacroOptionsEnableUnicode=$<BOOL:${EnableUnicode}>"
        "OgMacroOptionsLoaderArchitecture=\"${LoaderArchitecture}\""
        "OgMacroOptionsLoaderArchitectureIsMicrokernelLike=$<BOOL:$<STREQUAL:${LoaderArchitecture},MicrokernelLike>>"
        "OgMacroOptionsLoaderArchitectureIsOneProcess=$<BOOL:$<STREQUAL:${LoaderArchitecture},OneProcess>>"
        "OgMacroOptionsThreadLibrary=\"${ThreadLibrary}\""
        "OgMacroOptionsThreadLibraryIsC11Threads=$<BOOL:$<STREQUAL:${ThreadLibrary},C11Threads>>"
        "OgMacroOptionsThreadLibraryIsPthread=$<BOOL:$<STREQUAL:${ThreadLibrary},Pthread>>"
        "OgMacroOptionsThreadLibraryIsMcfGThread=$<BOOL:$<STREQUAL:${ThreadLibrary},McfGThread>>"
        "OgMacroOptionsEnableNonstandardFixedWidthIntegerTypes=$<BOOL:${EnableNonstandardFixedWidthIntegerTypes}>"
)
target_compile_options(
    OpenStgBase
    PRIVATE
        "$<$<AND:$<C_COMPILER_ID:MSVC>,$<BOOL:${EnableSseAndSse2}>>:/ARCH:SSE;/ARCH:SSE2>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>,$<BOOL:${EnableSse42}>>:/ARCH:SSE4.2>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>,$<BOOL:${EnableAvx}>>:/ARCH:AVX>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:CXX>>:/Zc:__cplusplus>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>,$<COMPILE_LANGUAGE:C>>:/Zc:__STDC__>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>>:/SOURCE-CHARSET:utf-8;/EXECUTION-CHARSET:utf-8>"
        "$<$<AND:$<C_COMPILER_ID:MSVC>>:/W4>"
        "$<$<AND:$<C_COMPILER_ID:Clang,GNU>,$<BOOL:${EnableSseAndSse2}>>:-msse;-msse2>"
        "$<$<AND:$<C_COMPILER_ID:Clang,GNU>,$<BOOL:${EnableSse42}>>:-msse4.2>"
        "$<$<AND:$<C_COMPILER_ID:Clang,GNU>,$<BOOL:${EnableAvx}>>:-mavx>"
        "$<$<AND:$<C_COMPILER_ID:Clang,GNU>>:-fstrict-aliasing>"
        "$<$<AND:$<C_COMPILER_ID:Clang,GNU>>:-Wall;-Wextra;-Wfloat-equal;-Wformat>"
        "$<$<AND:$<C_COMPILER_ID:GNU>>:-Wall;-Wextra;-Wpedantic;-Wcast-align;-Wno-unused-parameter;-Wstrict-overflow>"
        "$<$<AND:$<C_COMPILER_ID:GNU>>:-Wstring-compare;-Wconversion;-Waddress>"
        "$<$<AND:$<C_COMPILER_ID:GNU>>:-fexec-charset=UTF-8;-finput-charset=UTF-8;-fms-extensions>"
        "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<COMPILE_LANGUAGE:CXX>>:-Wregister>"
        "$<$<AND:$<C_COMPILER_ID:Clang>>:-Wpedantic;-Wconversion;-Wcast-align;-Wno-unused-parameter;-Wlifetime-safety-all>"
        "$<$<AND:$<C_COMPILER_ID:Clang>>:-Wno-unused-function>"
        "$<$<AND:$<C_COMPILER_ID:Clang>>:-fms-extensions>"
        "$<$<AND:$<CXX_COMPILER_ID:Clang>,$<COMPILE_LANGUAGE:CXX>>:-Wregister>"
        "$<$<AND:$<C_COMPILER_ID:GNU>,$<BOOL:${EnableAnalyzer}>>:-fanalyzer;-Wanalyzer-allocation-size;-Wanalyzer-null-dereference>"
        "$<$<AND:$<C_COMPILER_ID:GNU>,$<BOOL:${EnableAnalyzer}>>:-Wanalyzer-use-after-free>"
)
set_target_properties(
    OpenStgBase
    PROPERTIES
        C_STANDARD
        11
        C_STANDARD_REQUIRED
        TRUE
        C_EXTENSIONS
        TRUE
        POSITION_INDEPENDENT_CODE
        TRUE
)
target_link_libraries(
    OpenStgBase
    PUBLIC
        $<TARGET_NAME_IF_EXISTS:PkgConfig::Libdwarf>
        $<$<STREQUAL:${ThreadLibrary},McfGThread>:PkgConfig::McfGThread>
        $<$<STREQUAL:${ThreadLibrary},Pthread>:Threads::Threads>
        $<TARGET_NAME_IF_EXISTS:ICU::data>
        $<TARGET_NAME_IF_EXISTS:ICU::dt>
        $<TARGET_NAME_IF_EXISTS:ICU::i18n>
        $<TARGET_NAME_IF_EXISTS:ICU::in>
        $<TARGET_NAME_IF_EXISTS:ICU::io>
        $<TARGET_NAME_IF_EXISTS:ICU::uc>
)
target_link_options(
    OpenStgBase PRIVATE "$<$<AND:$<C_COMPILER_ID:Clang,GNU>>:-rdynamic>"
)
if(EnableUnitTest)
    find_package(Catch2 3 REQUIRED)
    include(CTest)
    include(Catch)
    add_executable(UnitTest)
    target_link_libraries(UnitTest PRIVATE OpenStgBase Catch2::Catch2WithMain)
    set_target_properties(
        UnitTest
        PROPERTIES
            CXX_STANDARD
            20
            CXX_STANDARD_REQUIRED
            TRUE
            CXX_EXTENSIONS
            TRUE
    )
    target_sources(
        UnitTest
        PRIVATE Source.CAndCpp/OpenStgBase/UnitTest/MemoryCopy.UnitTest.cpp
                Source.CAndCpp/OpenStgBase/UnitTest/StringGetLength.UnitTest.cpp
    )
    catch_discover_tests(UnitTest)
endif()
# 定义资源文件路径
set(RESOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Rsesources")

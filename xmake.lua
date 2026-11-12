add_rules("mode.debug", "mode.release")
add_requires("libdwarf")

option("LoaderArchitecture", function()
    set_values("LoaderArchitecture", "OneProcess", "MicrokernelLike")
    local Value = get_config("LoaderArchitecture")
    Value = get_config("LoaderArchitecture")
    if is_plat("windows") then
        set_default("OneProcess")
    else
        set_default("MicrokernelLike")
    end
    if Value == "OneProcess" then
        add_defines('OgMacroOptionsLoaderArchitecture="OneProcess"')
        add_defines("OgMacroOptionsLoaderArchitectureIsOneProcess=1")
        add_defines("OgMacroOptionsLoaderArchitectureIsMicrokernelLike=0")
    elseif Value == "MicrokernelLike" then
        add_defines('OgMacroOptionsLoaderArchitecture="MicrokernelLike"')
        add_defines("OgMacroOptionsLoaderArchitectureIsOneProcess=0")
        add_defines("OgMacroOptionsLoaderArchitectureIsMicrokernelLike=1")
    end
end)

option("ThreadLibrary", function()
    set_values("ThreadLibrary", "C11Threads", "Pthread", "McfGThread")
    local Value = get_config("ThreadsLibrary")
    if is_os("windows") and is_subhost("msys", "cygwin") and has_package("McfGThread") then
        set_default("McfGThread")
    elseif is_os("windows") and is_subhost("msys", "cygwin") then
        set_default("Pthread")
    elseif is_os("linux", "macosx") then
        set_default("Pthread")
    else
        set_default("C11Threads")
    end
    if Value == "McfGThread" then
        add_links("mcfgthread")
        add_defines('OgMacroOptionsThreadLibrary="McfGThread"')
        add_defines("OgMacroOptionsThreadLibraryIsMcfGThread=1")
        add_defines("OgMacroOptionsThreadLibraryIsPthread=0")
        add_defines("OgMacroOptionsThreadLibraryIsC11Threads=0")
    elseif Value == "Pthread" then
        add_links("pthread")
        add_defines("_REENTRANT")
        add_cflags("-pthread")
        add_defines('OgMacroOptionsThreadLibrary="Pthread"')
        add_defines("OgMacroOptionsThreadLibraryIsMcfGThread=0")
        add_defines("OgMacroOptionsThreadLibraryIsPthread=1")
        add_defines("OgMacroOptionsThreadLibraryIsC11Threads=0")
    elseif Value == "C11Threads" then
        add_defines('OgMacroOptionsThreadLibrary="C11Threads"')
        add_defines("OgMacroOptionsThreadLibraryIsMcfGThread=0")
        add_defines("OgMacroOptionsThreadLibraryIsPthread=0")
        add_defines("OgMacroOptionsThreadLibraryIsC11Threads=1")
    end
end)

option("EnableLibdwarf", function()
    set_default(false)
    local Value = get_config("EnableLibdwarf")
    if Value then
        add_links("libdwarf")
        add_defines("OgMacroOptionsEnableLibdwarfComponent=1")
    else
        add_defines("OgMacroOptionsEnableLibdwarfComponent=0")
    end
end)
option("EnableUnicode", function()
    set_default(true)
    local Value = get_config("EnableUnicode")
    if Value then
        add_defines("OgMacroOptionsEnableUnicode=1")
    end
end)
option("ExternLinker", function()
    set_default("None")
    set_values("Gold", "Bfd", "Mold", "Lld", "Wild", "None")
    local Value = get_config("ExternLinker")
    if Value == "None" then
    elseif Value == "Gold" then
        add_ldflags("gcc::-fuse-ld=gold", "clang::-fuse-ld=gold")
    elseif Value == "Bfd" then
        add_ldflags("gcc::-fuse-ld=bfd", "clang::-fuse-ld=bfd")
    elseif Value == "Mold" then
        add_ldflags("gcc::-fuse-ld=mold", "clang::-fuse-ld=mold")
    elseif Value == "Wild" then
        add_ldflags("gcc::-fuse-ld=wild", "clang::-fuse-ld=wild")
    elseif Value == "Lld" then
        add_ldflags("gcc::-fuse-ld=lld", "clang::-fuse-ld=lld")
    end
end)
option("EnableSseAndSse2", function()
    set_default(false)
    if get_config("EnableSseAndSse2") then
        add_defines("OgMacroOptionsEnableSseAndSse2=1")
        add_cxflags("gcc::-msse", "clang::-msse", "clang_cl::/arch:SSE2", "cl::/arch:SSE2")
    else
        add_defines("OgMacroOptionsEnableSseAndSse2=0")
    end
end)
target("OpenStgBase", function()
    set_kind("shared")
    set_languages("c11")
    set_encodings("utf-8")
    set_prefixname("lib")
    add_files("Source.CAndCpp/OpenStgBase/String/StringGetLength.c")
    add_includedirs("Source.CAndCpp/Include", { public = true })

    add_options("LoaderArchitecture")
    add_options("ExternLinker")
    add_options("ThreadsLibrary")
    add_options("EnableUnicode")
    add_options("EnableLibdwarf")

    local enableLibdwarf = get_config("EnableLibdwarf")
    local enableUnicode = get_config("EnableUnicode")
    local loaderArchitecture = get_config("LoaderArchitecture")
    local threadLibrary = get_config("ThreadsLibrary")
    if enableLibdwarf then
        add_packages("libdwarf")
    end
    if enableUnicode then
        add_packages("icu-i18n", "icu-io", "icu-uc")
    end
    if is_mode("debug") then
        add_defines("DEBUG=1", "_DEBUG=1")
    end
    if threadLibrary == "McfGThread" then
        add_packages("mcfgthread")
    end
    if is_plat("windows") then
        add_defines("_CRT_SECURE_NO_WARNINGS", "__STDC_WANT_LIB_EXT1__=1")
        add_defines("UNICODE=1", "_UNICODE=1")
    elseif is_plat("linux") then
        add_defines("_FORTIFY_SOURCE=1")
    end

    add_cflags("/Zc:__STDC__", { tools = { "cl", "clang_cl" }, public = true })
    add_cxxflags("/Zc:__plusplus", { tools = { "cl", "clang_cl" }, public = true })
    add_cxflags(
        "/SOURCE-CHARSET:utf-8",
        "/EXECUTION-CHARSET:utf-8",
        "/Wall",
        "/W4",
        { tools = { "cl", "clang_cl" }, public = true }
    )
    add_cxflags(
        "gcc::-fexec-charset=UTF-8",
        "gcc::-finput-charset=UTF-8",
        "-rdynamic",
        "-fpic", -- 位置无关代码
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-Wno-unused-parameter",
        "-Wno-tautological-undefined-compare",
        "-Wconversion",
        "-Wcast-align",
        "-Wincompatible-function-pointer-types",
        "-Wincompatible-function-pointer-types-strict",
        "-Wincompatible-pointer-types",
        { public = true }
    )
    on_config(function()
        print(("%s:%s"):format("EnableLibdwarf", enableLibdwarf))
        print(("%s:%s"):format("EnableUnicode", enableUnicode))
        print(("%s:%s"):format("LoaderArchitecture", loaderArchitecture))
        print(("%s:%s"):format("ThreadsLibrary", threadLibrary))
    end)
end)

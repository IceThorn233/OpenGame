/*
 *
 * @brief Memory maneger
 */

/* NOLINTBEGIN(cppcoreguidelines-*) */
#if !defined(OgBaseMacroHeaderTagMemory)
#define OgBaseMacroHeaderTagMemory 1
#if !(defined(OgMacroOptionsEnablePrecompilationHeader) && OgMacroOptionsEnablePrecompilationHeader)
#include <OpenStg/Base/Base.h>
#endif

OgMacroCBlockBegin

/**
 * @enum OgBsMemoryManipulationException
 * @brief Exception of the memory manipulating.
 */
enum OgBsMemoryManipulationException
{
    OgBsMemManExcNone = 0x00000000, /**< No exception */
    /*
     * @var OgBsMemoryManipulationException OgBsMemManExcNullParameter
     * @brief The value in parameter is NULL.
     */
    OgBsMemManExcNullParameter = 0x00000001,
    /**
     * @var OgBsMemoryManipulationException OgBsMemManExcInvalidParameter
     * @brief The vaule in parameter is invaild,
     */
    OgBsMemManExcInvalidParameter = 0x00000002,
    /*
     * @var OgBsMemoryManipulationException OgBsMemManExcInsufficientBuffer
     * @brief The copy operation failed due to insufficient buffer space.
     */
    OgBsMemManExcInsufficientBuffer = 0x00000003,
};

/**
 * @brief Copy `uSizeOfSource` characters form the object pointed to by `pcvSource` to the object
 * pointed by `pvDestination`
 *
 * REFERENCE: https://en.cppreference.com/c/string/byte/memcpy
 * REFERENCE: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/memcpy-wmemcpy
 *
 * REFERENCE MUSLC MEMCPY: https://git.musl-libc.org/cgit/musl/tree/src/string/memcpy.c
 * REFERENCE SIMD: https://github.com/skywind3000/FastMemcpy
 *
 * @note Both 'pcvSource' and 'pvDestination' are interpreted as arrays of `OgUnsignedByte`
 *
 * @param pvDestination Pointer of the object to copy to.
 * @param uDestinationSize Max number of bytes to modify in the destination (typically the size of
 * the destination object)
 * @param pcvSource Pointer of the object to copy form.
 * @param uCount Number of bytes to copy.
 *
 * @return Return a value to indicate what went wrong,
 * @retval OgBsMemManExcNone No exception.
 * @retval OgBsMemManExcNullParameter `pvDestination` or `pcvSource` is null.
 * @retval OgBsMemManExcInvalidParameter The value in `uDestinationSize` or `uCount` is either 0
 * or larger than `OgConstantUnsingedIntegerSizeMax`.
 * @retval OgBsMemManExcInsufficientBuffer The copy operation failed due to insufficient buffer
 * space.
 * @author IceThorn
 */
extern
enum OgBsMemoryManipulationException OgBsMemoryCopy(
    OgPVoid pvDestination,
    OgUnsignedIntegerSize uDestinationSize,
    OgPCVoid pcvSource,
    OgUnsignedIntegerSize uCount
);

OgMacroCBlockEnd

/* NOLINTEND(cppcoreguidelines-*) */
#endif

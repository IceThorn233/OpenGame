#include "Memory.h"

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif
#if !defined(OgBaseMacroHeaderTagBase)
#include <OpenStg/Base/Base.h>
#endif
#if !defined(OgBaseMacroHeaderTagMemory)
#include <OpenStg/Base/Memory.h>
#endif

#if defined(OgMacroBenchmarkOgBsMemoryUnsafeCopy)
#define OgDefinitionMemoryUnsafeCopy OgMacroBenchmarkOgBsMemoryUnsafeCopy
#else
#define OgDefinitionMemoryUnsafeCopy OgBsMemoryUnsafeCopy_FromMuslLibC
#endif

const struct OgBsStMemoryUnsafeCopy s_cfnMemoryCopy[] = {
    ogPvMacroGenerateOgBsStMemoryCopy(OgBsMemoryUnsafeCopy_Simple),
    ogPvMacroGenerateOgBsStMemoryCopy(OgBsMemoryUnsafeCopy_FromMuslLibC),
    ogPvMacroGenerateOgBsStMemoryCopy(OgBsMemoryUnsafeCopy_SystemLibC),
#if (defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2) && \
    (defined(__SSE2__) && __SSE2__) && (defined(__SSE__) && __SSE__)
    ogPvMacroGenerateOgBsStMemoryCopy(OgBsMemoryUnsafeCopy_SseAndSse2),
#endif
#if (defined(OgMacroOptionsEnableAvx) && OgMacroOptionsEnableAvx) && (defined(__AVX__) && __AVX__)
    ogPvMacroGenerateOgBsStMemoryCopy(OgBsMemoryUnsafeCopy_Avx),
#endif
};
void OgBsMoreMemoryCopyGetList(
    const struct OgBsStMemoryUnsafeCopy **const pcrgstOutput,
    OgUnsignedIntegerSize *const puLengthOutput
)
{
    if(pcrgstOutput == OgNullPtr || puLengthOutput == OgNullPtr)
    {
        return;
    }
    *pcrgstOutput = s_cfnMemoryCopy;
    *puLengthOutput = (sizeof(s_cfnMemoryCopy) / sizeof(struct OgBsStMemoryUnsafeCopy));
}

/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

/**
 *
 * REFERENCE "https://git.musl-libc.org/cgit/musl/tree/src/string/memcpy.c"
 * @copyright IceThorn
 * @date Beijing 2026-11-12 23:04:43
 */
enum OgBsMemoryManipulationException OgBsMemoryCopy(
    OgPVoid pvDestination,
    OgUnsignedIntegerSize uDestinationSize,
    OgPCVoid pcvSource,
    OgUnsignedIntegerSize uCount
)
{
    if(pvDestination == NULL || pcvSource == NULL)
    {
        return OgBsMemManExcNullParameter;
    }
    if(pvDestination == pcvSource)
    {
        return OgBsMemManExcInvalidParameter;
    }
    if(uDestinationSize == 0 || uCount == 0)
    {
        return OgBsMemManExcInvalidParameter;
    }
    if((uDestinationSize > OgConstantUnsingedIntegerSizeMax) ||
       (uCount > OgConstantUnsingedIntegerSizeMax))
    {
        return OgBsMemManExcInvalidParameter;
    }
    if(uDestinationSize < uCount)
    {
        return OgBsMemManExcInsufficientBuffer;
    }
    OgDefinitionMemoryUnsafeCopy(pvDestination, pcvSource, uCount);
    return OgBsMemManExcNone;
}

/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

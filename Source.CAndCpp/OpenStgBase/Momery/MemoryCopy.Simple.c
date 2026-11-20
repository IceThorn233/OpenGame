#if !defined(OgBaseMacroHeaderTagBase)
#include <OpenStg/Base/Base.h>
#endif
#if !defined(OgBaseMacroHeaderTagMemory)
#include <OpenStg/Base/Memory.h>
#endif

#include "Memory.h"

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif

void OgBsMemoryUnsafeCopy_Simple(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
)
{
    OgUnsignedByte *OgMacroSinceC99(restrict) const pbDestination =
        OgMacroStaticCast(OgUnsignedByte *, pvDestination);
    const OgUnsignedByte *OgMacroSinceC99(restrict) const pcbSource =
        OgMacroStaticCast(const OgUnsignedByte *, pcvSource);
    for(OgUnsignedIntegerSize uIndex = 0; uIndex < ucCount; ++uIndex)
    {
        pbDestination[uIndex] = pcbSource[uIndex];
    }
}

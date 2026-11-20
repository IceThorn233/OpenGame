#if !defined(OgBaseMacroHeaderTagBase)
#include <OpenStg/Base/Base.h>
#endif
#if !defined(OgBaseMacroHeaderTagMemory)
#include <OpenStg/Base/Memory.h>
#endif

#include "Memory.h"
#include <stdlib.h>

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif

void OgBsMemoryUnsafeCopy_SystemLibC(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
)
{
    memcpy(pvDestination, pcvSource, ucCount);
}

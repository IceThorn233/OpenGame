#if !defined(OgBaseMacroHeaderTagBasePrivateMemory)
#define OgBaseMacroHeaderTagBasePrivateMemory 1
#define OgBaseMacroHeaderTagBase 1
#if !defined(OgBaseMacroHeaderTagBase)
#include <OpenStg/Base/Base.h>
#endif
#if !defined(OgBaseMacroHeaderTagMemory)
#include <OpenStg/Base/Memory.h>
#endif
#if !defined(OgBaseMacroHeaderTagBaseUnsafeMemory)
#include <OpenStg/Base/More/Memory.h>
#endif

#define ogPvMacroGenerateOgBsStMemoryCopy(f) \
    { \
        .fn = (&f), \
        .szName = (#f), \
    }

#endif

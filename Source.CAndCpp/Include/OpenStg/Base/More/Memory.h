#if !defined(OgBaseMacroHeaderTagBaseUnsafeMemory)
#define OgBaseMacroHeaderTagBaseUnsafeMemory 1
#if !defined(OgBaseMacroHeaderTagBase)
#include <OpenStg/Base/Base.h>
#endif
OgMacroCBlockBegin

#if (defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2) && \
    (defined(__SSE2__) && __SSE2__) && (defined(__SSE__) && __SSE__)
OgMacroGnuAttribute(target("sse"), target("sse2"), nonnull(1, 2)) extern
/* REFERENCE SIMD: https://github.com/skywind3000/FastMemcpy */
void OgBsMemoryUnsafeCopy_SseAndSse2(
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgUnsignedIntegerSize uCount
);
#endif
#if (defined(OgMacroOptionsEnableAvx) && OgMacroOptionsEnableAvx) && (defined(__AVX__) && __AVX__)
/* REFERENCE SIMD: https://github.com/skywind3000/FastMemcpy */
OgMacroGnuAttribute(target("avx"), nonnull(1, 2)) extern
void OgBsMemoryUnsafeCopy_Avx(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
);
#endif
/* REFERENCE: https://en.cppreference.com/c/string/byte/memcpy */
OgMacroGnuAttribute(nonnull(1, 2)) extern
void OgBsMemoryUnsafeCopy_FromMuslLibC(
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgUnsignedIntegerSize uCount
);

/* REFERENCE MUSLC MEMCPY: https://git.musl-libc.org/cgit/musl/tree/src/string/memcpy.c */
OgMacroGnuAttribute(nonnull(1, 2)) extern
void OgBsMemoryUnsafeCopy_SystemLibC(
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgUnsignedIntegerSize uCount
);

OgMacroGnuAttribute(nonnull(1, 2)) extern
void OgBsMemoryUnsafeCopy_Simple(
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgUnsignedIntegerSize uCount
);

struct OgBsStMemoryUnsafeCopy
{
    void (*const fn)(
        OgPVoid OgMacroSinceC99(restrict) pvDestination,
        OgPCVoid OgMacroSinceC99(restrict) pcvSource,
        OgUnsignedIntegerSize uCount
    );
    OgConstantString const szName;
};

void OgBsMoreMemoryCopyGetList(
    const struct OgBsStMemoryUnsafeCopy **const pcrgstOutput,
    OgUnsignedIntegerSize *const puLengthOutput
);

OgMacroCBlockEnd
#endif

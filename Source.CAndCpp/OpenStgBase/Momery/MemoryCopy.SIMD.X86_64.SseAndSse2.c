
/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
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
#include "Memory.h"

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy16Byte128Bit_SseAndSse2_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 0, memoryAtIndex0);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy32Byte256Bit_SseAndSse2_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 0, memoryAtIndex0);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy64Byte512Bit_SseAndSse2_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 0, memoryAtIndex0);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_store_si128(OgMacroStaticCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    const __m128i memoryAtIndex4 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 4);
    const __m128i memoryAtIndex5 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 5);
    const __m128i memoryAtIndex6 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 6);
    const __m128i memoryAtIndex7 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 7);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 4, memoryAtIndex4);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 5, memoryAtIndex5);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 6, memoryAtIndex6);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 7, memoryAtIndex7);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_AlignedDestination_Prefetch(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid pcvPrefetchAddress
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    const __m128i memoryAtIndex4 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 4);
    const __m128i memoryAtIndex5 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 5);
    const __m128i memoryAtIndex6 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 6);
    const __m128i memoryAtIndex7 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 7);
    _mm_prefetch(OgMacroReinterpretCast(const char *, pcvPrefetchAddress), _MM_HINT_NTA);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 4, memoryAtIndex4);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 5, memoryAtIndex5);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 6, memoryAtIndex6);
    _mm_store_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 7, memoryAtIndex7);
}
OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy16Byte128Bit_SseAndSse2_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 0, memoryAtIndex0);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy32Byte256Bit_SseAndSse2_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy64Byte512Bit_SseAndSse2_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 0);
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_UnalignedDestination_Prefetch(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid pcvPrefetchAddress
)
{
    const __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    const __m128i memoryAtIndex4 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 4);
    const __m128i memoryAtIndex5 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 5);
    const __m128i memoryAtIndex6 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 6);
    const __m128i memoryAtIndex7 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 7);
    _mm_prefetch(OgMacroReinterpretCast(const char *, pcvPrefetchAddress), _MM_HINT_NTA);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 4, memoryAtIndex4);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 5, memoryAtIndex5);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 6, memoryAtIndex6);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 7, memoryAtIndex7);
}
OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    const __m128i memoryAtIndex1 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    const __m128i memoryAtIndex2 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    const __m128i memoryAtIndex3 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    const __m128i memoryAtIndex4 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 4);
    const __m128i memoryAtIndex5 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 5);
    const __m128i memoryAtIndex6 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 6);
    const __m128i memoryAtIndex7 =
        _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 7);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 4, memoryAtIndex4);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 5, memoryAtIndex5);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 6, memoryAtIndex6);
    _mm_storeu_si128(OgMacroReinterpretCast(__m128i *, pvDestination) + 7, memoryAtIndex7);
}

/*
 * NOTE: 没有些检查，没有写检查，没有写检查
 */

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"), nonnull(1, 2))
void OgBsMemoryUnsafeCopy_SseAndSse2(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
)
{
    OgMacroC(register) const OgUnsignedByte *OgMacroSinceC99(restrict) pcbSource =
        OgMacroReinterpretCast(const OgUnsignedByte *, pcvSource);
    OgMacroC(register) OgUnsignedByte *OgMacroSinceC99(restrict) pbDestination =
        OgMacroReinterpretCast(OgUnsignedByte *, pvDestination);
    OgMacroC(register) OgUnsignedIntegerSize uCount = ucCount;

    /* 对齐并复制 */
    /* 这里手动对齐 pcbSource 以调用 _mm_load_si128 */
    for(; (OgMacroUIntPtrCast(pcbSource) % OgMacroAlignOf(__m128i) != 0) && uCount != 0;
        ++pcbSource, ++pbDestination, --uCount)
    {
        *pbDestination = *pcbSource;
    }

    if(OgMacroUIntPtrCast(pbDestination) % OgMacroAlignOf(__m128i) == 0)
    {
        for(; (uCount >> 8) != 0; pcbSource += 128, pbDestination += 128, uCount -= 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_AlignedDestination_Prefetch(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination),
                OgMacroReinterpretCast(OgPCVoid, pcbSource + 256)
            );
        }
        if(uCount & 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_AlignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pcbSource += 128, pbDestination += 128, uCount -= 128;
        }
        /* 64 字节为单位复制 */
        if(uCount & 64)
        {
            ogBsPvMemoryCopy64Byte512Bit_SseAndSse2_AlignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 64;
            pbDestination += 64;
            uCount -= 64;
        }
        /* 32 字节为单位复制 */
        if(uCount & 32)
        {
            ogBsPvMemoryCopy32Byte256Bit_SseAndSse2_AlignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 32;
            pbDestination += 32;
            uCount -= 32;
        }
        /* 16 字节为单位复制 */
        if(uCount & 16)
        {
            ogBsPvMemoryCopy16Byte128Bit_SseAndSse2_AlignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 16;
            pbDestination += 16;
            uCount -= 16;
        }
        _mm_sfence();
        for(; uCount != 0; ++pcbSource, ++pbDestination, --uCount)
        {
            *pbDestination = *pcbSource;
        }
        return;
    }
    else
    /* SSE 和 SSE2 的 _mm_storeu_si128 不要求pbDestination对齐 */
    /* 飞肠省事 */
    {
        /* 128字节为单位复制 */
        for(; (uCount >> 8) != 0; pcbSource += 128, pbDestination += 128, uCount -= 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_UnalignedDestination_Prefetch(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination),
                OgMacroReinterpretCast(OgPCVoid, pcbSource + 256)
            );
        }
        if(uCount & 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2_UnalignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pcbSource += 128, pbDestination += 128;
        }
        /* 64 字节为单位复制 */
        if(uCount & 64)
        {
            ogBsPvMemoryCopy64Byte512Bit_SseAndSse2_UnalignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 64;
            pbDestination += 64;
        }
        /* 32 字节为单位复制 */
        if(uCount & 32)
        {
            ogBsPvMemoryCopy32Byte256Bit_SseAndSse2_UnalignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 32;
            pbDestination += 32;
        }
        /* 16 字节为单位复制 */
        if(uCount & 16)
        {
            ogBsPvMemoryCopy16Byte128Bit_SseAndSse2_UnalignedDestination(
                OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
            );
            pcbSource += 16;
            pbDestination += 16;
        }
        _mm_sfence();
        /* 8 字节为单位复制 */
        if(uCount & 8)
        {
            *OgMacroReinterpretCast(OgUnsignedInteger64 *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedInteger64 *, pcbSource);
            pcbSource += 8;
            pbDestination += 8;
        }
        if(uCount & 4)
        {
            *OgMacroReinterpretCast(OgUnsignedInteger32 *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedInteger32 *, pcbSource);
            pcbSource += 4;
            pbDestination += 4;
        }
        if(uCount & 2)
        {
            *OgMacroReinterpretCast(OgUnsignedInteger16 *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedInteger16 *, pcbSource);
            pcbSource += 2;
            pbDestination += 2;
        }
        if(uCount & 1)
        {
            *OgMacroReinterpretCast(OgUnsignedByte *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedByte *, pcbSource);
        }
        return;
    }
}
#endif
/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

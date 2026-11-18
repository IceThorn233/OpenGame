#if defined(OgMacroOptionsEnablePrecompilationHeader) && !OgMacroOptionsEnablePrecompilationHeader
#include <OpenStg/Base/Base.h>
#include <OpenStg/Base/String.h>
#include <OpenStg/Base/Memory.h>
#endif
#include <OpenStg/Base/LanguageExtension.h>

/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif

#if OgMacroOptionsIsBigEndian /* Big endian*/
#define OgPvMacroShiftToHigherAddress(Number, BytesToShift) ((Number) << ((BytesToShift) * 8))
#define OgPvMacroShiftToLowerAddress(Number, BytesToShift) ((Number) >> ((BytesToShift) * 8))
#else /* Little endian */
#define OgPvMacroShiftToHigherAddress(Number, BytesToShift) ((Number) >> ((BytesToShift) * 8))
#define OgPvMacroShiftToLowerAddress(Number, BytesToShift) ((Number) << ((BytesToShift) * 8))
#endif

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy16Byte128Bit_SseAndSse2(
    OgPCVoid OgAttrRestrict pcvSource, OgPVoid OgAttrRestrict pvDestination
)
{
    __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination), memoryAtIndex0);
}

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy32Byte256Bit_SseAndSse2(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    __m128i memoryAtIndex1 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
}
OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy64Byte512Bit_SseAndSse2(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    __m128i memoryAtIndex1 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    __m128i memoryAtIndex2 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    __m128i memoryAtIndex3 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_storeu_si128(OgMacroStaticCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
}
OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    __m128i memoryAtIndex0 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource));
    __m128i memoryAtIndex1 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 1);
    __m128i memoryAtIndex2 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 2);
    __m128i memoryAtIndex3 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 3);
    __m128i memoryAtIndex4 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 4);
    __m128i memoryAtIndex5 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 5);
    __m128i memoryAtIndex6 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 6);
    __m128i memoryAtIndex7 = _mm_load_si128(OgMacroStaticCast(const __m128i *, pcvSource) + 7);
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

OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy_SseAndSse2(
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

    /* SSE 和 SSE2 的 _mm_storeu_si128 不要求pbDestination对齐 */
    /* 这里手动对齐 pcbSource 以调用 _mm_load_si128 */
    /* 飞肠省事 */
    /* 对齐并复制 */
    for(; (OgMacroUIntPtrCast(pcbSource) % sizeof(__m128i) != 0) && uCount != 0;
        ++pcbSource, ++pbDestination, --uCount)
    {
        *pbDestination = *pcbSource;
    }
    _mm_prefetch(OgMacroStaticCast(const char *, pcbSource), _MM_HINT_NTA);
    /* 128字节为单位复制 */
    for(; (uCount >> 8) != 0; pcbSource += 128, pbDestination += 128, uCount -= 128)
    {
        ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2(
            OgMacroReinterpretCast(OgPCVoid, pcbSource),
            OgMacroReinterpretCast(OgPVoid, pbDestination)
        );
    }
    if(uCount & 128)
    {
        ogBsPvMemoryCopy128Byte1024Bit_SseAndSse2(
            OgMacroReinterpretCast(OgPCVoid, pcbSource),
            OgMacroReinterpretCast(OgPVoid, pbDestination)
        );
        pcbSource += 128, pbDestination += 128, uCount -= 128;
    }
    /* 64 字节为单位复制 */
    if(uCount & 64)
    {
        ogBsPvMemoryCopy64Byte512Bit_SseAndSse2(
            OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
        );
        pcbSource += 64;
        pbDestination += 64;
        uCount -= 64;
    }
    /* 32 字节为单位复制 */
    if(uCount & 32)
    {
        ogBsPvMemoryCopy32Byte256Bit_SseAndSse2(
            OgMacroStaticCast(OgPCVoid, pcbSource), OgMacroStaticCast(OgPVoid, pbDestination)
        );
        pcbSource += 32;
        pbDestination += 32;
        uCount -= 32;
    }
    /* 16 字节为单位复制 */
    if(uCount & 16)
    {
        ogBsPvMemoryCopy16Byte128Bit_SseAndSse2(
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
#endif /* OgMacroUseSse2 */
#if defined(OgMacroOptionsEnableAvx) && OgMacroOptionsEnableAvx
#endif

/**
 *
 * REFERENCE "https://git.musl-libc.org/cgit/musl/tree/src/string/memcpy.c"
 * @copyright IceThorn
 * @date Beijing 2026-11-12 23:04:43
 */
OgMacroGnuAttribute(always_inline) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy_MaybeFaster_FromMuslLibC(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucSizeToCopy
)
{
    typedef OgUnsignedInteger32 OgMacroGnuAttribute(may_alias) U32;

    OgUnsignedByte *OgMacroSinceC99(restrict) pbDestination =
        OgMacroStaticCast(OgUnsignedByte *, pvDestination);
    const OgUnsignedByte *OgMacroSinceC99(restrict) pcbSource =
        OgMacroStaticCast(const OgUnsignedByte *, pcvSource);
    OgUnsignedIntegerSize uSizeToCopy = ucSizeToCopy;
    U32 u32Word1 = 0;
    U32 u32Word2 = 0;

    for(; (OgMacroUIntPtrCast(pcbSource) % sizeof(OgUnsignedInteger32) != 0) && uSizeToCopy != 0;
        --uSizeToCopy, ++pcbSource, ++pbDestination)
    {
        *pbDestination = *pcbSource;
    }
    /*
     * 如果 pbDestination 和 pcbSource 都对齐到32位边界
     * 飞肠省事
     */
    if((OgMacroUIntPtrCast(pbDestination) % sizeof(OgUnsignedInteger32)) == 0)
    {
        for(; uSizeToCopy >= (sizeof(OgUnsignedInteger32) * 4);
            uSizeToCopy -= sizeof(OgUnsignedInteger32) * 4,
            pcbSource += sizeof(OgUnsignedInteger32) * 4,
            pbDestination += sizeof(OgUnsignedInteger32) * 4)
        {
            *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 0);
            *OgMacroReinterpretCast(U32 *, pbDestination + 4) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 4);
            *OgMacroReinterpretCast(U32 *, pbDestination + 8) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 8);
            *OgMacroReinterpretCast(U32 *, pbDestination + 12) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 12);
        }
        if(uSizeToCopy & 8)
        {
            *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 0);
            *OgMacroReinterpretCast(U32 *, pbDestination + 4) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 4);
            pbDestination += 8, pcbSource += 8;
        }
        if(uSizeToCopy & 4)
        {
            *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                *OgMacroReinterpretCast(const U32 *, pcbSource + 0);
            pbDestination += 4, pcbSource += 4;
        }
        if(uSizeToCopy & 2)
        {
            *pbDestination++ = *pcbSource++;
            *pbDestination++ = *pcbSource++;
        }
        if(uSizeToCopy & 1)
        {
            *pbDestination++ = *pcbSource++;
        }
        return;
    }
    if(uSizeToCopy >= 32)
    {
        /* 获取 pbDestination 的对齐边界 */
        switch(OgMacroUIntPtrCast(pbDestination) % 4)
        {
        /* 8 */
        case 1:
            {
                u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource);
                /* 让 pbDestination 对齐到32位边界 */
                *pbDestination++ = *pcbSource++;
                *pbDestination++ = *pcbSource++;
                *pbDestination++ = *pcbSource++;
                uSizeToCopy -= 3;
                /*             |      u32Word2     |    u32Word1        */
                /* Cache:       0xUN(0x12 0x34 0x56|0x78)0xUN 0xUN 0xUN */
                /* Destination:(0x12 0x34 0x56 0x78)0xUN 0xUN 0xUN 0xUN */
                /*              High address      <-   Low address      */
                /* 高地址位的u32向低地址位移动 */
                /* 低地址位的u32向高地址位移动 */
                for(; uSizeToCopy >= 17; pbDestination += 16, pcbSource += 16, uSizeToCopy -= 16)
                {
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 1);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 3) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 1);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 5);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 4) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 3) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 1);
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 9);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 8) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 3) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 1);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 13);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 12) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 3) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 1);
                }
            }
            break;
        case 2:
            {
                u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource);
                *pbDestination++ = *pcbSource++;
                *pbDestination++ = *pcbSource++;
                uSizeToCopy -= 2;
                for(; uSizeToCopy >= 18; pbDestination += 16, pcbSource += 16, uSizeToCopy -= 16)
                {
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 2);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 2) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 2);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 6);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 4) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 2) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 2);
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 10);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 8) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 2) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 2);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 14);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 12) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 2) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 2);
                }
            }
            break;
        case 3:
            {
                u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource);
                /* 让 pbDestination 对齐到32位边界 */
                *pbDestination++ = *pcbSource++;
                uSizeToCopy -= 1;
                for(; uSizeToCopy >= 19; pbDestination += 16, pcbSource += 16, uSizeToCopy -= 16)
                {
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 3);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 0) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 1) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 3);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 7);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 4) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 1) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 3);
                    u32Word2 = *OgMacroReinterpretCast(U32 *, pcbSource + 11);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 8) =
                        OgPvMacroShiftToHigherAddress(u32Word1, 1) |
                        OgPvMacroShiftToLowerAddress(u32Word2, 3);
                    u32Word1 = *OgMacroReinterpretCast(U32 *, pcbSource + 15);
                    *OgMacroReinterpretCast(U32 *, pbDestination + 12) =
                        OgPvMacroShiftToHigherAddress(u32Word2, 1) |
                        OgPvMacroShiftToLowerAddress(u32Word1, 3);
                }
            }
            break;
        }
    }

    if((uSizeToCopy & 16) != 0)
    {
        *pbDestination++ = *pcbSource++; /* 0 */
        *pbDestination++ = *pcbSource++; /* 1 */
        *pbDestination++ = *pcbSource++; /* 2 */
        *pbDestination++ = *pcbSource++; /* 3 */
        *pbDestination++ = *pcbSource++; /* 4 */
        *pbDestination++ = *pcbSource++; /* 5 */
        *pbDestination++ = *pcbSource++; /* 6 */
        *pbDestination++ = *pcbSource++; /* 7 */
        *pbDestination++ = *pcbSource++; /* 8 */
        *pbDestination++ = *pcbSource++; /* 9 */
        *pbDestination++ = *pcbSource++; /* 10*/
        *pbDestination++ = *pcbSource++; /* 11*/
        *pbDestination++ = *pcbSource++; /* 12*/
        *pbDestination++ = *pcbSource++; /* 13*/
        *pbDestination++ = *pcbSource++; /* 14*/
        *pbDestination++ = *pcbSource++; /* 15*/
    }
    if((uSizeToCopy & 8) != 0)
    {
        *pbDestination++ = *pcbSource++; /* 0 */
        *pbDestination++ = *pcbSource++; /* 1 */
        *pbDestination++ = *pcbSource++; /* 2 */
        *pbDestination++ = *pcbSource++; /* 3 */
        *pbDestination++ = *pcbSource++; /* 4 */
        *pbDestination++ = *pcbSource++; /* 5 */
        *pbDestination++ = *pcbSource++; /* 6 */
        *pbDestination++ = *pcbSource++; /* 7 */
    }
    if((uSizeToCopy & 4) != 0)
    {
        *pbDestination++ = *pcbSource++; /* 0 */
        *pbDestination++ = *pcbSource++; /* 1 */
        *pbDestination++ = *pcbSource++; /* 2 */
        *pbDestination++ = *pcbSource++; /* 3 */
    }
    if((uSizeToCopy & 2) != 0)
    {
        *pbDestination++ = *pcbSource++; /* 0 */
        *pbDestination++ = *pcbSource++; /* 1 */
    }
    if((uSizeToCopy & 1) != 0)
    {
        *pbDestination = *pcbSource; /* 0 */
    }

    return;
}

OgMacroGnuAttribute(always_inline) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy_MaybeFaster_Simple(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucSizeToCopy
)
{
    OgUnsignedByte *OgMacroSinceC99(restrict) pbDestination =
        OgMacroStaticCast(OgUnsignedByte *, pvDestination);
    const OgUnsignedByte *OgMacroSinceC99(restrict) pcbSource =
        OgMacroStaticCast(const OgUnsignedByte *, pcvSource);
    for(OgUnsignedIntegerSize uIndex = 0; uIndex < ucSizeToCopy; ++uIndex)
    {
        pbDestination[uIndex] = pcbSource[uIndex];
    }
}
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
#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
    ogBsPvMemoryCopy_SseAndSse2(pvDestination, pcvSource, uCount);
    return OgBsMemManExcNone;
#endif
    ogBsPvMemoryCopy_MaybeFaster_FromMuslLibC(pvDestination, pcvSource, uCount);
    return OgBsMemManExcNone;
    ogBsPvMemoryCopy_MaybeFaster_Simple(pvDestination, pcvSource, uCount);
    return OgBsMemManExcNone;
}

/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

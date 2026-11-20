
/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

#if defined(OgMacroOptionsEnableAvx) && OgMacroOptionsEnableAvx
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
/* Aligned */

OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy32Byte256Bit_Avx_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination), memoryAtIndex0);
}

OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy64Byte512Bit_Avx_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
}

OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_Avx_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
}
OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy256Byte2048Bit_Avx_AlignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    const __m256i memoryAtIndex4 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 4);
    const __m256i memoryAtIndex5 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 5);
    const __m256i memoryAtIndex6 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 6);
    const __m256i memoryAtIndex7 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 7);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 4, memoryAtIndex4);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 5, memoryAtIndex5);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 6, memoryAtIndex6);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 7, memoryAtIndex7);
}
OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy256Byte2048Bit_Avx_AlignedDestination_Prefetch(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid pcvPrefetchAddress
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    const __m256i memoryAtIndex4 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 4);
    const __m256i memoryAtIndex5 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 5);
    const __m256i memoryAtIndex6 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 6);
    const __m256i memoryAtIndex7 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 7);
    _mm_prefetch(OgMacroReinterpretCast(const char *, pcvPrefetchAddress), _MM_HINT_NTA);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 4, memoryAtIndex4);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 5, memoryAtIndex5);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 6, memoryAtIndex6);
    _mm256_store_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 7, memoryAtIndex7);
}
/* Unaligned */
OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy32Byte256Bit_Avx_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination), memoryAtIndex0);
}

OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy64Byte512Bit_Avx_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
}
OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy128Byte1024Bit_Avx_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
}

OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy256Byte2048Bit_Avx_UnalignedDestination(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource, OgPVoid OgMacroSinceC99(restrict) pvDestination
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    const __m256i memoryAtIndex4 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 4);
    const __m256i memoryAtIndex5 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 5);
    const __m256i memoryAtIndex6 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 6);
    const __m256i memoryAtIndex7 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 7);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 4, memoryAtIndex4);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 5, memoryAtIndex5);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 6, memoryAtIndex6);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 7, memoryAtIndex7);
}
OgMacroGnuAttribute(always_inline, target("avx")) OgMacroMsvc(__forceinline) static inline
void ogBsPvMemoryCopy256Byte2048Bit_Avx_UnalignedDestination_Prefetch(
    OgPCVoid OgMacroSinceC99(restrict) pcvSource,
    OgPVoid OgMacroSinceC99(restrict) pvDestination,
    OgPCVoid pcvPrefetchAddress
)
{
    const __m256i memoryAtIndex0 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 0);
    const __m256i memoryAtIndex1 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 1);
    const __m256i memoryAtIndex2 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 2);
    const __m256i memoryAtIndex3 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 3);
    const __m256i memoryAtIndex4 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 4);
    const __m256i memoryAtIndex5 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 5);
    const __m256i memoryAtIndex6 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 6);
    const __m256i memoryAtIndex7 =
        _mm256_load_si256(OgMacroReinterpretCast(const __m256i *, pcvSource) + 7);
    _mm_prefetch(OgMacroReinterpretCast(const char *, pcvPrefetchAddress), _MM_HINT_NTA);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 0, memoryAtIndex0);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 1, memoryAtIndex1);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 2, memoryAtIndex2);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 3, memoryAtIndex3);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 4, memoryAtIndex4);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 5, memoryAtIndex5);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 6, memoryAtIndex6);
    _mm256_storeu_si256(OgMacroReinterpretCast(__m256i *, pvDestination) + 7, memoryAtIndex7);
}
void OgBsMemoryUnsafeCopy_Avx(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
)
{
    /* 对齐到256位边界 */
    OgMacroC(register) const OgUnsignedByte *OgMacroSinceC99(restrict) pcbSource =
        OgMacroReinterpretCast(const OgUnsignedByte *, pcvSource);
    OgMacroC(register) OgUnsignedByte *OgMacroSinceC99(restrict) pbDestination =
        OgMacroReinterpretCast(OgUnsignedByte *, pvDestination);
    OgMacroC(register) OgUnsignedIntegerSize uCount = ucCount;

    for(; (OgMacroUIntPtrCast(pcbSource) % OgMacroAlignOf(__m256i)) != 0 && uCount != 0;
        --uCount, ++pbDestination, ++pcbSource)
    {
        *pbDestination = *pcbSource;
    }

    /* 检查 pbDestination 是否对齐到256位边界 */
    if((OgMacroUIntPtrCast(pbDestination) % OgMacroAlignOf(__m256i)) == 0)
    {
        /* 以128为单位复制 */
        for(; (uCount >> 9) != 0;)
        {
            ogBsPvMemoryCopy256Byte2048Bit_Avx_AlignedDestination_Prefetch(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination),
                OgMacroReinterpretCast(OgPCVoid, pcbSource + 512)
            );
            uCount -= 256;
            pbDestination += 256;
            pcbSource += 256;
        }
        if(uCount & 256)
        {
            ogBsPvMemoryCopy256Byte2048Bit_Avx_AlignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 256;
            pcbSource += 256;
        }
        if(uCount & 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_Avx_AlignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 128;
            pcbSource += 128;
        }
        /* 以64为单位复制 */
        if(uCount & 64)
        {
            ogBsPvMemoryCopy64Byte512Bit_Avx_AlignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 64;
            pcbSource += 64;
        }
        /* 以32为单位复制 */
        if(uCount & 32)
        {
            ogBsPvMemoryCopy32Byte256Bit_Avx_AlignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 32;
            pcbSource += 32;
        }
        /* 16 字节为单位复制 */
        if(uCount & 16)
        {
            *OgMacroReinterpretCast(OgUnsignedInteger64 *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedInteger64 *, pcbSource);
            pcbSource += 8;
            pbDestination += 8;
            *OgMacroReinterpretCast(OgUnsignedInteger64 *, pbDestination) =
                *OgMacroReinterpretCast(const OgUnsignedInteger64 *, pcbSource);
            pcbSource += 8;
            pbDestination += 8;
        }
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
    }
    else
    {
        /* 以128为单位复制 */
        for(; (uCount >> 9) != 0;)
        {
            ogBsPvMemoryCopy256Byte2048Bit_Avx_UnalignedDestination_Prefetch(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination),
                OgMacroReinterpretCast(OgPCVoid, pcbSource + 512)
            );
            uCount -= 256;
            pbDestination += 256;
            pcbSource += 256;
        }
        if(uCount & 256)
        {
            ogBsPvMemoryCopy256Byte2048Bit_Avx_UnalignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 256;
            pcbSource += 256;
        }
        if(uCount & 128)
        {
            ogBsPvMemoryCopy128Byte1024Bit_Avx_UnalignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 128;
            pcbSource += 128;
        }
        /* 以64为单位复制 */
        if(uCount & 64)
        {
            ogBsPvMemoryCopy64Byte512Bit_Avx_UnalignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 64;
            pcbSource += 64;
        }
        /* 以32为单位复制 */
        if(uCount & 32)
        {
            ogBsPvMemoryCopy32Byte256Bit_Avx_UnalignedDestination(
                OgMacroReinterpretCast(OgPCVoid, pcbSource),
                OgMacroReinterpretCast(OgPVoid, pbDestination)
            );
            pbDestination += 32;
            pcbSource += 32;
        }
        /* 16 字节为单位复制 */
        uCount &= 31;
        for(; uCount > 0; --uCount)
        {
            *pbDestination++ = *pcbSource++;
        }
    }
    _mm_sfence();
    _mm256_zeroupper();
    return;
}
#endif

/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

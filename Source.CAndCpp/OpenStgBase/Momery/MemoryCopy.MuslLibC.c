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

/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

#if OgMacroOptionsIsBigEndian /* Big endian*/
#define OgPvMacroShiftToHigherAddress(Number, BytesToShift) ((Number) << ((BytesToShift) * 8))
#define OgPvMacroShiftToLowerAddress(Number, BytesToShift) ((Number) >> ((BytesToShift) * 8))
#else /* Little endian */
#define OgPvMacroShiftToHigherAddress(Number, BytesToShift) ((Number) >> ((BytesToShift) * 8))
#define OgPvMacroShiftToLowerAddress(Number, BytesToShift) ((Number) << ((BytesToShift) * 8))
#endif

/**
 *
 * REFERENCE "https://git.musl-libc.org/cgit/musl/tree/src/string/memcpy.c"
 * @copyright IceThorn
 * @date Beijing 2026-11-12 23:04:43
 */
void OgBsMemoryUnsafeCopy_FromMuslLibC(
    OgPVoid OgMacroSinceC99(restrict) const pvDestination,
    OgPCVoid OgMacroSinceC99(restrict) const pcvSource,
    OgUnsignedIntegerSize const ucCount
)
{
    typedef OgUnsignedInteger32 OgMacroGnuAttribute(may_alias) U32;

    OgUnsignedByte *OgMacroSinceC99(restrict) pbDestination =
        OgMacroStaticCast(OgUnsignedByte *, pvDestination);
    const OgUnsignedByte *OgMacroSinceC99(restrict) pcbSource =
        OgMacroStaticCast(const OgUnsignedByte *, pcvSource);
    OgUnsignedIntegerSize uSizeToCopy = ucCount;
    U32 u32Word1 = 0;
    U32 u32Word2 = 0;

    for(; (OgMacroUIntPtrCast(pcbSource) % OgMacroAlignOf(OgUnsignedInteger32) != 0) &&
        uSizeToCopy != 0;
        --uSizeToCopy, ++pcbSource, ++pbDestination)
    {
        *pbDestination = *pcbSource;
    }
    /*
     * 如果 pbDestination 和 pcbSource 都对齐到32位边界
     * 飞肠省事
     */
    if((OgMacroUIntPtrCast(pbDestination) % OgMacroAlignOf(OgUnsignedInteger32)) == 0)
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

/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

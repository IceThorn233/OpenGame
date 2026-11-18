#include <stdalign.h>
/*
 * From musl libc.
 * musl/src/strlen.c
 *
 * @copyright Rich Felker
 * @copyright IceThorn
 * @date Beijing 2026-11-06 18:30:22
 *
 * NOTE: 位数特定的
 */
#if defined(OgMacroOptionsEnablePrecompilationHeader) && !OgMacroOptionsEnablePrecompilationHeader
#include <OpenStg/Base/String.h>
#include <OpenStg/Base/Base.h>
#endif

#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif
#endif
/*
 * NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

/* 0x0101010101010101*/
#define OgConstantLowBits \
    OgMacroStaticCast(OgUIntPtr, -1) / OgMacroStaticCast(OgUnsignedCharater, -1)
/* 0x8080808080808080*/
#define OgConstantHighBit \
    OgMacroStaticCast(OgUIntPtr, OgConstantLowBits << (sizeof(OgUnsignedCharater) * 8 - 1))

/* REFERENCE "https://git.musl-libc.org/cgit/musl/tree/src/string/strlen.c" */
OgMacroGnuAttribute(always_inline) OgMacroMsvc(__forceinline) static inline
OgUnsignedIntegerSize ogBsPvStringGetLength_MuslLibc(
    OgConstantString OgMacroSinceC99(restrict) pcsString
)
{
    /* register 关键字以提升性能(MSVC除外)  */
    OgMacroC(register) const OgUIntPtr *OgMacroGnuAttribute(may_alias) wWord = OgNullPtr;
    OgMacroC(register) OgConstantCharacter *pcPointerToCharacter = pcsString;
    /* 对齐字节 */
    for(; OgMacroUIntPtrCast(pcPointerToCharacter) % (sizeof(OgPVoid) != 0); ++pcPointerToCharacter)
    {
        if(*pcPointerToCharacter == '\0')
        {
            return OgMacroStaticCast(OgUIntPtr, pcPointerToCharacter - pcsString);
        }
    }
    /* 快速遍历是否有0 */
    for(wWord = OgMacroReinterpretCast(const OgUIntPtr *, pcPointerToCharacter);
        !((*wWord - OgConstantLowBits) & ~(*wWord) & OgConstantHighBit); ++wWord)
    {
        /* NOLINTNEXTLINE(clang-analyzer-deadcode.DeadStores) */
        pcPointerToCharacter = OgMacroReinterpretCast(OgConstantCharacter *, wWord);
    }
    pcPointerToCharacter = OgMacroReinterpretCast(OgConstantCharacter *, wWord);
    for(; (*pcPointerToCharacter) != '\0'; ++pcPointerToCharacter)
    {
    }
    return OgMacroStaticCast(OgUnsignedIntegerSize, pcPointerToCharacter - pcsString);
}

OgMacroGnuAttribute(always_inline) OgMacroMsvc(__forceinline) static inline
OgUnsignedIntegerSize ogBsPvStringGetLength_Simple(
    OgConstantString OgMacroSinceC99(restrict) pcsString
)
{
    OgMacroC(register) OgConstantString OgMacroSinceC99(restrict) pcsCurrent = pcsString;
    for(; *pcsCurrent != '\0'; ++pcsCurrent)
        ;
    return OgMacroStaticCast(OgUnsignedIntegerSize, pcsCurrent - pcsString);
}

#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
OgMacroGnuAttribute(always_inline, target("sse"), target("sse2"))
OgMacroMsvc(__forceinline) static inline
OgUnsignedIntegerSize ogBsPvStringGetLength_SseAndSse2(
    OgConstantString OgMacroSinceC99(restrict) pcsString
)
{
    return ogBsPvStringGetLength_Simple(pcsString);
}
#endif

OgUnsignedIntegerSize OgBsStringGetLength(
    OgConstantString OgMacroSinceC99(restrict) pcsString
)
{
    return ogBsPvStringGetLength_MuslLibc(pcsString);
    return ogBsPvStringGetLength_Simple(pcsString);
}
/*
 * NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-avoid-magic-numbers)
 */

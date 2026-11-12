/*
 * From musl libc.
 * musl/src/strlen.c
 *
 * @copyright Rich Felker
 * @copyright IceThorn
 * @since Beijing 2026-11-06 18:30:22
 *
 * NOTE: 位数特定的
 */
#include <OpenStg/Base/String.h>

/* 0x0101010101010101*/
#define OgConstantLowBits \
    OgMacroStaticCast(OgUIntPtr, -1) / OgMacroStaticCast(OgUnsignedCharater, -1)
/* 0x8080808080808080*/
#define OgConstantHighBit \
    OgMacroStaticCast(OgUIntPtr, OgConstantLowBits << (sizeof(OgUnsignedCharater) * 8 - 1))

OgUnsignedIntegerSize OgBsStringGetLength(
    OgConstantString restrict pcsString
)
{
    /* register 关键字以提升性能(MSVC除外)  */
    OgMacroC(register) OgConstantCharacter *pcPointerToCharacter = pcsString;
    OgMacroC(register) const OgUIntPtr *OgMacroGnuAttribute(may_alias) wWord = OgNullPtr;
    for (
        ; OgMacroStaticCast(OgUIntPtr, pcPointerToCharacter) % (sizeof(OgPVoid) != 0);
        ++pcPointerToCharacter
    )
    {
        if (*pcPointerToCharacter == '\0')
        {
            return OgMacroStaticCast(OgUIntPtr, pcPointerToCharacter - pcsString);
        }
    }
    for (
        wWord = OgMacroPointerCast(const OgPointerSizedUnsignedInteger *, pcPointerToCharacter);
        !((*wWord - OgConstantLowBits) & ~(*wWord) & OgConstantHighBit); ++wWord
    )
    {
        pcPointerToCharacter = OgMacroStaticCast(OgConstantCharacter *, wWord);
    }
    pcPointerToCharacter = OgMacroStaticCast(OgConstantCharacter *, wWord);
    for (; (*pcPointerToCharacter) != '\0'; ++pcPointerToCharacter)
    {
    }
    return OgMacroStaticCast(OgUIntPtr, pcPointerToCharacter - pcsString);
}

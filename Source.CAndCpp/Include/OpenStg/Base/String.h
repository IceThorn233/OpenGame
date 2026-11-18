/**
 * @file OpenStg/Base/String.h
 * @brief String manipulation.
 * @date Beiging 2026-09-06 16:34:21
 * @date Beiging 2026-11-06 16:15:17
 * @anchor IceThorn,ZhengYi0119
 */
#if !defined(OgBaseMacroHeaderTagString)
#define OgBaseMacroHeaderTagString 1
#if !(defined(OgMacroOptionsEnablePrecompilationHeader) && OgMacroOptionsEnablePrecompilationHeader)
#include <OpenStg/Base/Base.h>
#endif

OgMacroCBlockBegin
/**
 * @enum OgBsStringException
 * Exception of the string manipulating.
 */
enum OgBsStringException
{
    OgBsStrExcNone = 0, /**< No exception.*/
    OgBsStrExcInsufficientBuffer = 0x00000001,
    OgBsStrExcBufferOverflow = 0x00000001,
    /**
     * @var OgBsStringException OgBsStrExcInvaildParameter
     * Parameter is null
     */
    OgBsStrExcInvaildParameter = 0x00000002,
    /**
     * @var OgBsStringException OgBsStrExcAyachiNene
     * Ciallo～(∠・ω< )⌒★
     */
    OgBsStrExcAyachiNene = 0x0d000721,
};

/**
 * @enum OgBsStringManipulationOptions
 * Options of the string manipulation.
 */
enum OgBsStringManipulationOptions
{
    OgBsStrManNone = 0, /**< Default.*/
    /**
     * @var OgBsStringManipulationOptions OgBsStrManFillNullOnFailure
     * if the function fails,the destination string is set to a empty string.(\0)
     */
    OgBsStrManFillNullOnFailure = 0x00000001,
    /**
     * @var OgBsStringManipulationOptions OgBsStrManRestoreOnFailure
     */
    OgBsStrManRestoreOnFailure = 0x00000002,
    /**
     * @var OgBsStringManipulationOptions OgBsStrManAyachiNene
     * @brief Ciallo～(∠・ω< )⌒★
     */
    OgBsStrManAyachiNene = 0x0d000721,
};
/**
 * @brief Returns the length of the given null-terminated byte string,the number of characters in a
 * character array whose first element is pointed to by 'pcsString' up to and not including the
 * first null character.
 *
 * REFERENCE https://en.cppreference.com/c/string/byte/strlen
 *
 * REFERENCE MUSLC STRLEN https://git.musl-libc.org/cgit/musl/tree/src/string/strlen.c
 * REFERENCE SIMD (zh_CN) https://geek-doc.cn/languages/c/intermediate/18-string-performance
 * REFERENCE SIMD https://github.com/shines77/strlen_fast.git
 *
 * @anchor IceThorn
 * @param pcsString pointer to the null-terminated byte string to be examined
 * @return The length of the null-terminated byte string 'pcsString'
 */
extern
OgUnsignedIntegerSize OgBsStringGetLength(OgConstantString OgMacroSinceC99(restrict) pcsString);

/**
 * Appends a string.
 *
 * Appends a copy of the null-terminated byte string pointed to by 'pcsSource' to the end of the
 * null-terminated byte string pointed to by 'psDestination'.
 *
 * @brief Appends a string.
 * @param pcsSource Pointer to the null-terminated byte string to copy from.
 * @param psDestination Pointer to the null-terminated byte string to append to.
 * @param sDestinationLength Maximum number of characters to write,
 * @param ufStringManipulationOptions Options of the manipulation.
 * @return OgBsStrExcInvaildArgument If 'pcsSource' is null.
 */
extern
enum OgBsStringException OgBsStringAppend(
    OgString psDestination,
    OgSignedIntegerSize sDestinationLength,
    OgConstantString pcsSource,
    enum OgBsStringManipulationOptions ufStringManipulationOptions
);

/* extern enum OgBsStringException OgBsStringCopy(); */

/*
#if defined OgMacroOptionsEnableUnicode && OgMacroOptionsEnableUnicode
extern OgSignedIntegerSize OgBsUtf8StringGetLength(OgConstantUtf8String pcsStr);
extern OgSignedIntegerSize OgBsUtf8StringGetCharacterCount(OgConstantUtf8String pcsStr);

extern OgSignedIntegerSize OgBsUtf16StringGetLength(OgConstantUtf16String pcsStr);
extern OgSignedIntegerSize OgBsUtf16StringGetCharacterCount(OgConstantUtf16String pcsStr);

extern OgSignedIntegerSize OgBsUtf32StringGetLength(OgConstantUtf32String pcsStr);
extern OgSignedIntegerSize OgBsUtf32StringGetCharacterCount(OgConstantUtf32String pcsStr);
#endif
*/

OgMacroCBlockEnd
#endif

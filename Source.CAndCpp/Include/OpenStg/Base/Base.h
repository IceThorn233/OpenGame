/**
 * 吐槽：我在考虑什么兼容性？是想让WindowsNT4(With Visual C++6)跑吗？
 * @brief 我在干些什么啊???
 * @author IceThorn
 * @since Beijing 2026-11-12 19:24:30
 */

#if !defined(OgBaseMacroHeaderTagBase)
#define OgBaseMacroHeaderTagBase 1

/* Anis C89 */
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>
/* StdC99 */
#include <string.h>
#include <errno.h>
#include <uchar.h>
#include <stdbool.h>
#include <stdint.h>

#if __STDC_VERSION__ >= 201112L
/* StdC11 */
#include <uchar.h>
#include <stdalign.h>
#endif
#if __STDC_VERSION__ >= 201710L
/* StdC17 */
#endif
#if __STDC_VERSION__ >= 202311L
/* StdC23 */
#endif

#define OgMacroSinceAnsiC(Expression) Expression
/* StdC95 */
#if __STDC_VERSION__ >= 199409L
#define OgMacroSinceC95(Expression) Expression
#else
#define OgMacroSinceC95(Expression)
#endif
/* StdC99 */
#if __STDC_VERSION__ >= 199901L
#define OgMacroSinceC99(Expression) Expression
#else
#define OgMacroSinceC99(Expression)
#endif
/* StdC11 */
#if __STDC_VERSION__ >= 201112L
#define OgMacroSinceC11(Expression) Expression
#else
#define OgMacroSinceC11(Expression) Expression
#endif
/* StdC17 */
#if __STDC_VERSION__ >= 201710L
#define OgMacroSinceC17(Expression) Expression
#else
#define OgMacroSinceC17(Expression)
#endif
/* StdC23 */
#if __STDC_VERSION__ >= 202311L
#define OgMacroSinceC23(Expression) Expression
#define OgMacroC23Attribute(...) [[__VA_ARGS__]]
#else
#define OgMacroSinceC23(Expression)
#define OgMacroC23Attribute(...)
#endif

#if !defined OgMacroOptionsEnableNonstandardFixedWidthIntegerTypes
#if defined(__has_include) && __has_include(<stdint.h>)
#include <stdint.h>
#define OgMacroOptionsEnableNonstandardFixedWidthIntegerTypes 0
#else
#define OgMacroOptionsEnableNonstandardFixedWidthIntegerTypes 1
#endif
#endif

#if defined(_MSC_VER)
#define OgMacroMsvc(Expression) Expression
#define OgMacroMsvcDeclspec(Expression) __declspec(Expression)
#define OgMacroGnu(...)
#define OgMacroGnuAttribute(...)
#define OgMacroAlwaysInline __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define OgMacroMsvc(Expression)
#define OgMacroMsvcDeclspec(Expression)
#define OgMacroGnu(...) __VA_ARGS__
#define OgMacroGnuAttribute(...) __attribute__((__VA_ARGS__))
#define OgMacroAlwaysInline __attribute__((__always_inline__))
#else
#define OgMacroMsvc(...)
#define OgMacroMsvcDeclspec(Expression)
#define OgMacroGnu(...)
#define OgMacroGnuAttribute(...)
#define OgMacroAlwaysInline
#endif

#if defined(__cplusplus)
#define OgMacroC(...)
#define OgMacroCpp(...) __VA_ARGS__
#define OgMacroCBlockBegin \
    extern "C" \
    {
#define OgMacroCBlockEnd }
#define OgMacroUIntPtrCast(Expression) (reinterpret_cast<OgUIntPtr>(Expression))
#define OgMacroStaticCast(Type, Expression) (static_cast<Type>(Expression))
#define OgMacroReinterpretCast(Type, Expression) (reinterpret_cast<Type>(Expression))
#else
#define OgMacroC(...) __VA_ARGS__
#define OgMacroCpp(...)
#define OgMacroCBlockBegin
#define OgMacroCBlockEnd
#define OgMacroUIntPtrCast(Expression) ((OgUIntPtr)(Expression))
#define OgMacroStaticCast(Type, Expression) ((Type)(Expression))
#define OgMacroReinterpretCast(Type, Expression) ((Type)(OgPVoid)(Expression))
#endif

#if defined(__cplusplus) && __cplusplus >= 201103L
#define OgNullPtr nullptr
#elif defined(__cplusplus)
#define OgNullPtr 0L
#else
#define OgNullPtr ((OgPVoid)0)
#endif

OgMacroCBlockBegin

typedef char OgCharacter, *OgString;
typedef signed char OgSignedCharater;
typedef unsigned char OgUnsignedCharater;
typedef int8_t OgSignedInteger8, OgInteger8, OgSignedByte, OgSByte;
typedef uint8_t OgUnsignedInteger8, OgUnsignedByte, OgByte;
typedef int16_t OgSignedInteger16, OgInteger16;
typedef uint16_t OgUnsignedInteger16;
typedef int32_t OgSignedInteger32, OgInteger32;
typedef uint32_t OgUnsignedInteger32;
typedef int64_t OgSignedInteger64, OgInteger64;
typedef uint64_t OgUnsignedInteger64;
typedef int64_t OgSignedIntegerSize;
typedef uint64_t OgUnsignedIntegerSize;
typedef intptr_t OgIntPtr, OgPointerSizedSignedInteger;
typedef uintptr_t OgUIntPtr, OgPointerSizedUnsignedInteger;
typedef void *OgPVoid;
typedef const void *OgPCVoid;

typedef uint8_t OgBoolean, Og8BitBoolean;
typedef uint32_t Og32BitBoolean;

#define OgFalse 0
#define OgTrue 1
#define OgBooleanFalse UINT8_C(0)
#define OgBooleanTrue UINT8_C(1)
#define Og8BitBooleanFalse UINT8_C(0)
#define Og8BitBooleanTrue UINT8_C(1)
#define Og32BitBooleanFalse UINT32_C(0)
#define Og32BitBooleanTrue UINT32_C(1)

#define OgMacroSignedInteger8Constant(Value) INT8_C(Value)
#define OgMacroUnsignedInteger8Constant(Value) UINT8_C(Value)
#define OgMacroSignedInteger16Constant(Value) INT16_C(Value)
#define OgMacroUnsignedInteger16Constant(Value) UINT16_C(Value)
#define OgMacroSignedInteger32Constant(Value) INT32_C(Value)
#define OgMacroUnsignedInteger32Constant(Value) UINT32_C(Value)
#define OgMacroSignedInteger64Constant(Value) INT64_C(Value)
#define OgMacroUnsignedInteger64Constant(Value) UINT64_C(Value)
#define OgMacroSignedIntegerSizeConstant(Value) INT64_C(Value)
#define OgMacroUnsignedIntegerSizeConstant(Value) UINT64_C(Value)

#define OgConstantSingedIntegerSizeMax OgMacroSignedIntegerSizeConstant(0x00FFFFFFFFFFFFFF)
#define OgConstantUnsingedIntegerSizeMax OgMacroUnsignedIntegerSizeConstant(0x00FFFFFFFFFFFFFF)

typedef const char OgConstantCharacter, *OgConstantString;
typedef const char *OgConstantString;

#if defined(OgMacroOptionsEnableUnicode) && OgMacroOptionsEnableUnicode
typedef const wchar_t OgConstantWidthCharacter, *OgConstantWidthString;
typedef wchar_t OgWidthCharacter, *OgWidthString;
#if defined(__cplusplus) && defined(__cpp_char8_t)
typedef const char8_t OgConstantUtf8Character, *OgConstantUtf8String;
typedef char8_t OgUtf8Character, *OgUtf8String;
#else
typedef const char OgConstantUtf8Character, *OgConstantUtf8String;
typedef char OgUtf8Character, *OgUtf8String;
#endif
#if __STDC_VERSION__ >= 201112L
typedef const char16_t OgConstantUtf16Character, *OgConstantUtf16String;
typedef char16_t OgUtf16Character, *OgUtf16String;
typedef const char32_t OgConstantUtf32Character, *OgConstantUtf32String;
typedef char32_t OgUtf32Character, *OgUtf32String;
#else
typedef const uint16_t OgConstantUtf16Character, *OgConstantUtf16String;
typedef uint16_t OgUtf16Character, *OgUtf16String;
typedef const uint32_t OgConstantUtf32Character, *OgConstantUtf32String;
typedef uint32_t OgUtf32Character, *OgUtf32String;
#endif
#endif

OgMacroCBlockEnd
#endif

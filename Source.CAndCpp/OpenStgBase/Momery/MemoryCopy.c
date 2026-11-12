#include "Memory.h"

#if defined(OgMacroOptionsEnableSseAndSse2) && OgMacroOptionsEnableSseAndSse2
#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <immintrin.h>
#endif

OgMacroGnuAttribute(always_inline,gnu_inline)
static inline void ogBsPvMemoryCopy16Byte128Bit(
    OgPVoid OgMacroSinceC99(OgMacroC(restrict))  psDestination,
    OgPCVoid OgMacroSinceC99(OgMacroC(restrict)) pcsSource
)
{
    __m128i memoryAtIndex0 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pcsSource));
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, psDestination), memoryAtIndex0);
}
OgMacroGnuAttribute(always_inline,gnu_inline)
static inline void ogBsPvMemoryCopy32Byte256Bit(
    OgPVoid OgMacroSinceC99(OgMacroC(restrict)) psDestination,
    OgPCVoid OgMacroSinceC99(OgMacroC(restrict)) pcsSource
)
{
    __m128i memoryAtIndex0 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pcsSource));
    __m128i memoryAtIndex1 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pcsSource) + 1);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, psDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, psDestination) + 1, memoryAtIndex1);
}
OgMacroGnuAttribute(always_inline,gnu_inline)
static inline void ogBsPvMemoryCopy64Byte512Bit(
    OgPVoid OgMacroSinceC99(OgMacroC(restrict)) pvDestination,
    OgPCVoid OgMacroSinceC99(OgMacroC(restrict)) pvSource
)
{
    __m128i memoryAtIndex0 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource));
    __m128i memoryAtIndex1 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 1);
    __m128i memoryAtIndex3 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 2);
    __m128i memoryAtIndex4 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 4);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 2, memoryAtIndex3);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 3, memoryAtIndex4);
}
OgMacroGnuAttribute(always_inline,gnu_inline)
static inline void ogBsPvMemoryCopy128Byte1024Bit(
    OgPVoid OgMacroSinceC99(OgMacroC(restrict)) pvDestination,
    OgPCVoid OgMacroSinceC99(OgMacroC(restrict)) pvSource
)
{
    __m128i memoryAtIndex0 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource));
    __m128i memoryAtIndex1 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 1);
    __m128i memoryAtIndex2 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 2);
    __m128i memoryAtIndex3 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 4);
    __m128i memoryAtIndex4 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 5);
    __m128i memoryAtIndex5 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 6);
    __m128i memoryAtIndex6 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 7);
    __m128i memoryAtIndex7 = _mm_loadu_si128(OgMacroPointerCast(const __m128i *, pvSource) + 8);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination), memoryAtIndex0);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 1, memoryAtIndex1);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 2, memoryAtIndex2);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 3, memoryAtIndex3);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 4, memoryAtIndex4);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 5, memoryAtIndex5);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 6, memoryAtIndex6);
    _mm_storeu_si128(OgMacroPointerCast(__m128i *, pvDestination) + 7, memoryAtIndex7);
}
OgMacroGnuAttribute(always_inline,gnu_inline)
static inline void ogBsPvMemoryCopyIn256Byte(
    OgPVoid OgMacroC(OgMacroSinceC99(restrict)) pvDestination,
    OgPCVoid OgMacroC(OgMacroSinceC99(restrict)) pcvSource,
    OgUnsignedInteger16 uSizeOfSource
)
{
    OgUnsignedIntegerSize uCurrentIndex = 0;
}
#endif // OgMacroUseSse2

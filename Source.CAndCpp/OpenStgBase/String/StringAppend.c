#include <OpenStg/Base/String.h>

OgMacroGnuAttribute(always_inline, const) static inline
enum OgBsStringException pvOgBsStringAppend(
    OgString OgMacroSinceC99(OgMacroC(restrict)) psDestination,
    OgConstantString OgMacroSinceC99(OgMacroC(restrict)) pcsSource
)
{
    return OgBsStrExcNone;
}
enum OgBsStringException OgBsStringAppend(
    OgString psDestination,
    OgSignedIntegerSize sDestinationLength,
    OgConstantString pcsSource,
    enum OgBsStringManipulationOptions ufStringManipulationOptions
)
{
    return OgBsStrExcNone;
}

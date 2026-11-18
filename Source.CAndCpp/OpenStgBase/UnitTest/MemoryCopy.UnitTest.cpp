#include <OpenStg/Base/Memory.h>
#include <catch2/catch_all.hpp>
#include <random>
#include <limits>
#include <span>

constexpr inline size_t uTestBufferLength = 1024 * 1024;
constexpr inline int seed = 114514;

/*
 * NOLINTBEGIN(cppcoreguidelines-pro-type-member-init,cert-msc32-c,cert-msc51-cpp)
 */

/* $PWD/Source.CAndCpp/OpenStgBase/Momery/MemoryCopy.c */
TEST_CASE(
    "enum OgBsMemoryManipulationException "
    "OgBsMemoryCopy(OgPVoid,OgUnsignedIntegerSize,OgPCVoid,OgUnsignedIntegerSize)",
    "[OpenStg.Base.Memory]"
)
{
    std::array<OgUnsignedByte, uTestBufferLength> rgSource;
    std::array<OgUnsignedByte, uTestBufferLength> rgDestination;
    memset(OgMacroReinterpretCast(OgPVoid, rgSource.data()), 0, rgSource.size());
    memset(OgMacroReinterpretCast(OgPVoid, rgDestination.data()), 0, rgSource.size());
    std::mt19937 rngGenerator(seed);
    std::uniform_int_distribution<OgUnsignedByte> uidDistribution(
        std::numeric_limits<OgUnsignedByte>::min(), std::numeric_limits<OgUnsignedByte>::max()
    );
    for(size_t uIndex = 0; uIndex < uTestBufferLength; ++uIndex)
    {
        rgSource.at(uIndex) = rngGenerator();
    }
    std::span<OgUnsignedByte> sprgSourceWithOffset;

    /* 不偏移 */
    sprgSourceWithOffset = std::span<OgUnsignedByte>(rgSource);
    REQUIRE(sprgSourceWithOffset.size() == rgSource.size());
    REQUIRE(
        OgBsMemoryCopy(
            OgMacroReinterpretCast(OgPVoid, rgDestination.data()), rgDestination.size(),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(OgUnsignedIntegerSize, sprgSourceWithOffset.size())
        ) == OgBsMemManExcNone
    );
    REQUIRE(
        memcmp(
            OgMacroReinterpretCast(OgPCVoid, rgDestination.data()),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(size_t, sprgSourceWithOffset.size())
        ) == 0
    );
    memset(OgMacroReinterpretCast(OgPVoid, rgDestination.data()), 0, rgDestination.size());

    /* 偏移一位 */
    sprgSourceWithOffset = sprgSourceWithOffset.subspan(1);
    REQUIRE(sprgSourceWithOffset.size() == rgSource.size() - 1);
    REQUIRE(
        OgBsMemoryCopy(
            OgMacroReinterpretCast(OgPVoid, rgDestination.data()), rgDestination.size(),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(OgUnsignedIntegerSize, sprgSourceWithOffset.size())
        ) == OgBsMemManExcNone
    );
    REQUIRE(
        memcmp(
            OgMacroReinterpretCast(OgPCVoid, rgDestination.data()),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(size_t, sprgSourceWithOffset.size())
        ) == 0
    );
    memset(OgMacroReinterpretCast(OgPVoid, rgDestination.data()), 0, rgDestination.size());

    /* 偏移三位 */
    sprgSourceWithOffset = std::span<OgUnsignedByte>(rgSource).subspan(3);
    REQUIRE(sprgSourceWithOffset.size() == rgSource.size() - 3);
    REQUIRE(
        OgBsMemoryCopy(
            OgMacroReinterpretCast(OgPVoid, rgDestination.data()), rgDestination.size(),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(OgUnsignedIntegerSize, sprgSourceWithOffset.size())
        ) == OgBsMemManExcNone
    );
    REQUIRE(
        memcmp(
            OgMacroReinterpretCast(OgPCVoid, rgDestination.data()),
            OgMacroReinterpretCast(OgPCVoid, sprgSourceWithOffset.data()),
            OgMacroStaticCast(size_t, sprgSourceWithOffset.size())
        ) == 0
    );
}
/*
 * NOLINTEND(cppcoreguidelines-pro-type-member-init,cert-msc32-c,cert-msc51-cpp)
 */

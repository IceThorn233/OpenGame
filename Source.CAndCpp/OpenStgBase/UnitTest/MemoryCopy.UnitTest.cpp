#include <OpenStg/Base/Memory.h>
#include <catch2/catch_all.hpp>
#include <random>
#include <limits>
#include <span>
#include <stdlib.h>
#include <OpenStg/Base/More/Memory.h>

constexpr inline size_t uSourceBufferLength = 128 * 1024 * 1024 ;
constexpr inline size_t uDestinationBufferLength =
    128 * 1024 * 1024 + OgMacroAlignOf(OgUIntPtr) + 1;
constexpr inline int seed = 114514;

/*
 * NOLINTBEGIN(cppcoreguidelines-pro-type-member-init,cert-msc32-c,cert-msc51-cpp)
 */

/* $PWD/Source.CAndCpp/OpenStgBase/Momery/MemoryCopy.c */
TEST_CASE(
    "enum OgBsMemoryManipulationException "
    "OgBsMemoryCopy(OgPVoid,OgUnsignedIntegerSize,OgPCVoid,OgUnsignedIntegerSize)",
    "[OpenStg::Base::Memory]"
)
{
    OgUnsignedByte *pbSource = OgMacroReinterpretCast(
        OgUnsignedByte *, aligned_alloc(OgMacroAlignOf(OgUnsignedInteger64) * 4, uSourceBufferLength)
    );
    OgUnsignedByte *pbDestination = OgMacroReinterpretCast(
        OgUnsignedByte *,
        aligned_alloc(OgMacroAlignOf(OgUnsignedInteger64) * 4, uDestinationBufferLength)
    );
    const struct OgBsStMemoryUnsafeCopy *rgst = OgNullPtr;
    OgUnsignedIntegerSize uLength = 0;
    OgBsMoreMemoryCopyGetList(&rgst, &uLength);
    if(pbSource == OgNullPtr || pbDestination == OgNullPtr)
    {
        REQUIRE(false);
        return;
    }
    memset(OgMacroReinterpretCast(OgPVoid, pbSource), 0, uSourceBufferLength);
    memset(OgMacroReinterpretCast(OgPVoid, pbDestination), 0, uDestinationBufferLength);
    std::span<OgUnsignedByte> sSource{pbSource, uSourceBufferLength};
    std::span<OgUnsignedByte> sDestination{pbDestination, uDestinationBufferLength};
    std::span<const struct OgBsStMemoryUnsafeCopy> sst{rgst, uLength};
    std::mt19937 rgRandomGenerator{seed};
    for(size_t uIndex = 0; uIndex < sSource.size(); ++uIndex)
    {
        sSource[uIndex] = rgRandomGenerator();
    }
    for(const auto &st : sst)
    {
        // if(std::string_view(st.szName) == "OgBsMemoryUnsafeCopy_Simple")
        // {
        //     continue;
        // }
        for(size_t uOffset = 0; uOffset < OgMacroAlignOf(OgUIntPtr); ++uOffset)
        {
            std::span<OgUnsignedByte> sOffsetDestination =
                sDestination.subspan(uOffset, uSourceBufferLength);
            BENCHMARK(std::format("fun:{};Offset:{}", st.szName, uOffset))
            {
                st.fn(
                    OgMacroReinterpretCast(OgPVoid, sOffsetDestination.data()), sSource.data(),
                    sOffsetDestination.size()
                );
            };
            REQUIRE(sOffsetDestination.size() == sSource.size());
            REQUIRE(
                memcmp(sSource.data(), sOffsetDestination.data(), sOffsetDestination.size()) == 0
            );
            /* 检查是否存在数组越界(上溢) */
            REQUIRE(sOffsetDestination.data()[sOffsetDestination.size() + 1] == 0);
            memset(
                OgMacroStaticCast(OgPVoid, sOffsetDestination.data()), 0, sOffsetDestination.size()
            );
        }
    }
    free(OgMacroReinterpretCast(OgPVoid, pbSource));
    free(OgMacroReinterpretCast(OgPVoid, pbDestination));
}
/*
 * NOLINTEND(cppcoreguidelines-pro-type-member-init,cert-msc32-c,cert-msc51-cpp)
 */

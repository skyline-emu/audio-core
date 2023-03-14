// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <chrono>
#include <audio_core/common/common_types.h>

namespace Core::Timing {
namespace detail {
template<s64 TARGET_FREQ>
inline s64 ScaleCycles(s64 cycles) {
    static constexpr s64 TEGRA_X1_CNTFREQ{19200000};

    return static_cast<s64>(((cycles / TEGRA_X1_CNTFREQ) * TARGET_FREQ) +
                            (((cycles % TEGRA_X1_CNTFREQ) * TARGET_FREQ + (TEGRA_X1_CNTFREQ / 2)) / TEGRA_X1_CNTFREQ));
}
}

[[nodiscard]] constexpr std::chrono::nanoseconds CyclesToNs(s64 cycles) {
    return std::chrono::nanoseconds{detail::ScaleCycles<1000000000L>(cycles)};
}

[[nodiscard]] constexpr std::chrono::microseconds CyclesToUs(s64 cycles) {
    return std::chrono::microseconds{detail::ScaleCycles<1000000L>(cycles)};
}
}

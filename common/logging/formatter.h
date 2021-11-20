// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <type_traits>

#include <fmt/format.h>

// adapted from https://github.com/fmtlib/fmt/issues/2704
// a generic formatter for enum classes
#if FMT_VERSION >= 80100
template <typename E>
struct fmt::formatter<E, std::enable_if_t<std::is_enum_v<E>, char>> : formatter<std::underlying_type_t<E>> {
    template <typename FormatContext>
    auto format(const E& value, FormatContext& ctx) -> decltype(ctx.out()) {
        return fmt::formatter<std::underlying_type_t<E>>::format(static_cast<std::underlying_type_t<E>>(value), ctx);
    }
};
#endif

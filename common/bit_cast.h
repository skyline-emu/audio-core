// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <type_traits>

namespace Common {
    /**
     * @brief A temporary shim for C++ 20's bit_cast to make transitioning to it easier
     */
    template<typename To, typename From>
    requires (sizeof(To) == sizeof(From) && std::is_trivially_copyable_v<To> && std::is_trivially_copyable_v<From>)
    To BitCast(const From &from) {
        return *reinterpret_cast<const To *>(&from);
    }
}

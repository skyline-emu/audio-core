// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <audio_core/common/common_types.h>

namespace AudioCore {
union Result {
    u32 raw{};
    struct __attribute__((packed)) {
        u16 module : 9;
        u16 id : 12;
    };

    /**
     * @note Success is 0, it's the only result that's not specific to a module
     */
    constexpr Result() = default;

    constexpr Result(u32 val) : raw{val}  {}

    constexpr Result(u16 module, u16 id) : module(module), id(id) {}

    constexpr operator u32() const {
        return raw;
    }

    bool IsError() const {
        return raw != 0;
    }

    bool IsSuccess() const {
        return raw == 0;
    }
};

static constexpr Result ResultSuccess{};
}

namespace Service::Audio {
constexpr AudioCore::Result ResultNotFound{153, 1};
constexpr AudioCore::Result ResultOperationFailed{153, 2};
constexpr AudioCore::Result ResultInvalidSampleRate{153, 3};
constexpr AudioCore::Result ResultInsufficientBuffer{153, 4};
constexpr AudioCore::Result ResultOutOfSessions{153, 5};
constexpr AudioCore::Result ResultBufferCountReached{153, 8};
constexpr AudioCore::Result ResultInvalidChannelCount{153, 10};
constexpr AudioCore::Result ResultInvalidUpdateInfo{153, 41};
constexpr AudioCore::Result ResultInvalidAddressInfo{153, 42};
constexpr AudioCore::Result ResultNotSupported{153, 513};
constexpr AudioCore::Result ResultInvalidHandle{153, 1536};
constexpr AudioCore::Result ResultInvalidRevision{153, 1537};
}

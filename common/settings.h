// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include "common_types.h"

namespace AudioCore::Settings {
template<typename T>
struct Wrapper {
    T val;

    const T &GetValue() const {
        return val;
    }
};

/**
 * @note Only contains the settings relevant to audio core
 */
struct Values {
    Wrapper<std::string> sink_id{"auto"};
    Wrapper<std::string> audio_output_device_id{"auto"};
    Wrapper<std::string> audio_input_device_id{"auto"};
    bool dump_audio_commands{};
    u8 volume{100};
};

static inline Values values{}; //!< A static structure with the values set by Skyline code

static inline float Volume() {
    return values.volume / static_cast<f32>(200);
}
}

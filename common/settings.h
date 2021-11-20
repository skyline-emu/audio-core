// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include "common_types.h"

namespace AudioCore {
    /**
     * @note Only contains the settings relevant to audio core
     */
    struct Values {
        std::string sink_id;
        std::string audio_output_device_id;
        std::string audio_input_device_id;
        bool dump_audio_commands;
        u8 volume;

        u8 Volume() const {
            return volume;
        }
    };

    static inline Values values{}; //!< A static structure with the values set by Skyline code
}

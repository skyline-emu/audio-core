// SPDX-FileCopyrightText: Copyright 2022 yuzu Emulator Project
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <array>

#include <audio_core/common/common_types.h>

namespace AudioCore::AudioRenderer {

struct EffectResultState {
    std::array<u8, 0x80> state;
};

} // namespace AudioCore::AudioRenderer

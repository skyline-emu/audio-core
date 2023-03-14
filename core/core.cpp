// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <audio_core/audio_core.h>
#include "core_timing.h"
#include "memory.h"
#include "core.h"

namespace Core {

System::System() : memory{std::make_unique<Memory::Memory>()}, audio_core{std::make_unique<AudioCore::AudioCore>(*this)}, core_timing{std::make_unique<Core::Timing::CoreTiming>()} {}

System::~System() = default;

Core::Memory::Memory& System::Memory() {
    return *memory;
}

const Core::Memory::Memory& System::Memory() const {
    return *memory;
}

AudioCore::AudioCore& System::AudioCore() {
    return *audio_core;
}

const AudioCore::AudioCore& System::AudioCore() const {
    return *audio_core;
}

Timing::CoreTiming& System::CoreTiming() {
    return *core_timing;
}

const Timing::CoreTiming& System::CoreTiming() const {
    return *core_timing;
}
}

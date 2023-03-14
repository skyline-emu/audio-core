// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <mutex>
#include <memory>

namespace Kernel {
class KProcess;
}
namespace AudioCore {
class AudioCore;
} // namespace AudioCore

namespace Core::Timing {
class CoreTiming;
}

namespace Core::Memory {
class Memory;
} // namespace Core::Memory


namespace Core {
class System {
private:
    std::mutex stall_mutex;
    std::unique_ptr<Core::Memory::Memory> memory;
    std::unique_ptr<AudioCore::AudioCore> audio_core;
    std::unique_ptr<Timing::CoreTiming> core_timing;

  public:
    System();

    ~System();

    /// Gets a mutable reference to the system memory instance.
    [[nodiscard]] Core::Memory::Memory& Memory();

    /// Gets a constant reference to the system memory instance.
    [[nodiscard]] const Core::Memory::Memory& Memory() const;

    /// Gets a mutable reference to the audio interface
    [[nodiscard]] AudioCore::AudioCore& AudioCore();

    /// Gets an immutable reference to the audio interface.
    [[nodiscard]] const AudioCore::AudioCore& AudioCore() const;

    /// Provides a reference to the core timing instance.
    [[nodiscard]] Timing::CoreTiming& CoreTiming();

    /// Provides a constant reference to the core timing instance.
    [[nodiscard]] const Timing::CoreTiming& CoreTiming() const;

    bool IsMulticore() const {
        return true;
    }

    bool IsShuttingDown() const {
        return false;
    }

    bool IsPaused() const {
        return false;
    }

    std::unique_lock<std::mutex> StallApplication() {
        return std::unique_lock<std::mutex>{stall_mutex};
    };

    void UnstallApplication() const {};

    Kernel::KProcess *ApplicationProcess() {
        return nullptr;
    }
};

}

// SPDX-FileCopyrightText: Copyright 2022 yuzu Emulator Project
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <audio_core/common/common_types.h>

namespace AudioCore {

struct AudioBuffer {
    /// Timestamp this buffer started playing.
    u64 start_timestamp;
    /// Timestamp this buffer should finish playing.
    u64 end_timestamp;
    /// Timestamp this buffer completed playing.
    s64 played_timestamp;
    /// Game memory address for these samples.
    VAddr samples;
    /// Unqiue identifier for this buffer.
    u64 tag;
    /// Size of the samples buffer.
    u64 size;
};

} // namespace AudioCore

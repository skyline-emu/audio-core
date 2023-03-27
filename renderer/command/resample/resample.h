// SPDX-FileCopyrightText: Copyright 2022 yuzu Emulator Project
// SPDX-License-Identifier: MPL-2.0

#pragma once

#include <span>

#include <audio_core/common/common.h>
#include <audio_core/common/common_types.h>
#include <audio_core/common/fixed_point.h>

namespace AudioCore::AudioRenderer {
/**
 * Resample an input buffer into an output buffer, according to the sample_rate_ratio.
 *
 * @param output            - Output buffer.
 * @param input             - Input buffer.
 * @param sample_rate_ratio - Ratio for resampling.
                              e.g 32000/48000 = 0.666 input samples read per output.
 * @param fraction          - Current read fraction, written to and should be passed back in for
 *                            multiple calls.
 * @param samples_to_write  - Number of samples to write.
 * @param src_quality       - Resampling quality.
 */
void Resample(std::span<s32> output, std::span<const s16> input,
              const Common::FixedPoint<49, 15>& sample_rate_ratio,
              Common::FixedPoint<49, 15>& fraction, u32 samples_to_write, SrcQuality src_quality);

} // namespace AudioCore::AudioRenderer

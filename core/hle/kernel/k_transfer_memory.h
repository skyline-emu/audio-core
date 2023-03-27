// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <vector>
#include <audio_core/common/common_types.h>

namespace KernelShim {
class KTransferMemory {
public:
    KTransferMemory(size_t size) : data(size) {}

    VAddr GetSourceAddress() {
        return reinterpret_cast<VAddr>(data.data());
    }

private:
    std::vector<u8> data;
};
}

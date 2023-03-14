// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <audio_core/common/common_types.h>
#include "hle/kernel/k_process.h"

namespace Core::Memory {
constexpr std::size_t YUZU_PAGEBITS = 12;
constexpr u64 YUZU_PAGESIZE = 1ULL << YUZU_PAGEBITS;
constexpr u64 YUZU_PAGEMASK = YUZU_PAGESIZE - 1;

/// Central class that handles all memory operations and state.
class Memory {
public:
    u8* GetPointer(VAddr vaddr) {
        return reinterpret_cast<u8*>(vaddr);
    }

    template <typename T>
    T* GetPointer(VAddr vaddr) {
        return reinterpret_cast<T*>(GetPointer(vaddr));
    }

    const u8* GetPointer(VAddr vaddr) const {
        return reinterpret_cast<const u8*>(vaddr);
    }

    template <typename T>
    const T* GetPointer(VAddr vaddr) const {
        return reinterpret_cast<T*>(GetPointer(vaddr));
    }

    void Write32(VAddr addr, u32 data) {
        *GetPointer<u32>(addr) = data;
    }

    void ReadBlockUnsafe(VAddr src_addr, void* dest_buffer, std::size_t size) {
        std::memcpy(dest_buffer, GetPointer<void>(src_addr), size);
    }

    void WriteBlockUnsafe(VAddr dest_addr, const void* src_buffer, std::size_t size) {
        std::memcpy(GetPointer<void>(dest_addr), src_buffer, size);
    }

    void ZeroBlock(Kernel::KProcess &proc, VAddr dest_addr, std::size_t size) {
        std::memset(GetPointer<void>(dest_addr), 0, size);
    }
};
}

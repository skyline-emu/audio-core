// SPDX-License-Identifier: MPL-2.0
// Copyright © 2019 yuzu Emulator Project (https://github.com/yuzu-emu/yuzu/)

#pragma once

#include "common_types.h"
#include "bit_cast.h"

namespace AudioCore {
    #pragma pack(push, 1)
    template<size_t Start, size_t Count, typename Type>
    struct BitField {
      private:
        constexpr static size_t BitsInByte{8};
        constexpr static size_t PaddingBits{Start % BitsInByte};

        u8 paddingBytes[Start / BitsInByte];
        size_t item : PaddingBits + Count;

      public:
        constexpr void Assign(const Type &value) {
            constexpr size_t PaddingMask{(1 << PaddingBits) - 1};
            size_t newValue{static_cast<size_t>(value) << PaddingBits};
            item = newValue | (item & PaddingMask);
        }

        constexpr Type Value() const {
            return static_cast<Type>(item >> PaddingBits);
        }

        constexpr operator Type() const {
            return Value();
        }

        constexpr explicit operator bool() const {
            return Value() != 0;
        }
    };
    #pragma pack(pop)
}

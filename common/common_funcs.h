// SPDX-License-Identifier: MPL-2.0
// Copyright © 2019 yuzu Emulator Project (https://github.com/yuzu-emu/yuzu/)

#pragma once

#include "common_types.h"

#define CONCAT_INNER(a, b) a ## b
#define CONCAT(a, b) CONCAT_INNER(a, b)
#define PAD_NAME CONCAT(CONCAT(_pad, __COUNTER__), _)

#define INSERT_PADDING_BYTES(byteCount) u8 PAD_NAME[byteCount]{}
#define INSERT_PADDING_WORDS(wordCount) u32 PAD_NAME[wordCount]{}

#define INSERT_PADDING_BYTES_NOINIT(byteCount) u8 PAD_NAME[byteCount]
#define INSERT_PADDING_WORDS_NOINIT(wordCount) u32 PAD_NAME[wordCount]

#define DECLARE_ENUM_FLAG_OPERATORS(ENUMTYPE)                                      \
    constexpr ENUMTYPE operator|(ENUMTYPE a, ENUMTYPE b) {                         \
        using TYPE = std::underlying_type_t<ENUMTYPE>;                             \
        return static_cast<ENUMTYPE>(static_cast<TYPE>(a) | static_cast<TYPE>(b)); \
    }                                                                              \
    constexpr ENUMTYPE operator&(ENUMTYPE a, ENUMTYPE b) {                         \
        using TYPE = std::underlying_type_t<ENUMTYPE>;                             \
        return static_cast<ENUMTYPE>(static_cast<TYPE>(a) & static_cast<TYPE>(b)); \
    }                                                                              \
    constexpr ENUMTYPE& operator|=(ENUMTYPE& a, ENUMTYPE b) {                      \
        a = a | b;                                                                 \
        return a;                                                                  \
    }                                                                              \
    constexpr ENUMTYPE& operator&=(ENUMTYPE& a, ENUMTYPE b) {                      \
        a = a & b;                                                                 \
        return a;                                                                  \
    }                                                                              \
    constexpr bool True(ENUMTYPE key) noexcept {                                   \
        using TYPE = std::underlying_type_t<ENUMTYPE>;                             \
        return static_cast<TYPE>(key) != 0;                                        \
    }                                                                              \
    constexpr bool False(ENUMTYPE key) noexcept {                                  \
        using TYPE = std::underlying_type_t<ENUMTYPE>;                             \
        return static_cast<TYPE>(key) == 0;                                        \
    }

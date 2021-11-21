// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <fmt/format.h>

namespace AudioCore::Log {
    // Proxy logging framework, these functions are implemented by Skyline
    void Debug(const std::string& message);
    void Warn(const std::string& message);
    void Error(const std::string& message);
}

#define LOG_DEBUG(tag, message, ...) AudioCore::Log::Debug(fmt::format("Audio Core (" #tag "): " message __VA_OPT__(,) __VA_ARGS__))
#define LOG_WARNING(tag, message, ...) AudioCore::Log::Warn(fmt::format("Audio Core (" #tag "): " message __VA_OPT__(,) __VA_ARGS__))
#define LOG_ERROR(tag, message, ...) AudioCore::Log::Error(fmt::format("Audio Core (" #tag "): " message __VA_OPT__(,) __VA_ARGS__))

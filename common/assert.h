// SPDX-License-Identifier: MPL-2.0
// Copyright © 2021 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <exception>

#ifdef NDEBUG
#define DEBUG_ASSERT(condition)
#else
#define DEBUG_ASSERT(condition) if (!(condition)) throw std::runtime_error("Cannot fulfill condition: " #condition)
#endif

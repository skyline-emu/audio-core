// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <condition_variable>
#include <mutex>

namespace Common {

class Event {
public:
    void Set() {
        std::scoped_lock lock{mutex};
        cv.notify_one();
        set = true;
    }

    void Wait() {
        std::unique_lock lk{mutex};
        cv.wait(lk, [&] { return set.load(); });
        set = false;
    }

    void Reset() {
        std::unique_lock lk{mutex};
        set = false;
    }
private:
    std::atomic_bool set{};
    std::condition_variable cv;
    std::mutex mutex;
};

enum class ThreadPriority : u32 {
    Low = 0,
    Normal = 1,
    High = 2,
    VeryHigh = 3,
    Critical = 4,
};

inline void SetCurrentThreadPriority(ThreadPriority new_priority) {}

inline void SetCurrentThreadName(const char* name) {}

} // namespace Common

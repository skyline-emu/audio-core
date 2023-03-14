// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <chrono>
#include <set>
#include <string>
#include <functional>
#include <memory>
#include <optional>
#include <thread>
#include <audio_core/common/polyfill_thread.h>
#include <audio_core/common/common_types.h>

namespace Core::Timing {

/// Implemented on skyline side
u64 GetClockTicks();
std::chrono::nanoseconds GetClockNs();

using TimedCallback = std::function<std::optional<std::chrono::nanoseconds>(
    std::uintptr_t user_data, s64 time, std::chrono::nanoseconds ns_late)>;

/// Contains the characteristics of a particular event.
struct EventType {
    void ThreadFunc() {
        auto expected_time{std::chrono::system_clock::now() + start_time};
        std::this_thread::sleep_until(expected_time);
        while (!thread->get_stop_token().stop_requested()) {
            callback(0, 0, {});
            expected_time += resched_time;
            std::this_thread::sleep_until(expected_time);
        }
    }

    explicit EventType(TimedCallback&& callback_, std::string&& name_)
        : callback{std::move(callback_)}, name{std::move(name_)} {}

    void Run(std::chrono::nanoseconds _start_time,
             std::chrono::nanoseconds _resched_time) {
        start_time = _start_time;
        resched_time = _resched_time;
        thread.emplace(&EventType::ThreadFunc, this);
    }

    void Stop() {
        if (thread.value().joinable()) {
            thread->request_stop();
            thread->join();
        }
    }

    /// The event's callback function.
    TimedCallback callback;
    std::optional<std::jthread> thread;
    std::chrono::nanoseconds start_time;
    std::chrono::nanoseconds resched_time;
    /// A pointer to the name of the event.
    const std::string name;
};

class CoreTiming {
private:
    std::set<std::shared_ptr<EventType>> scheduled_events;
public:
    void ScheduleLoopingEvent(std::chrono::nanoseconds start_time,
                              std::chrono::nanoseconds resched_time,
                              const std::shared_ptr<EventType>& event_type,
                              std::uintptr_t user_data = 0, bool absolute_time = false) {
        scheduled_events.emplace(event_type);
        event_type->Run(start_time, resched_time);
    }

    void UnscheduleEvent(const std::shared_ptr<EventType>& event_type, std::uintptr_t user_data,
                         bool wait = true) {
        event_type->Stop();
        scheduled_events.erase(event_type);
    }

    u64 GetClockTicks() {
        return Core::Timing::GetClockTicks();
    }

    std::chrono::nanoseconds GetGlobalTimeNs() const {
        return GetClockNs();
    }
};

inline std::shared_ptr<EventType> CreateEvent(std::string name, TimedCallback&& callback) {
    return std::make_shared<EventType>(std::move(callback), std::move(name));
}
}


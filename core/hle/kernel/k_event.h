// SPDX-License-Identifier: MPL-2.0
// Copyright © 2023 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <utility>

#pragma once

namespace Kernel {
class KEvent;

class KReadableEvent {
  public:
    KEvent *event;
};

class KEvent {
private:
    KReadableEvent readable_event;
    std::function<void()> signal_callback;
    std::function<void()> clear_callback;

public:
    KEvent(std::function<void()> &&signal_callback, std::function<void()> &&clear_callback) : readable_event{this}, signal_callback{std::move(signal_callback)}, clear_callback{std::move(clear_callback)} {};

    void Signal() {
        signal_callback();
    }

    void Clear() {
        clear_callback();
    }

    KReadableEvent& GetReadableEvent() {
        return readable_event;
    }
};

}

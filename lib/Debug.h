#pragma once

#include "Logger.h"

class Debug {
private:
    static bool _enabled;

public:
    static void enable();
    static void disable();
    static bool isEnabled();
};
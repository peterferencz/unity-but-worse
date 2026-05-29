#pragma once

#include <string>
#include <iostream>

namespace Logger {
    void Log(const std::string& message);
    void Warn(const std::string& message);
    void Error(const std::string& message);
    void Fatal(const std::string& message);
}

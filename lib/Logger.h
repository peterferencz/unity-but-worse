#pragma once

#include <string>
#include <iostream>

namespace Logger {
    void Log(std::string);
    void Warn(std::string);
    void Error(std::string);
    void Fatal(std::string);
}

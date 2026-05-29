#include "Logger.h"


namespace Logger {

    void Log(const std::string& msg){
        std::cout << "[Log] " << msg << std::endl;
    }
    
    void Warn(const std::string& msg){
        std::cout << "[Warn] " << msg << std::endl;
    }

    void Error(const std::string& msg){
        std::cout << "[ERROR] " << msg << std::endl;
    }

    void Fatal(const std::string& msg){
        std::cout << "[FATAL] " << msg << std::endl;
        exit(1);
    }
}
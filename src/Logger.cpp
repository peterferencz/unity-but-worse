#include "Logger.h"


namespace Logger {

    void Log(std::string msg){
        std::cout << "[Log] " << msg << std::endl;
    }
    
    void Warn(std::string msg){
        std::cout << "[Warn] " << msg << std::endl;
    }

    void Error(std::string msg){
        std::cout << "[ERROR] " << msg << std::endl;
    }

    void Fatal(std::string msg){
        std::cout << "[FATAL] " << msg << std::endl;
        exit(1);
    }
}
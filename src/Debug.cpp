#include "Debug.h"

bool Debug::_enabled = false;

void Debug::enable(){
    _enabled = true;
    Logger::Log("[Debug] Enabled");
}

void Debug::disable(){
    _enabled = false;
    Logger::Log("[Debug] Disabled");
}

bool Debug::isEnabled(){
    return _enabled;
}
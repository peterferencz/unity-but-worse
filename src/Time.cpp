#include "Time.h"


float Time::deltaTime = 0;
double Time::timeStamp = 0;

float Time::getDeltaTime(){
    return deltaTime;
}

double Time::getTimeStamp() {
    return timeStamp;
}
#pragma once

class Window;   //FWDecl

class Time {

friend class Window;

private:
    static float deltaTime;
    static double timeStamp;

public:
    static float getDeltaTime();
    static double getTimeStamp();

};
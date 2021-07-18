#pragma once
class Timer{
    public:
    unsigned long currentMicros;
    unsigned long previousMicros;
    bool IsDone(unsigned long interval);
    Timer(){
        previousMicros = 0;
    }
};
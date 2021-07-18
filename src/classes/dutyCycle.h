#pragma once
class DutyCycle{
    public:
    float HighPart;
    float LowPart();
    const float HighCeiling = 0.99;;
    const float HighFloor = 0.001;
    bool rising = true;
    void SetDutyCycle(int phasePot);
    int SetSweepMode(int ratePot);
    void DutyCycleSweep(int sweepMode, float rate);
    float SetSweepRate(int ratePot);
    int GetWobbleSteps(int ratePot);
    int GetWobbleSmooth(int ratePot);
    float KnobTone(int ratePot);

    // Constructor
    DutyCycle(){
        
    }

};
#pragma once
class DutyCycle{
    public:
    float HighPart;
    float LowPart();
    const float HighCeiling = 0.99;;
    const float HighFloor = 0.001;
    bool rising = true;
    void SetDutyCycle(int);
    int SetSweepMode(int);
    void DutyCycleSweep(int, float);
    float SetSweepRate(int);
    int GetWobbleSteps(int);
    int GetWobbleSmooth(int inputPot);
    float KnobTone(int);

    // Constructor
    DutyCycle(){
        
    }

};
#pragma once
class DutyCycle{
    public:
    float HighPart;
    float LowPart();
    const float HighCeiling = 0.99;;
    const float HighFloor = 0.001;
    void SetDutyCycle(int input);

    DutyCycle(){
        
    }

};
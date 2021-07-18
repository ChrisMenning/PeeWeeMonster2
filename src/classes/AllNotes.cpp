#include "AllNotes.h"
#include "math_utils.h"

Note AllNotes::GetNoteFromCV(int input)
{
    int variance = 3;
    // NOTE: This loop is too slow, even if it's more elegant.
    for (int i = 0; i < 37; i++)
    {
        if (i == 36) // If this is the highest note, just return the highest note.
        {
            return Notes[36];
        }
        else if (input > (Notes[i].AnalogValue - variance) && input < (Notes[i+1].AnalogValue + variance))
        {
            return Notes[i]; // Return this note within the variance range.
        } 
        else if (input > (Notes[i].AnalogValue + variance) && input < (Notes[i+1].AnalogValue - variance))
        {
            // If the input CV value is above this note's high variance and below the next note's low variance,
            // return the value between the expected frequencies.
            float newFreq = mapIntRangetoFloatRange(input, Notes[i].AnalogValue + variance, Notes[i+1].AnalogValue - variance, 
                                           Notes[i].Freq, Notes[i+1].Freq);

            Note newNote = {"Glide", input, newFreq};                              
            return newNote;
                                        
        }
    }

    // if (input > (Notes[0].AnalogValue - variance) && input < (Notes[0+1].AnalogValue + variance)) // C1
    // {
    //     return Notes[0].AnalogValue;
    // } else if (input > (Notes[0].AnalogValue + variance) && input < (Notes[0+1].AnalogValue - variance)) // glide
    // {
    //     return mapIntRangetoFloatRange(input, Notes[0].AnalogValue + variance, Notes[0+1].AnalogValue - variance, Notes[0].Freq, Notes[0+1].Freq);
    // }
    // else if (input > (Notes[1].AnalogValue - variance) && input < (Notes[1+1].AnalogValue + variance)) // C#1
    // {
    //     return Notes[1].AnalogValue;
    // } else if (input > (Notes[1].AnalogValue + variance) && input < (Notes[1+1].AnalogValue - variance)) // glide
    // {
    //     return mapIntRangetoFloatRange(input, Notes[1].AnalogValue + variance, Notes[1+1].AnalogValue - variance, Notes[1].Freq, Notes[1+1].Freq);
    // }
    // else if (input > (Notes[2].AnalogValue - variance) && input < (Notes[2+1].AnalogValue + variance))
    // {
    //     return Notes[2].AnalogValue;
    // } else if (input > (Notes[2].AnalogValue + variance) && input < (Notes[2+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[2].AnalogValue + variance, Notes[2+1].AnalogValue - variance, Notes[2].Freq, Notes[2+1].Freq);
    // }
    // else if (input > (Notes[3].AnalogValue - variance) && input < (Notes[3+1].AnalogValue + variance))
    // {
    //     return Notes[3].AnalogValue;
    // } else if (input > (Notes[3].AnalogValue + variance) && input < (Notes[3+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[3].AnalogValue + variance, Notes[3+1].AnalogValue - variance, Notes[3].Freq, Notes[3+1].Freq);
    // }
    // else if (input > (Notes[4].AnalogValue - variance) && input < (Notes[4+1].AnalogValue + variance))
    // {
    //     return Notes[4].AnalogValue;
    // } else if (input > (Notes[4].AnalogValue + variance) && input < (Notes[4+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[4].AnalogValue + variance, Notes[4+1].AnalogValue - variance, Notes[4].Freq, Notes[4+1].Freq);
    // }
    // else if (input > (Notes[5].AnalogValue - variance) && input < (Notes[5+1].AnalogValue + variance))
    // {
    //     return Notes[5].AnalogValue;
    // } else if (input > (Notes[5].AnalogValue + variance) && input < (Notes[5+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[5].AnalogValue + variance, Notes[5+1].AnalogValue - variance, Notes[5].Freq, Notes[5+1].Freq);
    // }
    // else if (input > (Notes[6].AnalogValue - variance) && input < (Notes[6+1].AnalogValue + variance))
    // {
    //     return Notes[6].AnalogValue;
    // } else if (input > (Notes[6].AnalogValue + variance) && input < (Notes[6+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[6].AnalogValue + variance, Notes[6+1].AnalogValue - variance, Notes[6].Freq, Notes[6+1].Freq);
    // }
    // else if (input > (Notes[7].AnalogValue - variance) && input < (Notes[7+1].AnalogValue + variance))
    // {
    //     return Notes[7].AnalogValue;
    // } else if (input > (Notes[7].AnalogValue + variance) && input < (Notes[7+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[7].AnalogValue + variance, Notes[7+1].AnalogValue - variance, Notes[7].Freq, Notes[7+1].Freq);
    // }
    // else if (input > (Notes[8].AnalogValue - variance) && input < (Notes[8+1].AnalogValue + variance))
    // {
    //     return Notes[8].AnalogValue;
    // } else if (input > (Notes[8].AnalogValue + variance) && input < (Notes[8+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[8].AnalogValue + variance, Notes[8+1].AnalogValue - variance, Notes[8].Freq, Notes[8+1].Freq);
    // }
    // else if (input > (Notes[9].AnalogValue - variance) && input < (Notes[9+1].AnalogValue + variance))
    // {
    //     return Notes[9].AnalogValue;
    // } else if (input > (Notes[9].AnalogValue + variance) && input < (Notes[9+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[9].AnalogValue + variance, Notes[9+1].AnalogValue - variance, Notes[9].Freq, Notes[9+1].Freq);
    // }
    // else if (input > (Notes[10].AnalogValue - variance) && input < (Notes[10+1].AnalogValue + variance))
    // {
    //     return Notes[10].AnalogValue;
    // } else if (input > (Notes[10].AnalogValue + variance) && input < (Notes[10+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[10].AnalogValue + variance, Notes[10+1].AnalogValue - variance, Notes[10].Freq, Notes[10+1].Freq);
    // }
    // else if (input > (Notes[11].AnalogValue - variance) && input < (Notes[11+1].AnalogValue + variance))
    // {
    //     return Notes[11].AnalogValue;
    // } else if (input > (Notes[11].AnalogValue + variance) && input < (Notes[11+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[11].AnalogValue + variance, Notes[11+1].AnalogValue - variance, Notes[11].Freq, Notes[11+1].Freq);
    // }
    // else if (input > (Notes[12].AnalogValue - variance) && input < (Notes[12+1].AnalogValue + variance))
    // {
    //     return Notes[12].AnalogValue;
    // } else if (input > (Notes[12].AnalogValue + variance) && input < (Notes[12+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[12].AnalogValue + variance, Notes[12+1].AnalogValue - variance, Notes[12].Freq, Notes[12+1].Freq);
    // }
    // else if (input > (Notes[13].AnalogValue - variance) && input < (Notes[13+1].AnalogValue + variance))
    // {
    //     return Notes[13].AnalogValue;
    // } else if (input > (Notes[13].AnalogValue + variance) && input < (Notes[13+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[13].AnalogValue + variance, Notes[13+1].AnalogValue - variance, Notes[13].Freq, Notes[13+1].Freq);
    // }
    // else if (input > (Notes[14].AnalogValue - variance) && input < (Notes[14+1].AnalogValue + variance))
    // {
    //     return Notes[14].AnalogValue;
    // } else if (input > (Notes[14].AnalogValue + variance) && input < (Notes[14+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[14].AnalogValue + variance, Notes[14+1].AnalogValue - variance, Notes[14].Freq, Notes[14+1].Freq);
    // }
    // else if (input > (Notes[15].AnalogValue - variance) && input < (Notes[15+1].AnalogValue + variance))
    // {
    //     return Notes[15].AnalogValue;
    // } else if (input > (Notes[15].AnalogValue + variance) && input < (Notes[15+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[15].AnalogValue + variance, Notes[15+1].AnalogValue - variance, Notes[15].Freq, Notes[15+1].Freq);
    // }
    // else if (input > (Notes[16].AnalogValue - variance) && input < (Notes[16+1].AnalogValue + variance))
    // {
    //     return Notes[16].AnalogValue;
    // } else if (input > (Notes[16].AnalogValue + variance) && input < (Notes[16+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[16].AnalogValue + variance, Notes[16+1].AnalogValue - variance, Notes[16].Freq, Notes[16+1].Freq);
    // }
    // else if (input > (Notes[17].AnalogValue - variance) && input < (Notes[17+1].AnalogValue + variance))
    // {
    //     return Notes[17].AnalogValue;
    // } else if (input > (Notes[17].AnalogValue + variance) && input < (Notes[17+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[17].AnalogValue + variance, Notes[17+1].AnalogValue - variance, Notes[17].Freq, Notes[17+1].Freq);
    // }
    // else if (input > (Notes[18].AnalogValue - variance) && input < (Notes[18+1].AnalogValue + variance))
    // {
    //     return Notes[18].AnalogValue;
    // } else if (input > (Notes[18].AnalogValue + variance) && input < (Notes[18+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[18].AnalogValue + variance, Notes[18+1].AnalogValue - variance, Notes[18].Freq, Notes[2+1].Freq);
    // }
    // else if (input > (Notes[19].AnalogValue - variance) && input < (Notes[19+1].AnalogValue + variance))
    // {
    //     return Notes[19].AnalogValue;
    // } else if (input > (Notes[19].AnalogValue + variance) && input < (Notes[19+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[19].AnalogValue + variance, Notes[19+1].AnalogValue - variance, Notes[19].Freq, Notes[19+1].Freq);
    // }
    // else if (input > (Notes[20].AnalogValue - variance) && input < (Notes[20+1].AnalogValue + variance))
    // {
    //     return Notes[20].AnalogValue;
    // } else if (input > (Notes[20].AnalogValue + variance) && input < (Notes[20+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[20].AnalogValue + variance, Notes[20+1].AnalogValue - variance, Notes[20].Freq, Notes[20+1].Freq);
    // }
    // else if (input > (Notes[21].AnalogValue - variance) && input < (Notes[21+1].AnalogValue + variance))
    // {
    //     return Notes[21].AnalogValue;
    // } else if (input > (Notes[21].AnalogValue + variance) && input < (Notes[21+1].AnalogValue - variance))
    // {
    //     return mapIntRangetoFloatRange(input, Notes[21].AnalogValue + variance, Notes[21+1].AnalogValue - variance, Notes[21].Freq, Notes[21+1].Freq);
    // }
    Note nullNote = {"null", 0, 0};
    return nullNote;
}
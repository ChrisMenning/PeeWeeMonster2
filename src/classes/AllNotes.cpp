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
    Note nullNote = {"null", 0, 0};
    return nullNote;
}
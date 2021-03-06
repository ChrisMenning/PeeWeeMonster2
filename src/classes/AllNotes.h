#pragma once
#include "note.h"
class AllNotes{
    public:
        // Notes adjusted again 7/18/21
        Note Notes[37] = {Note("C1", 208, 26), 
                      Note("C1Sharp", 226, 29), 
                      Note("D1", 244, 30),
                      Note("D1Sharp", 261, 31.5),
                      Note("E1", 278, 33),
                      Note("F1", 296, 35),
                      Note("F1Sharp", 313, 38),
                      Note("G1", 330, 40),
                      Note("G1Sharp", 348, 42),
                      Note("A1", 366, 48),
                      Note("A1Sharp", 387, 53.8),
                      Note("B1", 401, 54),
                      Note("C2", 419, 56),
                      Note("C2Sharp", 436, 60),
                      Note("D2", 455, 65),
                      Note("D2Sharp", 473, 70),
                      Note("E2", 491, 75),
                      Note("F2", 509, 80),
                      Note("F2Sharp", 526, 85),
                      Note("G2", 543, 90),
                      Note("G2Sharp", 561, 100),
                      Note("A2", 579, 110),
                      Note("A2Sharp", 596, 120),
                      Note("B2", 614, 130),
                      Note("C3", 632, 140.2),
                      Note("C3Sharp", 649, 155),
                      Note("D3", 667, 171),
                      Note("D3Sharp", 684, 184),
                      Note("E3", 702, 196.2),
                      Note("F3", 720, 210.25),
                      Note("F3Sharp", 737, 242.1),
                      Note("G3", 755, 260),
                      Note("G3Sharp", 772, 300),
                      Note("A3", 790, 320),
                      Note("A3Sharp", 807, 380),
                      Note("B3", 825, 450),
                      Note("C4", 843, 500),
                     };

        // Note Notes[37] = {Note("C1", 208, 33.8), 
        //               Note("C1Sharp", 226, 36), 
        //               Note("D1", 244, 38),
        //               Note("D1Sharp", 261, 40.5),
        //               Note("E1", 278, 43.1),
        //               Note("F1", 296, 45.9),
        //               Note("F1Sharp", 313, 48.7),
        //               Note("G1", 330, 51.7),
        //               Note("G1Sharp", 348, 54.8),
        //               Note("A1", 366, 58.4),
        //               Note("A1Sharp", 387, 62),
        //               Note("B1", 401, 65.9),
        //               Note("C2", 419, 70.1),
        //               Note("C2Sharp", 436, 74.7),
        //               Note("D2", 455, 79.2),
        //               Note("D2Sharp", 473, 84.3),
        //               Note("E2", 491, 90),
        //               Note("F2", 509, 95.9),
        //               Note("F2Sharp", 526, 102),
        //               Note("G2", 543, 98),
        //               Note("G2Sharp", 561, 108.8),
        //               Note("A2", 579, 123.8),
        //               Note("A2Sharp", 596, 131.8),
        //               Note("B2", 614, 140.2),
        //               Note("C3", 632, 149.8),
        //               Note("C3Sharp", 649, 160),
        //               Note("D3", 667, 171),
        //               Note("D3Sharp", 684, 184),
        //               Note("E3", 702, 196.2),
        //               Note("F3", 720, 210.25),
        //               Note("F3Sharp", 737, 225.5),
        //               Note("G3", 755, 242.1),
        //               Note("G3Sharp", 772, 260),
        //               Note("A3", 790, 280),
        //               Note("A3Sharp", 807, 301),
        //               Note("B3", 825, 323.77),
        //               Note("C4", 843, 350.3),
        //              };
    // Notes with scientifically correct frequencies.
    // Note Notes[37] = {Note("C1", 208, 32.7), 
    //                   Note("C1Sharp", 226, 34.65), 
    //                   Note("D1", 244, 36.71),
    //                   Note("D1Sharp", 261, 38.89),
    //                   Note("E1", 278, 41.2),
    //                   Note("F1", 296, 43.65),
    //                   Note("F1Sharp", 313, 46.25),
    //                   Note("G1", 330, 49),
    //                   Note("G1Sharp", 348, 51.91),
    //                   Note("A1", 366, 55),
    //                   Note("A1Sharp", 387, 58.27),
    //                   Note("B1", 401, 61.74),
    //                   Note("C2", 419, 65.41),
    //                   Note("C2Sharp", 436, 69.3),
    //                   Note("D2", 455, 73.42),
    //                   Note("D2Sharp", 473, 77.78),
    //                   Note("E2", 491, 82.41),
    //                   Note("F2", 509, 87.31),
    //                   Note("F2Sharp", 526, 92.5),
    //                   Note("G2", 543, 98),
    //                   Note("G2Sharp", 561, 103.83),
    //                   Note("A2", 579, 110),
    //                   Note("A2Sharp", 596, 116.54),
    //                   Note("B2", 614, 123.47),
    //                   Note("C3", 632, 130.81),
    //                   Note("C3Sharp", 649, 138.59),
    //                   Note("D3", 667, 146.83),
    //                   Note("D3Sharp", 684, 155.56),
    //                   Note("E3", 702, 164.81),
    //                   Note("F3", 720, 174.61),
    //                   Note("F3Sharp", 737, 185),
    //                   Note("G3", 755, 196),
    //                   Note("G3Sharp", 772, 207.65),
    //                   Note("A3", 790, 220),
    //                   Note("A3Sharp", 807, 223.08),
    //                   Note("B3", 825, 246.94),
    //                   Note("C4", 843, 261.63),
    //                   };
                      
    Note GetNoteFromCV(int cvValue);
};
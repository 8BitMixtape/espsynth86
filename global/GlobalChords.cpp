#include "Arduino.h"
#include "GlobalChords.h"

const uint8_t CHORDS[][3] = 
{ 
  
  {0, 4, 7},    // 0: "major"  
  {4, 7, 12},   // 1:  
  {7, 12, 16},  // 2:
  
  {0, 4, 8},    // 3: "augmented"
  {4, 8, 12},   // 4:  
  {8,12,16},    // 5:
  
  {0, 4, 9},    // 6: "6th"  
  {4, 9, 12},   // 7:  
  {9, 12, 16},  // 8:  
  
  {0, 4, 10},   // 9: "7th" 
  {4, 10, 12},  // 10:  
  {10, 12, 16}, // 11: 
  
  {0, 5, 7},    // 12: "sus4"
  {5, 7, 12},   // 13: 
  
  {0, 5, 8},    // 14: "sus4 aug5"
  {5, 8, 12},   // 15: 
  
  {0, 5, 9},    // 16: "sus4 6"
  {5, 9, 12},   // 17:  
  {9, 12, 17},  // 18: 
  
  {0, 3, 9},    // 19: "m6th"
  {3, 9, 12},   // 20: 
  {9, 12, 15},  // 21:
  
  {0, 3, 8},    // 22: "mAug 5"
  {3, 8, 12},   // 23: 
  {8, 12, 15},  // 24: 
  
  {0, 3, 7},    // 25: "minor"
  {3, 7, 12},   // 26:
  {7, 12, 15},  // 27: 
  
  {0, 3, 6},    // 28: "diminished"
  {3, 6, 12},   // 29: 
  {6, 12, 15},  // 30:
  
  {0, 7, 12}    // 31: 5ths  

};

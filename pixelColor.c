//
//  pixelColor.c
//  comp1917
//
//  Created by Benjamin McGrath on 22/04/2016.
//  Copyright © 2016 Benjamin McGrath. All rights reserved.
//

#include <stdio.h>
#include "pixelColor.h"

typedef struct _colourMap {
    int steps;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} colourMap;

colourMap colourTable[] = {
    {  0,   0,   0,   0},
    { 30, 255,   0,   0},
    { 70,   0, 255,   0},
    {110,   0,   0, 255},
    {150, 255,   0, 255},
    {255, 255, 255, 255},
    {256,   0,   0,   0}
};

#define NUM_COL (sizeof(colourTable)/sizeof(colourMap))


unsigned char stepsToRed (int steps){
    
    int colourIndex = 0;
    while (colourIndex<NUM_COL-1) {
        if (steps <= colourTable[colourIndex+1].steps) {
            double s1= colourTable[colourIndex  ].steps;
            double s2= colourTable[colourIndex+1].steps;
            
            double c1= colourTable[colourIndex  ].red;
            double c2= colourTable[colourIndex+1].red;
            
            return (unsigned char) (c1 + (steps -s1)/(s2-s1)*(c2-c1));


        }
        
        colourIndex++;
    }
    
    return 0;
//    return steps==256 ? 0 : (255-steps);
}
unsigned char stepsToBlue (int steps){
    
    int colourIndex = 0;
    while (colourIndex<NUM_COL-1) {
        if (steps <= colourTable[colourIndex+1].steps) {
            double s1= colourTable[colourIndex  ].steps;
            double s2= colourTable[colourIndex+1].steps;
            
            double c1= colourTable[colourIndex  ].blue;
            double c2= colourTable[colourIndex+1].blue;
            
            return (unsigned char) (c1 + (steps -s1)/(s2-s1)*(c2-c1));
            
            
        }
        
        colourIndex++;
    }
    
    return 0;

    
//    return steps==256 ? 0 : steps;
}
unsigned char stepsToGreen (int steps){
    
    
    int colourIndex = 0;
    while (colourIndex<NUM_COL-1) {
        if (steps <= colourTable[colourIndex+1].steps) {
            double s1= colourTable[colourIndex  ].steps;
            double s2= colourTable[colourIndex+1].steps;
            
            double c1= colourTable[colourIndex  ].green;
            double c2= colourTable[colourIndex+1].green;
            
            return (unsigned char) (c1 + (steps -s1)/(s2-s1)*(c2-c1));
            
            
        }
        
        colourIndex++;
    }
    
    return 0;

    
    
//    return steps==256 ? 0 : (100-0.5*steps);
}

//
//  main.c
//  Leap Year
//
//  Created by Md Mashiur Rahman on 8/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_GREG_CAL 1582
#define TRUE 1
#define FALSE 0

int isLeapYear (int year);

int main(int argc, char * argv[]) {
    int year;
    printf("Please enter a year after 1582: \n");
    scanf("%d", &year);
    
    assert (year>=START_GREG_CAL);
    
    int leap;
    leap = isLeapYear(year);
    
    if(leap == TRUE) {
        printf("%d is a leap year!\n", year);
    } else {
        printf("%d is not a leap year!\n", year);
    }
    
    
    return EXIT_SUCCESS;
}

int isLeapYear(int year) {
    int isItALeapYear;
    if (year%400 == 0) {
        isItALeapYear = TRUE;
    } else if(year%100 == 0) {
        isItALeapYear = FALSE;
    } else if (year%4 == 0){
        isItALeapYear = TRUE;
    } else {
        isItALeapYear = FALSE;
    }
    return isItALeapYear;
}
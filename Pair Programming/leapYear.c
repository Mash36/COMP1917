//  main.c
//  Leap Year
//
//  Created by Md Mashiur Rahman on 4/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//  Try using the input: 1581

#include <stdio.h>
#include <assert.h>
#define START_GREG_CAL 1582

int main(int argc, const char * argv[]) {
    int year;
    printf("Enter a year to check leap year: \n");
    scanf("%d", &year);
    
    assert (year>=START_GREG_CAL);
    
    if (year%400 == 0)
        printf("%d is a leap year.\n", year);
    else if(year%100 == 0)
        printf("%d is not a leap year.\n", year);
    else if (year%4 == 0)
        printf("%d is a leap year.\n",year);
    else
        printf("%d is not a leap year.\n",year);
    return 0;
}
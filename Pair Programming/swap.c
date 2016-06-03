//
//  main.c
//  swap
//
//  Created by Md Mashiur Rahman on 22/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>

void swap(int *first, int *second);

int main(int argc, const char * argv[]) {
    
    int first, second;
    
    printf("Enter the value of x and y\n");
    scanf("%d %d",&first,&second);
    
    printf("Before Swapping\n x = %d\n y = %d\n", first,second);
    
    swap(&first, &second);
    
    printf("After Swapping\nx = %d\ny = %d\n", first, second);
    
    return 0;
}

void swap(int *first, int *second) {
    int temp;
    
    temp = *second;
    *second   = *first;
    *first   = temp;
}
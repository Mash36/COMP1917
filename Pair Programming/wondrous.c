//
//  main.c
//  C Wonderous Function
//
//  Created by Md Mashiur Rahman on 22/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>

int printWondrous (int start);
int main(int argc, const char * argv[]) {
    //int n;
    //scanf ("%d", &n);
    printWondrous(3);
    return 0;
}

int printWondrous (int start){
    int n = start;
    int counter = 1;
    printf("%d\n",n);
    while (n > 1) {
        if (n%2 == 0) {
            n = n/2;
        } else {
                n = n * 3 + 1;
        } counter ++;
        printf("%d\n",n);
    }
    return (counter);
}
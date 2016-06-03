//
//  main.c
//  LibyaFlag
//
//  Created by Md Mashiur Rahman on 19/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#define WIDTH 15
#define HEIGHT 5
#define IRISH_WIDTH (WIDTH/3)

void showPixel (int col);
int main(int argc, const char * argv[]) {
    int col = 0;
    int row = 0;
    
    while (row < HEIGHT) {
        col = 0;
        while (col < WIDTH) {
            showPixel (col);
            col++;
        } printf("\n");
        row++;
    }
    return 0;
}

    void showPixel (int col) {
    char pixel;
        if (col < IRISH_WIDTH) {
            pixel = 'g';
        } else if (col < 2*(IRISH_WIDTH)) {
            pixel = 'w';
        }  else {
                pixel = 'o';
            }
    printf("%c", pixel);
    }
    

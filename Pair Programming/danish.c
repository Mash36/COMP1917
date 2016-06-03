//
//  main.c
//  Show Danish
//
//  Created by Md Mashiur Rahman on 19/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#define WIDTH 13
#define HEIGHT 22

void showDanish (void);
void printRow (void);
int main(int argc, const char * argv[]) {

    showDanish();
    return 0;
}

void showDanish(void) {
    printRow ();
    printf("\n");
    
    printRow ();
}

void printRow (void){
    int col = 0;
    int row = 0;
    
    while (row < HEIGHT) {
        col = 0;
        while (col < WIDTH) {
            col++;
        } printf("***** ******\n");
        row++;
    }

}
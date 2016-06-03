//
//  main.c
//  Freq Analysis
//
//  Created by Md Mashiur Rahman on 5/04/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void frequency(FILE* file);

int main(int argc, char* argv[]) {
    FILE *file;
     file = fopen ("/Users/Tamim/Desktop/COMP1917/Hello/Mod4/Freq Analysis/Freq Analysis/thing.txt","r");
     if (file == NULL) {
         printf ("File open failed\n");
         return 1;
     }
    frequency(file);

    fclose (file);
    return EXIT_SUCCESS;
}

void frequency(FILE* file)  {
    char character;
    int index, total = 0;
    int freq[26] = {0};
    
    character = getc(file);
    while(character != EOF){
        if (character >= 'A' &&
            character <= 'Z') {
            character += 'a' - 'A';
        }
        
        if (character >= 'a' &&
            character <= 'z') {
            
            index = character - 'a';
            freq[index] ++;
            total++;
        }
        character = getc(file);
    }
    
    double percent;
    index = 0;
    while (index < 26){
        percent = ((double)freq[index]/(double)total)*100;
        printf("%c == %d or %.3lf%c \n", index+'a', freq[index], percent, '%');
        index ++;
    }
}



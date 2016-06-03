#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define upperStart 65
#define lowerStart 97

int checkConsoleArgs(int);
string getCipherChars(string, int);
char encryptChar(int, int);

int main (int argc, string argv[]) {
    // see if cipher was passed as argument during execute
    checkConsoleArgs(argc);
    
    // convert string arg to integer
    int cipherNum = atoi(argv[1]);
    
    printf("What would you like to encrypt?\n");
    string decodedString = GetString();
    
    // pass the string input and the cipher number to encrypt
    getCipherChars(decodedString, cipherNum);
    
    return 0;
}

int checkConsoleArgs (int consoleArgsCount) {
    // this program was executed juuuuust right!
    if(consoleArgsCount == 2) {
        return 0;
        
        // this program was executed with too few console arguments.
    } else if(consoleArgsCount < 2) {
        printf("This program requires a cipher as a console argument. Please try again.\n");
        return 1;
        
        // this program was executed with too many console arguments.
    } else {
        printf("Please enter only one cipher for the encryption.\n");
        return 1;
    }
}

string getCipherChars(string decodedString, int cipherNum){
    int decodedStringLen = strlen(decodedString);
    int newChar;
    for(int i = 0; i < decodedStringLen; i++) {
        newChar = decodedString[i];
        
        // encrypt chars if it's alphabetical
        if(isalpha(newChar)) {
            encryptChar(newChar, cipherNum);
            
            // print other chars as is.
        } else {
            printf("%c", newChar);
        }
    }
    
    printf("\n");
    return 0;
}

char encryptChar(newChar, cipherNum) {
    char encryptedChar;
    int indexStart;
    
    // if uppercase char, set the index to start at uppercase ASCII start
    if isupper(newChar) {
        indexStart = upperStart;
        
        // if lowercase char, set the index to start at lowercase ASCII start
    } else {
        indexStart = lowerStart;
    }
    
    // find alpha index of cipher
    cipherNum = ((newChar - indexStart) + cipherNum) % 26;
    
    // convert back to ASCII index of cipher
    encryptedChar = indexStart + cipherNum;
    
    printf("%c", encryptedChar);
    
    return 0;
}
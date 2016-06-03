//
//  encode.c
//  W3L1
//  Created by Md Mashiur Rahman on 9/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

char encode(char plainText);
int isLowercase (char text);
void testEncode(void);

int main(int argc, const char * argv[]) {
    char plainText;
    char encodedText;
    testEncode();
    
    printf("Enter a plain text charcter: ");
    scanf("%c", &plainText);
    encodedText = encode (plainText);
    
    
    printf("The encoded text is %c\n", encodedText);
    
    return 0;
}

char encode(char plainText) {
    char encodedText;
    if (plainText >= 'a' && plainText < 'z') {
        encodedText = plainText +1;
    } else if (plainText == 'z'){
        encodedText = 'a';
    } else {
        encodedText = plainText;
    }
    return encodedText;
}

int isLowercase (char text){
    char plainText;
    int result = (plainText >= 'a' && plainText <= 'z');
    return result;
}

void testEncode(void) {
    assert(encode('a') == ('b'));
    assert(encode('z') == ('a'));
    assert(encode('4') == ('4'));
    assert(encode('A') == ('A'));
    assert(encode('?') == ('?'));
}
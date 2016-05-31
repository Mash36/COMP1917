//
//  main.c
//  rot13
//
//  Created by Md Mashiur Rahman on 22/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#define ROT_13 13

char encode (char letter);
void test();

int main(int argc, const char * argv[]) {
    
    test();
    printf("All test passed. \\m/\n");
    return 0;
}

char encode (char letter){
    char newLetter = letter;
    if ((letter < 'n' && letter >= 'a') || (letter < 'N' && letter >= 'A')){
        newLetter += ROT_13;
    } else if (((letter >= 'n') && (letter <= 'z')) || ((letter >= 'N') && (letter <= 'Z'))){
        newLetter -= ROT_13;
    }

    return (newLetter);
}

void test(){
    assert (encode ('a')==('n'));
    assert (encode ('s')==('f'));
    assert (encode ('m')==('z'));
    assert (encode ('?')==('?'));
    assert (encode ('A')==('N'));
    assert (encode ('S')==('F'));
    assert (encode ('Z')==('M'));

}
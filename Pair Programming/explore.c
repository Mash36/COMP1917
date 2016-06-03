//
//  main.c
//  memory
//
//  Created by Md Mashiur Rahman & Isabelle Dou on 15/03/16.
//

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);
void showSize ();

int main(int argc, const char * argv[]) {
    
    int x;
    int y;
    long total;
    int *address;
    address = &x;
    printf("address of x is %p\n", address);
    printf("The value stored at %p is %u\n", address, *address);
    
    
    x = 40;
    y = 2;
    showSize();
    total = add (x, y);
    
    printf("the sum of %d and %d is %ld\n", x, y, total);
    
    unsigned long ul       = 0;
    unsigned int ui        = 0;
    unsigned long long ull = 0;
    unsigned short us      = 0;
    
    signed long sl       = 0;
    signed int si        = 0;
    signed long long sll = 0;
    signed short ss      = 0;
    
    long l       = 0;
    int i        = 0;
    long long ll = 0;
    short s      = 0;

    float f = 1e-7;
    double d = 1e-7;
    
    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program
    
    double grandTotal;
    grandTotal =  ul + ui + ull + us +
    sl + si + sll + ss +
    l +  i +  ll +  s +
    f + d;
    
    printf ("all these things added together make %f\n", grandTotal);
    
    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;
    
    return answer;
}

void showSize (){
    int p;
    float q;
    char r;
    double t;
    printf("Size of int: %lu bytes\n",sizeof(p));
    printf("Size of float: %lu bytes\n",sizeof(q));
    printf("Size of char: %lu bytes\n",sizeof(r));
    printf("Size of double: %lu byte\n",sizeof(t));
}



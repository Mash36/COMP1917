//
//  main.c
//  Sort 3 Numbers in ascending order
//
//  Created by Md Mashiur Rahman on 16/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

    int a, b, c, second, third, first;
    
    scanf("%d %d %d", &a, &b, &c);
    
      if (a>b) {
        second=a;
        first=b;
    } else {
        second=b;
        first=a;
    } if (second>c) {
        third=second;
        
      if(first>c) {
        second=first;
        first=c;
    } else {
        second=c;
        }
    } else
        third=c;
    
    printf("%d\n", first);
    printf("%d\n", second);
    printf("%d\n", third);

    return EXIT_SUCCESS;
}

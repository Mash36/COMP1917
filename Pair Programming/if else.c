//
//  This is a demo program.
//  Mash shows how to do IF Statement.
//  Created by Md Mashiur Rahman on 7/03/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int A, B;
    
    printf("Enter two integers to check\n");
    scanf("%d %d",&A,&B);
    
    if(A==B) {
        printf("Result: %d = %d\n",A,B);
    } else if(A>B) {
            printf("Result: %d > %d\n",A,B);
    } else {
            printf("Result: %d < %d\n",A,B);
    }
    return 0;
}

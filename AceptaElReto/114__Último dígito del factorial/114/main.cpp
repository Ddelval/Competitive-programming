// AceptaElReto 114:  Último dígito del factorial
//
//  main.cpp
//  114
//
//  Created by David del Val on 10/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int cases;
    int num;
    int i;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        scanf("%d",&num);
        if(num>4){
            printf("0\n");
            continue;
        }
        
        switch (num) {
            case 0: printf("1\n"); break;
            case 1: printf("1\n"); break;
            case 2: printf("2\n"); break;
            case 3: printf("6\n"); break;
            case 4: printf("4\n"); break;
        }
        
        
    }
    return 0;
}

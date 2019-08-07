// AceptaElReto 117:  La fiesta aburrida
//
//  main.cpp
//  117
//
//  Created by David del Val on 01/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int number;
    char name [100];
    char c;
    scanf("%d",&number);
    scanf("%c",&c);
    for(int i=0;i<number;i++){
        scanf("%s",name);
        scanf("%s",name);
        printf("Hola, %s.\n",name);
    }
    return 0;
}


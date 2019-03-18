//
//  main.cpp
//  150
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char c;
    int num;
    scanf("%d %c",&num,&c);
    while(num||c!='0'){
        for(int j=0;j<num;j++){
            for(int i=0;i<num-j-1;i++){
                putchar(' ');
            }
            for(int i=0;i<num+2*j;i++){
                putchar(c);
            }
            putchar('\n');
        }
        for(int j=1;j<num;j++){
            for(int i=0;i<=j-1;i++){
                putchar(' ');
            }
            for(int i=0;i<=3*num-3-2*j;i++){
                putchar(c);
            }
            putchar('\n');
        }
        scanf("%d %c",&num,&c);
    }
    return 0;
}

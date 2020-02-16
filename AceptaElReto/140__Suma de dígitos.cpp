// AceptaElReto 140:  Suma de dígitos
//
//  main.cpp
//  140
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    char s[10];
    int sum;
    int i;
    scanf("%s",s);
    while(s[0]!='-'){
        sum=0;
        for(i=0;s[i+1];i++){
            printf("%c + ",s[i]);
            sum+=s[i]-'0';
        }
        sum+=s[i]-'0';
        printf("%c = %d\n",s[i],sum);
        scanf("%s",s);
    }
    return 0;
}

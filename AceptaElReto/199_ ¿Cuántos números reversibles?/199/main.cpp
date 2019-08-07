// AceptaElReto 199:  ¿Cuántos números reversibles?
//
//  main.cpp
//  199
//
//  Created by David del Val on 04/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int cif;
    int a;
    scanf("%d",&cif);
    while(cif){
        if(!(cif%2)){
            a = cif/2-1;
            printf("%lld\n",(long long)(pow(3,a)*pow(10,a)*20));
        }
        else{
            long long a=(cif-1)/2;
            if(!(a%2)){
                printf("0\n");
            }
            else{
                
                a=(a-1)/2;
                printf("%lld\n",(long long)(pow(100,a)*20*pow(5,(a+1))));
            }
        }
       scanf("%d",&cif);
    }
    return 0;
}

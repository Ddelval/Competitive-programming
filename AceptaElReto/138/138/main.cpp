//
//  main.cpp
//  138
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
using namespace std;
int const powers[13]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625,1220703125};
int main() {
    int num;
    int aux;
    int count;
    int lim;
    scanf("%d",&lim);
    for(int j=0;j<lim;j++){
        scanf("%d",&num);
        count=0;
        for(int i=0;i<13;i++){
            aux=num/powers[i];
            if(!aux){
                break;
            }
            else{
                count+=aux;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}


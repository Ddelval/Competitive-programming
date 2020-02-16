// AceptaElReto 202:  K bits a uno
//
//  main.cpp
//  202
//
//  Created by David del Val on 05/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//


//using namespace std;
#include <stdio.h>
long mat[1001][1001];
long res;
long combinations(int num,int ones){
    
    if(ones==num||ones ==0){
        return 1;
    }
    if(ones<0||num<ones){
        return 0;
    }
    if(num==1){
        return 0;
    }
    if(ones==2){
        /*return num*(num-1)/2;*/
        if(mat[num][ones]){
            return mat[num][ones];
            
        }
        return num*(num-1)/2;
        
    }
    if(ones==1){
        return num;
    }
        if(mat[num][ones]){
            return mat[num][ones];
            
       }
    
        res=(combinations(num-1,ones-1)+(combinations(num-1,ones)))%1000000007;
        mat[num][ones]=res;
        return res;
     
    
}
int main() {
    int num,ones;
    scanf("%d %d",&num,&ones);
    while(num||ones){
        
        printf("%ld\n",combinations(num, ones)%1000000007);
        scanf("%d %d",&num,&ones);
    }
    return 0;
}

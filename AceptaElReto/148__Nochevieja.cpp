// AceptaElReto 148:  Nochevieja
//
//  main.cpp
//  148
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
using namespace std;
const int has[24]={1380,1320,1260,1200,1140,1080,1020,960,900,840,780,720,660,600,540,480,420,360,300,240,180,120,60,0};
int main() {
    int h,m;
    scanf("%d:%d",&h,&m);
    while(h||m){
        printf("%d\n",has[h]+60-m);
        scanf("%d:%d",&h,&m);
    }
    return 0;
}

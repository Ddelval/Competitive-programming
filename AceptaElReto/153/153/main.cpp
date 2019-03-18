//
//  main.cpp
//  153
//
//  Created by David del Val on 27/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int cases;
    int h,m;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        scanf("%d:%d",&h,&m);
        m=(60-m);
        if(m==60){
            m=0;
        }
        h=(12-h);
        if(m){
            h--;
        }
        if(h<=0){
            h+=12;
        }
        printf("%.2d:%.2d\n",h,m);
    }
    return 0;
}

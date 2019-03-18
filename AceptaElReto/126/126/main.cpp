//
//  main.cpp
//  126
//
//  Created by David del Val on 02/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
using namespace std;
int main() {
    int num,fact;
    scanf("%d %d",&num,&fact);
go:while(num>-1||fact>-1){
        if(num==1||num<=fact){
            printf("YES\n");
            scanf("%d %d",&num,&fact);
            goto go;
        }
        printf("NO\n");
        scanf("%d %d",&num,&fact);
    }
    return 0;
}

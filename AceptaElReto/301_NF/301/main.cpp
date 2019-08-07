//
//  main.cpp
//  301
//
//  Created by David del Val on 12/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
int matri[3][1000];
long target;
int possible(int type, int ammount, long previous){
    if(previous+ammount*matri[0][type]<target){
        possible(type+1,ammount,previous+ammount*matri[0][type]<target);
    }
    else if{
        if(ammount>-1&&type==0){
            
        }
        if(ammount>-1){
            possible(type,ammount-1,previous);
        }
        else{
            possible(type-1,matri[1][type-1],previous);
        }
    }
    
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

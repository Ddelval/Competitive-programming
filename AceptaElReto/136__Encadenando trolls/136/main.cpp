//
//  main.cpp
//  136
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int strength;
int cuts;
void cut(int length){
    int l1;
    if(length>strength){
        cuts++;
        l1=2*(length/3)+length%3;
        cut(l1);
        l1=length-l1;
        cut(l1);
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int length;
    cin>>strength>>length;
    while(strength){
        strength*=2;
        cuts=0;
        cut(length);
        cout<<cuts<<"\n";
        cin>>strength>>length;
    }
    
    return 0;
}

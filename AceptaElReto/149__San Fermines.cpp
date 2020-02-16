// AceptaElReto 149:  San Fermines
//
//  main.cpp
//  149
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int toros,maxspeed,speed;
    while(cin>>toros){
        cin>>maxspeed;
        for(int i=1;i<toros;i++){
            cin>>speed;
            if(speed>maxspeed){
                maxspeed=speed;
            }
        }
        cout<<maxspeed<<"\n";
    }
    return 0;
}

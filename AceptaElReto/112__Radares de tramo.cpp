// AceptaElReto 112:  Radares de tramo
//
//  main.cpp
//  112
//
//  Created by David del Val on 01/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
   ios_base::sync_with_stdio(false);
    long maxspeed;
    long time;
    long distance;
    while(1){
        cin>>distance>>maxspeed>>time;
        if(!(distance ||maxspeed||time)){
            break;
        }
        if(distance<=0||maxspeed<=0||time<=0){
            cout<<"ERROR\n";
            continue;
        }
        else{
            //The input seems correct
            if(distance*18>5*maxspeed*time){
                if(distance*3>maxspeed*time){
                    cout<<"PUNTOS\n";
                }
                else{
                    cout<<"MULTA\n";
                }
            }
            else{
                cout<<"OK\n";
            }
            
        }
    }
    return 0;
}

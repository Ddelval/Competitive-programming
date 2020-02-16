// AceptaElReto 135:  Viaje en el tiempo
//
//  main.cpp
//  135
//
//  Created by David del Val on 23/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int cases;
    int prev;
    int num;
    int factor;
    int counter;
    int prevfactor;
    cin>>cases;
    for(int i=0;i<cases;i++){
        counter=0;
        cin>>prev>>num;
        prevfactor=num-prev;
        if(prevfactor<0){
            prevfactor+=1000000;
        }
        prev=num;
        cin>>num;
        while(num!=-1){
            factor=num-prev;
            if(factor<0){
                factor+=1000000;
            }
            if(factor!=prevfactor){
                counter++;
                prevfactor=factor;
            }
            prev=num;
            cin>>num;
        }
        
        cout<<counter<<" "<<(prevfactor+prev)%1000000<<"\n";
    }
    
    return 0;
}

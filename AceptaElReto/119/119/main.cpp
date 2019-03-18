//
//  main.cpp
//  119
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
long data[3163];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    long n;
    long rem;
    long shields;
    data[1]=5;
    cin>>n;
    while(n){
        shields=0;
        while(n){
            rem=sqrt(n);
            n=n-rem*rem;
            if(!(data[rem])){
                data[rem]=(rem-2)*(rem-2)+4*2*(rem-2)+4*3;
            }
            shields+=data[rem];
        }
        cout<<shields<<"\n";
        cin>>n;
    }
    return 0;
}

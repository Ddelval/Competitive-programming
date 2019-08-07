// AceptaElReto 156:  Ascensor
//
//  main.cpp
//  156
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,n2;
    int sum;
    while(cin>>n&&n>=0){
        sum=0;
        while(cin>>n2&&n2!=-1){
            if(n>n2){
                sum+=n-n2;
            }
            else{
                sum+=n2-n;
            }
            n=n2;
        }
        
        cout<<sum<<"\n";
    }
    return 0;
}

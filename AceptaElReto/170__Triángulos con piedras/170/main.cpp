// AceptaElReto 170:  Triángulos con piedras
//
//  main.cpp
//  170
//
//  Created by David del Val on 29/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    int out;
    int n;
    while(cin>>num&&num){
        out=(int)sqrt(2*num);
        n=num-((out*out+out)/2);
        if(n<0){
            out--;
            n=num-((out*out+out)/2);
        }
        cout<<out<<" "<<n<<"\n";
    }
    return 0;
}

//
//  main.cpp
//  167
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
int const pow[15]={4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int sum;
    int power;
    string output;
    while(cin>>n){
        sum=0;
        power=0;
        while(n!=1){
            sum+=n*pow[power];
            power++;
            n/=2;
        }
        sum+=pow[power];
        //output.append(to_string(sum));
        //output.append("\n");
        cout<<sum<<"\n";
    }
    //cout<<output;
    return 0;
}

//
//  main.cpp
//  147
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int matches,turn;
    int a;
    while(cin>>matches>>turn){
        if(matches%(turn+1)==1){
            cout<<"PIERDO\n";
            continue;
        }
        a=matches%(turn+1)-1;
        if(a<0){
            a+=turn+1;
        }
        cout<<a<<"\n";
    }
    
    
    
    return 0;
}

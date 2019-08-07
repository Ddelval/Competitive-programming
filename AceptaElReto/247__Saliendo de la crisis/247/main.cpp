//
//  main.cpp
//  247
//
//  Created by David del Val on 11/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int len,a,b;
    bool working;
    while(cin>>len &&len){
        working =true;
        cin>>a;
        for(int i=1;i<len;i++){
            cin>>b;
            if(b<=a){
                working=false;
            }
            
            a=b;
        }
        if(working){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

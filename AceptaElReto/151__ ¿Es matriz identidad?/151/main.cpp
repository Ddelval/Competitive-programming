//
//  main.cpp
//  151
//
//  Created by David del Val on 26/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    bool bad;
    int range;
    while(cin>>range && range){
        bad=false;
        for(int i=0;i<range;i++){
            for(int j=0;j<i;j++){
                cin>>n;
                if(n){
                    bad=true;
                }
            }
            cin>>n;
            if(n!=1){
                bad=true;
            }
            for(int j=i+1;j<range;j++){
                cin>>n;
                if(n){
                    bad=true;
                }
            }
        }
        if(bad){
            cout<<"NO\n";
        }
        else{
            cout<<"SI\n";
        }
        
        
    }
    return 0;
}

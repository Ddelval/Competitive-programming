// AceptaElReto 168:  La pieza perdida
//
//  main.cpp
//  168
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool dat[10000];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int len,aux;
    int mis;
    int l1;
    while(cin>>len&&len){
        l1=len-1;
        for(int i=0;i<l1;i++){
            cin>>aux;
            dat[aux-1]=true;
        }
        for(int i=0;i<len;i++){
            if(dat[i]){
                dat[i]=false;
            }
            else{
                mis=i+1;
            }
        }
        cout<<mis<<"\n";
    }
    return 0;
}

// AceptaElReto 369:  Contando en la arena
//
//  main.cpp
//  369
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    string s;
    while(cin>>num&&num){
        s="";
        for(int i=0;i<num;i++){
            s.append("1");
        }
        s.append("\n");
        cout<<s;
    }
    return 0;
}

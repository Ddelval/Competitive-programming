//
//  main.cpp
//  165
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char s[11];
    bool hpar;
    string st;
    while(cin>>s&&(s[0]!='-')){
        hpar=true;
        for(int i=0;s[i];i++){
            if((s[i]-'0')%2){
                hpar=false;
                break;
            }
        }
        if(hpar){
            st.append("SI\n");
        }
        else{
            st.append("NO\n");
        }
        
        
    }
    cout<<st;
    return 0;
}

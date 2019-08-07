// AceptaElReto 334:  Galos, romanos y otras gentes
//
//  main.cpp
//  334
//
//  Created by David del Val on 16/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int cas,i,len;
    string s;
    getline(cin,s);
    cas=stoi(s);
    bool belongs;
    string out;
    for(i=0;i<cas;++i){
        getline(cin,s);
        belongs = false;
        out="";
        len=(int)s.length();
        if(len>=3&&s[0]=='M'&&s[1]=='A'&&s[2]=='C'){
            belongs = true;
            out="PICTO";
        }
        if(s[len-1]=='A'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="INDIO";
            }
        }
        else if(len>=2&&s[len-2]=='E'&&s[len-1]=='Z'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="HISPANO";
            }
        }
        else if(len>=2&&s[len-2]=='I'&&s[len-1]=='S'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="BRETON";
            }
        }
        else if(len>=2&&s[len-2]=='O'&&s[len-1]=='S'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="BRETON";
            }
        }
        else if(len>=2&&s[len-2]=='A'&&s[len-1]=='X'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="BRETON";
            }
        }
        else if(len>=2&&s[len-2]=='A'&&s[len-1]=='F'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="NORMANDO";
            }
        }
        else if(len>=2&&s[len-2]=='A'&&s[len-1]=='S'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="GRIEGO";
            }
        }
        else if(len>=2&&s[len-2]=='I'&&s[len-1]=='C'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="GODO";
            }
        }
        else if(len>=2&&s[len-2]=='U'&&s[len-1]=='S'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="ROMANO";
            }
        }
        else if(len>=2&&s[len-2]=='U'&&s[len-1]=='M'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="ROMANO";
            }
        }
        else if(len>=2&&s[len-2]=='I'&&s[len-1]=='X'){
            if(belongs){
                out="MULATO";
            }
            else{
                belongs = true;
                out="GALO";
            }
        }
        else{
            if(!belongs){
                out="PLUS ULTRA";
            }
        }
        cout<<out<<"\n";
        
    }
    return 0;
}

// AceptaElReto 144:  Teclado estropeado
//
//  main.cpp
//  144
//
//  Created by David del Val on 25/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string s;
    int cursor;
   while(getline(cin,s)){
       string buff;
        cursor=0;
        for(int j=0;j<s.length();j++){
            switch(s[j]){
                case '-':
                    cursor=0;
                    break;
                case '+':
                    if(buff.length()){
                        cursor=(int)buff.length();
                    }
                    else{
                        cursor=0;
                    }
                    break;
                case'3':
                    if(cursor!=buff.length()){
                        buff.erase(buff.begin()+cursor);
                    }
                    break;
                case'*':
                    cursor++;
                    if(cursor>buff.length()){
                        cursor=(int)buff.length();
                    }
                    break;
                default:
                    if(cursor==buff.length()){
                        buff.push_back(s[j]);
                        cursor++;
                    }
                    else{
                        buff.insert(buff.begin()+cursor, s[j]);
                        cursor++;
                    }
                    break;
            }
            
        }
       buff.append("\n");
    cout<<buff;
    }
    return 0;
}

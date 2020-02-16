// AceptaElReto 252:  ¿Acaso hubo búhos acá?
//
//  main.cpp
//  252
//
//  Created by David del Val on 11/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int i,j;
    string s1;
    string s2;
    bool diff;
    while(getline(cin,s1)&&s1!="XXX"){
        s2.clear();
        for(int i=(int)s1.length()-1;i>=0;i--){
            if(s1[i]>='A'&&s1[i]<='Z'){
                s1[i]=(char)s1[i]+('a'-'A');
                s2.push_back(s1[i]);
            }
            else{
                s2.push_back(s1[i]);
            }
        }
        i=j=0;
        diff=false;
        while(i<s1.length()){
            while(s1[i]==' '){
                i++;
            }
            while(s2[j]==' '){
                j++;
            }
            if(s1[i]!=s2[j]){
                diff=true;
                break;
            }
            i++;
            j++;
        }
        if(!diff){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}

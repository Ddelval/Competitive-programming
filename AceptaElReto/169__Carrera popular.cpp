// AceptaElReto 169:  Carrera popular
//
//  main.cpp
//  169
//
//  Created by David del Val on 29/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string prev;
    int coup, part;
    int cases;
    bool done=false;
    cin>>cases;
    for(int i=0;i<cases;i++){
        coup=0;
        part=0;
        prev="";
        while(true){
            cin>>s;
            if(s=="===="){
                break;
            }
            for(int i=0;i<s.length();i++){
                if('a'<=s[i]&&'z'>=s[i]){
                    s[i]-=('z'-'Z');
                }
            }
            part++;
            if(prev==s){
                coup++;
                done=true;
            }
            else{
                if(done){
                    coup++;
                    done=false;
                }
            }
            
            prev=s;
            getline(cin,s);
        }
        if(done){
            coup++;
            done=false;
        }
        cout<<part<<" "<<coup<<"\n";
    }
    return 0;
}

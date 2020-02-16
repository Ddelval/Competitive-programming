//
//  main.cpp
//  110
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    long s;
    long n;
    long a1,a2;
    bool out=false;
    cin>>s;
    while(s){
        n=s*s;
        if(n==1){
            cout<<"SI\n";
            cin>>s;
            continue;
        }
        if(n<10){
            cout<<"NO\n";
            cin>>s;
            continue;
        }
        string str =to_string(n);
        str="0"+str;
        int half= (int)str.length()/2;
        string st1,st2;
        st1=str.substr(0,half);
        st2=str.substr(half,str.length()-half);
        a2=stoi(st2);
        if(a2){
            a1=stoi(st1);
            if((a1+a2)==s){
                cout<<"SI\n";
                cin>>s;
                continue;
            }
        }
            for(int i=half-1;i>0;i--){
                st1=str.substr(0,i);
                st2=str.substr(i,str.length()-i);
                a2=stoi(st2);
                if(a2){
                    a1=stoi(st1);
                    if((a1+a2)==s){
                        cout<<"SI\n";
                        cin>>s;
                        out=true;
                        break;
                    }
                }
            }
        if(out){
            out=false;
            continue;
        }
            for(int i=half+1;i<str.length();i++){
                st1=str.substr(0,i);
                st2=str.substr(i,str.length()-i);
                a2=stoi(st2);
                if(a2){
                    a1=stoi(st1);
                    if((a1+a2)==s){
                        cout<<"SI\n";
                        cin>>s;
                        out = true;
                        break;
                    }
                }
            }
        if(out){
            out=false;
            continue;
        }
        
        cout<<"NO\n";
        cin>>s;
    }
    return 0;
}

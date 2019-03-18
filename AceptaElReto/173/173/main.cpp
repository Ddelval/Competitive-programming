//
//  main.cpp
//  173
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int marc[2];
    char current;
    char prev;
    bool f,s;
    bool printspace;
    while(1){
        prev='A';
        s=false;
        marc[0]=0;
        marc[1]=0;
        f=true;
        printspace=false;
        while(cin>>current&&current!='F'){
            if(prev==current){
                marc[current-'A']++;
            }
            else{
               prev=current;
            }
            
            s=false;
            if(marc[0]>=9){
                if(marc[0]-marc[1]>=2){
                    if(printspace){
                        cout<<" ";
                    }
                    else{
                        printspace=true;
                    }
                    cout<<marc[0]<<"-"<<marc[1];
                    marc[0]=0;
                    marc[1]=0;
                    prev='A';
                    s=true;
                }
            }
            if(marc[1]>=9){
                if(marc[1]-marc[0]>=2){
                    if(printspace){
                        cout<<" ";
                    }
                    else{
                        printspace=true;
                    }
                    cout<<marc[0]<<"-"<<marc[1];
                    marc[0]=0;
                    marc[1]=0;
                    prev='B';
                    s=true;
                }
            }
            
            
            
            f=false;
        }
        if(f){
            break;
        }
        if(!s){
            if(printspace){
                cout<<" ";
            }
            cout<<marc[0]<<"-"<<marc[1];
        }
        cout<<"\n";
        
    }
    
    return 0;
}

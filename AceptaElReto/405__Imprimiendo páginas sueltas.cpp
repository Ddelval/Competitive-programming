// AceptaElReto 405:  Imprimiendo páginas sueltas
//
//  main.cpp
//  405
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    bool interval;
    bool comma;
    int first = 0;
    int nextnum;
    while(1){
        cin>>num;
        if(!num){
            break;
        }
        interval=false;
        comma=false;
        while(cin>>nextnum){
            if(!nextnum){
                break;
            }
            if(nextnum==num+1){
                if(!interval){
                    interval=true;
                    first=num;
                }
            }
            else{
                if(comma){
                    cout<<",";
                }
                else{
                    comma=true;
                }
                if(interval){
                    cout<<first<<"-"<<num;
                    interval=false;
                }
                else{
                    cout<<num;
                }
                
                
            }
            num=nextnum;
        }
        if(comma){
            cout<<",";
        }
        else{
            comma=true;
        }
        if(interval){
            cout<<first<<"-"<<num;
            interval=false;
        }
        else{
            cout<<num;
        }
        cout<<"\n";
        
    }
    return 0;
}

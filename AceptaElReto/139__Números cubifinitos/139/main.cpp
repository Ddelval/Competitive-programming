// AceptaElReto 139:  Números cubifinitos
//
//  main.cpp
//  139
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;
int nexts[5105];
int transformat (int input){
    if(input<5105){
        if(nexts[input]){
            return nexts[input];
        }
        int output=0;
        int aux,aux2=input;/*
        string pars;
        pars=to_string(input);
        for(int i=0;i<pars.length();i++){
            aux=(char)pars[i]-'0';
            output+=aux*aux*aux;
        }*/
        while(aux2!=0){
            aux=aux2%10;
            output+=aux*aux*aux;
            aux2/=10;
        }
        nexts[input]=output;
        return output;
    }
    int output=0;
    int aux,aux2=input;/*
             string pars;
             pars=to_string(input);
             for(int i=0;i<pars.length();i++){
             aux=(char)pars[i]-'0';
             output+=aux*aux*aux;
             }*/
    while(aux2!=0){
        aux=aux2%10;
        output+=aux*aux*aux;
        aux2/=10;
    }
    return output;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int candidate;
    int curr;
    set<int> steps;
    cin>>candidate;
    while(candidate){
        steps.clear();
        if(candidate==1){
            cout<<"1 -> cubifinito.\n";
            cin>>candidate;
            continue;
        }
        curr=candidate;
        steps.insert(curr);
        cout<<candidate<<" ";
        while(curr!=1){
            curr=transformat(curr);
            if(curr==1){
                cout<<"- 1 -> cubifinito.\n";
                break;
            }
            if(steps.count(curr)==1){
                cout<<"- "<<curr<<" -> no cubifinito.\n";
                break;
            }
            else{
                cout<<"- "<<curr<<" ";
                steps.insert(curr);
            }
        }
        cin>>candidate;
    }
    return 0;
}

// AceptaElReto 134:  Escalera de color
//
//  main.cpp
//  134
//
//  Created by David del Val on 23/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int,char> carta;
int getnum(string n){
    if(n=="J"){
        return 11;
    }
    if(n=="Q"){
        return 12;
    }
    if(n=="K"){
        return 13;
    }
    if(n=="A"){
        return 14;
    }
    return stoi(n);
}
string setnum(int n){
    switch(n){
        case 11:
            return "J";
            break;
        case 12:
            return "Q";
            break;
        case 13:
            return "K";
            break;
        case 14:
            return "A";
            break;
        default:
            return to_string(n);
            break;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    vector<carta> data(4);
    char buff;
    string s;
    char palo;
    bool exit;
    cin>>s;
    while(s!="0"){
        exit=false;
        data[0].first=getnum(s);
        cin>>buff;
        data[0].second=buff;
        palo=buff;
        for(int i=1;i<4;i++){
            cin>>s;
            data[i].first=getnum(s);
            cin>>buff;
            if(buff!=palo){
                exit=true;
            }
            data[i].second=buff;
        }
        if(exit){
            cout<<"NADA\n";
            cin>>s;
            
            continue;
        }
        sort(data.begin(),data.end());
        if(data[3].first-data[0].first>4){
            cout<<"NADA\n";
            cin>>s;
            continue;
        }
        if(data[3].first-data[0].first==4){
            
            for(int i=1;i<4;i++){
                if(data[i].first!=data[i-1].first+1){
                    cout<<setnum(data[i].first-1)<<" "<<data[i].second<<"\n";
                    break;
                }
            }
            
            cin>>s;
            
            continue;
        }
        if(data[3].first-data[0].first==3){
            if(data[3].first!=14){
                cout<<setnum(data[3].first+1)<<" "<<data[3].second<<"\n";
                
            }
            else{
                cout<<setnum(data[0].first-1)<<" "<<data[3].second<<"\n";
            }
            cin>>s;
            continue;
        }
        
        
    }
    
    return 0;
}

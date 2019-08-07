//
//  main.cpp
//  130
//
//  Created by David del Val on 23/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    pair<long,long> start;
    pair<long,long> end;
    long size;
    cin>>size;
    while(size){
        cin>>start.first>>start.second>>end.first>>end.second;
        if((start.first+start.second-end.first-end.second)%2){
            cout<<"IMPOSIBLE\n";
        }
        else if(start.first==end.first&&start.second==end.second){
            cout<<"0\n";
        }
        else{
            if(start.first+start.second==end.first+end.second){
                cout<<"1\n";
            }
            else if(start.first-end.first==start.second-end.second){
                cout<<"1\n";
            }
            else{
                cout<<"2\n";
            }
        }
        cin>>size;
    }
    return 0;
}

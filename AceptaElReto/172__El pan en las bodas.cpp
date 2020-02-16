// AceptaElReto 172:  El pan en las bodas
//
//  main.cpp
//  172
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    bool comen;
    bool f;
    char com;
    char init;
    while(cin>>n&&n){
        f=true;
        comen=true;
        init='.';
        for(i=0;i<n;i++){
            cin>>com;
            if(com!='.'&&init=='.'){
                init=com;
            }
            if(com!=init&&com!='.'){
                comen=false;
                break;
            }
        }
        for(i++;i<n;i++){
            cin>>com;
        }
        if(comen){
            cout<<"TODOS COMEN\n";
        }
        else{
            cout<<"ALGUNO NO COME\n";
        }
    }
    return 0;
}

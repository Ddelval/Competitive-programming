//
//  main.cpp
//  163
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    int i;
    while(cin>>num&&num!="FIN"){
        for(i=(int)num.length()-1;i>=0;i--){
            if(num[i]=='F'){
                num[i]='0';
            }
            else if(num[i]=='9'){
                num[i]='A';
                break;
            }
            else{
                num[i]=num[i]+1;
                break;
            }
        }
        if(i<0){
            cout<<"1";
        }
        cout<<num<<"\n";
    }
    return 0;
}

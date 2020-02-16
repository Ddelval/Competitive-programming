// AceptaElReto 254:  Esquiando en Alaska
//
//  main.cpp
//  254
//
//  Created by David del Val on 11/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> squies;
vector <int> squiers;
int absolute(int a){
    if(a<0){
        return -a;
    }
    else{
        return a;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int len;
    int aux;
    int diff;
    while(cin>>len && len){
        squies.clear();
        squiers.clear();
        for(int i=0;i<len;i++){
            cin>>aux;
            squies.push_back(aux);
        }
        for(int i=0;i<len;i++){
            cin>>aux;
            squiers.push_back(aux);
        }
        sort(squiers.begin(),squiers.end());
        sort(squies.begin(),squies.end());
        diff=0;
        for(int i=0;i<len;i++){
            diff+=absolute(squiers[i]-squies[i]);
        }
        cout<<diff<<"\n";
    }
    return 0;
}

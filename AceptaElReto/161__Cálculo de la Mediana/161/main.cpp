//
//  main.cpp
//  161
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int cases;
    vector<int> v;
    int a;
    while(cin>>cases && cases){
        v.clear();
        for(int i=0;i<cases;i++){
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        if(cases%2){
            //Odd
            cout<<2*v[cases/2]<<"\n";
        }
        else{
            cout<<v[cases/2]+v[cases/2-1]<<"\n";
        }
    }
    return 0;
}

//
//  main.cpp
//  157
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
const int mon[13]={0,334,306,275,245,214,184,153,122,92,61,31,0};
const int di[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int cases;
    int m,d;
    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>d>>m;
        cout<<mon[m]+di[m]-d<<"\n";
    }
    return 0;
}

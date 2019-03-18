//
//  main.cpp
//  164
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a1,b1,a2,b2;
    while(cin>>a1>>b1>>a2>>b2&&(a2>=a1&&b2>=b1)){
        cout<<(a2-a1)*(b2-b1)<<"\n";
    }
    return 0;
}

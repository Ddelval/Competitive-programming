// AceptaElReto 155:  Perímetro de un rectángulo
//
//  main.cpp
//  155
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int l1,l2;
    while(cin>>l1>>l2&&l1>=0&&l2>=0){
        cout<<2*l1+2*l2<<"\n";
    }
    return 0;
}

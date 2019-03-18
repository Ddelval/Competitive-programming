//
//  main.cpp
//  110f
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    while(a){
        switch (a) {
            case 1:
            case 9:
            case 45:
            case 55:
            case 99:
            case 297:
            case 703:
            case 999:
            case 2223:
            case 2728:
            case 4879:
            case 4950:
            case 5050:
            case 5292:
            case 7272:
            case 7777:
            case 9999:
            case 17344:
            case 22222:
            case 38962:
                cout<<"SI\n";
                break;
            default:
                cout<<"NO\n";
                break;
        }
        cin>>a;
    }
    
    return 0;
}

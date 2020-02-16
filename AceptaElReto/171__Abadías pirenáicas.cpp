// AceptaElReto 171:  Abadías pirenáicas
//
//  main.cpp
//  171
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int abd[100000];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max;
    int count;
    int num;
    while(cin>>num && num){
        for(int i=0;i<num;i++){
            cin>>abd[i];
        }
        max=0;
        count=0;
        for(int i=num-1;i>=0;i--){
            if(abd[i]>max){
                count++;
                max=abd[i];
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}

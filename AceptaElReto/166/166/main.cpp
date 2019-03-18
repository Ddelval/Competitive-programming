//
//  main.cpp
//  166
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    string s;
    while(cin>>a>>b&&a){
        if(b<a){
            s.append(to_string(min(a-b,(b+(99-a)))));
            s.append("\n");
        }
        else{
            s.append(to_string(min(b-a,(a+(99-b)))));
            s.append("\n");
        }
        
    }
    cout<<s;
    return 0;
}

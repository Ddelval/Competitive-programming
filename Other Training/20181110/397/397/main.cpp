//
//  main.cpp
//  397
//
//  Created by David del Val on 09/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>

using namespace std;

int main(void) {
     long long int cases, z, n;
    
    cin>>cases;
    for(z=0;z<cases;z++){
        cin>>n;
        if(n%3==0||n%3==2){
            cout<<"SI"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

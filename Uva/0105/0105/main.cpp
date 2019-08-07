//
//  main.cpp
//  0105
//
//  Created by David del Val on 27/10/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int land[10001]={0};
    bool flag=true;
    int start=0;
    int end=0;
    int x1,x2,h;
    int i;
    int tempheight=-1;
    while(cin>>x1>>h>>x2){
        if(flag){
            start=x1;
        }
        flag=false;
        for(i=x1;i<x2;i++){
            land[i]= max(land[i], h);
        }
        end=max(end,x2);
        
        
    }
    for(i=start;i<=end;i++){
        if(tempheight!=land[i]){
            cout<<i<<" "<<land[i];
            if(i!=end){
                cout<<" ";
            }
        }
        tempheight=land[i];
        
    }
    cout<<endl;
    
    
    
    return 0;
}

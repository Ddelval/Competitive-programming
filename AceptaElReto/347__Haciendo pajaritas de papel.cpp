// AceptaElReto 347:  Haciendo pajaritas de papel
//
//  main.cpp
//  347
//
//  Created by David del Val on 30/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int counter;
void pap(int x,int y){
    if(x<10||y<10){
        return;
    }
    else{
        if(x>=y){
            counter+=x/y;
            pap(x%y,y);
        }
        else{
            counter+=y/x;
            pap(y%x,x);
        }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int x,y;
    while(cin>>x>>y && (x|| y)){
        counter=0;
        pap(x,y);
        cout<<counter<<"\n";
    }
    return 0;
}

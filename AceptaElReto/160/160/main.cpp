//
//  main.cpp
//  160
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    bool top,bottom;
    int aux;
    int size;
    while(cin>>size&&size){
        top=true;
        bottom=true;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                cin>>aux;
                if(aux){
                    bottom=false;
                }
            }
            cin>>aux;
            for(int j=i+1;j<size;j++){
                cin>>aux;
                if(aux){
                    top=false;
                }
            }
        }
        if(bottom||top){
            cout<<"SI\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}

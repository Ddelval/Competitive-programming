// AceptaElReto 158:  Los saltos de Mario
//
//  main.cpp
//  158
//
//  Created by David del Val on 28/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int cases;
    int walls;
    int pw,w;
    int up,down;
    cin>>cases;
    for(int i=0;i<cases;i++){
        cin>>walls;
        cin>>pw;
        up=0;
        down=0;
        for(int i=1;i<walls;i++){
            cin>>w;
            if(w>pw){
                up++;
            }
            else if(w<pw){
                down++;
            }
            pw=w;
        }
        cout<<up<<" "<<down<<"\n";
    }
    return 0;
}

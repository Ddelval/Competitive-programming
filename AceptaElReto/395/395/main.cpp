//
//  main.cpp
//  395
//
//  Created by David del Val on 15/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int rows,cols;
cha
typedef struct{
    vector<vector<bool>> v_mat;
    vector<vector<bool>> h_mat;
    vector<bool> h;
    vector<bool> v;
}board;


int main(int argc, const char * argv[]) {
    cin>>rows>>cols;
    char prev,curr;
    board b;
    vector<bool> vec;
    for(int i=0;i<cols;i++){
        b.v.push_back(0);
        vec.push_back(0);
    }
    for(int i=0;i<rows;i++){
        b.h.push_back(0);
        b.v_mat.push_back(vec);
    }
    for(int i=0;i<rows;i++){
        cin>>prev;
        for(int j=1;j<cols;j++){
            cin>>curr;
            if(curr!=prev){
                b.v_mat[i][j-1]=true;
            }
            prev=curr;
        }
    }
    cout<<"ex";
    
    return 0;
}

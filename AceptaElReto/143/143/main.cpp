//
//  main.cpp
//  143
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int m,n;
    int a;
    vector<int> q;
    while(1){
        while(!q.empty()){
            q.pop_back();
        }
        cin>>m;
        while(m!=-1){
            q.push_back(m);
            cin>>m;
        }
        if(q.empty()){
            break;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>n;
            for(int j=0;j<n/2;j++){
                a=q[q.size()-n+j];
                q[q.size()-n+j]=q[q.size()-1-j];
                q[q.size()-1-j]=a;
            }
        }
        cout<<q.back()<<"\n";
    }
    return 0;
}

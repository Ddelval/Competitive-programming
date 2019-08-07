//
//  main.cpp
//  142
//
//  Created by David del Val on 24/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    queue<int> q;
    int p;
    cin>>n>>p;
    while(n||p){
        if(!p){
            cout<<n<<"\n";
            cin>>n>>p;
            continue;
        }
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            for(int i=0;i<p;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        cout<<q.front()<<"\n";
        q.pop();
        cin>>n>>p;
    }
    return 0;
}

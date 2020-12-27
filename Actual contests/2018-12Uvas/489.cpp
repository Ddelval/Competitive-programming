#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> prev;
    priority_queue<int> curr;
    int p,c;
    int a;
    bool bad;
    while(cin>>p>>c){
        while (!curr.empty()) {
            curr.pop();
        }
        while (!prev.empty()) {
            prev.pop();
        }
        bad=false;
        if(c<p){
            for(int i=0;i<p;i++){
                cin>>a;
            }
            for(int i=0;i<c;i++){
                cin>>a;
            }
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<p;i++){
            cin>>a;
            prev.push(a);
        }
        for(int i=0;i<c;i++){
            cin>>a;
            curr.push(a);
        }
        for(int i=0;i<p;i++){
            if(prev.top()>curr.top()){
                bad=true;
                break;
            }
            else{
                prev.pop();
                curr.pop();
            }
        }
        if(bad){
            cout<<"NO\n";
        }
        else{
            cout<<"SI\n";
        }
        
    }
    return 0;
}


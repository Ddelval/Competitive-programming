// AceptaElReto 341:  Reina del súper
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii>> pq;
int main() {
    ios::sync_with_stdio(false);
    int places,people,wait;
    ii current;
    while(cin>>places>>people){
        while(not pq.empty()){
            pq.pop();
        }
        for(int i=0;i<places;++i){
            pq.push(mp(0,i));
        }
        for(int i=0;i<people;++i){
            cin>>wait;
            current=pq.top();
            pq.pop();
            current.first+=wait;
            pq.push(current);
        }
        cout<<pq.top().second+1<<"\n";
    }
    return 0;
}


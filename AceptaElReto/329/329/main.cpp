#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <limits.h>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> ii;
ii data[100010];
int buildings;
int main() {
    ios::sync_with_stdio(false);
    int x,y;
    int i,cursor;
    int counter;
    while(cin>>buildings&&buildings){
        for(i=0;i<buildings;++i){
            cin>>x>>y;
            data[i]=mp(y,x);
        }
        sort(data,data+buildings);
        counter=1;
        cursor=data[0].first;
        for(i=0;i<buildings;++i){
            if(!(data[i].second<cursor)){
                cursor=data[i].first;
                counter++;
            }
        }
        cout<<counter<<"\n";
        
    }
    return 0;
}


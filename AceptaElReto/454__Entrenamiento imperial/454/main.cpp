// AceptaElReto 454:  Entrenamiento imperial
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
using namespace std;
struct train{
    int dist;
    int desniv;
    train(int a,int b){
        dist=a;
        if(b>=0) desniv=b;
        else desniv=0;
    }
};
int dist,height;
int cursor;
vector<train> succ;
bool possible(int cur,int rdist,int rheight){
    if(cur==succ.size()) return false;
    train t=succ[cur];
    if(rdist>=t.dist&&rheight>=t.desniv) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    int a,b;
    int days;
    bool bo;
    int d,h;
    while(cin>>dist>>height){
        succ.clear();
        while(cin>>a>>b&&(a||b)){
            succ.push_back(train(a,b));
        }
        cursor=0;
        days=0;
        while(cursor<succ.size()){
            bo=possible(cursor,dist,height);
            if(!bo) break;
            d=dist;
            h=height;
            while(possible(cursor,d,h)){
                d-=succ[cursor].dist;
                h-=succ[cursor].desniv;
                cursor++;
            }
            days++;
        }
        if(!bo){
            cout<<"DESTITUIDO\n";
            continue;
        }
        cout<<days<<"\n";
    }
    return 0;
}


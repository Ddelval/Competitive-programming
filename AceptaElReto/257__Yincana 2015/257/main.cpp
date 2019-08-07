// AceptaElReto 257:  Yincana 2015
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
typedef pair <int,int> ii;
int pcon;
int coord[505][2];
int store[505][505]; // results of the execution of send
int dist(int p1, int p2){
    return abs(coord[p1][0]-coord[p2][0])+abs(coord[p1][1]-coord[p2][1]);
}

/**
 p1 will always be the person who is at the node that has a higher lable
 @param p1 position of person 1 currently
 @param p2 position of person 2 currently
 @param target the node that we have to arrive to next
 @return the minimum time needed to get from this situation to the end of the run
 */
int send(int p1,int p2,int target){
    int a,b;
    if(target==pcon+1) return 0;
    if(store[p1][p2]) return store[p1][p2];
    
    if(target>=p2) a=dist(p1,target)+send(target,p2,target+1);
    else a=dist(p1,target)+send(p2,target,target+1);
        
    if(target>=p1) b=dist(p2,target)+send(target,p1,target+1);
    else b=dist(p2,target)+send(p1,target,target+1);
    
    return store[p1][p2]=min(a,b);
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin>>cas;
    coord[0][0]=0;
    coord[0][1]=0;
    for(int i=0;i<cas;++i){
        //Input
        cin>>pcon;
        for(int j=1;j<=pcon;++j){
            cin>>coord[j][0]>>coord[j][1];
        }
        //Process
        cout<<send(0,0,1)<<"\n";
        //Clean the array
        for(int j=0;j<=pcon;++j){
            for(int w=0;w<=pcon;++w){
                store[j][w]=0;
            }
        }
    }
    return 0;
}


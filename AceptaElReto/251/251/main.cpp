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
typedef pair<int,int> ii;
bool mat[2003];
int nmon, insert;
int cas;
long long counter;
int mmone;
int coinvalue[10];
void select(){
    queue<ii> que;//First element current money, second coin count
    ii curr;
    int i;
    que.push(ii(0,0));
    while(!que.empty()){
        curr=que.front();
        que.pop();
        if(curr.second>=insert){
            continue;
        }
        for(i=0;i<nmon;++i){
            if(!mat[curr.first+coinvalue[i]]){
                counter++;
                mat[curr.first+coinvalue[i]]=true;
                que.push(ii(curr.first+coinvalue[i],curr.second+1));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    
    cin>>cas;
    for(int i=0;i<cas;++i){
        cin>>nmon>>insert;
        mmone=0;
        for(int j=0;j<nmon;++j){
            cin>>coinvalue[j];
            if(coinvalue[j]>mmone)mmone=coinvalue[j];
        }
        counter=0;
        memset(mat,0,mmone*insert+1);
        select();
        cout<<counter<<"\n";
    }
    return 0;
}


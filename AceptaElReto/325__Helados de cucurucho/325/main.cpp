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
char mmry[15];
int size;
string out;
void findCombination(int v,int c,int depth){
    if(depth==size){
        for(int i=0;i<size;++i) out.push_back(mmry[i]);
        out.push_back(' ');
        return;
    }
    if(v&&c){
        mmry[depth]='C';
        findCombination(v,c-1,depth+1);
        mmry[depth]='V';
        findCombination(v-1,c,depth+1);
        return;
    }
    if(v){
        mmry[depth]='V';
        findCombination(v-1,c,depth+1);
        return;
    }
    mmry[depth]='C';
    findCombination(v,c-1,depth+1);
}
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int v,c;
    cin>>cas;
    for(int z=0;z<cas;++z){
        cin>>c>>v;
        size=v+c;
        out.clear();
        findCombination(v,c,0);
        out.pop_back();
        cout<<out<<"\n";
    }
    return 0;
}


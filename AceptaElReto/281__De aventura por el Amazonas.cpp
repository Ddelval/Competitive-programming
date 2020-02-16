// AceptaElReto 281:  De aventura por el Amazonas
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
int pob;
long lengths[200][200];
void coutboard(){
    for(int i=1;i<pob;i++){
        for(int j=0;j<pob-i-1;j++){
            cout<<lengths[i-1][j]<<" ";
        }
        cout<<lengths[i-1][pob-i-1]<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    
    //priority_queue<long,vector<long>,greater<long>> pq;
    vector<long> pq;
    while(cin>>pob){
        for(int i=1;i<pob;i++){
            for(int j=0;j<pob-i;j++){
                cin>>lengths[i-1][j];
            }
        }
        for(int i=pob-3;i>=0;--i){
            for(int j=pob-2-i;j>0;--j){
                pq.clear();
                pq.push_back(lengths[i][j]);
                for(int w=1;i+w<pob-1-(pob-2-i-j);++w){
                    pq.push_back(lengths[i+w][j-w]+lengths[i][w-1]);
                }
                lengths[i][j]=*min_element(pq.begin(),pq.end());
            }
        }
        coutboard();
    }
    return 0;
}


// AceptaElReto 386:  Clúster de microondas
//
//  main.cpp
//  386
//
//  Created by David del Val on 18/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> inuse(86401);
vector<pair<int,int>> qp2;
int nper,t;
bool Possible(int currentmw){
    priority_queue <int,vector<int>,greater<int>> current_mw;
    int aux;
    for(int i=0;i<currentmw;i++){
        current_mw.push(0);
    }
   // for(auto it=qp2.begin();it!=qp2.end();it++){
    for(int i=0;i<qp2.size();i++){
        if(qp2[i].first+t<current_mw.top()){
            return false;
        }
        else{
            aux=current_mw.top();
            current_mw.pop();
            current_mw.push(max(aux+qp2[i].second,qp2[i].first+qp2[i].second));
        }
            
    }
    return true;
}
int BusquedaBin(int left, int right){
    if(left+1==right){
        return right;
    }
    if(Possible((left+right)/2)){
        return BusquedaBin(left, (left+right)/2);
    }
    else{
        return BusquedaBin((left+right)/2,right);
    }
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int n,i;
    int a,b;
    int maxindex;
    maxindex=0;
    while(cin>>n>>t&&n){
        nper=n;
        qp2.clear();
        for(i=0;i<n;++i){
            cin>>a>>b;
            qp2.push_back(make_pair(a,b));
        }
        cout<<BusquedaBin(0,n)<<"\n";
        
        
    }
    return 0;
}

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
typedef pair<int,pair<int,int>> ip;
int DtoI(int d,int m,int y){
    m--;
    m+=y*12;
    d+=m*30;
    return d;
}
pair<int,pair<int,int>> ItoD(int i){
    pair<int,pair<int,int>> p;
    p.first=i/(360);
    p.second.first=(i%(360))/30;
    p.second.first++;
    p.second.second=((i%(360))%30);
    return p;
}
bool compar(ii i1,ii i2){
    if(i1.first==i2.first){
        if(i1.second>i2.second){
            return true;
        }
        else{
            return false;
        }
    }
    else if(i1.first>i2.first){
        return false;
    }
    return true;
}
int main() {
    vector<ii> travels;
    ios::sync_with_stdio(false);
    int ntravel,nconsol,d1,m1,y1,d2,m2,y2;
    int s,e;
    ii d;
    ip a;
    
    while(cin>>ntravel){
        s=DtoI(12,6,1968);
        for(int i=0;i<ntravel;i++){
            scanf("%d/%d/%d",&d1,&m1,&y1);
            e=DtoI(d1,m1,y1);
            d.first=s;
            d.second=e;
            travels.push_back(d);
            scanf("%d/%d/%d",&d2,&m2,&y2);
            s=DtoI(d2,m2,y2);
            
        }
        e=DtoI(30,12,9999);
        d.first=s;
        d.second=e;
        travels.push_back(d);
        sort(travels.begin(),travels.end(),compar);
        /*ip a;
        for(int i=0;i<travels.size();i++){
            a =ItoD(travels[i].first);
            cout<<a.second.second<<" "<<a.second.first<<" "<<a.first<<" ";
            a =ItoD(travels[i].second);
            cout<<a.second.second<<" "<<a.second.first<<" "<<a.first<<" ";
            cout<<"\n";
        }*/
        cin>>nconsol;
        int counter=0;
        for(int i=0;i<nconsol;i++){
            counter=0;
            scanf("%d/%d/%d",&d1,&m1,&y1);
            e=DtoI(d1,m1,y1);
            
        }
        
    }
    return 0;
}


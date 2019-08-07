// AceptaElReto 464:  Entrando en pelotón
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
int runn[100];
int main() {
    ios::sync_with_stdio(false);
    vector<ii> vec;
    int riders,h,m,s,t;
    int previ,pos;
    while(cin>>riders){
        vec.clear();
        for(int i=0;i<riders;i++){
            scanf("%d:%d:%d",&h,&m,&s);
            t=h*3600+m*60+s;
            vec.push_back(make_pair(t,i));
        }
        sort(vec.begin(),vec.end());
        pos=1;
        runn[vec[0].second]=pos;
        previ=vec[0].first;
        for(int i=1;i<riders;i++){
            if(vec[i].first-previ>1){
                pos=i+1;
            }
            runn[vec[i].second]=pos;
            previ=vec[i].first;
        }
        for(int i=0;i<riders;i++){
            printf("%d\n",runn[i]);
        }
        printf("---\n");
    }
    return 0;
}


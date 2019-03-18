//
//  main.cpp
//  109
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    string p1,p2;
    int s1,s2;
    int matches;
    cin>>p1;
    while(p1!="FIN"){
        matches=0;
        map<string,int> points;
        vector<pair<int,string>> order;
        cin>>p1;
        while(p1!="FIN"){
            cin>>s1>>p2>>s2;
            if(s1>s2){
                points[p1]+=2;
                points[p2]++;
            }
            else{
                points[p2]+=2;
                points[p1]++;
            }
            
            matches++;
            
            cin>>p1;
        }
        for(auto p:points){
            order.push_back(make_pair(p.second,p.first));
        }
        sort(order.begin(),order.end(),greater<pair<int,string>>());
        if(order.size()>=2&&order[0].first==order[1].first){
            cout<<"EMPATE "<<(points.size()*(points.size()-1)-matches)<<"\n";
        }
        else{
            cout<<order[0].second<<" "<<(points.size()*(points.size()-1)-matches)<<"\n";
        }
        cin>>p1;
    }
    return 0;
}

//
//  main.cpp
//  461
//
//  Created by David del Val on 09/01/2019.
//  Copyright © 2019 David del Val. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <math.h>
using namespace std;
typedef struct{
    int required;
    int lost;
    int maintained;

}pp;
typedef long long ll;

ll maxim(ll a,ll b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
bool b1=true;
bool comparepp(pp n1, pp n2){
    if(n1.maintained>n2.maintained){
        return b1;
    }
    if(n1.maintained<n2.maintained){
        return !b1;
    }
    else{
        //Canged this
        if(n1.required>n2.required){
            return b1;
        }
        else{
            return !b1;
        }
    }
    
}
//priority_queue<pp,vector<pp>,function<bool(pp,pp)>> pq(compare);
vector<pp> pq;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    
    int nbases;
    int requiredforassault,dead,left,lost;
    ll soldiers,usablesoldiers;
    while(cin>>nbases&&nbases){
        pq.clear();
        for(int i=0;i<nbases;i++){
            cin>>requiredforassault>>dead>>left;
            lost=dead+left;
            if(lost>requiredforassault){
                requiredforassault=lost;
            }
            pp a;
            a.required=requiredforassault;
            a.lost=lost;
            a.maintained=requiredforassault-lost;
            //pq.push(a);
            pq.push_back(a);
            
        }
       /* soldiers =0;
        usablesoldiers=0;
        soldiers=pq.top().required;
        usablesoldiers=pq.top().required-pq.top().lost;
        pq.pop();
        while(!pq.empty()){
            if(usablesoldiers>=pq.top().required){
                //No need for more soldiers
                usablesoldiers-=pq.top().lost;
            }
            else{
                soldiers+=pq.top().required-usablesoldiers;
                usablesoldiers+=pq.top().required-usablesoldiers;
                usablesoldiers-=pq.top().lost;
            }
            pq.pop();
        }
        */
        sort(pq.begin(),pq.end(),comparepp);
        soldiers =0;
        usablesoldiers=0;
        soldiers=pq.front().required;
        usablesoldiers=pq.front().required-pq.front().lost;
        for(int i=1;i<pq.size();i++){
            if(usablesoldiers>=pq[i].required){
                //No need for more soldiers
                usablesoldiers-=pq[i].lost;
            }
            else{
                soldiers+=pq[i].required-usablesoldiers;
                usablesoldiers+=pq[i].required-usablesoldiers;
                usablesoldiers-=pq[i].lost;
            }
        }
        cout<<soldiers<<"\n";
        
        
        
    }
    return 0;
}

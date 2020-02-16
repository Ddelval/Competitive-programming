// AceptaElReto 431:  Genética Jedi
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

int main() {
    ios::sync_with_stdio(false);
    vector<int> children;
    int cas,nhijos,k, maxf,j,f,i;
    while(cin>>cas&&cas){
        children.clear();
        for(i=0;i<cas;++i){
            cin>>nhijos>>k;
            cin>>maxf;
            for(j=1;j<nhijos;++j){
                cin>>f;
                if(f>maxf) maxf=f;
            }
            children.push_back(maxf*k);
        }
        sort(children.begin(),children.end(),greater<int>());
        cout<<children[0];
        for(i=1;i<children.size();++i){
            cout<<" "<<children[i];
        }
        cout<<"\n";
        
    }
    
    return 0;
}


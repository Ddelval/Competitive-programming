// AceptaElReto 250:  El desgaste de los bombines
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    int cas;
    int i,j;
    long aux;
    long min,minpos;;
    long candidat;
    ll sum_r;
    ll sum_l;
    ll tot;
    while(cin>>cas&&cas){
        vi.clear();
        sum_r=0;
        for(i=0;i<cas;++i){
            cin>>aux;
            sum_r+=aux;
            vi.push_back(aux);
        }
        if(!sum_r){
            cout<<"0\n";
            continue;
        }
        tot=abs(sum_r);
        sum_r*=-1;
        sum_l=0;
        min=tot;
        minpos=-1;
        for(j=0;j<vi.size()-1;++j){
            sum_r+=vi[j];
            sum_l+=vi[j];
            candidat=abs(sum_r+sum_l);
            if(candidat<min){
                min=candidat;
                minpos=j;
            }
        }
        if(min>=tot){
            cout<<"0\n";
            continue;
        }
        cout<<minpos+1<<"\n";
    }
    
    return 0;
}


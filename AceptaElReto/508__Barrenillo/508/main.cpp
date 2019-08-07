#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pl;
vector<pl> intervals;
ll m, mi;
int main(){
    ios::sync_with_stdio(false);
    int np;
    while(cin>>np&&np){
        intervals.clear();
        ll x,y,res;
        ll t;
        for(int i=0;i<np;++i){
            cin>>x>>y;
            intervals.push_back(mp(max((ll)0,x-y),-1));
            intervals.push_back(mp(x+y,+1));
        }
        sort(intervals.begin(),intervals.end());
        m=t=0;
        for(int i=0; i<intervals.size();++i){
            t-=intervals[i].second;;
            if(t>m) m=t;
        }
        cout<<m<<"\n";
        
    }
    
    return 0;
}


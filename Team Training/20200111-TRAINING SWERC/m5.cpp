#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> dat;
int n;

bool check(int k){
    if(k>n)return false;
    for(int i=0;i<n-k;++i){
        if(min(dat[i].se,dat[i+k-1].se)-max(dat[i].fi,dat[i+k-1].fi)+1 >= k)return true;
    }
    return false;
}


int main(){
    cin>>n;
    int a,b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        dat.pb({a,b});
    }
    int r,l;
    r=n+1;l=1;
    while(r-l>1){
        int mid((r+l)/2);
        if(check(mid))l=mid;
        else r=mid;   
    }
    cout<<l<<"\n";

    return 0;
}
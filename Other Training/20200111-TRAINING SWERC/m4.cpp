#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int getmedian(vector<pii> &dat){
    sort(dat.begin(),dat.end(),[](pii a, pii b){
        return a.se<=b.se;
    });
    return dat[(dat.size()+1)/2].se;
}
vector<pii> getd(vector<pii> src, ll m){
    vector<pii> ne;
    sort(src.begin(),src.end());
    ll n=src.size();
    pii prev=src[0];
    pii imm=src[0];
    for(int i=1;i<n;++i){
        if(src[i].fi!=prev.fi){
            if(prev.se<=m)ne.pb(prev);
            if(imm.se>=m && (prev!=imm||prev.se>m))ne.pb(imm);
            prev=src[i];
        }
        imm=src[i];
    }
    
    if(prev.se<=m)ne.pb(prev);
    if(imm.se>=m && (prev!=imm||prev.se>m))ne.pb(imm);
    
   
    return ne;
}

int main(){
    ll x,y,n;
    cin>>x>>y>>n;
    vector<pii> dat;
    ll a,b;
    for(ll i=0;i<n;++i){
        cin>>a>>b;
        dat.pb({a,b});
    }
    ll m=getmedian(dat);
    ll res=0;
    while(1){
        vector<pii> g=getd(dat,m);
        ll mm=getmedian(dat);
        if(mm=m){
            for(auto el:g){
                res+=2*abs(el.se-mm);
            }
            res+=x-1;
            break;
        };
        m=mm;
    }
    cout<<res<<"\n";
    return 0;
}
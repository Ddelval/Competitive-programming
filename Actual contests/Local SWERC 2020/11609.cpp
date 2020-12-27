#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

ll mod=1000000007;
ll binexp(ll n){
    if(n==1)return 2;
    if (n==0) return 1;
    ll h= binexp(n/2);
    h=(h*h)%mod;
    if(n%2){
        h=(h*2)%mod;
    }

    return h;
}

int main(){
    int t;
    cin>>t;
    int z=1;
    while(t--){
        ll n;
        cin>>n;
        ll res= (n*binexp(n-1))%mod;
        cout<<"Case #"<<z<<": "<<res<<"\n";
        z++;

    }
    return 0;
}
//  1337-C.cpp
//  Created by David del Val on 16/04/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;


vector<vi> adyList;
int seen[200000];
int dep[200000];
vi child;
vi mark;
int n,k;

void search(int node,int depth){
    if(seen[node])return;
    
    dep[node]=depth;
    seen[node]=1;
    for(auto ch: adyList[node]){
        search(ch,depth+1);
        if(seen[ch]==2){
            child[node]+=child[ch]+1;
        }
    }
    
    seen[node]=2;
}

ll count(int node,int accum){
    ll ret=0;
    if(seen[node])return 0;

    seen[node]=1;
    if(mark[node])ret+=accum;
    for(auto ch:adyList[node]){
        if(!mark[node])ret+=count(ch,accum+1);
        else ret+=count(ch,accum);
    }
    return ret;
}
int main(){
    cin>>n>>k;
    int a,b;
    adyList= vector<vi>(n,vi());
    child=vi(n,0);
    mark=vi(n,0);
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        adyList[a-1].push_back(b-1);
        adyList[b-1].push_back(a-1);
    }
    for(int i=0;i<n;++i){
        seen[i]=0;
        child[i]=0;
    }
    search(0,0);
    vector<pii> v(n);
    for(int i=0;i<n;++i){
        v[i]=mp(dep[i]-child[i],i);
    }
    sort(all(v),greater<pii>());
    for(int i=0;i<k;++i){
        mark[v[i].se]=1;
    }
    for(int i=0;i<n;++i){
        seen[i]=0;
    }
    cout<<count(0,0)<<"\n";


    return 0;
}
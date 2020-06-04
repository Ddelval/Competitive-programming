//  1354-D.cpp
//  Created by David del Val on 03/06/2020
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


int n,q;
vi dat;
vi op;
int re2[2];
bool check(int x){
    //cout<<"Checking "<<x<<endl;
    int rel[2]={0,0};
    for_each(all(dat),[&rel,x](auto a){rel[a>x]++;});
    //cout<<rel[0]<<" "<<rel[1]<<endl;
    for(auto ins:op){
        //cout<<"Operation " <<ins<<endl;
        if(ins<0){
            if(-ins<=rel[0])rel[0]--;
            else rel[1]--;
        }
        else{
            rel[ins>x]++;
        }
        //cout<<rel[0]<<" "<<rel[1]<<endl;
    }
    return rel[0]>0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    dat=vi(n);
    op=vi(q);
    for(int i=0;i<n;++i)cin>>dat[i];
    for(int i=0;i<q;++i)cin>>op[i];
    int r=n+1;
    int l=0;
    if(!check(r)){
        cout<<"0\n";
        return 0;
    }
    while(r-l>1){
        int mid=(r+l)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<"\n";
    return 0;
}
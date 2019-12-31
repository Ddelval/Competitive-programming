//  7
//	main.cpp
//  Created by David del Val on 31/12/2019
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
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}
#define REPO(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) for(int i=0;i<b;i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<double>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;


int main(){
    ios::sync_with_stdio(false);
    ll n,p;
    while(cin>>n>>p){
        ll cnt=0;
        ll ma=0;
        ll a;
        for(int i=0;i<n;++i){
            cin>>a;
            if(a+ma>p){
                ma=min(a,ma);
                continue;
            }
            cnt++;
            ma=max(a,ma);
        }
        cout<<cnt<<"\n";
    }

    return 0;
}

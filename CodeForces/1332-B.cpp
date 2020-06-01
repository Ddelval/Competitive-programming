//  1332-B.cpp
//  Created by David del Val on 10/04/2020
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

int primes[]={2,3,5,7,11,13,17,19,23,29,31};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi dat(n);
        vi used(12,false);
        int ma=0;
        int a;
        for(int i=0;i<n;++i){
            cin>>a;
            for (int j=0;j<11;++j){
                if(a%primes[j]==0){
                    dat[i]=j+1;
                    ma=max(ma,j+1);
                    used[j+1]=true;
                    break;
                }
            }
        }
        int corr=0;
        map<int,int> num;
        for (int i=1;i<=ma;++i){
            if(used[i]){
                num[i]=i-corr;
            }
            else{
                corr++;
            }
        }
        cout<<ma-corr<<"\n";
        for(int i=0;i<n;++i){
            if(i)cout<<" ";
            cout<<num[dat[i]];
        }
        cout<<"\n";
    }
    
    return 0;
}
//  1330-A.cpp
//  Created by David del Val on 08/04/2020
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

bool marked[200];

int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<200;++i)marked[i]=false;
        int n,x;
        cin>>n>>x;
        vi dat(n);
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            a--;
            marked[a]=true;
        }
        int i;
        for(i=0;i<200;++i){
            if(marked[i])continue;
            else{
                if(x==0){
                    break;
                }
                x--;
                
            }
        }
        cout<<i<<"\n";
    }
    
    return 0;
}
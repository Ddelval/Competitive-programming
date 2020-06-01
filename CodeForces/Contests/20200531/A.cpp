//  A.cpp
//  Created by David del Val on 31/05/2020
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


int main(){
    
    int n,x;
    int t;
    cin>>t;
    for(int w=0;w<t;++w){
        cin>>n>>x;
        int even=0;
        int odd=0;
        int a;
        for(int i=0;i<n;++i){
            cin>>a;
            if(a%2==0)even++;
            else odd++;
        }

        
        if(odd==0){
            cout<<"No\n";
            continue;
        }

        odd--;
        x--;
        x-=2*min(x/2,odd/2);
        if(x<=even){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        
    }
    
    return 0;
}
//  1327-B.cpp
//  Created by David del Val on 12/04/2020
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_set<int> s;
        int nm=-1;
        int km=-1;
        for(int i=0;i<n;++i){
            int l;
            cin>>l;
            int a;
            bool married=false;
            for(int j=0;j<l;++j){
                cin>>a;
                if(!married){
                    if(s.count(a)==0){
                        married=true;
                        s.insert(a);
                    }
                }
            }
            if(!married){
                nm=i;
            }
        }
        if(nm!=-1){
            for(int i=1;i<=n;++i){
                if(!s.count(i)){
                    km=i;
                }
            }
            cout<<"IMPROVE\n";
            cout<<nm+1<<" "<<km<<"\n";
        }
        else{
            cout<<"OPTIMAL\n";
        }

    }
    
    return 0;
}
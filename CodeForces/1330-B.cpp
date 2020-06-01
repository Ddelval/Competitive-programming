//  1330-B.cpp
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


bool check(int pos, vi &dat){
    set<int> s1;
    for(int i=0;i<pos;++i){
        if(s1.count(dat[i])){
            return false;
        }
        s1.insert(dat[i]);
    }
    s1.clear();

    for(int i=pos;i<dat.size();++i){
        if(s1.count(dat[i])){
            return false;
        }
        s1.insert(dat[i]);
    }
    if(*max_element(dat.begin(),dat.begin()+pos)!=pos){
        return false;
    }
    if(*max_element(dat.begin()+pos,dat.end())!=dat.size()-pos){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi dat(n);
        for(int i=0;i<n;++i){
            cin>>dat[i];
        }
       vi sols;
       int ma = *max_element(dat.begin(),dat.end());
       if(check(ma,dat)){
           sols.pb(ma);
       }
       if(n-ma!=ma&&check(n-ma,dat)){
            sols.pb(n-ma);
       }

        cout<<sols.size()<<"\n";
        for(int i:sols) cout<<i<<" "<<n-i<<"\n";
    }
    
    return 0;
}
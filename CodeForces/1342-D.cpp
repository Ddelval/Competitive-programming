//  1342-D.cpp
//  Created by David del Val on 11/06/2020
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
inline pii operator + (pii a, pii b){
    return {a.fi+b.fi,a.se+b.se};
}

inline ostream& operator << (ostream& o, pii p){
    o<<p.fi<<" "<<p.se;
    return o;
}

template<typename>
struct is_std_vector : std::false_type {};
template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

template <typename T>
inline ostream& operator << (ostream& o, vector<T> &p){
    for(int i=0;i<p.size();++i){
        o<<setw(3)<<p[i];
        if(is_std_vector<T>::value)o<<"\n";
    }
    return o;
}



#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    vi data(n);
    for(int i=0;i<n;++i)cin>>data[i];
    vi lims(k);
    for(int i=0;i<k;++i)cin>>lims[i];
    vi presums(k);
    sort(all(data));
    for(int i=n-1;i>=0;--i){
        presums[data[i]-1]++;
    }
    for(int i=k-2;i>=0;--i) presums[i]+=presums[i+1];

    int sol=1;
    for(int i=0;i<k;++i){
        sol=max(sol,(int) ceil(double(presums[i])/lims[i]));
    }
    vector<vi> testcases(sol,vi());

    for(int i=0;i<n;++i) testcases[i%sol].pb(data[i]);

    cout<<sol<<"\n";
    for(int i=0;i<sol;++i){
        cout<< testcases[i].size();
        for(int j=0;j<testcases[i].size();++j){
            cout<<" ";
            cout<<testcases[i][j];
        }
        cout<<"\n";
    }
    
    return 0;
}
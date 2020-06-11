//  1348-C.cpp
//  Created by David del Val on 10/06/2020
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
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int> m;
        for(char c:s)m[c]++;
        
        sort(all(s));
        int countfirst=1;
        while(countfirst<n && s[countfirst]==s[countfirst-1])countfirst++;
        if(countfirst<k){
            cout<<s[k-1]<<"\n";
            continue;
        }
        
        if(m.size()==1){
            string res="";
            for(int i=0;i<(n/k+(n%k!=0));++i)res+=s[0];
            cout<<res<<"\n";
        }
        else if(m.size()==2 && m.begin()->se==k){
            string res="";
            for(auto c:m){
                res+=string(c.se/k+(c.se%k!=0),c.fi);
            }
            cout<<res<<"\n";
        }
        else{
            cout<<s.substr(k-1,n-k+1)<<"\n";
        }
    }
    return 0;
}
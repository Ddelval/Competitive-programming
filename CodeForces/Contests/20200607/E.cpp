//  E.cpp
//  Created by David del Val on 07/06/2020
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


/*
#ifdef _LOCAL_
//Local constraints
const int bitsize=6;
#else
// Judge constraints
const int bitsize=62;
#endif*/

vl dat;
const int bitsize=62;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    dat=vl(n);
    for(int i=0;i<n;++i)cin>>dat[i];
    sort(all(dat));
    int maxbit=0;
    for(int i=0;i<bitsize;++i){
        if(dat[n-1]& (1LL<<i))maxbit=i;
    }
    set<int> seq;
    for(int i=n-1;i>=0;--i){
        if(dat[i] &(1LL<<maxbit))seq.insert(i);
    }
    /*cout<<"seq: ";
    for(auto a:seq)cout<<a<<" ";
    cout<<"\n";
*/
    ll value=dat[n-1];
    vi occur(bitsize,0);
    for(auto v:seq){
        for(int i=0;i<bitsize;++i){
            if(dat[v] &(1LL<<i))occur[i]++;
        }
    }
    //cout<<"occur"<<occur<<"\n";
    
    for(int i=0;i<n;++i){
        if(seq.count(i))continue;
        for(int j=i+1;j<n;++j){
            if(seq.count(j))continue;
            ll currval=0;
            vi occur2(bitsize,0);
            for(int z=0;z<bitsize;++z){
                if(dat[i] &(1LL<<z))occur2[z]++;
                if(dat[j] &(1LL<<z))occur2[z]++;
            }
            for(int w=0;w<bitsize;++w){
                if(occur[w]+occur2[w]>=max(1,(int)seq.size())){
                    currval+=(1LL<<w);
                }
            }
            value=max(value,currval);
        }

        ll currval=0;
        vi occur2(bitsize,0);
        for(int z=0;z<bitsize;++z){
            if(dat[i] &(1LL<<z))occur2[z]++;
        }
        for(int w=0;w<bitsize;++w){
            if(occur[w]+occur2[w]>=max(1,(int)seq.size()-1)){
                currval+=(1LL<<w);
            }
        }
        value=max(value,currval);
    }

    ll currval=0;
    for(int w=0;w<bitsize;++w){
        if(occur[w]>=max(1,(int)seq.size()-2)){
            currval+=(1LL<<w);
        }
    }
    value=max(value,currval);

    cout<<value<<"\n";


    return 0;
}
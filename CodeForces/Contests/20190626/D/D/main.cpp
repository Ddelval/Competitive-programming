//  D
//    main.cpp
//  Created by David del Val on 26/06/2019
//
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <string.h>
#include <limits.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

void ECHO(string _s){cout<<endl;(void)_s;}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    unsigned _i; string _s2="";
    for(_i=0;_i<_s.length();++_i){if(_s[_i]==',')break;if(_s[_i]!=' ')_s2+=_s[_i];}
    if(_i==_s.length()){--_i;}cout<<"  ("<<_s2<<"):"<<x;
    ECHO(_s.substr(_i+1, _s.length()-_i-1), args...);
}


template<typename T0, typename T1>
inline ostream& operator << (ostream& os, pair<T0, T1>& p){
    return os << "(" << p.first << ", " << p.second <<")";
}

template <typename T>
inline ostream& operator << (ostream& os, vector<T>& v){
    for(unsigned i = 0; i < v.size(); ++i){cout << v[i] << "_";}cout<<endl;
    return os;
}

template<typename T> inline T _min(T x1, T x2, T x3){return min(x1, min(x2, x3));}
template<typename T> inline T _min(T x1, T x2, T x3, T x4){return min(min(x1, x2), min(x2, x3));}

//gcd(0, n) = n
inline int _gcd(int a, int b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    for(int z=0;z<q;++z){
        int n,a;
        cin>>n;
        vi v;
        vector<int> v2;
        v.assign(n+1, 0);
        for(int i=0;i<n;++i){
            cin>>a;
            v[a]++;
        }
        v2.reserve(n);
        for(int i=1;i<=n;++i){
            if(v[i])v2.pb(v[i]);
        }
        sort(v2.begin(),v2.end());
        int prev=INT_MAX,tot=0;
        for(int i=((int)v2.size())-1;i>=0;--i){
            if(v2[i]>=prev){
                prev--;
                if(prev<=0)break;
                tot+=prev;
            }
            else{
                prev=v2[i];
                tot+=prev;
            }
        }
        cout<<tot<<"\n";
        
    }
    
    
    return 0;
}

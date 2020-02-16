//  1181-D
//	main.cpp
//  Created by David del Val on 25/06/2019
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
#define LIM 500002
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll output[LIM];
int accum[LIM];
vector<vector<int>> works;
priority_queue<pii,vector<pii>,greater<pii>> name;
vector<pll> que;
vector<int> res;
stack<int> aux;
int main(){
    ios::sync_with_stdio(false);
    int M,n,m,q;
    int a;
    M=-1;
    cin>>n>>m>>q;
    for(int i=0;i<n;++i){
        cin>>a;
        accum[a-1]++;
    }
    vector<int> v;
    works.assign(n+3, v);
    for(int i=0;i<m;++i){
        a=accum[i];
        M=max(M,a);
        works[a].pb(i);
    }
    for(int i=0;i<n+3;++i){
        if(!works[i].empty()){
            sort(works[i].begin(), works[i].end());
        }
    }
    ll b;
    que.reserve(q);
    for(ll i=0;i<q;++i){
        cin>>b;
        b-=n;
        que.pb(mp(b,i));
    }
    int index=1;
    int pos=0;
    sort(que.begin(),que.end());
    auto it=que.begin();
    vector<int> aa=works[0];
    while(pos!=M){
        while(aa.size()+index>it->first){
            output[it->second]=aa[it->first-index];
            it++;
            if(it==que.end())break;
        }
        index+=aa.size();
        if(it==que.end())break;
        if(works[pos+1].size()==0){
            pos++;
            continue;
        }
        
        vector<int> w;
        w.resize(aa.size()+works[pos+1].size());
        merge(works[pos+1].begin(), works[pos+1].end(), aa.begin(), aa.end(), w.begin());
        aa=w;
        pos++;
    }
    while(it!=que.end()){
        output[it->second]=(it->first-index)%m;
        it++;
    }
    for(int i=0;i<q;++i){
        cout<<output[i]+1<<"\n";
    }
    

    return 0;
}


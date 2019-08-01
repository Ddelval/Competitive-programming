//  1196-F
//	main.cpp
//  Created by David del Val on 25/07/2019
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

#define LIM 802
ll ady[LIM][LIM];
int main(){
    ios::sync_with_stdio(false);
    vector<pair<int,pii>> rawin;
    int n,m,k;
    cin>>n>>m>>k;
    int a,b,c;
    rawin.reserve(m);
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        rawin.pb((mp(c,mp(a,b))));
    }
    sort(rawin.begin(), rawin.end());
    set<int> nodes;
    int lim=min(m,k);
    for(int i=0;i<lim;++i){
        nodes.insert(rawin[i].se.fi);
        nodes.insert(rawin[i].se.se);
    }
    map<int,int> map;
    int i=0;
    for(auto it=nodes.begin();it!=nodes.end();it++){
        map[*it]=i;
        i++;
    }
    int a1,a2;
    for(int i=0;i<LIM;++i){
        for(int j=0;j<LIM;++j){
            ady[i][j]=LLONG_MAX/3;
        }
    }
    for(int i=0;i<lim;++i){
        a1=map[rawin[i].se.fi];
        a2=map[rawin[i].se.se];
        ady[a1][a2]=rawin[i].fi;
        ady[a2][a1]=rawin[i].fi;
        /*for(int a=0;a<n;++a){
            for(int b=0;b<n;++b){
                printf("%.10lld ",ady[a][b]);
            }
            printf("\n");
        }
        printf("\n\n");*/
    }
    int l=nodes.size();
    for(int z=0;z<l;++z){
        for(int i=0;i<l;++i){
            for(int j=0;j<l;++j){
                if(i!=j&&ady[i][j]>ady[i][z]+ady[z][j]){
                    ady[i][j]=ady[i][z]+ady[z][j];
                }
            }
        }
    }
    vector<ll> costs;
    for(int i=0;i<l;++i){
        for(int j=0;j<i;++j){
            costs.pb(ady[i][j]);
        }
    }
    sort(costs.begin(),costs.end());
    cout<<costs[k-1];


    return 0;
}


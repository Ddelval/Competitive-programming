// UVa Online Judge 793: Network Connections
//  0793
//	main.cpp
//  Created by David del Val on 01/08/2019
//
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
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
#define REP(i,a,b) for(int i=a;i<b;++i)
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
#define parent(x) subsets[(x)].parent
#define rank(x) subsets[(x)].rank
struct subset {
    int parent,rank;
};
vector<subset>subsets;
int find(int i){
    while(parent(i)!=parent(parent(i))){
        parent(i)=parent(parent(i));
    }
    return parent(i);
}
void Union(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px==py)return;
    if(rank(px)>rank(py)){
        parent(py)=parent(px);
    }
    else if(rank(px)<rank(py)){
        parent(px)=parent(py);
    }
    else{
        parent(py)=parent(px);
        rank(px)++;
    }
}
void start(int n){
    subsets=vector<subset>(n);
    for(int i=0;i<n;++i){
        parent(i)=i;
        rank(i)=1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    string s;
    int q;
    getline(cin,s);
    q=stoi(s);
    getline(cin,s);
    for(int z=0;z<q;++z){
        int n;
        getline(cin,s);
        n=stoi(s);
        start(n);
        int yes=0;
        int no=0;
        while(getline(cin,s)&&s!=""){
            char t;
            int a, b;
            stringstream ss;
            ss.str(s);
            ss>>t>>a>>b;
            if(t=='c'){
                Union(a-1,b-1);
            }
            else{
                if(find(a-1)==find(b-1)){
                    yes++;
                }
                else{
                    no++;
                }
            }
        }
        cout<<yes<<","<<no<<"\n";
        if(z!=q-1)cout<<"\n";
    }
    
    return 0;
}


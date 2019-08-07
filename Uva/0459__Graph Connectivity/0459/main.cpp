// UVa Online Judge 459: Graph_Connectivity
//  0459
//	main.cpp
//  Created by David del Val on 01/08/2019
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

struct Subset{ int parent,rank,size;};

vector<Subset> subsets;
int n;
int find(int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(int x,int y){
    int px=find(x);
    int py=find(y);
    
    if(subsets[px].rank<subsets[py].rank){
        subsets[px].parent=subsets[py].parent;
        //subsets[py].size+=subsets[px].size;
    }
    else if(subsets[px].rank>subsets[py].rank){
        subsets[py].parent=subsets[px].parent;
        //subsets[px].size+=subsets[py].size;
    }
    else{
        subsets[py].parent=subsets[px].parent;
        //subsets[px].size+=subsets[py].size;
        subsets[px].rank++;
    }
}
void init(int nn){
    n=nn;
    subsets=vector<Subset>(n);
    for(int i=0;i<n;++i){
        subsets[i].parent=i;
        subsets[i].rank=1;
        subsets[i].size=1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int q;
    string s;
    getline(cin,s);
    q=stoi(s);
    getline(cin,s);
    for(int z=0;z<q;++z){
        getline(cin,s);
        char c=s[0];
        init(c-'A'+1);
        while(getline(cin,s)&&s!=""){
            Union(s[0]-'A', s[1]-'A');
        }
        int count;
        set<int> ssss;
        for(int i=0;i<n;++i)find(i);
        for(Subset s:subsets) ssss.insert(s.parent);
        cout<<ssss.size()<<"\n";
        if(z!=q-1)cout<<"\n";
    }


    return 0;
}


//  D1
//	main.cpp
//  Created by David del Val on 17/07/2019
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

#define lim 100005
#define CT 998244353
int n;
string dat[lim];
ll sum(int na){
    ll su=0;
    int index= (int)dat[0].length()-na/2-1;
    for(int i=0;i<n;++i){
        su+=dat[i][index];
    }
    su-=n*'0';
    su=su*n;
    return su;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>dat[i];
    }
    ll pval=0;
    ll carry=0;
    ll cval=0;
    ll buff=0;
    string total;
    for(int i=0;i<dat[0].length()*2;++i){
        if(i%2)cval=pval;
        else cval=sum(i);
        buff=cval;
        cval+=carry;
        total+=(cval%10)+'0';
        carry=cval/10;
        pval=buff;
    }
    string a=to_string(carry);
    reverse(a.begin(),a.end());
    total+=a;
    reverse(total.begin(),total.end());
    ll finres=0;
    int half=(int)total.length()/2;
    finres+=stoll(total.substr(half,total.length()-half))%CT;
    string a1=total.substr(0,half);
    ll a2=stoll(a1)%CT;
    ll a3=(ll)pow(10,total.length()-half)%CT;
    finres+=(a2*a3)%CT;
    cout<<finres%CT;

    return 0;
}


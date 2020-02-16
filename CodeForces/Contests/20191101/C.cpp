//  C
//	main.cpp
//  Created by David del Val on 01/11/2019
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
#define LSB(x) ((x) & (-(x)))
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}
#define REPO(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) for(int i=0;i<b;i++)

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
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
long mm=1e9+7;
ll fib[100009];
void fill(){
    fib[0]=1;
    fib[1]=1;
    for(int i=2
        ;i<100009;i++){
        fib[i]=(fib[i-1]+fib[i-2])%mm;
    }
}
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    fill();
    int n=(int)s.length();
    for(int i=0;i<n;++i){
        if(s[i]=='m'||s[i]=='w'){
            cout<<"0";
            return 0;
        }
    }
    int cnt=0;
    ll tot=1;
    for(int i=1;i<n;++i){
        if(s[i]=='u'&&s[i-1]=='u'){
            if(!cnt)cnt=2;
            else cnt++;
        }
        else if(s[i]=='n'&&s[i-1]=='n'){
            if(!cnt)cnt=2;
            else cnt++;
        }
        else{
            tot*=fib[cnt];
            tot%=mm;
            cnt=0;
        }
    }
    tot*=fib[cnt];
    tot%=mm;
    cnt=0;
    cout<<tot;
    return 0;
}



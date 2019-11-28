//  1260-D
//	main.cpp
//  Created by David del Val on 28/11/2019
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
int m,n,k,t;
vi soldiers;
vector<pair<pair<int,int>,int>> traps;
bool check(int agil){
    int fpos=0;
    int ipos=INT_MAX;
    for( auto a:traps){
        if(a.se>agil){
            fpos=max(fpos,a.fi.se);
            ipos=min(ipos,a.fi.se);
        }
    }
    if(ipos=INT_MAX)ipos=0;
    
    //cout<<agil<<" "<<2*fpos+n<<"\n";
    return 2*(fpos-ipos)+n+1<=t;
}

int main(){
    ios::sync_with_stdio(false);
    
    cin>>m>>n>>k>>t;
    soldiers=vi(m);
    REP(i,m)cin>>soldiers[i];
    sort(all(soldiers));
    traps=vector<pair<pair<int,int>,int>>(k);
    int a,b,c;
    REP(i,k){
        cin>>a>>b>>c;
        traps[i]={{a,b},c};
    }
    int l,r;
    l=0;
    r=m-1;
    if(check(soldiers[l])){
        cout<<m<<"\n";
        return 0;
    }
    if(!check(soldiers[r])){
        cout<<"0\n";
        return 0;
    }
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(soldiers[mid])) r=mid;
        else l=mid;
    }
    cout<<m-r<<"\n";

    return 0;
}



//  C
//	main.cpp
//  Created by David del Val on 06/10/2019
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
vi dat;
vl sus;
ll k;
ll a,b,x,y;
ll mcm;
ll sums(ll index){
    index--;
    if(index<0)return 0;
    if(index>=sus.size())return sus.back();
    else return sus[index];
}
bool check(ll ind){
    ll tot=0;
    bool sw=false;;
    ll i1=(ind/mcm);
    tot+=sums(i1)*(x+y);
    ll i2=(ind/a);
    ll i3=(ind/b);
    if(x<y){
        swap(i2,i3);
        swap(x,y);
        sw=true;
    }
    tot+=(sums(i2)-sums(i1))*x;
    
    tot+=(sums(i3+i2-i1)-sums(i2))*y;
    if(sw)swap(x,y);
    return tot>=k;
}

int main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        dat=vi(n);
        int aa;
        for(int i=0;i<n;++i){cin>>aa; dat[i]=aa/100;}
        sort(all(dat),greater<int>());
        sus=vl(n);
        sus[0]=dat[0];
        for(int i=1;i<n;++i)sus[i]=dat[i]+sus[i-1];
        int r,l;
        cin>>x>>a>>y>>b>>k;
        mcm=a*b;
        mcm/=_gcd(a,b);
        r=n;
        l=0;
        if(!check(r)){
            cout<<"-1\n";
            continue;
        }
        while(r-l>1){
            int mid=(r+l)/2;
            if(check(mid))r=mid;
            else l=mid;
        }
        cout<<r<<"\n";
    }

    return 0;
}



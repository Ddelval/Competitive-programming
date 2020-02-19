//  1301-D
//	main.cpp
//  Created by David del Val on 16/02/2020
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
#define REP(i,n) for(int i=0;i<n;i++)

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


int main(){
    
    int n,m,k;
    cin>>n>>m>>k;

    if(k>4*m*n-2*n-2*m){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    string spat;
    spat="DUL";
    vector<pair<int,string>> steps;
    int mv=k;
    int nmv;
    for(int w=0;w<n;++w){
        nmv=min(mv, m-1);
        if(nmv)steps.pb({nmv,"R"});
        mv-=nmv;
        if(mv==0)break;
        if(w==n-1){
            nmv=min(mv,m-1);
            if(nmv)steps.pb({nmv,"L"});
            mv-=nmv;
            break;
        }
        nmv=min(mv, (m-1)*3);
        if((nmv)/3)steps.pb({(nmv)/3,"DUL"});
        if((nmv)%3)steps.pb({1,spat.substr(0,nmv%3)});
        mv-=nmv;
        if(mv==0)break;
        
        steps.pb({1,"D"});
        mv-=1;
        if(mv==0)break;
    }
    if(mv!=0){
        steps.pb({mv,"U"});
    }
    
    cout<<steps.size()<<"\n";
    for(auto a:steps){
        cout<<a.fi<<" "<<a.se<<"\n";
    }


    return 0;
}
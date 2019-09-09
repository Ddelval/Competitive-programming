//  C
//	main.cpp
//  Created by David del Val on 22/08/2019
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


int main(){
    ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--){
		ll n,a,b;
		ll cheight;
		cin>>n>>a>>b;
		string road;
		cin>>road;
		int pi=0;
		int i=0;
		ll cost=0;
		while(i<road.length()&&road[i]=='0'){
			i++;
		}
		if(i==road.length()){
			cout<<n*a+b*(n+1)<<"\n";
			continue;
		}
		cost+=(i-1)*a+i*b+2*a;
		
		while(true){
			pi=i;
			while(road[i]=='1'){
				i++;
			}
			cost+=(i-pi+1)*2*b+(i-pi)*a;
			int i2=i;
			while(i2<road.length()&&road[i2]=='0'){
				i2++;
			}
			if(i2==road.length()){
				cost+=2*a+(i2-i-1)*a+b*(i2-i);
				break;
			}
			else{
				ll c1=LLONG_MAX;
				if(i2-i-2>=0)c1=4*a+(i2-i-2)*a+(i2-i-1)*b;
				ll c2= (i2-i)*a+2*b*(i2-i-1);
				cost+=min(c1,c2);
			}
			i=i2;
		}
		cout<<cost<<"\n";
	}

    return 0;
}



//  D
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
const ll mo=998244353;
ll fact[300000];
ll calfact(ll n){
	if(fact[n])return fact[n];
	int i=0;
	while(fact[i])i++;
	for(;i<=n;++i){
		fact[i]=((i%mo)*(fact[i-1]%mo))%mo;
	}
	return fact[n];
}
int main(){
	ios::sync_with_stdio(false);
	fact[0]=1;
	vii dat;
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		dat.pb(mp(a,b));
	}
	sort(all(dat));
	ll orseq1=1;
	int counter=0;
	for(int i=1;i<dat.size();++i){
		if(dat[i].fi!=dat[i-1].fi){
			if(counter){
				orseq1*=calfact(counter+1);
				orseq1%=mo;
				counter=0;
			}
		}
		else counter++;
	}
	if(counter){
		orseq1*=calfact(counter+1);
		orseq1%=mo;
		counter=0;
	}
	sort(all(dat),[](pii a,pii b){
		return a.se<b.se;
	});
	ll orseq2=1;
	for(int i=1;i<dat.size();++i){
		if(dat[i].se!=dat[i-1].se){
			if(counter){
				orseq2*=calfact(counter+1);
				orseq2%=mo;
				counter=0;
			}
		}
		else counter++;
	}
	if(counter){
		orseq2*=calfact(counter+1);
		orseq2%=mo;
		counter=0;
	}
	sort(all(dat));
	bool bb=true;
	for(int i=1;i<dat.size();++i){
		if(dat[i].se<dat[i-1].se){
			bb=false;
			break;
		}
	}
	ll orboth=0;
	if(bb){
		orboth=1;
		for(int i=1;i<dat.size();++i){
			if(dat[i].fi!=dat[i-1].fi||dat[i].se!=dat[i-1].se){
				if(counter){
					orboth*=calfact(counter+1);
					orboth%=mo;
					counter=0;
				}
			}
			else counter++;
		}
		if(counter){
			orboth*=calfact(counter+1);
			orboth%=mo;
			counter=0;
		}
	}
	ll res=calfact(n);
	res=(((res-orseq1+mo)%mo-orseq2+mo)%mo+orboth)%mo;
	cout<<res;
	return 0;
}



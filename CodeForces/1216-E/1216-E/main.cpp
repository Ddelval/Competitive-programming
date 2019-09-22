//  1216-E
//	main.cpp
//  Created by David del Val on 21/09/2019
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
ll prevsum[]={
	0,45,9045,1395495,189414495,23939649495,
	2893942449495,339393974949495,38939394344949495,4393939398494949495
};
ll prevres[]={
	0,9,
	189,
	2889,
	38889,
	488889,
	5888889,
	68888889,
	788888889,
	8888888889,
	98888888869
};
//Length of sequence up to k
ll calculate(ll k){
	if(!k)return 0;
	if(k==1)return 1;
	int dig=(int)ceil(log10(k+1));
	ll bas=pow(10,dig-1);
	ll prev=prevres[dig-1];
	ll res=((k-bas+1)*(prev)+dig*((k-bas+1)*(k-bas+2))/2);
	return res+prevsum[dig-1];
}

int main(){
    ios::sync_with_stdio(false);
	/*ll a=0;
	ll prevre=0;;	ll au=0;
	for(int i=1;i<11;++i){
		prevre=prevres[i-1]+i*(pow(10,i)-2-pow(10,(i-1)));
		cout<<prevre<<"\n";
	}*/
	int q;
	cin>>q;
	while(q--){
		ll k;
		cin>>k;
		ll r=999999999ll;
		ll l=0;
		while(r-l>1){
			ll mid=(r+l)/2;
			if(calculate(mid)<k)l=mid;
			else r=mid;
		}
		ll target=r;
		k-=calculate(target-1);
		//cout<<calculate(target-1)<<"\n"<<calculate(target)<<"\n";
		int dig=1;
		while(k-prevres[dig]>0)dig++;
		ll increment=-1;
		if(dig){
			k-=prevres[dig-1];
			increment=(k-1)/dig;
			k-=increment*dig;
			
		}
		string a=to_string((ll)pow(10,dig-1)+increment);
		cout<<a[k-1]<<"\n";
	}
	

    return 0;
}



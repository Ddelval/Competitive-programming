//  1083-E
//	main.cpp
//  Created by David del Val on 01/09/2019
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

struct rect{
	ll p,q;
	ll a;
	rect (ll x,ll y,ll a){
		this->a=a;
		this->p=x;
		this->q=y;
	}
	bool operator <(const rect & ab) const{
		if(p<ab.p)return true;
		return false;
	}
};

struct line{
	ll m,c;
	ll eval (ll x){
		return m*x+c;
	}
	long double intersectX(line l){
		return (long double)(c-l.c)/(l.m-m);
	}
};
int main(){
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<rect> rects;
	ll x,y,a;
	REP(i,n){
		cin>>x>>y>>a;
		rects.pb(rect(x,y,a));
	}
	sort(all(rects));
	
	vector<line> dq;
	dq.push_back({0,0});
	ll ans=0;
	vi ints(n);
	iota(ints.begin(),ints.end(),0);
	for(int i=0;i<n;++i){
		/*
		 We remove lines as long as the next line gives us a higher value for this x.
		 We can do this because the querries are sorted
		 
		 while(dq.size()>=2&&dq.back().eval(rects[i].q)<=dq[dq.size()-2].eval(rects[i].q)){
		 	dq.pop_back();
		 }
		 In a more general case:
		 */
		int idx=*lower_bound(ints.begin(), ints.begin()+dq.size()-1, rects[i].q, [&dq](int idx,int x){
			return dq[idx].intersectX(dq[idx+1])>x;
		});
		
		ll f=dq[idx].eval(rects[i].q)+rects[i].p*1LL*rects[i].q-rects[i].a;
		ans=max(ans,f);
		line cur={-rects[i].p,f};
		/*
		 We are inserting new lines, if the new intersection point is to the right,
		 the last line is useless
		 We can do this because the lines are sorted by slope
		 */
		while(dq.size()>=2&&cur.intersectX(dq[dq.size()-1])>=dq[dq.size()-1].intersectX(dq[dq.size()-2])){
			dq.pop_back();
		}
		dq.push_back(cur);
	}
	cout<<ans;

    return 0;
}



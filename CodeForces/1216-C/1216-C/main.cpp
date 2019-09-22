//  1216-C
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
struct rect{
	pii low;
	pii high;
};
rect intersect(rect r1,rect r2){
	rect res;
	res.low.fi=max(r1.low.fi,r2.low.fi);
	res.low.se=max(r1.low.se,r2.low.se);
	res.high.fi=min(r1.high.fi,r2.high.fi);
	res.high.se=min(r1.high.se,r2.high.se);
	//if(res.high.fi<res.low.fi)swap(res.high.fi,res.low.fi);
	//if(res.high.se<res.low.se)swap(res.low.se,res.high.se);
	return res;
}
ll area(rect inter3){
	return (inter3.high.fi-inter3.low.fi)*(inter3.high.se-inter3.low.se);
}
bool wrong(rect a){
	return a.low.fi>a.high.fi||a.low.se>a.high.se;
}
int main(){
    ios::sync_with_stdio(false);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	rect white={{a,b},{c,d}};
	cin>>a>>b>>c>>d;
	rect b1={{a,b},{c,d}};
	cin>>a>>b>>c>>d;
	rect b2={{a,b},{c,d}};
	
	rect inter1=intersect(white,b1);
	
	rect inter2=intersect(white,b2);
	if(wrong(inter1)&&!wrong(inter2)){
		if(inter2.low==white.low&&inter2.high==white.high)cout<<"NO";
		else cout<<"YES";
		return 0;
	}
	
	else if(wrong(inter2)&&!wrong(inter1)){
		if(inter1.low==white.low&&inter1.high==white.high)cout<<"NO";
		else cout<<"YES";
		return 0;
	
	}
	else if(wrong(inter1)&&wrong(inter2)){
		cout<<"YES";
		return 0;
		
	}
	ll ar=0;
	rect inter3=intersect(inter1, inter2);
	if(wrong(inter3))ar=0;
	else ar=area(inter3);
	if(area(white)==area(inter1)+area(inter2)-ar){
		cout<<"NO";
	}
	else cout<<"YES";
    return 0;
}



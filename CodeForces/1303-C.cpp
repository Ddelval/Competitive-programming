//  1303-C
//  Created by David del Val on 20/02/2020
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

string dfs(int sss, int parent,set<int> ady[]){
    string s;
    s.push_back((char)('a'+sss));
    for(auto a:ady[sss]){
        if(a==parent)continue;
        
        s=s+dfs(a,sss,ady);
    }
    return s;
}


int main(){
    
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<int> ady[28];
        for(int i=1;i<s.length();++i){
            ady[s[i-1]-'a'].insert(s[i]-'a');
            ady[s[i]-'a'].insert(s[i-1]-'a');
        }
        int sss=-1;
        bool b=false;
        for(int i=0;i<28;++i){
            if(ady[i].size()==1)sss=i;
            if(ady[i].size()>2)b=true;
        }
        if(sss==-1&&s.length()==1){
            sss=s[0]-'a';
        }
        if(b||sss==-1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        string sa=dfs(sss,-1,ady);
        ady[s[0]-'a'].insert(s[0]);
        for(int i=0;i<26;++i){
            if(ady[i].size()==0)sa.pb('a'+i);
        }
        cout<<sa<<"\n";

    }
        
    return 0;

}
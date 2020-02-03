//  D
//	main.cpp
//  Created by David del Val on 14/12/2019
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
map<string,int> m;


pair<bool,vi> obtain(set<string> &exclude, set<string> &src, int num){
    int cnt=0;
    vi dat;
    if(cnt==num){
        return {true,dat};
    }
    for(string s:src){
        string s1=s;
        reverse(all(s1));
        if(!exclude.count(s1)){
            dat.pb(m[s]);
            cnt++;
        }
        if(cnt==num)break;
    }
    return {cnt==num,dat};
}
void finish(pair<bool,vi> r){
    cout<<r.se.size()<<"\n";
    bool b=false;
    for(auto a:r.se){
        if(b)cout<<" ";
        cout<<a;
        b=true;
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int cnt00,cnt11,cnt10,cnt01;
        cnt00=cnt11=cnt10=cnt01=0;
        set<string> s10,s01;
        m.clear();
        
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            if(s[0]=='0'&&s[(int)s.length()-1]=='0')cnt00++;
            if(s[0]=='1'&&s[(int)s.length()-1]=='1')cnt11++;
            if(s[0]=='0'&&s[(int)s.length()-1]=='1'){
                cnt01++;
                s01.insert(s);
                m[s]=i+1;
            }
            if(s[0]=='1'&&s[(int)s.length()-1]=='0'){
                cnt10++;
                s10.insert(s);
                m[s]=i+1;
            }
        }
        
        vector<vi> vvec;
        // 00 01 11 10 01 ...
        if(cnt01){
            int l=n-cnt00-cnt11-1;
            int n10,n01;
            n10=ceil (l/2.0);
            n01=floor(l/2.0)+1;
            if(n10>=cnt10){
                auto r=obtain(s10, s01, n10-cnt10);
                if(r.fi) vvec.pb(r.se);
            }
            if(n01>=cnt01){
                auto r=obtain(s01, s10, n01-cnt01);
                if(r.fi) vvec.pb(r.se);
            }
        }
        
        
        //11 10 00 01 10 ...
        if(cnt10){
            int l=n-cnt00-cnt11-1;
            int n10,n01;
            n10=floor (l/2.0)+1;
            n01=ceil  (l/2.0);
            if(n10>=cnt10){
                auto r=obtain(s10, s01, n10-cnt10);
                if(r.fi) vvec.pb(r.se);
                
            }
            if(n01>=cnt01){
                auto r=obtain(s01, s10, n01-cnt01);
                if(r.fi) vvec.pb(r.se);
            
            }
        }
        
        if(vvec.size()){
            sort(all(vvec),[](vi a,vi b){
                return a.size()<b.size();
            });
            finish({1,vvec[0]});
            continue;
        }
        
        // 00 00 ...
        if(cnt00&&!cnt11&&!cnt10&&!cnt01){
            cout<<"0\n";
            continue;
        }
        // 11 11 ...
        if(cnt11&&!cnt00&&!cnt10&&!cnt01){
            cout<<"0\n";
            continue;
        }
        cout<<"-1\n";
    }

    return 0;
}



//  C
//	main.cpp
//  Created by David del Val on 24/07/2019
//
//


#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <string.h>
#include <limits.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second
#define echobin(x) cout<<#x<<":"<<x<<" ="<<bitset<8>(x)<<"  ";
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );}

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
inline int _gcd(int a, int b){ while(b) b %= a ^= b ^= a ^= b; return a;}

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
    ios::sync_with_stdio(false);
    ll q;
    cin>>q;
    for(int z=0;z<q;++z){
        int n;
        cin>>n;
        int X,x,Y,y;
        X=Y=100000;
        x=y=-100000;
        bool fail=false;
        for(int i=0;i<n ;++i){
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            if(c&&d&&e&&f)continue;
            if(c&&d&&e){
                if(b>Y){
                    fail=true;
                }
                y=max(y,b);
                continue;
            }
            if(c&&e&&f){
                if(b<y){
                    fail=true;
                }
                Y=min(Y,b);
                continue;
            }
            if(d&&e&&f){
                if(a>X){
                    fail=true;
                }
                x=max(x,a);
                continue;
            }
            if(d&&c&&f){
                if(a<x){
                    fail=true;
                }
                X=min(X,a);
                continue;
            }
            if(d&&e){
                if(a>X){
                    fail=true;
                }
                if(b>Y){
                    fail=true;
                }
                //
                //
                x=max(x,a);
                y=max(y,b);
                continue;
            }
            if(f&&e){
                if(a>X){
                    fail=true;
                }
                if(b<y){
                    fail=true;
                }
                //X=min(X,a);
                x=max(x,a);
                //y=max(y,b);
                Y=min(Y,b);
                continue;
            }
            if(f&&c){
                if(a<x){
                    fail=true;
                }
                if(b<y){
                    fail=true;
                }
                X=min(X,a);
                //x=max(x,a);
                //y=max(y,b);
                Y=min(Y,b);
                continue;
            }
            if(c&&d){
                if(a<x){
                    fail=true;
                }
                if(b>Y){
                    fail=true;
                }
                //X=min(X,a);
                X=min(X,a);
                y=max(y,b);
                //Y=min(Y,b);
                continue;
            }
            if(c&&e){
                if(b<y||b>Y)fail=true;
                y=b;
                Y=b;
                continue;
            }
            if(d&&f){
                if(a<x||a>X)fail=true;
                x=a;
                X=a;
                continue;
            }
            if(c){
                if(b<y||b>Y)fail=true;
                if(a<x){
                    fail=true;
                }
                y=b;
                Y=b;
                X=min(X,a);
                continue;
            }
            if(e){
                if(b<y||b>Y)fail=true;
                if(a>X){
                    fail=true;
                }
                y=b;
                Y=b;
                x=max(x,a);
                continue;
            }
            if(d){
                if(a<x||a>X)fail=true;
                if(b>Y)fail=true;
                x=a;
                X=a;
                y=max(y,b);
                continue;
            }
            if(f){
                if(a<x||a>X)fail=true;
                if(b<y)fail=true;
                x=a;
                X=a;
                Y=min(Y,b);
                continue;
            }
            if(a<x||a>X)fail=true;
            if(b<y||b>Y)fail=true;
            x=a;
            X=a;
            y=b;
            Y=b;
        }
        if(fail){
            cout<<"0\n";
        }
        else{
            cout<<"1 "<<x<<" "<<y<<"\n";
        }
        
    }


    return 0;
}


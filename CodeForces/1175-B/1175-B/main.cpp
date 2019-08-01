//  1175-B
//	main.cpp
//  Created by David del Val on 28/06/2019
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
ll x;
ll lim;
bool over;
struct Command{
    int a;
    //a=0: for
    //a=1: end
    //a=2: add
    //a=3: void
    int aux;
    //times for loop
    Command(int a,int b){
        this->a=a;
        this->aux=b;
    }
    Command(){

    }
};
vector<Command> data;
void loop(int n, int ipos){
    int it;
    for(int i=0;i<n;++i){
        it=ipos;
        while(data[it].a!=1){
            if(data[it].a==0){
                loop(data[it].aux,it+1);
                while(data[it].a!=1)it++;
            }
            else if(data[it].a==2){
                x++;
                if(x>lim){
                    over=true;
                    return;
                }
            }
            it++;
        }
        if(over)return;
    }
}


int main(){
    ios::sync_with_stdio(false);
    x=0;
    string s;
    over=false;
    lim=(ll)pow(2,32)-1;
    Command c;
    int n,a;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        if(s=="add"){
            c=Command(2,0);
        }
        else if(s=="for"){
            cin>>a;
            c=Command(0,a);
        }
        else if(s=="end"){
            c=Command(1,0);
        }
        data.push_back(c);
    }
    c=Command(1,0);
    data.push_back(c);
    loop(1, 0);
    cout<<x;

    return 0;
}


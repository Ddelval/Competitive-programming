//  1370-C.cpp
//  Created by David del Val on 22/06/2020
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
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator + (pii a, pii b){
    return {a.fi+b.fi,a.se+b.se};
}

inline ostream& operator << (ostream& o, pii p){
    o<<p.fi<<" "<<p.se;
    return o;
}

template<typename>
struct is_std_vector : std::false_type {};
template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

template <typename T>
inline ostream& operator << (ostream& o, vector<T> &p){
    for(int i=0;i<p.size();++i){
        o<<setw(3)<<p[i];
        if(is_std_vector<T>::value)o<<"\n";
    }
    return o;
}



#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

bool powdos(int n){
    while(n%2==0)n=n/2;
    return n==1;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string r1="FastestFinger\n";
    string r2="Ashishgup\n";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<r1;
            continue;
        }
        if(n==2 || n%2==1){
            cout<<r2;
            continue;
        }
        if(powdos(n)){
            cout<<r1;
            continue;
        }
        if((n/2)%2==0){
            cout<<r2;
            continue;
        }
        else{
            int div=-1;
            int r=n/2;
            for(int i=3;i<=sqrt(r);++i){
                if(r%i==0){
                    div=i;
                    break;
                }
            }
            if(div==-1){
                cout<<r1;
                continue;
            }
            else{
                cout<<r2;
            }
        }
    }
    
    return 0;
}
//  1341-B.cpp
//  Created by David del Val on 18/06/2020
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
const int lim=2e5+10;
int mont[lim];
int peak[lim];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;++i)cin>>mont[i];

        /*cout<<"mont"<<endl;
        for(int i=0;i<n;++i)cout<<mont[i]<<" ";
        cout<<endl;*/
        for(int i=1;i<n-1;++i){
            bool p=false;
            if(mont[i-1]<mont[i]&& mont[i]>mont[i+1])p=true;
            peak[i]=peak[i-1]+p;
            
        }
        /*for(int i=0;i<n+2;++i)cout<<peak[i]<<" ";
        cout<<endl;
*/
        ll parts=0;
        ll index=0;
        for(int l=0;l+k-1<n;++l){
            if(peak[l+k-2]-peak[l]>parts){
                parts=peak[l+k-2]-peak[l];
                index=l;
            }
        }
        cout<<parts+1<<" "<<index+1<<"\n";

    }
    
    return 0;
}
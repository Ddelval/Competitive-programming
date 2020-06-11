//  1348-D.cpp
//  Created by David del Val on 10/06/2020
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


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll counter=1;
        ll sum=0;
        vl dat;
        while(sum+counter<=n){
            //cout<<sum<<" "<<counter<<endl;
            dat.pb(counter);
            sum+=counter;
            counter*=2;
        }
        if(n-sum)dat.pb(n-sum);
        sort(all(dat));
        //cout<<dat<<endl;
        vl result;
        for(int i=1;i<dat.size();++i){
            result.pb(dat[i]-dat[i-1]);
        }
        if(dat.size()==1)cout<<"1\n0\n";
        else{
            cout<<result.size()<<"\n";
            for(int i=0;i<result.size();++i){
                if(i)cout<<" ";
                cout<<result[i];
            }
            cout<<"\n";
        }
    }
    
    return 0;
}
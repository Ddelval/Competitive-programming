//  B.cpp
//  Created by David del Val on 04/06/2020
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

int rel[1025][1025];
int n;
int res=0;
vi elements;
bool taken[1025];
bool test(int pos,int val){
    //cout<<"Searching: "<<pos<<" "<<val<<"\n";
    if(pos>=n)return true;
    if(taken[pos])return test(pos+1,val);
    taken[pos]=true;
    for(int i=pos+1;i<n;++i){
        //cout<<pos<<" "<<i<<" "<<rel[pos][i]<<"\n";
        if(!taken[i] && rel[pos][i]==val){
            taken[i]=true;
            //cout<<pos<<" "<<i<<"\n";
            if(test(pos+1,val)){
                res=val;
                taken[pos]=false;
                taken[i]=false;
                return true;
                
            }
            taken[i]=false;
        }
    }
    taken[pos]=false;
    return false;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        elements=vi(n);
        for(int i=0;i<n;++i)cin>>elements[i];

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                rel[i][j]=elements[i] ^ elements[j];
            }
        }
        bool done=false;
        for(int i=1;i<=1024;++i){
            //cout<<"Testing: "<<rel[0][i]<<"\n";
            if(test(0,i)){
                done=true;
                break;
            }
        }
        if(done){
            cout<<res<<"\n";
        }
        else{
            cout<<"-1\n";
        }

    }
    return 0;
}
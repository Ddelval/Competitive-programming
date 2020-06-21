//  1367-E.cpp
//  Created by David del Val on 21/06/2020
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



vector<int> cycleLengths(int m, int k){
    auto lengths=vi();
    auto adyList= vector<vi>(m,vi());
    auto visited=vi(m,0);

    for(int i=0;i<m;++i){
        if(visited[i])continue;

        int j= (i+k)%m;
        visited[i]=true;
        lengths.push_back(0);
        lengths.back()++;
        while(!visited[j]){
            lengths.back()++;
            visited[j]=true;
            j=(j+k)%m;
        }
    }
    return lengths;

    


}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        vi beads(30);
        int n,k;
        cin>>n>>k;

        for(int i=0;i<n;++i){
            char c;
            cin>>c;
            beads[c-'a']++;
        }

        for(int i=n;i>0;--i){
            vi cycles= cycleLengths(i,k);
            //cout<<i<<": "<<cycles<<endl;
            priority_queue<int,vi,less<int>> pq;
            for(int i=0;i<30;++i)pq.push(beads[i]);

            bool canfill=true;
            sort(all(cycles));
            while(!cycles.empty()){
                if(pq.top()<cycles.back()){
                    canfill=false;
                    break;
                }
                else{
                    int a=pq.top();pq.pop();
                    pq.push(a-cycles.back());
                    cycles.pop_back();
                }
            }
            if(canfill){
                cout<<i<<endl;
                break;
            }

        }
    }
    
    
    return 0;
}
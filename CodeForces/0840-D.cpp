//  0849-D.cpp
//  Created by David del Val on 05/06/2020
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

template <typename T>
struct WaveletTree{
    using it= typename vector<T>::iterator;

    // Components
    vector<T> vec;
    int lo=0, hi=0;
    
    WaveletTree *l =nullptr, *r=nullptr;

    //Destructor
    ~WaveletTree(){
        if(l)delete l;
        if(r)delete r;
    }

    //Constructor
    WaveletTree() = default;
    WaveletTree(vector<T>&&ve): WaveletTree(ve.begin(),ve.end(),*min_element(all(ve)),*max_element(all(ve))){ }

    WaveletTree(it from, it to, int lo, int hi){
        this->lo=lo;
        this->hi=hi;
        int mid= (lo+hi)/2;
        vec.reserve(to-from+1);
        vec.push_back(0);
        auto f=[mid](int x){return x<=mid;};
        for_each(from,to,[&](auto el){ vec.push_back(vec.back()+ f(el));});
        if(lo==hi || from==to) return;

        auto midit=stable_partition(from,to,f);
        this->l=new WaveletTree(from,midit,lo,mid);
        this->r=new WaveletTree(midit,to,mid+1,hi);
    }


    /*
        Number of ocurrences of y in A[l] ... A[r]
    */
    int count(int l, int r, T y){
        if(l>r)return 0;
        r++; // Internally consider open interval [l, r)
        if(lo == hi){
            if(lo == y) return vec[r]-vec[l];
            else return 0;
        }
        else{
            int mid=(lo+hi)/2;
            if(y<=mid) return this->l->count(vec[l],vec[r]-1,y); //-1 -> Close the interval again
            else       return this->r->count(l-vec[l],r-vec[r]-1,y);

        }
    }
    //Find the k-th smallest element in positions [l,r]
    T quantile (int k, int l, int r){
        if(this->lo==this->hi)return this->lo;

        r++; // internally consider open interval on the right [l, r)
        int c= vec[r]-vec[l];
        if(k<=c) return this->l->quantile(k,vec[l],vec[r]-1);//-1 -> Close the interval again
        else     return this->r->quantile(k,l-vec[l],r-vec[r]-1)

    }
    int solve (int l, int r, int k){
        if(r-l+1<k)return INT_MAX/2; //Not enough elements
        if(lo==hi) return lo;
        else{
            return min( this->l->solve(vec[l],vec[r+1]-1,k),
                        this->r->solve(l-vec[l],r-vec[r+1],k));
        }
    }

};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    vi data(n);
    for(int i=0;i<n;++i)cin>>data[i];
    WaveletTree<int> wav(move(data));
    int l,r,k;
    for(int i=0;i<q;++i){
        cin>>l>>r>>k;
        l--;
        r--;
        int sol=wav.solve(l,r,(r-l+1)/k+1);
        if(sol==INT_MAX/2)cout<<"-1\n";
        else cout<<sol<<"\n";
    }


    return 0;
}

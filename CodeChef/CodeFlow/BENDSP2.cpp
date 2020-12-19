//  BENDSP2.cpp
//  Created by David del Val on 14/11/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

template <typename T, typename Q>
inline ostream& operator<<(ostream& o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
   private:
    template <typename X>
    static auto check(X const& x) -> decltype(x.begin());
    static subs_fail check(...);

   public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream&> operator<<(ostream& o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    T a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// ====================================================== //
// ================== Pairs operations ================== //
// ====================================================== //
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream& operator<<(ostream& o, pair<T, Q> p) {
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}


ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int oddInRange(int a,int b){
    if(b<a)
        swap(a, b);

    int r = (b - a + 1) / 2;

    if(r*2==(b-a+1)){
        return r;
    }
    else if (a%2){
        return r + 1;
    }
    else{
        return r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vl hs;
    hs = readVector<ll>(n);
    int q;
    cin >> q;
    ll vals[2];
    vals[0] = vals[1] = 0;
    for (int i = 0; i < n;++i){
        vals[(i+1)%2]+=hs[i];
    }
    while(q--){
        ll a, b, c;
        cin >> a;
        if(a==1){
            cin >> a >> b >> c;

            ll codd = (oddInRange(a, b));

            vals[0] += (b - a + 1 - codd) * c;
            vals[1] += codd * c;
        }
        else if(a==2){
            cout << vals[1] << "\n";
        }
        else{
            cout << vals[0] << "\n";
        }
    }

        return 0;
}
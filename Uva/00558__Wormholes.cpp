//  00558__Wormholes.cpp
//  Created by David del Val on 22/12/2020
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
inline ostream &operator<<(ostream &o, pair<T, Q> p);

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
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
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
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

bool hasNegCycle(vector<pair<pii, int>> edges, int n) {
    vi dist(n, INT_MAX / 10);

    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            dist[e.fi.se] = min(dist[e.fi.se], dist[e.fi.fi] + e.se);
        }
    }
    bool negativeCycle = false;
    for (auto e : edges) {
        if (dist[e.fi.se] > min(dist[e.fi.se], dist[e.fi.fi] + e.se)) {
            negativeCycle = true;
        }
    }
    return negativeCycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        using vppi = vector<pair<pii, int>>;
        vppi adyList;
        int a, b, c;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            adyList.push_back({{a, b}, c});
        }
        bool hasC=hasNegCycle(adyList, n);
        if(!hasC){
            cout << "not possible\n";
        }
        else{
            cout << "possible\n";
        }
    }

    return 0;
}
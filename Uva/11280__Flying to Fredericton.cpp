//  11280__Flying to Fredericton.cpp
//  Created by David del Val on 23/12/2020
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
    o << "(" << p.fi << " " << p.se << ")";
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

int iinf = INT_MAX / 10;
vi costs(vector<pair<pii, int>> edges, int n, vi queries) {
    vi dists(n, iinf);
    vi dists2(n, iinf);
    vi costs;
    dists[0] = 0;

    auto it = queries.begin();
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            dists2[e.fi.se] = min(dists2[e.fi.se], dists[e.fi.fi] + e.se);
        }
        if (it != queries.end() && i == *it) {
            costs.push_back(dists2[n - 1]);
            it++;
        }
        dists = dists2;
    }
    while(it!=queries.end()){
        costs.push_back(dists2[n - 1]);
        it++;
    }
    return costs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int z = 1;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> cities;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            cities.insert({s, i});
        }
        int m;
        cin >> m;
        vector<pair<pii, int>> edges;
        string t;
        int a;
        for (int i = 0; i < m; ++i) {
            cin >> s >> t >> a;
            edges.pb({{cities[s], cities[t]}, a});
        }
        int q;
        cin >> q;
        vi queries = readVector<int>(q);
        vi q2 = queries;
        sort(all(queries));

        vi c = costs(edges, n, queries);

        map<int, int> ma;
        for (int i = 0; i < q; ++i) {
            ma[queries[i]] = c[i];
        }
        if (z != 1)
            cout << "\n";

        cout << "Scenario #" << z++ << "\n";
        for (auto a : q2) {
            a = ma[a];
            if (a == iinf) {
                cout << "No satisfactory flights\n";
            } else {
                cout << "Total cost of flight(s) is $" << a << "\n";
            }
        }
    }

    return 0;
}
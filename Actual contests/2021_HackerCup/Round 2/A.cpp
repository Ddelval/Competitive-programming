//  A.cpp
//  Created by David del Val on 25/09/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

#ifdef DEBUG
#define db(x) x
#define echo(x) cout << #x << ": " << x << endl;
#else
#define db(x)
#define echo(x)
#endif

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

template <typename T> struct subs_succeeded : std::true_type {};
template <> struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T> struct get_iter_res {
private:
    template <typename X> static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <> struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T> struct get_termination {
    static constexpr const char *get() { return sep1; }
};
template <typename U, typename S> struct get_termination<vector<U, S>> {
    static constexpr const char *get() { return sep2; }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator =
                get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll> inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) { return {a.fi + b.fi, a.se + b.se}; }

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

// gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int z = 1;
    while (t--) {
        int n, m;
        cin >> m >> n;

        vector<ll> changes = vl(n, 0);
        map<int, vector<pii>> models;

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            models[a].pb({1, i});
        }

        for (int j = 0; j < m; ++j) {
            echo(models);
            db({ cout << "\n"; });
            vi remain;
            map<int, vector<pii>> nextModels;
            for (int i = 0; i < n; ++i) {
                int a;
                cin >> a;
                if (models.count(a) && models[a].size() > 0) {
                    pii &model = models[a].back();
                    echo(model);
                    nextModels[a].pb(model);
                    models[a].pop_back();
                } else {
                    remain.pb(a);
                }
            }
            echo(remain);
            for (auto &vec : models) {
                for (pii elem : vec.se) {
                    nextModels[remain.back()].push_back({0, elem.se});
                    echo(elem.se);
                    changes[elem.se]++;
                    remain.pop_back();
                }
            }
            swap(models, nextModels);

            for (auto &velem : models) {
                sort(all(velem.se), greater<pii>());
            }
        }
        echo(changes);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(changes[i] - 1, 0ll);
        }
        cout << "Case #" << z++ << ": " << ans << "\n";
    }

    return 0;
}
//  1547-G.cpp
//  Created by David del Val on 26/08/2021
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
vector<vi> adyList;
const int lim = 4e5;
int visited1[lim];
int instack[lim];
int visited2[lim];
int visited3[lim];
int from2[lim];
int inloop[lim];
void dfs1(int cnode) {
    visited1[cnode] = true;
    instack[cnode] = true;
    for (auto ady : adyList[cnode]) {
        if (instack[ady]) {
            from2[ady] = true;
            inloop[ady] = true;
        }
        else if (visited1[ady]) {
            from2[ady] = true;
        } else {
            dfs1(ady);
        }
    }
    instack[cnode] = false;
}
void dfs2(int cnode) {
    visited2[cnode] = true;
    for (auto ady : adyList[cnode]) {
        if (!visited2[ady]) {
            dfs2(ady);
        }
    }
}
void dfs3(int cnode) {
    visited3[cnode] = true;
    for (auto ady : adyList[cnode]) {
        if (!visited3[ady]) {
            dfs3(ady);
        }
    }
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
        adyList = vector<vi>(n, vi());
        for (int i = 0; i < n; ++i) {
            visited1[i] = visited2[i] = from2[i] = 0;
            visited3[i] = inloop[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adyList[a].pb(b);
        }
        dfs1(0);
        for (int i = 0; i < n; ++i) {
            if (visited2[i] == 0 && from2[i]) {
                dfs2(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited3[i] == 0 && inloop[i]) {
                dfs3(i);
            }
        }
        vi ans(n);
        for (int i = 0; i < n; ++i) {
            if (visited1[i] == 0) {
                ans[i] = 0;
            } else if (visited2[i] == 0) {
                ans[i] = 1;
            } else if (visited3[i]==0) {
                ans[i] = 2;
            } else {
                ans[i] = -1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
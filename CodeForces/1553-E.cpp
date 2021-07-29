//  1553-E.cpp
//  Created by David del Val on 28/07/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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
namespace UFDS {
const int lim = 3 * 10e5;
int parent[lim];
int rankk[lim];

void initialize(int n) {
    for (int i = 0; i < n; ++i) {
        rankk[i] = 0;
        parent[i] = i;
    }
}
int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    if (rankk[pa] > rankk[pb]) {
        parent[pb] = pa;
    } else if (rankk[pa] < rankk[pb]) {
        parent[pa] = pb;
    } else {
        parent[pa] = pb;
        rankk[pb]++;
    }
}
}; // namespace UFDS

int swapsPermutation(vi perm1, vi perm2) {
    int n = perm1.size();
    UFDS::initialize(n + 1);
    int components = n;
    for (int i = 0; i < n; ++i) {
        if (UFDS::find(perm1[i]) != UFDS::find(perm2[i])) {
            components--;
            UFDS::Union(perm1[i], perm2[i]);
        }
    }
    return n - components;
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
        vi matches(n, 0);
        vi data = readVector<int>(n);
        for (int i = 0; i < n; ++i) {
            int perm = (n + 1 - data[i] + i) % n;
            // cout << "s  " << i << " " << perm << "\n";
            matches[perm]++;
        }
        vi sols;
        for (int i = 0; i < n; ++i) {
            if (matches[i] + 2 * m >= n) {
                vi perm2(n, 0);
                for (int j = 1; j <= n; ++j) {
                    perm2[(i + (j - 1)) % n] = j;
                }
                // cout << perm2 << ": " << swapsPermutation(data, perm2) <<
                // endl;
                if (swapsPermutation(data, perm2) <= m) {

                    sols.pb(i);
                }
            }
        }
        cout << sols.size() << " " << sols << "\n";
    }

    return 0;
}
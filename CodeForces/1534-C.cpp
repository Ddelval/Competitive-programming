//  1534-C.cpp
//  Created by David del Val on 19/06/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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
template <>
struct Has_iterator<string> : subs_fail {};

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
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

const int lim = 4 * 1e5;
int parent[lim];
int rankk[lim];

void initialize(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rankk[i] = 1;
    }
}

int findParent(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void Union(int n1, int n2) {
    int p1 = findParent(n1);
    int p2 = findParent(n2);

    if (p1 == p2) {
        return;
    }
    if (rankk[p1] > rankk[p2]) {
        parent[p2] = p1;
    } else if (rankk[p1] < rankk[p2]) {
        parent[p1] = p2;
    } else {
        parent[p1] = p2;
        rankk[p2]++;
    }
}

const ll mod = 7 + 1e9;
ll binaryExp(int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp == 1) {
        return 2;
    }
    ll res = binaryExp(exp / 2);
    res = (res * res) % mod;
    if (exp % 2) {
        res = (res * 2) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi data1 = readVector<int>(n);
        vi data2 = readVector<int>(n);
        initialize(n + 1);
        for (int i = 0; i < n; ++i) {
            Union(data1[i], data2[i]);
        }
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if (parent[i] == i) {
                c++;
            }
        }
        cout << binaryExp(c) << "\n";
    }

    return 0;
}
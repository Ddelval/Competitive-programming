//  1537-B.cpp
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

ll ans;
pll iniPos;
pll items[2];
pll answer[2];
void calculate() {
    ll dist = abs(items[0].fi - iniPos.fi) + abs(items[0].se - iniPos.se);
    dist += abs(items[0].fi - items[1].fi) + abs(items[0].se - items[1].se);
    if (dist > ans) {
        ans = dist;
        answer[0] = items[0];
        answer[1] = items[1];
    }
}
void explore(int depth, vector<pll> &items, vector<bool> &visited) {
    if (depth == 2) {
        calculate();
        return;
    }
    for (int i = 0; i < items.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            ::items[depth] = items[i];
            explore(depth + 1, items, visited);
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
        ll n, m, i, j;
        cin >> n >> m >> i >> j;
        vector<pll> corners = {{1, 1}, {1, m}, {n, 1}, {n, m}};
        vector<bool> visited(4, false);
        ans = 0;
        explore(0, corners, visited);
        cout << answer[0].fi << " " << answer[0].se << " ";
        cout << answer[1].fi << " " << answer[1].se << "\n";
    }

    return 0;
}
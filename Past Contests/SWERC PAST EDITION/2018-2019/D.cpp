//  D.cpp
//  Created by David del Val on 10/02/2021
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
map<int, pii> extremes;
ll cost(int iline) {
    ll c = 0;
    for (auto a : extremes) {
        if (iline > a.se.fi) {
            c += 2 * (iline - a.se.se);
        } else if (iline >= a.se.se) {
            c += 2 * (a.se.fi - a.se.se);
        } else {
            c += 2 * (a.se.fi - iline);
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x, y;
    cin >> x >> y;
    cin >> n;
    vector<pii> dat;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dat.pb({a, b});
    }
    sort(all(dat));
    for (int i = 0; i < n; ++i) {
        if (extremes.count(dat[i].fi) == 0) {
            extremes[dat[i].fi] = {dat[i].se, dat[i].se};
        } else {
            extremes[dat[i].fi] = {max(dat[i].se, extremes[dat[i].fi].fi), min(dat[i].se, extremes[dat[i].fi].se)};
        }
    }
    int l = 0;
    int r = y - 1;
    while (r - l > 2) {
        //cout << l << " " << r << endl;

        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        //cout << m1 << " " << cost(m1) << " " << m2 << " " << cost(m2) << endl;

        if (cost(m1) == cost(m2)) {
            l = m1;
            r = m2;
        } else if (cost(m1) > cost(m2)) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }
    cout << min(cost(l), min(cost(r), cost((l + r) / 2))) + x - 1 << "\n";

    return 0;
}
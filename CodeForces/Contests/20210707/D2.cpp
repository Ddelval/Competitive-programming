//  D2.cpp
//  Created by David del Val on 07/07/2021
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

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
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

vi factorIntoBase(ll a, int base) {

    vi res;
    while (a > 0) {
        res.pb(a % base);
        a /= base;
    }
    reverse(all(res));
    return res;
}
ll fromBase(vi &data, int base) {
    ll exp = 1;
    ll ans = 0;
    for (int i = 0; i < data.size(); ++i) {
        ans += data[i] * exp;
        exp *= base;
    }
    return ans;
}
vi mergeVec(vi &dataNeg, vi &dataPos, int base) {
    int n = max(dataNeg.size(), dataPos.size());
    vi res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        int val = 0;
        if (i < dataNeg.size()) {
            val -= dataNeg[int(dataNeg.size()) - 1 - i];
        }
        if (i < dataPos.size()) {
            val += dataPos[int(dataPos.size()) - 1 - i];
        }
        val = (val % base + base) % base;
        res.pb(val);
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
        int n, k;
        cin >> n >> k;

        ll r;
        bool done = false;
        vi fprev = {0};
        for (ll w = 0; w < n; ++w) {
            if (w) {
                vi fnext = factorIntoBase(w, k);
                vi fres = mergeVec(fprev, fnext, k);
                //cout << w << " - " << fprev << " - " << fnext << " - " << fres << endl;
                fprev = fnext;
                cout << fromBase(fres, k) << "\n";
            } else {
                cout << "0\n";
            }
            cout.flush();
            cin >> r;
            if (r == 1) {
                done = true;
                break;
            }
            if (r == -1) {
                return 0;
            }
        }
        if (!done) {
            return 0;
        }
    }

    return 0;
}
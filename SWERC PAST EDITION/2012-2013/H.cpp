//  H.cpp
//  Created by David del Val on 15/02/2021
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c;

    cin >> c;
    int n, p;
    cin >> n >> p;
    vector<pll> shares;
    ll a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        shares.pb({a, b});
    }
    vl packets_cost;
    vl packets_profit;
    for (int i = 0; i < p; ++i) {
        int r;
        ll cos = 0;
        ll rev = 0;
        cin >> r;
        for (int j = 0; j < r; ++j) {
            cin >> a >> b;
            a--;
            cos += shares[a].fi * b;
            rev += shares[a].se * b;
        }
        rev -= cos;
        if (cos <= c && rev > 0) {
            packets_cost.pb(cos);
            packets_profit.pb(rev);
        }
    }
    //cout << packets_cost << endl;
    //cout << packets_profit << endl;

    map<int, ll> dp;
    dp.insert({packets_cost[0], packets_profit[0]});
    for (int i = 1; i < packets_cost.size(); ++i) {
        auto dp2 = dp;
        if (dp2.count(packets_cost[i]) == 0) {
            dp2[packets_cost[i]] = packets_profit[i];
        } else if (dp2[packets_cost[i]] < packets_profit[i]) {
            dp2[packets_cost[i]] = packets_profit[i];
        }
        for (auto a : dp) {
            if (a.fi + packets_cost[i] <= c) {
                if (dp2.count(a.fi + packets_cost[i]) == 0) {
                    dp2[a.fi + packets_cost[i]] = a.se + packets_profit[i];
                } else if (dp2[a.fi + packets_cost[i]] < a.se + packets_profit[i]) {
                    dp2[a.fi + packets_cost[i]] = a.se + packets_profit[i];
                }
            }
        }
        //cout << "-" << dp2 << endl;
        dp = dp2;
    }
    //cout << dp << endl;
    ll ans = 0;
    for (auto a : dp) {
        ans = max(ans, a.se);
    }
    cout << ans << "\n";

    return 0;
}
//  D.cpp
//  Created by David del Val on 11/02/2022
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
const int lim = 1000 + 1;
ll precalc[lim];
void calculate_cost() {
    for (int i = 0; i < lim; ++i) {
        precalc[i] = inf;
    }
    precalc[1] = 0;
    for (int i = 1; i <= lim; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i + i / j >= lim) {
                continue;
            }
            precalc[i + i / j] = min(precalc[i + i / j], precalc[i] + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    calculate_cost();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi cost(n);
        vi value(n);
        ll total_cost = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            cost[i] = precalc[a];
            total_cost += cost[i];
        }
        ll total_value = 0;
        for (int i = 0; i < n; ++i) {
            cin >> value[i];
            total_value += value[i];
        }
        echo(cost);
        echo(value);
        if (total_cost <= k) {
            cout << total_value << "\n";
            continue;
        }
        total_cost = k;
        vi best(total_cost + 1, 0);
        for (int i = 0; i < n; ++i) {
            vi best2 = best;
            for (int j = 0; j <= total_cost; ++j) {
                if (j + cost[i] <= total_cost) {
                    best2[j + cost[i]] =
                        max(best[j + cost[i]], best[j] + value[i]);
                }
            }
            if (cost[i] < total_cost) {
                best2[cost[i]] = max(best2[cost[i]], value[i]);
            }

            for (int j = 1; j <= total_cost; ++j) {
                best2[j] = max(best2[j], best2[j - 1]);
            }

            swap(best, best2);
            echo(best);
        }
        cout << best[k] << "\n";
    }

    return 0;
}
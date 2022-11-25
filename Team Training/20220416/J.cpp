//  J.cpp
//  Created by David del Val on 16/04/2022
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
const int lim = 200 + 10;

ll costs[lim][lim];
ll accumCosts[lim][lim];
int n;

ll calculateCost(int l, int c, int r) {
    ll ans = 0;
    for (int i = l; i < c; ++i) {
        /*
        for (int j = c; j < n; ++j) {
            ans += costs[i][j];
        }
        for (int j = 0; j < l; ++j) {
            ans += costs[i][j];
        }
        */
        ans += accumCosts[i][n];
        ans -= accumCosts[i][c] - accumCosts[i][l];
    }
    // echo(ans);
    for (int i = c + 1; i <= r; ++i) {
        /*
        for (int j = 0; j <= c; ++j) {
            ans += costs[i][j];
        }
        for (int j = r + 1; j < n; ++j) {
            ans += costs[i][j];
        }
        */
        ans += accumCosts[i][n];
        ans -= accumCosts[i][r + 1] - accumCosts[i][c + 1];
    }

    /*
    cout << "calc: " << l + 1 << " " << c + 1 << " " << r + 1 << ": " << ans
         << endl;
         */
    return ans;
}
ll dp[lim][lim];
ll center[lim][lim];

ll solve(int l, int r) {
    if (r <= l) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    ll ans = inf;

    for (int i = l; i <= r; ++i) {
        // try to make i the center
        ll partial = 0;
        partial += solve(l, i - 1);
        partial += solve(i + 1, r);
        partial += calculateCost(l, i, r);
        if (partial < ans) {
            ans = partial;
            center[l][r] = i;
            /*
            cout << "Adjust " << l + 1 << " " << r + 1 << " " << partial << " "
                 << center[l][r] << "\n";
                 */
        }
    }
    // cout << l + 1 << " " << r + 1 << " " << ans << " " << center[l][r] <<
    // "\n";
    return dp[l][r] = ans;
}

int root[lim];
void setRoots(int prev, int l, int r) {
    if (r < l) {
        return;
    }
    if (l == r) {
        root[l] = prev;
    } else {
        root[center[l][r]] = prev;
        setRoots(center[l][r], l, center[l][r] - 1);
        setRoots(center[l][r], center[l][r] + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> costs[i][j];
            dp[i][j] = -1;
            accumCosts[i][j + 1] = accumCosts[i][j] + costs[i][j];
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += costs[i][j];
        }
        cout << (i + 1) << " " << sum << " " << calculateCost(0, i, n - 1)
             << endl;
    }

    explore(-1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << roots[i] + 1;
    }
    */
    solve(0, n - 1);
    // cout << solve(0, n - 1) << "\n";
    setRoots(-1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << root[i] + 1;
    }
    cout << "\n";

    return 0;
}
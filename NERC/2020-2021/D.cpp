//  1510-D.cpp
//  Created by David del Val on 07/09/2021
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

set<int> lookup[10][10];
const int lim = 1e5;
ll dp[lim][10];
ll accumDigit[lim][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    vl data;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (d % 2 && a % 2 == 0) {
            continue;
        } else if (d % 5 && a % 5 == 0) {
            continue;
        }
        data.pb(a);
    }
    int lDigit = 1;
    vi remDigit(data.size()), preDigit(data.size());
    for (int i = int(data.size()) - 1; i >= 0; i--) {
        remDigit[i] = lDigit;
        lDigit *= data[i];
        lDigit %= 10;
    }
    lDigit = 1;
    for (int i = 0; i < data.size(); i++) {
        preDigit[i] = lDigit;
        lDigit *= data[i];
        lDigit %= 10;
    }
    if (lDigit == d && data.size() != 0) {
        cout << data.size() << "\n" << data << "\n";
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int resDigit = (i * j) % 10;
            lookup[resDigit][i].insert(j);
            lookup[resDigit][j].insert(i);
        }
    }

    for (int i = 0; i < lim; ++i) {
        for (int j = 0; j < 10; ++j) {
            dp[i][j] = inf;
        }
    }
    map<pii, pii> previous;
    set<pii> removed;

    pii last = {-1, -1};
    for (int i = 0; i < data.size(); ++i) {
        if (i) {
            for (int j = 0; j < 10; ++j) {
                accumDigit[i][j] = (accumDigit[i - 1][j] * data[i]) % 10;
                dp[i][j] = dp[i - 1][j];
                if (dp[i][j] < inf) previous[{i, j}] = {i - 1, j};
            }
            for (int j = 0; j < 10; ++j) {
                int next = (accumDigit[i - 1][j] * remDigit[i]) % 10;
                if (dp[i][next] > dp[i - 1][j] * data[i]) {
                    dp[i][next] = dp[i - 1][j] * data[i];
                    accumDigit[i][next] = accumDigit[i - 1][j];
                    removed.insert({i, next});
                    previous[{i, next}] = {i - 1, j};
                }
            }
        }
        int opt = (preDigit[i] * remDigit[i]) % 10;
        if (dp[i][opt] > data[i]) {
            dp[i][opt] = data[i];
            accumDigit[i][opt] = preDigit[i];
            removed.insert({i, opt});
            previous[{i, opt}] = {-1, -1};
        }

        if ((last == pii(-1, -1) && dp[i][d] < inf) ||
            (last != pii(-1, -1) && dp[i][d] < dp[last.fi][last.se])) {
            last = {i, d};
        }
    }

    echo(data);
    echo(lDigit);
    echo(previous);
    if (last == pii{-1, -1}) {
        cout << "-1\n";
    } else {
        set<int> skipped;
        while (last != pii{-1, -1}) {
            if (removed.count(last)) skipped.insert(last.fi);
            last = previous[last];
            // echo(last);
        }
        vi sol;
        for (int i = 0; i < data.size(); ++i) {
            if (!skipped.count(i)) {
                sol.pb(data[i]);
            }
        }
        cout << sol.size() << "\n" << sol << "\n";
    }

    return 0;
}
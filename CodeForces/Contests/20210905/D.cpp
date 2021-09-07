//  D.cpp
//  Created by David del Val on 05/09/2021
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

pii conv(ll a) {
    ll cnt = 0;
    while (a % 10 == 0) {
        a /= 10;
        cnt++;
    }
    return {a % 10, cnt};
}
ll inverse(pii rec) {
    ll multi = 1;
    while (rec.se--) {
        multi *= 10;
    }
    return rec.fi * multi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> s >> n;
        reverse(all(s));
        ll base = 1;
        ll counted = 0;
        ll accum = 0;
        vector<vi> elems(10, vi());
        for (int i = 0; i < int(s.length()); ++i) {
            if (s[i] != '0') {
                echo(i);
                if (counted == n - 1) {
                    accum += (s[i] - '0') * base;
                    echo(accum);
                } else {
                    elems[i].pb(s[i] - '0');
                    counted++;
                }
                db(cout << "hi> " << counted << endl);
            }
            base *= 10;
        }
        vi res;
        echo(accum);
        if (accum) {
            res.pb(accum);
            counted++;
        }
        echo(counted);
        if (counted < n) {
            for (int i = 0; i < 10; ++i) {
                int j = 0;
                while (j < elems[i].size()) {
                    if (elems[i][j] != 1) {
                        elems[i][j]--;
                        elems[i].pb(1);
                        counted++;
                    } else {
                        j++;
                    }
                    if (counted == n) {
                        break;
                    }
                }
                if (counted == n) {
                    break;
                }
            }
        }
        if (counted < n) {
            int i = 1, j = int(elems[i].size()) - 1;

            while (elems[i].empty()) {
                i++;
                j = int(elems[i].size()) - 1;
            }
            while (counted < n) {
                db(cout << i << " " << j << endl);
                echo(elems);
                if (elems[i][j] > 1) {
                    elems[i][j]--;
                    elems[i].push_back(1);
                    counted++;
                } else if (j > 0) {
                    j--;
                } else if (i != 0) {
                    elems[i].pop_back();
                    elems[i - 1].push_back(9);
                    elems[i - 1].push_back(1);
                    counted++;
                    i--;
                    j = int(elems[i].size()) - 1;
                    echo("hi");

                } else {
                    do {
                        i++;
                        j = int(elems[i].size()) - 1;
                    } while (elems[i].empty());
                }
            }
        }
        base = 1;
        for (int i = 0; i < 10; ++i) {
            for (auto el : elems[i]) {
                res.pb(el * base);
            }
            base *= 10;
        }
        cout << res << "\n";
    }

    return 0;
}
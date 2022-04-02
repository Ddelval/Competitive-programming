//  C.cpp
//  Created by David del Val on 12/02/2022
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi datt = readVector<int>(n);
        bool pos = false;
        for (int i = 1; i < n - 1; ++i) {
            if (datt[i] != 1) {
                pos = true;
            }
        }
        if (n == 3 && datt[1] % 2) {
            pos = false;
        }
        if (!pos) {
            cout << "-1\n";
            continue;
        }
        ll total = 0;
        ll odd = 0;
        ll dif = 0;
        int tran = 0;
        int not1 = 0;
        bool additional = true;
        for (int i = 1; i < n - 1; ++i) {
            total += datt[i];
            odd += datt[i] % 2;
            if (i > 1) {
                if ((datt[i - 1] % 2) ^ (datt[i] % 2)) {
                    tran++;
                }
            }
            not1 += datt[i] != 1;
        }

        if (tran > 2) {
            additional = false;
        } else if (tran == 2 && datt[1] % 2 == 1) {
            additional = false;
        }
        if (not1 > 1) {
            additional = false;
        } else {
            bool found1 = false;
            bool foundother = false;
            for (int i = 1; i < n - 1; ++i) {
                if (datt[i] == 1) {
                    found1 = true;
                    if (foundother) {
                        additional = false;
                        break;
                    }
                } else if (datt[i] % 2) {
                    foundother = true;
                }
            }
        }
        if (odd == 0) {
            cout << total / 2 << "\n";
        } else {
            ll ans = 0;
            if (additional) {
                total--;
                odd--;
                ans++;
            }
            ans += odd / 2;
            if (odd % 2) {
                ans++;
                total--;
            }
            ans += total / 2;
            cout << ans << "\n";
        }
    }

    return 0;
}
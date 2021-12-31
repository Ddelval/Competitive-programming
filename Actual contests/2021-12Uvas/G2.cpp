//  G2.cpp
//  Created by David del Val on 31/12/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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
void print(int y, int m, int d) { printf("%02d/%02d/%04d\n", d, m, y); }

void increase(vi &date) {
    date[0]++;
    if (date[1] == 2) {
        if (date[2] % 4 == 0) {
            if (date[0] == 30) {
                date[0] = 1;
                date[1]++;
                return;
            }
        } else {
            if (date[0] == 29) {
                date[0] = 1;
                date[1]++;
                return;
            }
        }
    } else {
        if (date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 ||
                                      date[1] == 8 || date[1] == 10 ||
                                      date[1] == 12) {
            if (date[0] == 32) {
                date[0] = 1;
                date[1]++;
            }
        } else {
            if (date[0] == 31) {
                date[0] = 1;
                date[1]++;
            }
        }
    }
    if (date[1] == 13) {
        date[1] = 1;
        date[2]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  
    cout.tie(0);
    int d, m, y;
    char c;
    while (cin >> d >> c >> m >> c >> y && (d | m | y)) {
        vi date = vi({d, m, y});
        int yy, mm, dd;
        cin >> yy >> mm >> dd;
        mm += 12 * yy;
        dd += 28 * mm;
        for (int i = 0; i < dd; ++i) {
            increase(date);
        }
        print(date[2], date[1], date[0]);
    }

    return 0;
}
//  1632-D.cpp
//  Created by David del Val on 31/01/2022
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

template <typename T> class SparseTable {
private:
    vector<vector<T>> table;
    std::function<T(T, T)> f;

public:
    SparseTable() {}
    SparseTable(vector<T> &data, std::function<T(T, T)> f) : f(f) {
        int n = data.size();
        table.pb(data);
        for (int j = 1; (1ll << j) <= n; ++j) {
            vector<T> nextRow(n);
            for (int i = 0; i + (1ll << j) <= n; ++i) {
                int otherIndex = i + (1ll << (j - 1));
                nextRow[i] = f(table.back()[i], table.back()[otherIndex]);
            }
            table.push_back(std::move(nextRow));
        }
    }
    static int msb_index(int x) { return __builtin_clz(1) - __builtin_clz(x); }

    T valueInRange(int left, int right) {
        int j = msb_index(right - left + 1);
        ll intervalSize = 1ll << j;
        return f(table[j][left], table[j][right - intervalSize + 1]);
    }
};
int n;
vi datt;
SparseTable<int> sp;

int dif(int i, int j) {
    int dist = j - i + 1;
    int gc = sp.valueInRange(i, j);
    return gc - dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    datt = readVector<int>(n);
    sp = SparseTable<int>(datt, [](int a, int b) { return int(_gcd(a, b)); });

    int changing = 0;
    vi res;
    res.reserve(n);
    int left = 0;
    for (int i = 0; i < n; ++i) {
        bool change = false;
        if (dif(i, i) == 0) {
            change = true;
        } else if (i) {
            int r = i;
            int l = left;
            if (dif(l, i) == 0) {
                change = true;
            } else if (dif(l, i) < 0) {
                while (r - l > 1) {
                    int mid = (r + l) / 2;
                    int val = dif(mid, i);
                    if (val == 0) {
                        change = true;
                        break;
                    } else if (val < 0) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                if (dif(l, i) == 0) {
                    change = true;
                }
                if (dif(r, i) == 0) {
                    change = true;
                }
            }
        }
        if (change) {
            changing += 1;
            left = i+1;
        }
        res.pb(changing);
    }
    cout << res << "\n";

    return 0;
}
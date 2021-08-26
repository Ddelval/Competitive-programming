//  0471-G.cpp
//  Created by David del Val on 13/08/2021
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

template <typename T> vi prefixFun(const T &s, int n) {
    vi res(n);
    for (int i = 1; i < n; ++i) {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = res[j - 1];
        }
        res[i] = j + (s[i] == s[j]);
    }
    return res;
}

template <typename T>
int kmpSearch(const T &text, int n, const T &pattern, int m,
              const vi &patternPre) {

    int count = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = max(0, patternPre[j] - 1);
        }
        j += (text[i] == pattern[j]);
        if (j == m) {
            count++;
            j = patternPre[j - 1];
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi data1(n - 1);
    vi data2(m - 1);
    int prev, a;
    cin >> prev;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        data1[i] = a - prev;
        prev = a;
    }
    cin >> prev;
    for (int i = 0; i < m - 1; ++i) {
        cin >> a;
        data2[i] = a - prev;
        prev = a;
    }
    if (m > n) {
        cout << "0\n";
        return 0;
    }
    if (m == 1) {
        cout << n << "\n";
        return 0;
    }
    echo(data1);
    echo(data2);
    vi prefun = prefixFun(data2, data2.size());
    echo(prefun);
    int res = kmpSearch(data1, data1.size(), data2, data2.size(), prefun);
    cout << res << "\n";

    return 0;
}
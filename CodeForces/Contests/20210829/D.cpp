//  D.cpp
//  Created by David del Val on 29/08/2021
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

int askOr(int i, int j) {
    int ans;
    cout << "or " << i << " " << j << endl;
    cout.flush();
    cin >> ans;
    return ans;
}
int askAnd(int i, int j) {
    int ans;
    cout << "and " << i << " " << j << endl;
    cout.flush();
    cin >> ans;
    return ans;
}

vi group3(int start) {
    vi ors(3);
    ors[0] = askOr(start, start + 1);
    ors[1] = askOr(start + 1, start + 2);
    ors[2] = askOr(start, start + 2);
    vi ands(3);
    ands[0] = askAnd(start, start + 1);
    ands[1] = askAnd(start + 1, start + 2);
    ands[2] = askAnd(start, start + 2);
    vi sums(3);
    for (int i = 0; i < 3; ++i) {
        sums[i] = ors[i] + ands[i];
    }
    int mid = (sums[0] + sums[1] - sums[2]) / 2;
    vi res(3);
    res[0] = sums[0] - mid;
    res[1] = mid;
    res[2] = sums[1] - mid;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vi elems;
    auto ne = group3(1);
    for (auto e : ne) {
        elems.pb(e);
    }
    for (int i = 3; i < n; i++) {
        elems.pb(askAnd(1, i + 1) + askOr(1, i + 1) - elems[0]);
    }
    sort(all(elems));
    echo(elems);
    cout << "finish " << elems[k - 1] << "\n";

    return 0;
}
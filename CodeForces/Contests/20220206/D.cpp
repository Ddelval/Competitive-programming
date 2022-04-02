//  D.cpp
//  Created by David del Val on 06/02/2022
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

vi dat;

int q(int i1, int i2, int i3) {
    int n;
    /*
    cout << "? " << i1 << " " << i2 << " " << i3 << "\n";
    cout.flush();
    cin >> n;
    */
    n = max(dat[i1], max(dat[i2], dat[i3]));
    n -= min(dat[i1], min(dat[i2], dat[i3]));
    return n;
}
pii group4(int i1, int i2, int i3, int i4) {
    vi picked;
    int q1, q2, q3, q4;
    vector<vi> pattern = {
        {i1, i2, i3}, {i1, i3, i4}, {i1, i2, i4}, {i2, i3, i4}};

    q1 = q(i1, i2, i3);
    int ma = q1;
    picked = {i1, i2, i3};

    q2 = q(i1, i3, i4);
    if (q2 > ma) {
        picked = {i1, i3, i4};
        ma = q2;
    }
    q3 = q(i1, i2, i4);
    if (q3 > ma) {
        picked = {i1, i3, i4};
        ma = q3;
    }
    q4 = q(i2, i3, i4);
    if (q4 > ma) {
        picked = {i2, i3, i4};
        ma = q4;
    }
    // picked contains both the max and the min of the array and an element that
    // is in between
    vector qv = {q1, q2, q3, q4};

    set<int> qs;
    qs.insert(q1);
    qs.insert(q2);
    qs.insert(q3);
    qs.insert(q4);
    if (qs.size() == 1) {
        return {i1, -1};
    }
    if (qs.size() == 2) {
        if (q1 == 0) {
            return {i4, i1};
        }
        if (q2 == 0) {
            return {i2, i1};
        }
        if (q3 == 0) {
            return {i3, i1};
        }
        if (q4 == 0) {
            return {i1, i2};
        }
    }
    vi sel;
    set<int> sel2;
    set<int> sel3;
    echo(qv);
    for (int i = 0; i < 4; ++i) {
        if (qv[i] == ma) {
            if (sel2.size() == 0) {
                for (auto a : pattern[i]) {
                    sel2.insert(a);
                }
            } else {
                for (auto a : pattern[i]) {
                    if (sel2.count(a)) {
                        sel3.insert(a);
                    }
                }
                break;
            }
        }
    }
    echo(sel3);
    assert(sel3.size() == 2);
    return {*sel3.begin(), *sel3.rbegin()};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dat = {5, 2, 2, 3, 3, 4, 6, 0, 6};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi indices;
        for (int i = 0; i < n; ++i) {
            indices.pb(i);
        }
        cout << group4(3,4,6,8) << endl;
    }

    return 0;
}
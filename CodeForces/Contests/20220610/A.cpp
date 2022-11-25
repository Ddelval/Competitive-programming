//  A.cpp
//  Created by David del Val on 10/06/2022
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
        int n, m, k;
        cin >> n >> m >> k;
        string s1, s2;
        cin >> s1 >> s2;
        sort(all(s1));
        sort(all(s2));
        reverse(all(s1));
        reverse(all(s2));
        string res;
        int last = -1;
        int same_count = 0;
        echo(s1);
        echo(s2);

        while (true) {
            if (s1.empty() || s2.empty()) {
                break;
            } else {
                echo(last);
                echo(same_count);
                echo(res);
                echo(s1);
                echo(s2);
                if (s1.back() == s2.back()) {
                    if (last == 1) {
                        last = 2;
                        res += s2.back();
                        s2.pop_back();
                    } else {
                        last = 1;
                        res += s1.back();
                        s1.pop_back();
                    }
                    same_count = 1;
                } else if (s1.back() < s2.back()) {
                    if (last == 1 && same_count == k) {
                        last = 2;
                        same_count = 1;
                        res += s2.back();
                        s2.pop_back();
                    } else {
                        same_count = 1 + same_count * (last == 1);
                        last = 1;
                        res += s1.back();
                        s1.pop_back();
                    }
                } else {
                    if (last == 2 && same_count == k) {
                        last = 1;
                        same_count = 2;
                        res += s1.back();
                        s1.pop_back();
                    } else {
                        same_count = 1 + same_count * (last == 2);
                        last = 2;
                        res += s2.back();
                        s2.pop_back();
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
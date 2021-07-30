//  1536-B.cpp
//  Created by David del Val on 02/07/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

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

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

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
        string s;
        cin >> s;
        set<char> elemns;
        for (auto a : s) {
            elemns.insert(a);
        }
        bool done = false;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (elemns.count(c) == 0) {
                cout << c << "\n";
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }
        for (char c1 = 'a'; c1 < 'z'; ++c1) {
            for (char c2 = 'a'; c2 < 'z'; ++c2) {
                string ss;
                ss.pb(c1);
                ss.pb(c2);
                if (s.find(ss) == string::npos) {
                    cout << ss << "\n";
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
        }
        if (done) {
            continue;
        }
        for (char c1 = 'a'; c1 < 'z'; ++c1) {
            for (char c2 = 'a'; c2 < 'z'; ++c2) {
                for (char c3 = 'a'; c3 < 'z'; ++c3) {
                    string ss;
                    ss.pb(c1);
                    ss.pb(c2);
                    ss.pb(c3);
                    if (s.find(ss) == string::npos) {
                        cout << ss << "\n";
                        done = true;
                        break;
                    }
                }
                if (done) {
                    break;
                }
            }
            if (done) {
                break;
            }
        }
    }

    return 0;
}
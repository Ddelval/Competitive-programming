//  1560-E.cpp
//  Created by David del Val on 22/08/2021
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
        string s;
        cin >> s;
        vi occur(27, 0);
        for (char c : s) {
            occur[c - 'a']++;
        }
        int cuts = 0;
        for (int i = 0; i < 27; ++i) {
            if (occur[i]) {
                cuts++;
            }
        }
        vi lastIndex(27, -1);
        for (int i = 0; i < s.length(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> cutOrder;
        for (int i = 0; i < 27; ++i) {
            if (lastIndex[i] != -1) {
                cutOrder.pb({lastIndex[i], i});
            }
        }
        sort(all(cutOrder));
        vi required(27, 0);
        for (int i = 0; i < cutOrder.size(); ++i) {
            required[cutOrder[i].se] = occur[cutOrder[i].se] / (i + 1);
        }
        string sOrig;
        int rem = cuts;
        echo(rem);
        for (int i = 0; i < s.length(); ++i) {
            required[s[i] - 'a']--;
            if (!required[s[i] - 'a']) {
                rem--;
            }
            if (!rem) {
                sOrig = s.substr(0, i + 1);
                break;
            }
        }
        echo(sOrig);
        string sO = sOrig;
        string sTest = sOrig;
        for (int i = 0; i < cuts; ++i) {
            string s2;
            for (char c : sOrig) {
                if (c - 'a' != cutOrder[i].se) {
                    s2.pb(c);
                }
            }
            sTest += s2;
            swap(s2, sOrig);
        }
        if (sTest == s) {
            cout << sO << " ";
            for (int i = 0; i < cuts; ++i) {
                cout << char('a' + cutOrder[i].se);
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
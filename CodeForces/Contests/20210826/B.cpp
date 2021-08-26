//  B.cpp
//  Created by David del Val on 26/08/2021
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

int valid[] = {1, 4, 6, 8, 9};

const int lim = 1e5;
bitset<lim> bs;
vl primes;
void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < lim; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

map<string, string> results;
string check(string s) {
    if (results.count(s)) {
        return results[s];
    }
    if (s.length() == 1) {
        if (bs[s[0] - '0'] == 0) {
            return s;
        } else {
            return "";
        }
    }
    ll num = 0;
    for (int i = 0; i < s.size(); ++i) {
        num *= 10;
        num += (s[i] - '0');
        string s1 = "";
        string s2 = "";
        if (i != 0) {
            s1 = s.substr(0, i);
        }
        if (i != int(s.size()) - 1) {
            s2 = s.substr(i + 1, int(s.size()) - (i + 1));
        }
        string sr = check(s1 + s2);
        if (sr.length()) {
            return results[s] = sr;
        }
    }
    //echo(s);
    //echo(num);
    if (bs[num] == 0) {
        return s;
    } else {
        return "";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        bool done = false;
        string ans;
        for (auto c : s) {
            for (int i = 0; i < 5; ++i) {
                if (c - '0' == valid[i]) {
                    done = true;
                    ans += c;
                    break;
                }
            }
            if (done) {
                break;
            }
        }
        if (!done) {
            // Only contains 2,3,5,7;
            string s2 = s;
            sort(all(s2));
            for (int i = 1; i < k; ++i) {
                if (s2[i] == s2[i - 1]) {
                    ans += s2[i];
                    ans += s2[i];
                    done = true;
                    break;
                }
            }
            if (!done) {
                ans = check(s);
            }
        }
        cout << ans.size() << "\n" << ans << "\n";
    }

    return 0;
}
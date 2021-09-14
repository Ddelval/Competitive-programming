//  A3.cpp
//  Created by David del Val on 11/09/2021
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
const ll mod = 1000000007;

ll calculateFinalLength(string s) {
    ll finalLength = 0;
    for (char c : s) {
        if (c == '.') {
            finalLength *= 2;
        } else {
            finalLength++;
        }
        finalLength %= mod;
    }
    return finalLength;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int z = 1;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        n = s.length();
        ll len = calculateFinalLength(s);
        // echo(len);
        ll firstO = -1;
        ll firstX = -1;
        ll lastIndex = 0;
        char lastChar = s[0];
        if (s[0] == 'O') {
            firstO = 0;
        } else if (s[0] == 'X') {
            firstX = 0;
        }
        // products
        ll ans = 0;

        // accumulators
        ll lacum = 0;
        ll racum = 0;
        ll npairs = 0;

        ll currenPrefixLen = 1;

        for (int i = 1; i < n; ++i) {

            /*
                        db(cout << currenPrefixLen << " " << firstO << " " <<
               firstX << " "
                                << lastIndex << " " << lastChar << endl);
                        echo(ans);
                        echo(s[i]);
                        */

            if (s[i] == 'F') {
                currenPrefixLen++;
                currenPrefixLen %= mod;
                continue;
            }
            if (s[i] != '.') {
                if (s[i] != lastChar && lastChar != 'F') {
                    ll l, r;
                    l = (lastIndex + 1) % mod;
                    r = (len - currenPrefixLen + mod) % mod;
                    r = (r + mod) % mod;

                    ans += (l * r) % mod;
                    ans %= mod;
                    lacum = (lacum + l) % mod;
                    racum = (racum + r) % mod;
                    npairs++;
                    npairs = (npairs % mod);
                }
                lastChar = s[i];
                lastIndex = currenPrefixLen;
                echo(currenPrefixLen);

                if (s[i] == 'O' && firstO == -1) {
                    firstO = currenPrefixLen;
                }
                if (s[i] == 'X' && firstX == -1) {
                    firstX = currenPrefixLen;
                }

                currenPrefixLen++;
                currenPrefixLen %= mod;
            } else {
                ll nextAns = ans;
                nextAns += (mod + (-currenPrefixLen * lacum) % mod) % mod;
                nextAns %= mod;
                nextAns += (currenPrefixLen * racum) % mod;
                nextAns %= mod;
                ll prefSq = (currenPrefixLen * currenPrefixLen) % mod;
                nextAns += mod + (-npairs * prefSq) % mod;
                nextAns %= mod;
                ans += (mod + nextAns) % mod;
                ans %= mod;

                lacum = (2 * lacum) % mod + (currenPrefixLen * npairs) % mod;
                lacum %= mod;
                racum = (2 * racum) % mod +
                        (mod + (-currenPrefixLen * npairs) % mod) % mod;
                racum %= mod;

                npairs = (npairs * 2) % mod;

                if (lastChar != 'F') {
                    ll l = -1, r = -1;
                    if (lastChar == 'X' && firstO != -1 && firstO < firstX) {
                        l = (lastIndex + 1) % mod;
                        r = len - (currenPrefixLen + firstO) % mod;
                        r = (r + mod) % mod;
                    }

                    if (lastChar == 'O' && firstX != -1 && firstX < firstO) {
                        l = (lastIndex + 1) % mod;
                        r = len - (currenPrefixLen + firstX) % mod;
                        r = (r + mod) % mod;
                    }

                    if (l != -1) {
                        lacum = (lacum + l) % mod;
                        racum = (racum + r) % mod;
                        ans = (ans + (l * r) % mod) % mod;
                        npairs++;
                        npairs %= mod;
                    }
                }
                lastIndex += currenPrefixLen;
                lastIndex %= mod;
                currenPrefixLen *= 2;
                currenPrefixLen %= mod;
            }
        }
        cout << "Case #" << z++ << ": ";
        cout << ans % mod << "\n";
    }

    return 0;
}
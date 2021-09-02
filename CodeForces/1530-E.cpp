//  1530-E.cpp
//  Created by David del Val on 27/08/2021
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
        vi freq(27, 0);
        for (auto a : s) {
            freq[a - 'a']++;
        }
        int df = 0;
        int has1 = -1;
        for (int i = 0; i < 27; ++i) {
            df += freq[i] != 0;
            if (freq[i] == 1 && has1 == -1) {
                has1 = i;
            }
        }
        if (has1 != -1) {
            string sol;
            sol.pb('a' + has1);
            freq[has1]--;
            for (int i = 0; i < 27; ++i) {
                while (freq[i]--)
                    sol.pb('a' + i);
            }
            cout << sol << "\n";
        } else if (df == 1) {
            cout << s << "\n";
        } else {
            int first = -1;
            for (int i = 0; i < 27; ++i) {
                if (freq[i] > 0) {
                    first = i;
                    break;
                }
            }
            echo("hi");
            int target = s.length() / 2 + 1;
            string sol;
            if (freq[first] <= target && freq[first] >= 2) {
                sol.pb('a' + first);
                sol.pb('a' + first);
                freq[first] -= 2;
                int other = first + 1;
                while (freq[first]) {
                    echo(freq[first]);
                    while (!freq[other]) {
                        other++;
                        echo(other);
                    }
                    sol.pb(other + 'a');
                    freq[other]--;
                    sol.pb('a' + first);
                    freq[first]--;
                }
                for (int i = 0; i < 27; ++i) {
                    while (freq[i]) {
                        sol.pb('a' + i);
                        freq[i]--;
                    }
                }
            } else if (df == 2) {
                sol.pb('a' + first);
                freq[first]--;
                echo("jjj");
                for (int i = first + 1; i < 27; ++i) {
                    while (freq[i]) {
                        sol.pb('a' + i);
                        freq[i]--;
                    }
                }
                while (freq[first]) {
                    sol.pb('a' + first);
                    freq[first]--;
                }
            } else {
                int second = -1;
                int third = -1;
                for (int i = first + 1; i < 27; ++i) {
                    if (freq[i] && second == -1) {
                        second = i;
                    } else if (freq[i] && third == -1) {
                        third = i;
                        break;
                    }
                }
                sol.pb('a' + first);
                sol.pb('a' + second);
                echo(sol);
                freq[first]--;
                freq[second]--;
                while (freq[first]--)
                    sol.pb('a' + first);

                sol.pb('a' + third);
                echo(sol);
                freq[third]--;
                for (int i = 0; i < 27; ++i) {
                    while (freq[i] > 0) {
                        sol.pb('a' + i);
                        freq[i]--;
                        echo(sol);
                    }
                }
            }
            cout << sol << "\n";
        }
    }

    return 0;
}
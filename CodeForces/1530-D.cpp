//  1530-D.cpp
//  Created by David del Val on 31/07/2021
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi data = readVector<int>(n);
        set<int> elems;
        for (auto &a : data) {
            a--;
            elems.insert(a);
        }
        set<int> notNamed;
        set<int> pos;
        for (int i = 0; i < n; ++i) {
            if (!elems.count(i)) {
                notNamed.insert(i);
            }
            pos.insert(i);
        }
        int m = elems.size();
        vi result(n, -1);
        if (n - m >= 2) {
            for (int i = 0; i < n; ++i) {
                if (elems.count(data[i])) {
                    result[i] = data[i];
                    elems.erase(data[i]);
                    pos.erase(i);
                }
            }
            set<int> critical;
            for (auto a : pos) {
                if (notNamed.count(a)) {
                    critical.insert(a);
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (result[i] == -1) {
                    int selection = -1;
                    if (!critical.empty()) {
                        for (auto a : critical) {
                            if (a != i) {
                                selection = a;
                                break;
                            }
                        }
                    }
                    if (selection == -1) {
                        for (auto a : notNamed) {
                            if (a != i) {
                                selection = a;
                                break;
                            }
                        }
                    }
                    result[i] = selection;
                    critical.erase(selection);
                    notNamed.erase(selection);
                }
            }
        } else if (n - m == 1) {
            int rem = *notNamed.begin();
            result[rem] = data[rem];
            elems.erase(result[rem]);
            for (int i = 0; i < n; ++i) {
                if (result[i] == -1) {
                    if (elems.count(data[i])) {
                        result[i] = data[i];
                        elems.erase(data[i]);
                    } else {
                        result[i] = rem;
                    }
                }
            }
        } else {
            result = data;
        }
        int matches = 0;
        for (int i = 0; i < n; ++i) {
            if (data[i] == result[i]) {
                matches++;
            }
            result[i]++;
        }
        cout << matches << "\n" << result << "\n";
    }

    return 0;
}
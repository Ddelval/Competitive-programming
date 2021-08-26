//  E.cpp
//  Created by David del Val on 24/08/2021
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

int n;
vi datt;
int findElem(int e) { return find(all(datt), e) - datt.begin(); }
void permut(int p) {
    vi datt2(n);
    for (int i = 0; i < p; ++i) {
        datt2[p - i - 1] = datt[i];
    }
    for (int i = p; i < n; ++i) {
        datt2[i] = datt[i];
    }
    // cout << "permuting " << p << " | " << datt << " | " << datt2 << endl;
    swap(datt, datt2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        datt = readVector<int>(n);
        int operations = 0;
        vi permutat;
        int tosort = n;
        bool possible = true;
        while (tosort != 1) {
            int pos1 = findElem(1);
            if (pos1 % 2 == 1) {
                possible = false;
                break;
            }
            permutat.push_back(pos1 + 1);
            permut(pos1 + 1);
            int pos2 = findElem(2);
            if (pos2 % 2 == 0) {
                possible = false;
                break;
            }
            permutat.push_back(pos2);
            permut(pos2);
            permutat.push_back(pos2 + 2);
            permut(pos2 + 2);
            permutat.push_back(3);
            permut(3);
            permutat.push_back(tosort);
            permut(tosort);
            tosort -= 2;
            for (int i = 0; i < tosort; ++i) {
                datt[i] -= 2;
            }
            // cout << "finalizing iteration " << tosort << ": " << datt <<
            // endl;
        }
        for (int i = 0; i < n; ++i) {
            datt[n - 1 - i] += 2 * (i / 2);
        }
        permut(n);
        permutat.push_back(n);
        for (int i = 0; i < n; ++i) {
            if (datt[i] != i + 1) {
                possible = false;
            }
        }
        if (possible) {
            cout << permutat.size() << "\n";
            cout << permutat << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
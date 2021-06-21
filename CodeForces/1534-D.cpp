//  1534-D.cpp
//  Created by David del Val on 21/06/2021
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

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
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

    int n;
    cin >> n;

    cout << "? " << 1 << "\n";
    cout.flush();

    vi from1 = readVector<int>(n);
    int even, odd;
    even = odd = 0;
    for (auto a : from1) {
        if (a && a % 2 == 0) {
            even++;
        }
        if (a && a % 2 == 1) {
            odd++;
        }
    }

    int comp = 0;
    if (odd < even) {
        comp = 1;
    }

    int a;
    vector<pii> results;
    results.reserve(n - 1);
    for (int i = 0; i < n; ++i) {
        if (from1[i]) {
            if (from1[i] % 2 == comp) {
                cout << "? " << (i + 1) << "\n";
                cout.flush();
                for (int j = 0; j < n; ++j) {
                    cin >> a;
                    if (a == 1) {
                        results.push_back({i + 1, j + 1});
                    }
                }
            }
        }
    }
    if (comp == 0) {
        for (int j = 0; j < n; ++j) {
            if (from1[j] == 1) {
                results.push_back({1, j + 1});
            }
        }
    }
    cout << "!\n";
    for (auto a : results) {
        cout << a.fi << " " << a.se << "\n";
    }
    cout.flush();

    return 0;
}
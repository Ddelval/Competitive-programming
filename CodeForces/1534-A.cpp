//  1534-A.cpp
//  Created by David del Val on 19/06/2021
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

const int lim = 50;
char board[lim][lim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
            }
        }
        bool correct1 = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 != 0) {
                    correct1 &= (board[i][j] != 'W');
                } else {
                    correct1 &= (board[i][j] != 'R');
                }
            }
        }
        bool correct2 = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 != 0) {
                    correct2 &= (board[i][j] != 'R');
                } else {
                    correct2 &= (board[i][j] != 'W');
                }
            }
        }
        if (!correct1 && !correct2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        char c1 = 'R';
        char c2 = 'W';
        if (correct2) {
            swap(c1, c2);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 != 0) {
                    board[i][j] = c1;
                } else {
                    board[i][j] = c2;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
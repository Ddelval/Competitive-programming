//  11110__Equidivisions.cpp
//  Created by David del Val on 23/12/2020
//
//

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
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
vector<vi> visited;
vector<vi> tab;
int n;
int dfs(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= n || y >= n)
        return 0;
    if (visited[x][y])
        return 0;
    if (tab[x][y] != c)
        return 0;
    visited[x][y] = 1;

    return 1 + dfs(x, y + 1, c) + dfs(x, y - 1, c) + dfs(x + 1, y, c) + dfs(x - 1, y, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n && n) {
        string s;
        getline(cin, s);
        tab = vector<vi>(n, vi(n, n));
        vector<pii> data(n, {0, 0});

        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            getline(cin, s);
            stringstream ss(s);
            while (ss >> a >> b) {
                a--;
                b--;
                tab[a][b] = i;
                data[i] = {a, b};
            }
        }
        visited = vector<vi>(n, vi(n, 0));
        bool correct = true;
        for (int i = 0; i < n - 1; ++i) {
            if (dfs(data[i].fi, data[i].se, i) != n) {
                correct = false;
            }
        }
        bool done = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (tab[i][j] == n) {
                    if (dfs(i, j, n) != n) {
                        correct = false;
                    }
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }
        if (correct) {
            cout << "good\n";
        } else {
            cout << "wrong\n";
        }
    }

    return 0;
}
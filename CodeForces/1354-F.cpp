//  1354-F.cpp
//  Created by David del Val on 08/08/2021
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

pair<ll, vl> hungarian(vector<vl> matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vl u(n), v(m + 1), matched(m + 1, -1);

    for (int i = 0; i < n; ++i) {
        int j0 = m;
        matched[j0] = i;
        vl dist(m + 1, inf);
        vi from(m + 1, -1);
        vector<bool> seen(m + 1, 0);

        while (matched[j0] != -1) {
            seen[j0] = true;
            int i0 = matched[j0], jNext = -1;
            ll delta = inf;
            for (int j = 0; j < m; ++j) {
                if (seen[j])
                    continue;
                ll candidateDistance = matrix[i0][j] - u[i0] - v[j];
                if (candidateDistance < dist[j]) {
                    dist[j] = candidateDistance;
                    from[j] = j0;
                }
                if (dist[j] < delta) {
                    delta = dist[j];
                    jNext = j;
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (seen[j]) {
                    u[matched[j]] += delta;
                    v[j] -= delta;
                } else {
                    dist[j] -= delta;
                }
            }
            j0 = jNext;
        }
        while (j0 != m) {
            int j1 = from[j0];
            matched[j0] = matched[j1];
            j0 = j1;
        }
    }
    ll ans = -v[m];
    vl rowMatchesWith(n);
    for (int j = 0; j < m; ++j) {
        if (matched[j] != -1) {
            rowMatchesWith[matched[j]] = j;
        }
    }
    return {ans, rowMatchesWith};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vl> matrix(k, vl(n));
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            for (int spot = 0; spot < k; ++spot) {
                matrix[spot][i] = (spot - k + 1) * b + a;
                matrix[spot][i] *= -1;
            }
        }
        auto result = hungarian(matrix);
        vector<bool> chosen(n, 0);
        for (auto a : result.se) {
            chosen[a] = true;
        }
        cout << k - 1 + 2 * (n - k) + 1 << "\n";
        for (int i = 0; i < k - 1; ++i) {
            cout << 1 + result.se[i] << " ";
        }
        for (int i = 0; i < n; ++i) {
            if (!chosen[i]) {
                cout << 1 + i << " -" << 1 + i << " ";
            }
        }
        cout << result.se[k - 1] + 1 << "\n";
    }

    return 0;
}
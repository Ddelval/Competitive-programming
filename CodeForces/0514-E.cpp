//  0514-E.cpp
//  Created by David del Val on 05/07/2021
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

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
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

const int lim = 105;
vector<vl> matrix;
ll dp[lim];
ll coef[lim];

const ll mod = 1e9 + 7;
vector<vl> operator*(const vector<vl> &mat1, const vector<vl> &mat2) {
    int n = mat1.size();
    int m = mat2[0].size();
    vector<vl> result(n, vl(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
                result[i][j] %= mod;
            }
        }
    }
    return result;
}

vector<vl> elevate(const vector<vl> &matrix, int power) {
    if (power == 1) {
        return matrix;
    }
    vector<vl> par = elevate(matrix, power / 2);
    vector<vl> res = par * par;
    if (power % 2) {
        res = res * matrix;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    matrix.assign(101, vl(101, 0));
    cin >> n >> x;
    ll a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        coef[a]++;
    }
    dp[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += coef[j] * dp[i - j];
            dp[i] %= mod;
        }
    }

    if (x <= 100) {
        ll ans = 0;
        for (int i = 0; i <= x; ++i) {
            //cout << i << " " << dp[i] << endl;
            ans += dp[i];
            ans %= mod;
        }
        cout << ans << "\n";
        return 0;
    }

    for (int i = 1; i <= 100; ++i) {
        matrix[0][i - 1] = coef[i];
        matrix[100][i - 1] = coef[i];
    }
    matrix[100][100] = 1;
    for (int i = 0; i < 100 - 1; ++i) {
        matrix[i + 1][i] = 1;
    }
    //cout << matrix << endl;
    matrix = elevate(matrix, x - 100 + 1);
    vector<vl> column;
    ll accum = 0;
    for (int i = 99; i >= 0; --i) {
        accum += dp[i];
        accum %= mod;
        column.pb(vl(1, dp[i]));
    }
    column.pb(vl(1, accum));
    //cout << column << endl;
    auto result = matrix * column;
    //cout << matrix << endl;
    //cout << result << endl;
    cout << (result.back()[0]) % mod << "\n";

    return 0;
}
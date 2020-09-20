//  D.cpp
//  Created by David del Val on 14/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

inline ostream& operator<<(ostream& o, pii p) {
    o << p.fi << " " << p.se;
    return o;
}

template <typename>
struct is_std_vector : std::false_type {};
template <typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type {};

template <typename T>
inline ostream& operator<<(ostream& o, vector<T>& p) {
    for (int i = 0; i < p.size(); ++i) {
        o << setw(3) << p[i];
        if (is_std_vector<T>::value) o << "\n";
    }
    return o;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int sizes[3];
vl elems[3];

const int siz = 200 + 10;
ll dp[siz][siz][siz];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));

    for (int i = 0; i < 3; ++i) {
        cin >> sizes[i];
    }
    for (int i = 0; i < 3; ++i) {

        elems[i] = vl(sizes[i]);
        for (int j = 0; j < sizes[i]; ++j) {
            cin >> elems[i][j];
        }

        sort(all(elems[i]), greater<int>());
        elems[i].push_back(0);
    }

    for (int i = 0; i <= sizes[0]; ++i) {
        for (int j = 0; j <= sizes[1]; ++j) {
            for (int w = 0; w <= sizes[2]; ++w) {
                dp[i + 1][j + 1][w] = max(dp[i + 1][j + 1][w], dp[i][j][w] + elems[0][i] * elems[1][j]);
                dp[i][j + 1][w + 1] = max(dp[i][j + 1][w + 1], dp[i][j][w] + elems[1][j] * elems[2][w]);
                dp[i + 1][j][w + 1] = max(dp[i + 1][j][w + 1], dp[i][j][w] + elems[0][i] * elems[2][w]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < siz;++i){
        for (int j = 0; j < siz;++j){
            for (int w = 0; w < siz;++w){
                ans = max(ans, dp[i][j][w]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
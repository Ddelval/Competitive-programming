//  B.cpp
//  Created by David del Val on 12/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, sx, sy;
    cin >> n >> m >> sy >> sx;
    sx--;
    sy--;
    vector<pii> res;
    int cy, cx;
    cx = sx;
    cy = sy;
    

    while (cy >= 0) {
        res.push_back({cx, cy});
        cy--;
    }
    cy++;
    while (cx != 0) {
        cx--;
        res.push_back({cx, cy});
    }
    if (sx != m - 1) {
        cx = sx;
        while (cx < m - 1) {
            cx++;
            res.push_back({cx, cy});
        }
    }
    for (int i = 1; i < n; ++i) {
        if (cx ==0) {
            for (int j = 0; j < m; ++j) {
                if (j == sx && i <= sy) continue;
                res.push_back({j, i});
            }
            cx = m - 1;
        } else {
            for (int j = m - 1; j >= 0; --j) {
                if (j == sx && i <= sy) continue;
                res.push_back({j, i});
            }
            cx = 0;
        }
    }
    //cout << "siz " << res.size() << "\n";
    for (auto a : res) {
        cout << a.se+1 << " " << a.fi+1 << "\n";
    }

    return 0;
}
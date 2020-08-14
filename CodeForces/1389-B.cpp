//  1389-B.cpp
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

    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vi arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        ll Mres = 0;
        for (int i = 0; i <= z; ++i) {
            ll res = 0;
            int ma = 0;
            for (int j = 0; j < k + 1 - 2 * i; ++j) {
                res += arr[j];
                if (j<n-1) {
                    ma = max(ma, arr[j] + arr[j + 1]);
                }
            }
            res += ma * i;
            Mres = max(Mres, res);
        }
        cout << Mres << "\n";
    }

    return 0;
}
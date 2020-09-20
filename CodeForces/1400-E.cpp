//  1400-E.cpp
//  Created by David del Val on 26/08/2020
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

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    int a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
vi arr;
const int lim = 5010;
int dp[lim][lim];
ll n;

int explore(int index, int heightConIndex) {
    if (index == n) return 0;
    if (dp[index][heightConIndex] != -1) return dp[index][heightConIndex];
    int ans = 0;

    if (arr[index] <= arr[heightConIndex]) {
        ans = explore(index + 1, index);
    } else {
        ans = 1 + explore(index + 1, heightConIndex);
        ans = min(ans, arr[index] - arr[heightConIndex] + explore(index + 1, index));
    }
    //cout << index << " " << heightConIndex << " " << ans << endl;
    return dp[index][heightConIndex] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr = readVector<int>(n);
    arr.pb(0);

    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            dp[i][j] = -1;
        }
    }

    cout << explore(0, n) << "\n";

    return 0;
}
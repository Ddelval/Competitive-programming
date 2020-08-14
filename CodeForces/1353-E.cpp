//  1353-E.cpp
//  Created by David del Val on 03/07/2020
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
        int n, k;
        cin >> n >> k;
        vi data(n);
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) data[i] = s[i] - '0';

        vi presum(n+1);
        presum[0] = 0;
        for (int i = 0; i < n; ++i) presum[i + 1] = presum[i] + data[i];

        vi dp(n);
        for (int seq = 0; seq < k;++seq){
            dp[seq] = data[seq] == 0 ;
            dp[seq] += presum[seq];
            for (int j = seq + k; j < n; j += k) {
                if (j > n) break;
                dp[j] = min(presum[j], dp[j - k] + presum[j] - presum[j - k + 1]);
                dp[j] += data[j] == 0;
            }
        }
        //cout << "dp " << dp << endl;
        int res = presum[n];
        for (int i = 0; i < n;++i){
            res = min(res, dp[i] + presum[n] - presum[i + 1]);
        }
        cout << res << endl;
    }

    return 0;
}
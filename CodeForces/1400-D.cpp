//  1400-D.cpp
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
        int n;
        cin >> n;
        vi data(n);
        for (int i = 0; i < n; ++i) cin >> data[i];

        ll totalSum = 0;
        vi buffer2(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            ll sum = 0;
            ll tsum = 0;
            for (int j = i + 1; j < n; ++j) {
                if (data[j] == data[i]) {
                    tsum += sum;
                    sum += buffer2[data[j]];
                } else {
                    sum += buffer2[data[j]];
                }
            }
            buffer2[data[i]]++;
            totalSum += tsum;
        }
        cout << totalSum << "\n";
    }

    return 0;
}
//  1373_D.cpp
//  Created by David del Val on 02/07/2020
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

int n;
vi dat;
ll tryMax(int ipos) {
    ll ma = 0;
    ll sum = 0;
    for (int i = ipos; i < n; i += 2) {
        if (i >= 1) sum += dat[i - 1];
        sum += dat[i];
        if (sum < 0) sum = 0;
        ma = max(ma, sum);
    }
    return ma;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        dat = vi(n);
        for (int i = 0; i < n; ++i) cin >> dat[i];
        ll firstval = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                firstval += dat[i];
                dat[i] = -dat[i];
            }
        }
        //cout << dat << endl;
        //cout << tryMax(1) << " " << tryMax(2) << endl;
        cout << firstval + max(tryMax(1), tryMax(2)) << "\n";
    }

    return 0;
}
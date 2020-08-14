//  1394-A.cpp
//  Created by David del Val on 13/08/2020
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

int n, d, m;
vi small;
vi big;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> m;
    small.reserve(n);
    big.reserve(n);
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > m)
            big.push_back(a);
        else
            small.push_back(a);
    }

    if (big.size() == 0) {
        cout << accumulate(all(small), 0LL) << "\n";
        return 0;
    }
    sort(all(big), greater<int>());
    sort(all(small), greater<int>());

    vl bigSum(big.size() + 1);
    vl smallSum(small.size() + 1);
    bigSum[0] = 0;
    smallSum[0] = 0;
    for (int i = 0; i < big.size(); ++i) {
        bigSum[i + 1] = bigSum[i] + big[i];
    }
    for (int i = 0; i < small.size(); ++i) {
        smallSum[i + 1] = smallSum[i] + small[i];
    }
    //for (int i = 0; i < big.size(); ++i) smallSum.push_back(smallSum.back());
    ll res = 0;

    for (int chooseBig = 0; chooseBig < big.size() + 1; ++chooseBig) {
        ll chooseSmall = n - (1ll * (chooseBig - 1) * (d + 1) + 1);
        if (chooseSmall < 0 || chooseSmall > smallSum.size()) continue;
        if (1ll * (chooseBig - 1) * (d + 1) + 1 <= n) {
            //cout << chooseBig << " " << chooseSmall << endl;
            res = max(res, bigSum[chooseBig] + smallSum[chooseSmall]);
        }
    }
    cout << res << "\n";

    return 0;
}
//  C.cpp
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

const int lim = 200 + 10;
int n, m;
int a[lim], b[lim];

int setBitNumber(int n) {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n = n + 1;

    return (n >> 1);
}

int getMin(int ia) {
    int mi = numeric_limits<int>::max();
    for (int i = 0; i < m; ++i) {
        mi = min(mi, a[ia] & b[i]);
    }
    return mi;
}

int getMaxSetBitMin() {
    int mi = 0;
    for (int i = 0; i < n; ++i) {
        int r = getMin(i);
        mi = max(mi, setBitNumber(r));
    }
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    int res = 0;
    int mi;
    while ((mi = getMaxSetBitMin()) != 0) {
        res += mi;
        mi = ~mi;
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] & mi;
        }
    }
    cout << res << "\n";
    

    return 0;
}
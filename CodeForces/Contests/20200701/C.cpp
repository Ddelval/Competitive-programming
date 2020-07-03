//  C.cpp
//  Created by David del Val on 01/07/2020
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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        ll totake = abs(a - b);
        if (totake >= n) {
            if (m <= min(a, b)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            continue;
        }

        if (a > b)
            a -= totake;
        else
            b -= totake;

        n -= totake;

        totake = min(min(a, b), min(n, m));
        a -= totake;
        b -= totake;
        n -= totake;
        m -= totake;

        bool no = false;
        if (a == 0 && (m != 0 || n > b)) no = true;
        if (b == 0 && (m != 0 || n > a)) no = true;
        if (n == 0 && (m > min(a, b))) no = true;
        if (m == 0 && (n > max(a, b))) no = true;

        if (no) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
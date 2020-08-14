//  1325-D.cpp
//  Created by David del Val on 04/07/2020
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

    ll xo, su;

    cin >> xo >> su;

    if (xo > su || xo % 2 != su % 2) {
        cout << "-1\n";
        return 0;
    }
    if (xo == su && xo == 0) {
        cout << "0\n";
        return 0;
    }
    if (xo == su) {
        cout << "1\n"
             << xo << endl;
        return 0;
    }

    ll an = (su - xo) / 2;

    ll v1 = 0;
    bool posible = true;
    for (int i = 0; i < 63; ++i) {
        ll mask = 1;
        mask = mask << i;

        if ((an & mask) && (xo & mask)) {
            posible = false;
            break;
        } else if ((an & mask) || (xo & mask)) {
            v1 += mask;
        }
    }
    if (posible) {
        cout << "2\n"
             << v1 << " " << an << endl;
    } else {
        cout << "3\n"
             << xo << " " << an << " " << an << endl;
    }

    return 0;
}
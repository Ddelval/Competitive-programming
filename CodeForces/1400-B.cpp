//  1400-B.cpp
//  Created by David del Val on 25/08/2020
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

ll p, f;
ll s, w;
ll cs, cw;

ll calculate(ll ns, ll nw, ll capacity) {
    ll ps, pw;
    ps = s;
    pw = w;
    if (ps > pw) {
        swap(ps, pw);
        swap(ns, nw);
    }

    if (ps * ns >= capacity) {
        return capacity / ps;
    }
    ll accum = ns;
    capacity -= ns * ps;
    accum += min((capacity / pw), nw);
    return accum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> p >> f;
        cin >> cs >> cw;
        cin >> s >> w;

        ll mM = 0;
        for (ll s1 = 0; s1 <= cs; ++s1) {
            if (s1 * s > p) break;
            ll w1 = (p - s1 * s) / w;
            w1 = min(w1, cw);
            //cout << "to1 " << s1 << " " << w1 << "    " << s1 + w1 << "\n";
            //cout << "to2 " << cs - s1 << " " << cw - w1 << "    " << calculate(cs - s1, cw - w1, f) << "\n";
            mM = max(mM, s1 + w1 + calculate(cs - s1, cw - w1, f));
        }
        cout << mM << "\n";
    }

    return 0;
}
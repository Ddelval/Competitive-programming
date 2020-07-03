//  1374-E1.cpp
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

ll get(vi& vec, int index) {
    if (index < vec.size())
        return vec[index];
    else
        return INT_MAX;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vi both, alice, bob;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;

        if (a && b)
            both.pb(t);
        else if (a)
            alice.pb(t);
        else if (b)
            bob.pb(t);
    }
    int iboth, ialice, ibob;
    iboth = ialice = ibob = 0;
    ll res = 0;
    ll tmp = 0;
    sort(all(both));
    sort(all(alice));
    sort(all(bob));

    /*cout << both << endl
         << alice << endl
         << bob << endl;
         */
    for (int i = 0; i < k; ++i) {
        if (get(alice, ialice) + get(bob, ibob) < get(both, iboth)) {
            tmp = get(alice, ialice) + get(bob, ibob);
            ialice++;
            ibob++;
        } else {
            tmp = get(both, iboth);
            iboth++;
        }
        //cout << tmp << " ";
        if (tmp < INT_MAX)
            res += tmp;
        else {
            res = -1;
            break;
        }
    }
    cout << res << "\n";

    return 0;
}
//  1397-B.cpp
//  Created by David del Val on 01/09/2020
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

template <typename T, typename Q>
inline ostream& operator<<(ostream& o, pair<T, Q> p) {
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

ll inf = LLONG_MAX / 10;
bool possible(ll n, ll val) {
    return log(inf) / log(val) >= n;
}
ll calculateDiff(vl& values, ll ob) {
    ll in = 1;
    ll out = 0;
    for (auto a : values) {
        out += abs(a - in);
        in *= ob;
        if (out > inf || out < 0) return inf;
    }
    return out;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vl data = readVector<ll>(n);

    sort(all(data));

    ll val = 2;
    ll res = accumulate(all(data), 0ll) - n;
    while (possible(n, val)) {
        res = min(res, calculateDiff(data, val));
        //cout << val << " " << res<<endl;
        val++;
    }
    cout << res << "\n";

    return 0;
}
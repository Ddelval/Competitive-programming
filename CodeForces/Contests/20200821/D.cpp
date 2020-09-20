//  D.cpp
//  Created by David del Val on 21/08/2020
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

ll n;
const ll mod = 1e9 + 7;
vector<vector<int>> adyList;
vector<ll> factors;
vector<int> children;
vector<int> visited;

ll getChildren(int i) {
    if (visited[i]) return 0;
    visited[i] = true;
    ll ans = 0;
    ll pans;
    for (auto a : adyList[i]) {
        pans = getChildren(a);
        // cout << i << " " << pans << endl;
        if (pans) children.push_back(pans);
        ans += pans;
    }
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        adyList = vector<vi>(n, vi());
        children = vector<int>();
        visited = vector<int>(n, 0);
        factors = vector<ll>();
        for (int i = 0; i < n - 1; ++i) {
            cin >> a >> b;
            a--;
            b--;
            adyList[a].push_back(b);
            adyList[b].push_back(a);
        }
        int m;
        cin >> m;
        ll c;
        for (int i = 0; i < m; ++i) {
            cin >> c;
            factors.push_back(c);
        }
        getChildren(0);

        vl weights(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            weights[i] = children[i] * (n - children[i]);
        }
        sort(all(weights), greater<ll>());
        //cout << weights << "\n";
        sort(all(factors), greater<ll>());
        //cout << factors << "\n";
        if (factors.size() > weights.size()) {
            int diff = int(factors.size()) - int(weights.size())+1;
            ll multi = 1;
            for (int i = 0; i < diff; ++i) {
                multi = (multi * factors[i]) % mod;
            }
            vl fact2;
            fact2.reserve(weights.size());
            fact2.push_back(multi);
            for (int i = diff ; i < factors.size(); ++i) {
                fact2.push_back(factors[i]);
            }
            factors = move(fact2);
        }
        //cout << factors << endl;
        ll res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i < factors.size()) {
                res = (res + factors[i] * weights[i]) % mod;
            } else {
                res = (res + weights[i]) % mod;
            }
            //cout << "res " << res << endl;
        }
        cout << res << "\n";
    }

    return 0;
}
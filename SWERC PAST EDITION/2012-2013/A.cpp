//  A.cpp
//  Created by David del Val on 14/02/2021
//
//

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    T a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// ====================================================== //
// ================== Pairs operations ================== //
// ====================================================== //
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int n, m;
vector<vi> adyList;

ll shortestCycle(int snode) {

    queue<int> q;
    vl dists(n, iinf);
    vl par(n, -1);
    dists[snode] = 0;
    q.push(snode);

    ll res = iinf;

    while (!q.empty()) {
        int cnode = q.front();
        q.pop();
        //cout << "cnode: " << cnode << " " << par[cnode] << endl;

        for (auto a : adyList[cnode]) {
            //cout << "\t" << a << " " << dists[a] << endl;

            if (dists[a] != iinf && par[cnode] != a) {
                res = min(res, dists[a] + dists[cnode] + 1ll);
                //cout << "found";
            }
            if (dists[a] == iinf) {
                par[a] = cnode;
                dists[a] = dists[cnode] + 1;
                q.push(a);
            }
            //cout << "\t\t" << a << " " << dists[a] << " " << par[a] << endl;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int z = 0;
    while (t--) {
        z++;
        cin >> n >> m;
        adyList = vector<vi>(n);

        int a, b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            adyList[a].pb(b);
            adyList[b].pb(a);
        }

        ll ans = iinf;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, shortestCycle(i));
        }
        cout << "Case " << z << ": ";
        if (ans == iinf) {
            cout << "impossible";
        } else {
            cout << ans;
        }
        cout << "\n";
    }

    return 0;
}
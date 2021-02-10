//  11710__Expensive Subway.cpp
//  Created by David del Val on 04/02/2021
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

vi parent;
vi rankk;

void initialize(int n) {
    rankk = vi(n, 0);
    parent = vi(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    if (rankk[pa] > rankk[pb]) {
        parent[pb] = pa;
    } else if (rankk[pa] < rankk[pb]) {
        parent[pa] = pb;
    } else {
        parent[pa] = pb;
        rankk[pb]++;
    }
}

ll kruskal(vector<pair<pii, int>> &edgeList, int n) {
    int cost = 0;

    sort(all(edgeList), [](pair<pii,int> a, pair<pii,int> b) { return a.se < b.se; });
    for (auto a : edgeList) {
        if (find(a.fi.fi) == find(a.fi.se)) {
            continue;
        }
        Union(a.fi.fi, a.fi.se);
        cost += a.se;
        n--;
        if (n == 1)
            return cost;
    }
    return iinf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m && n) {
        map<string, int> ma;
        string s;

        for (int i = 0; i < n; ++i) {
            cin >> s;
            ma[s] = i;
        }
        string r;
        vector<pair<pii, int>> edges;
        int a;
        for (int i = 0; i < m; ++i) {
            cin >> s >> r >> a;
            edges.pb({{ma[s], ma[r]}, a});
        }
        cin >> s;
        initialize(n);
        int res = kruskal(edges, n);
        if(n==1){
            cout<<"0\n";
            continue;
        }

        if (res == iinf) {
            cout << "Impossible\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}
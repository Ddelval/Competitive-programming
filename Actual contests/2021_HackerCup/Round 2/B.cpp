//  B.cpp
//  Created by David del Val on 25/09/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

#ifdef DEBUG
#define db(x) x
#define echo(x) cout << #x << ": " << x << endl;
#else
#define db(x)
#define echo(x)
#endif

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

template <typename T> struct subs_succeeded : std::true_type {};
template <> struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T> struct get_iter_res {
private:
    template <typename X> static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <> struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T> struct get_termination {
    static constexpr const char *get() { return sep1; }
};
template <typename U, typename S> struct get_termination<vector<U, S>> {
    static constexpr const char *get() { return sep2; }
};

template <typename U> struct get_termination<set<U>> {
    static constexpr const char *get() { return sep2; }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator =
                get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll> inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) { return {a.fi + b.fi, a.se + b.se}; }

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

// gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif
vector<set<int>> children;

void explore(int parent, int current) {
    children[current].erase(parent);
    for (auto a : children[current]) {
        explore(current, a);
    }
}

int timer;
int n, l;
vector<int> tin, tout;
vector<vector<int>> up;
vi lcaValues;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : children[v]) {
        if (u != p) dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin = vi(n);
    tout = vi(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void propagateValues(int cnode) {
    int commonLCA = lcaValues[cnode];
    for (auto ch : children[cnode]) {
        propagateValues(ch);
        if (lcaValues[ch] != -1) {
            commonLCA = lca(commonLCA, lcaValues[ch]);
        }
    }
    if (commonLCA == cnode) {
        commonLCA = -1;
    }
    lcaValues[cnode] = commonLCA;
}

int calculateAnswer(int cnode) {
    int ans = 0;
    for (auto child : children[cnode]) {
        ans += calculateAnswer(child);
        if (lcaValues[child] == -1) {
            ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int z = 1;
    while (t--) {
        cin >> n;
        timer = 0;
        children.assign(n, set<int>());
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            children[a].insert(b);
            children[b].insert(a);
        }
        explore(-1, 0);
        vector<vi> components;
        unordered_map<int, int> types;
        for (int i = 0; i < n; ++i) {
            int f;
            cin >> f;
            if (types.count(f)) {
                components[types[f]].push_back(i);
            } else {
                components.push_back(vi());
                components.back().push_back(i);
                types[f] = types.size();
            }
        }
        preprocess(0);

        lcaValues = vi(n, -1);
        for (vi component : components) {
            int lcaNode = component[0];
            for (int i = 1; i < component.size(); ++i) {
                lcaNode = lca(lcaNode, component[i]);
            }
            for (auto ele : component) {
                lcaValues[ele] = lcaNode;
            }
        }
        propagateValues(0);

        cout << "Case #" << z++ << ": " << calculateAnswer(0) << "\n";
    }

    return 0;
}
//  1632-E.cpp
//  Created by David del Val on 31/01/2022
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

struct node;

template <> struct get_termination<node> {
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

struct node {
    int id;
    node *parent = nullptr;
    vector<node *> children;
    int depth;
    int rem_depth = 0;
    int rem_depth2 = 0;
    int f;

    node(int i) { this->id = i; }
    bool operator==(const node &n) { return this->id == n.id; }
};

ostream &operator<<(ostream &o, node &n) {
    o << "{" << n.id << " ";
    if (n.parent) {
        o << "parent: " << n.parent->id << " ";
    } else {
        o << "root ";
    }

    o << "| depth: " << n.depth << " "
      << "rem_depth: " << n.rem_depth << " " << n.rem_depth2 << " "
      << "f: " << n.f << " ";
    o << "| children:";
    for (auto child : n.children) {
        o << " " << child->id;
    }
    o << "}";
    return o;
}
vector<node> nodes;
vector<node *> leaves;
vector<vector<node *>> depthMap;
int max_depth;
int x;
int n;

void propagate(node *n) {
    for (auto child : n->children) {
        child->depth = n->depth + 1;
        max_depth = max(max_depth, child->depth);
        child->parent = n;
        propagate(child);
    }
    if (n->children.size() == 0) {
        leaves.push_back(n);
    }
}

bool check(int val) {
    if (val >= max_depth) {
        return true;
    }
    if (val == 0) {
        return false;
    }

    // Reset
    for (int i = 0; i < n; ++i) {
        nodes[i].f = 0;
    }
    // Recalculate
    for (int i = max_depth; i >= 0; --i) {
        for (node *n : depthMap[i]) {
            if (n->rem_depth2 + n->depth > val && n->rem_depth + n->depth > val) {
                n->f = n->rem_depth2 + n->rem_depth;
            }

            if (n->children.size()) {
                for (auto ch : n->children) {
                    n->f = max(n->f, ch->f);
                }
            }
        }
    }
    echo(val);
    echo(nodes);
    if ((nodes[0].f + 1) / 2 + x <= val) {
        return true;
    }
    return false;
}

set<int> explored;
void explore(int current, vector<vector<int>> &adyList) {
    if (explored.count(current)) {
        return;
    }
    explored.insert(current);
    for (auto child : adyList[current]) {
        if (!explored.count(child)) {
            nodes[current].children.push_back(&nodes[child]);
            explore(child, adyList);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        nodes.clear();
        leaves.clear();
        max_depth = 0;
        for (int i = 0; i < n; ++i) {
            nodes.pb(node(i));
        }
        vector<vector<int>> adyList(n, vector<int>());
        explored.clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adyList[u].pb(v);
            adyList[v].pb(u);
        }
        explore(0, adyList);
        echo(nodes);
        nodes[0].depth = 0;
        propagate(&nodes[0]);

        depthMap = vector<vector<node *>>(max_depth + 1);

        for (int i = 0; i < n; ++i) {
            node *n = &nodes[i];
            echo(n->depth);
            echo(max_depth);
            depthMap[n->depth].push_back(n);
        }
        for (int i = max_depth; i >= 0; --i) {
            for (node *n : depthMap[i]) {
                n->rem_depth = 0;
                n->rem_depth2 = 0;

                if (n->children.size()) {
                    vi depths;
                    for (auto ch : n->children) {
                        depths.push_back(ch->rem_depth + 1);
                    }
                    sort(all(depths), greater<int>());
                    n->rem_depth = depths[0];
                    if (depths.size() > 1) {
                        n->rem_depth2 = depths[1];
                    }
                }
            }
        }

        // cout << nodes << "\n\n";

        vi results;
        results.reserve(n);
        for (x = 1; x <= n; ++x) {
            // Binary search the answer
            echo(x);
            int r, l;
            r = 0;
            l = max_depth;
            while (l - r > 1) {
                int mid = (l + r) / 2;
                if (check(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            results.push_back(l);
        }
        cout << results << "\n";
    }

    return 0;
}
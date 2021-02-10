//  10305__Ordering Tasks.cpp
//  Created by David del Val on 14/01/2021
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
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

vi topoSort;
vi visited;
vector<vi> adyList;
void dfs(int node) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    for (auto a : adyList[node]) {
        dfs(a);
    }
    topoSort.push_back(node);
}
void topologicalSort() {
    int n = adyList.size();

    visited = vi(n, 0);
    topoSort.clear();

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(all(topoSort));
}

void kahnTopoSort() {
    int n = adyList.size();
    topoSort.clear();

    vi noIncoming;
    vi hasincoming(n, 0);
    for (auto a : adyList) {
        for (auto b : a) {
            hasincoming[b]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!hasincoming[i]) {
            noIncoming.push_back(i);
        }
    }
    while (noIncoming.size() != 0) {
        int curr = *noIncoming.begin();
        noIncoming.erase(noIncoming.begin());
        topoSort.push_back(curr);
        for (auto a : adyList[curr]) {
            hasincoming[a]--;
            if (!hasincoming[a]) {
                noIncoming.push_back(a);
            }
        }
    }
    for(auto a:hasincoming){
        if(a!=0){
            cout << "graph has at least one cycle";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m && n) {
        int a, b;
        adyList = vector<vi>(n, vi());
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            a--;
            b--;
            adyList[a].pb(b);
        }
        kahnTopoSort();
        //topologicalSort();

        for (auto &a : topoSort) {
            a++;
        }
        cout << topoSort << endl;
    }

    return 0;
}
//  11504__Dominios.cpp
//  Created by David del Val on 26/12/2020
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
vector<vi> adyList; // Graph
vi low, num;        // num and low for DF
int cnt;            // Counter for DFS
stack<int> st;
vi inStack;      // Position in the stack + 1
vector<vi> sccs; // Contains the SCCs at the end

void dfs(int u) {
    low[u] = num[u] = cnt++;
    st.push(u);
    inStack[u] = st.size();
    for (auto a : adyList[u]) {
        if (num[a] == -1) {
            dfs(a);
        }
        if (inStack[a]) {
            low[u] = min(low[u], low[a]);
        }
    }
    if (low[u] == num[u]) { // Root of a SCC
        vi v;
        // Add all the nodes till u (included)
        int lim = inStack[u];
        while (st.size() && st.size() >= lim) {
            v.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
        }

        sccs.push_back(v);
    }
}
void TarjanSCC(int n) {
    low = num = vi(n, -1);
    inStack = vi(n, 0);
    st = stack<int>();
    cnt = 0;
    sccs = vector<vi>();

    for (int i = 0; i < n; ++i) {
        if (num[i] == -1) {
            dfs(i);
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
        int n, m;
        cin >> n >> m;
        adyList = vector<vi>(n, vi());
        int a, b;
        vector<pii> edges;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            a--;
            b--;
            adyList[a].pb(b);
            edges.pb({a, b});
        }
        TarjanSCC(n);
        int ncomp = sccs.size();
        map<int, int> comp;
        for (int i = 0; i < ncomp; ++i) {
            for (auto a : sccs[i]) {
                comp[a] = i;
            }
        }
        //cout << comp << endl;
        vi com(ncomp, 0);
        for (auto a : edges) {
            if (comp[a.fi] != comp[a.se]) {
                com[comp[a.se]]++;
            }
        }
        int res = 0;
        for (auto a : com) {
            if (!a)
                res++;
        }
        cout << res << "\n";
    }

    return 0;
}
//  11709__Trust groups.cpp
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
vector<vi> adyList;

vi low, num;
int cnt; // Counter for DFS
stack<int> st;
vi inStack;
vector<vi> sccs;

void dfs(int u) {
    low[u] = num[u] = cnt++;

    st.push(u);
    inStack[u] = true;
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
        while (!st.empty() && st.top() != u) {
            v.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
        }
        if (!st.empty()) { // Add u
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

    int p, t;
    while (cin >> p >> t && p) {
        map<string, int> people;
        string s;
        getline(cin, s);
        adyList = vector<vi>(p, vi());

        for (int i = 0; i < p; ++i) {
            getline(cin, s);
            people[s] = i;
        }
        string st;
        for (int j = 0; j < t; ++j) {
            getline(cin, s);
            getline(cin, st);

            adyList[people[s]].pb(people[st]);
        }
        TarjanSCC(p);
        cout << sccs.size() << "\n";
    }

    return 0;
}
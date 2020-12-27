//  00315__Network.cpp
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

vector<vi> adyList;
vi num;
vi low;
vi artic;
int cnt;
int rchild;
int root;
set<pii> bridges;

void dfs(int nparent, int nnode) {
    num[nnode] = low[nnode] = cnt++;
    if (nparent == root)
        rchild++;

    for (auto a : adyList[nnode]) {
        if (num[a] == -1) { // Tree edge
            dfs(nnode, a);
            low[nnode] = min(low[nnode], low[a]);
            if (low[a] >= num[nnode]) {
                artic[nnode] = true;
            }
            if (low[a] > num[nnode]) {
                //bridges.insert({nnode, a});
            }
        } else if (a != nparent) { // Back edge
            low[nnode] = min(low[nnode], num[a]);
        }
    }
}
void findArticulations(int n, int root) {
    cnt = rchild = 0;
    ::root = root;
    low = num = vi(n, -1);
    artic = vi(n, 0);
    bridges.clear();

    dfs(-1, 0);
    if (rchild == 1) { // Special case
        artic[root] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n && n) {
        adyList = vector<vi>(n, vi());
        int p;
        while (cin >> p && p) {
            p--;
            string s;
            getline(cin, s);
            stringstream ss(s);
            int a;
            while (ss >> a) {
                a--;
                adyList[p].pb(a);
                adyList[a].pb(p);
            }
        }
        /*
        cout << "ady\n";
        for (int i = 0; i < n; ++i) {
            cout << i << ": " << adyList[i] << endl;
        }
        */
        findArticulations(n, 0);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (artic[i])
                count++;
        }
        //cout << artic << endl;
        cout << count << "\n";
    }

    return 0;
}
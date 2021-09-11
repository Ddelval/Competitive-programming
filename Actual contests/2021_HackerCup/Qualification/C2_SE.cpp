//  C2_SE.cpp
//  Created by David del Val on 10/09/2021
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
vi gold;
vector<vi> children;

const int nlim = 55, klim = 55;
ll dp[nlim][nlim][klim][3][2];

ll go(int node, int child, int nPaths, int openEdges, int mustUseMe) {
    ll ans = -inf;
    if (dp[node][child][nPaths][openEdges][mustUseMe] != -1) {
        return dp[node][child][nPaths][openEdges][mustUseMe];
    }
    if (child >= children[node].size()) {
        ans = (mustUseMe && openEdges) ? gold[node] : 0;
        if (mustUseMe && !openEdges) {
            ans = -inf;
        }
        goto regist;
    }

    if (nPaths > 0 && openEdges == 0) {
        ll bonus = mustUseMe ? gold[node] : 0;
        ans = max(ans, bonus + go(node, child, nPaths - 1, 2, 0));
    }

    for (int pathsToGive = 0; pathsToGive <= nPaths; ++pathsToGive) {
        if (openEdges > 0) {
            ll myNext =
                go(node, child + 1, nPaths - pathsToGive, openEdges - 1, 0);
            ll theirNext = go(children[node][child], 0, pathsToGive, 1, 1);
            ll bonus = mustUseMe ? gold[node] : 0;
            ans = max(ans, myNext + theirNext + bonus);
        }
        ll myNext =
            go(node, child + 1, nPaths - pathsToGive, openEdges, mustUseMe);

        ll theirNext = go(children[node][child], 0, pathsToGive, 0, 0);
        theirNext =
            max(theirNext, go(children[node][child], 0, pathsToGive, 0, 1));
        ans = max(ans, myNext + theirNext);
    }

regist:
    dp[node][child][nPaths][openEdges][mustUseMe] = ans;
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
        int n, k;
        cin >> n >> k;
        gold = readVector<int>(n);
        children = vector<vi>(n, vi());
        vector<vi> chil(n, vi());
        for (int i = 0; i < n; ++i) {
            for (int i1 = 0; i1 < n; ++i1) {
                for (int i2 = 0; i2 <= k; ++i2) {
                    for (int i3 = 0; i3 < 3; ++i3) {
                        for (int i4 = 0; i4 < 2; ++i4) {
                            dp[i][i1][i2][i3][i4] = -1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            chil[a].pb(b);
            chil[b].pb(a);
        }

        queue<int> q;
        vi visited(n, 0);
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visited[current] = true;
            for (auto a : chil[current]) {
                if (!visited[a]) {
                    children[current].pb(a);
                    q.push(a);
                }
            }
        }
        cout << "Case #" << z++ << ": ";
        if (k == 0 || n == 1) {
            cout << gold[0] << "\n";
        } else {
            cout << go(0, 0, k, 0, 1) << "\n";
        }
    }

    return 0;
}
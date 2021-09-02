//  C1.cpp
//  Created by David del Val on 28/08/2021
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
vi seen;
vector<vi> adyList;
vl values;
vl doubleCost;
ll dfs(int cnode) {
    if (seen[cnode]) {
        return 0;
    }
    seen[cnode] = true;
    vl opts;
    for (auto nnode : adyList[cnode]) {
        ll ne = dfs(nnode);
        // cout << cnode << " " << nnode << " " << ne << endl;
        if (ne) {
            opts.push_back(ne);
        }
    }
    // echo(opts);
    ll best = 0;
    if (opts.size()) {
        sort(all(opts));
        best = opts.back();
        opts.pop_back();
        reverse(all(opts));
        for (int i = 0; i < opts.size(); ++i) {
            doubleCost.pb(opts[i]);
        }
    }

    return values[cnode] + best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int cas = 1;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        values = readVector(n);
        adyList = vector<vi>(n, vi());
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adyList[a].pb(b);
            adyList[b].pb(a);
        }
        vl branches;
        doubleCost.clear();
        seen = vi(n, 0);
        seen[0] = 1;
        for (int start : adyList[0]) {
            branches.pb(dfs(start));
        }
        sort(all(branches), greater<ll>());
        sort(all(doubleCost), greater<ll>());
        vl branchesPreSum(branches.size() + 1, 0);
        for (int i = 0; i < branches.size(); ++i) {
            branchesPreSum[i + 1] = branchesPreSum[i] + branches[i];
        }
        vl doublePreSum(doubleCost.size() + 1, 0);
        for (int i = 0; i < doubleCost.size(); ++i) {
            doublePreSum[i + 1] = doubleCost[i] + doublePreSum[i];
        }
        echo(branches);
        echo(doubleCost);
        ll sol = values[0];
        if (k && branches.size() > 0) {
            ll bestPossible = 0;
            for (int pickedBranches = 1; pickedBranches <= branches.size();
                 ++pickedBranches) {
                ll sol = branchesPreSum[pickedBranches];

                ll pathsCarved = pickedBranches / 2;
                ll pathsRemaining = k - pathsCarved - pickedBranches % 2;
                if (pathsRemaining < 0) {
                    break;
                }
                ll type2pickable = pathsRemaining + pickedBranches % 2;
                if (type2pickable >= 0) {
                    type2pickable = min(type2pickable, (ll)doubleCost.size());
                    sol += doublePreSum[type2pickable];
                }
                bestPossible = max(bestPossible, sol);
            }
            sol += bestPossible;
        }

        cout << "Case #" << cas++ << ": " << sol << "\n";
    }

    return 0;
}
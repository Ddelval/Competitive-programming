//  1534-F1.cpp
//  Created by David del Val on 01/07/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
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
const int lim = 400'000 + 10;
int boardd[lim];
int n, m;

int &board(int i, int j) {
    return boardd[i * m + j];
}

vi visited;
vector<vi> sccs;

void dfs(int nnode, vector<int> &v, vector<vi> &adyList) {
    if (visited[nnode]) {
        return;
    }
    visited[nnode] = true;
    for (auto a : adyList[nnode]) {
        dfs(a, v, adyList);
    }
    v.push_back(nnode);
}
void kosaraju(int n, vector<vi> &adyList) {
    visited = vi(n, 0);
    stack<int> s;
    sccs.clear();

    vi postorder;
    for (int i = 0; i < n; ++i) {
        dfs(i, postorder, adyList);
    }
    reverse(all(postorder));

    vector<vi> rAdyList = vector<vi>(n, vi());
    for (int i = 0; i < n; ++i) {
        for (auto v : adyList[i]) {
            rAdyList[v].push_back(i);
        }
    }

    visited = vi(n, 0);
    vi data;
    for (auto a : postorder) {
        if (!visited[a]) {
            data = vi();
            dfs(a, data, rAdyList);
            if (!data.empty()) {
                sccs.push_back(data);
            }
        }
    }
}

unordered_map<int, int> leftLimit, rightLimit, value, indicess;
vector<set<int>> sccAdyList;
set<int> importantSccs;
set<int> visitt;

pii calculateLimits(int nnode) {
    if (indicess.count(nnode)) {
        return make_pair(indicess[nnode], indicess[nnode]);
    }
    if (visitt.count(nnode)) {
        return make_pair(leftLimit[nnode], rightLimit[nnode]);
    }

    int left = iinf;
    int right = -iinf;

    for (auto a : sccAdyList[nnode]) {
        auto res = calculateLimits(a);
        left = min(left, res.fi);
        right = max(right, res.se);
    }
    leftLimit[nnode] = left;
    rightLimit[nnode] = right;
    visitt.insert(nnode);
    return make_pair(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    char a;
    int index = 0;
    vi first(m, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            if (a == '#') {
                board(i, j) = index++;
                if (first[j] == -1) {
                    first[j] = i;
                }
            } else {
                board(i, j) = -1;
            }
            //cout << setw(3) << board(i, j) << " ";
        }
        //cout << endl;
    }

    vi data = readVector<int>(m);
    unordered_map<int, int> specialNodes;
    for (int j = 0; j < m; ++j) {
        int count = 0;
        if (data[j] == 0) {
            continue;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (board(i, j) != -1) {
                count++;
            }
            if (count == data[j]) {
                specialNodes[board(i, j)] = j;
                break;
            }
        }
    }

    vector<vi> adyList(index, vi());
    for (int j = 0; j < m; ++j) {
        bool center, left, right;
        center = left = right = true;
        if (first[j] == -1) {
            continue;
        }
        int cnode = board(first[j], j);
        for (int i = first[j]; i < n; ++i) {
            if (center && board(i, j) != -1 && board(i, j) != cnode) {
                adyList[cnode].push_back(board(i, j));
                cnode = board(i, j);
                if (i && board(i - 1, j) != -1) {
                    adyList[cnode].push_back(board(i - 1, j));
                }
                left = right = true;
            }
            if (left && j && board(i, j - 1) != -1) {
                adyList[cnode].push_back(board(i, j - 1));
                left = false;
            }
            if (right && j != m - 1 && board(i, j + 1) != -1) {
                adyList[cnode].push_back(board(i, j + 1));
                right = false;
            }
        }
    }
    /*
    for (int i = 0; i < index; ++i) {
        cout << i << ":" << adyList[i] << "\n";
    }
    */

    kosaraju(index, adyList);
    vi needed(sccs.size(), 1);

    /*
    for (auto a : sccs) {
        cout << a << endl;
    }
    */

    unordered_map<int, int> nToScc;
    for (int i = 0; i < sccs.size(); ++i) {
        for (auto a : sccs[i]) {
            nToScc[a] = i;
        }
    }

    sccAdyList = decltype(sccAdyList)(sccs.size());

    for (int i = 0; i < sccs.size(); ++i) {
        for (auto a : sccs[i]) {
            for (auto b : adyList[a]) {
                if (nToScc[b] != i)
                    sccAdyList[i].insert(nToScc[b]);
            }
        }
    }

    /*
    cout << "Ady list:" << endl;
    for (int i = 0; i < sccAdyList.size(); ++i) {
        cout << i << ":" << sccAdyList[i] << "\n";
    }
    */

    for (auto a : specialNodes) {
        int scc = nToScc[a.fi];
        if (importantSccs.insert(scc).second) {
            value[scc] = a.se;
        } else {
            value[scc] = min(value[scc], a.se);
        }
    }

    vi toErase;
    for (auto it = importantSccs.begin(); it != importantSccs.end(); it++) {
        for (auto connected : sccAdyList[*it]) {
            if (importantSccs.count(connected)) {
                toErase.push_back(connected);
            }
        }
    }
    for (auto a : toErase) {
        importantSccs.erase(a);
    }
    vector<int> values;
    for (auto a : importantSccs) {
        values.push_back(value[a]);
    }

    sort(all(values));
    //cout << "values:" << values << endl;

    unordered_map<int, int> valuestoNodes;
    for (int i = 0; i < values.size(); ++i) {
        valuestoNodes[values[i]] = i;
    }
    for (auto a : importantSccs) {
        indicess[a] = valuestoNodes[value[a]];
    }

    /*
    cout << "Special nodes: " << specialNodes << endl;
    cout << "Special sccs: " << importantSccs << endl;
    */

    vector<pii> intervals;
    for (int i = 0; i < sccs.size(); ++i) {
        auto pa = calculateLimits(i);
        if (pa.fi == iinf && pa.se == -iinf) {
            continue;
        }
        intervals.pb(pa);
    }

    sort(all(intervals), [](pii &p1, pii &p2) {
        if (p1.fi != p2.fi) {
            return p1.fi < p2.fi;
        }
        return p1.se > p2.se;
    });

    vector<pii> intervals2;
    for (int i = 0; i < intervals.size(); ++i) {
        if (i && intervals[i - 1].fi == intervals[i].fi) {
            continue;
        }
        intervals2.push_back(intervals[i]);
    }
    int intervalIndex = -1;
    int ans = 0;
    int current_right = -1;
    int next_right = -1;
    //cout << "int2 " << intervals2 << endl;
    for (int i = 0; i < values.size(); ++i) {
        while (intervalIndex < (int)intervals2.size() - 1 && intervals2[intervalIndex + 1].first <= i) {
            intervalIndex++;
            next_right = max(next_right, intervals2[intervalIndex].second);
        }
        if (i > current_right) {
            current_right = next_right;
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
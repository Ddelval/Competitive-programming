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

template <typename T>
struct is_vector : std::false_type {};

template <typename U>
struct is_vector<vector<U>> : std::true_type {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            if (is_vector<typename T::value_type>::value) {
                o << "\n";
            } else {
                o << " ";
            }
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
    /**
    for (int i = 0; i < index; ++i) {
        cout << i << ":" << adyList[i] << "\n";
    }
    **/

    kosaraju(index, adyList);
    vi needed(sccs.size(), 1);
    /**
    for (auto a : sccs) {
        cout << a << endl;
    }
    **/
    unordered_map<int, int> nToScc;
    for (int i = 0; i < sccs.size(); ++i) {
        for (auto a : sccs[i]) {
            nToScc[a] = i;
        }
    }
    for (int i = 0; i < index; ++i) {
        for (auto conn : adyList[i]) {
            if (nToScc[conn] != nToScc[i]) {
                needed[nToScc[conn]] = 0;
            }
        }
    }
    int count = 0;
    for (auto a : needed) {
        count += a;
    }
    cout << count << "\n";

    return 0;
}
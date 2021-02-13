//  F.cpp
//  Created by David del Val on 13/02/2021
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

const int lim = 110;
int board[lim][lim];
int rows[lim][lim];
int cols[lim][lim];

vector<vector<ll>> adjList;
vector<vector<ll>> adjMat;

void initialize(int n) {
    adjList = decltype(adjList)(n);
    adjMat = decltype(adjMat)(n, vector<ll>(n, 0));
}

map<int, int> p;
bool bfs(int source, int sink) {
    queue<int> q;
    vi visited(adjList.size(), 0);
    q.push(source);
    visited[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == sink)
            return true;
        for (auto v : adjList[u]) {
            if (adjMat[u][v] > 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
                p[v] = u;
            }
        }
    }
    return false;
}
int max_flow(int source, int sink) {
    ll max_flow = 0;
    while (bfs(source, sink)) {
        ll flow = inf;
        for (int v = sink; v != source; v = p[v]) {
            flow = min(flow, adjMat[p[v]][v]);
        }
        for (int v = sink; v != source; v = p[v]) {
            adjMat[p[v]][v] -= flow; // Decrease capacity forward edge
            adjMat[v][p[v]] += flow; // Increase capacity backward edge
        }
        max_flow += flow;
    }
    return max_flow;
}
void addedgeUni(int orig, int dest, ll flow) {
    adjList[orig].pb(dest);
    adjMat[orig][dest] = flow;
    adjList[dest].pb(orig); //Add edge for residual flow
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;
    while (c--) {
        for (int i = 0; i < lim; ++i) {
            for (int j = 0; j < lim; ++j) {
                board[i][j] = 0;
            }
        }
        int h, w;
        cin >> h >> w;
        int p;
        cin >> p;
        int a, b;
        vector<pii> points;
        for (int i = 0; i < p; ++i) {
            cin >> a >> b;
            a--;
            b--;
            board[a][b] = i + 1;
            points.pb({a, b});
        }
        int W;
        cin >> W;
        for (int i = 0; i < W; ++i) {
            cin >> a >> b;
            a--;
            b--;
            board[a][b] = -1;
        }

        int rindex = 0;
        for (int i = 0; i < h; ++i) {

            bool found = false;
            for (int j = 0; j < w; ++j) {
                if (board[i][j] > 0) {
                    found = true;
                }
                if (board[i][j] == -1) {
                    if (found) {
                        rindex++;
                        found = false;
                    }
                } else {
                    rows[i][j] = rindex;
                }
            }
            if (found) {
                rindex++;
                found = false;
            }
        }
        int cindex = 0;
        for (int i = 0; i < w; ++i) {

            bool found = false;
            for (int j = 0; j < h; ++j) {
                if (board[j][i] > 0) {
                    found = true;
                }
                if (board[j][i] == -1) {
                    if (found) {
                        cindex++;
                        found = false;
                    }
                } else {
                    cols[j][i] = cindex;
                }
            }
            if (found) {
                cindex++;
                found = false;
            }
        }
        /*
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << rows[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << cols[i][j] << " ";
            }
            cout << endl;
        }*/

        vector<pii> pres;
        map<int, int> col;
        map<int, int> row;
        for (auto a : points) {
            if (!row.count(rows[a.fi][a.se])) {
                row[rows[a.fi][a.se]] = row.size();
            }
            if (!col.count(cols[a.fi][a.se])) {
                col[cols[a.fi][a.se]] = col.size();
            }
            pres.pb({row[rows[a.fi][a.se]], col[cols[a.fi][a.se]]});
        }
        //cout << pres;

        int nn = col.size() + row.size() + 10;
        initialize(nn);
        for (int i = 0; i < row.size();++i){
            addedgeUni(nn - 5, i, 1);
        }
        for (int j = 0; j < col.size();++j){
            addedgeUni(j + row.size(), nn - 4, 1);
        }
        for(auto a:pres){
            addedgeUni(a.fi,row.size()+a.se,1);
        }
        cout<<max_flow(nn-5,nn-4)<<"\n";
    }

    return 0;
}
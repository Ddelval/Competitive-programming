//  102694-B.cpp
//  Created by David del Val on 23/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

inline ostream& operator<<(ostream& o, pii p) {
    o << p.fi << " " << p.se;
    return o;
}

template <typename>
struct is_std_vector : std::false_type {};
template <typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type {};

template <typename T>
inline ostream& operator<<(ostream& o, vector<T>& p) {
    for (int i = 0; i < p.size(); ++i) {
        o << setw(3) << p[i];
        if (is_std_vector<T>::value) o << "\n";
    }
    return o;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int n;
vector<vi> adyList;
vector<int> findPath(int ini) {
    vi parent(n, -1);
    queue<int> q;
    q.push(ini);
    parent[ini] = -2;
    int last;
    while (!q.empty()) {
        last = q.front();
        q.pop();
        for (auto i : adyList[last]) {
            if (parent[i] == -1) {
                parent[i] = last;
                q.push(i);
            }
        }
    }
    vi path;
    while (last != -2) {
        path.pb(last);
        last = parent[last];
    }
    return path;
}
vi visited;
vi depth;
pii bfs(int inode, int idepth = 0) {
    queue<pii> q;
    q.push({inode, idepth});
    pii a;
    visited[inode] = true;
    depth[inode] = idepth;
    while (!q.empty()) {
        a = q.front();
        //cout << a << endl;
        q.pop();
        for (int i : adyList[a.fi]) {
            if (!visited[i]) {
                visited[i] = true;
                depth[i] = a.se + 1;
                q.push({i, a.se + 1});
            }
        }
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int a, b;
    adyList = vector<vi>(n, vi());
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--, b--;
        adyList[a].pb(b);
        adyList[b].pb(a);
    }
    visited = vi(n);
    depth = vi(n);
    int id = bfs(0).fi;
    vi path = findPath(id);
    //cout << "path: " << path << endl;
    visited = vi(n);
    depth = vi(n);
    for (auto a : path) visited[a] = true;

    for (int i = 0; i < path.size(); ++i) {
        int plen = max(i, (int)path.size() -1- i);
        //cout << "plen " << plen << endl;
        bfs(path[i], plen);
    }
    for (int i = 0; i < n; ++i) {
        if (depth[i] == path.size()-1) {
            cout << depth[i]+1 << "\n";
        } else {
            cout << path.size()-1 << "\n";
        }
    }

    return 0;
}
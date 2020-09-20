//  102694-A.cpp
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
pii bfs(int inode) {
    vi visited(n);
    queue<pii> q;
    q.push({inode, 0});
    pii a;
    visited[inode] = true;
    while (!q.empty()) {
        a = q.front();
        //cout << a << endl;
        q.pop();
        for (int i : adyList[a.fi]) {
            if (!visited[i]) {
                visited[i] = true;
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
    adyList = vector<vi>(n, vi());
    int a, b;

    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--, b--;
        adyList[a].pb(b);
        adyList[b].pb(a);
    }
    pii res1 = bfs(0);
    //cout << res1 << endl;
    cout << 3 * bfs(res1.fi).se << "\n";

    return 0;
}
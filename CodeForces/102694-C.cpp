//  102694-C.cpp
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

int n, q;

const int lim = 3e5;
vector<vi> adyList;

int lift[lim][30];
int level[lim];

void bfs(int inode) {
    queue<pii> q;

    q.push({inode, 0});
    level[inode] = 0;
    lift[inode][0] = -1;

    while (!q.empty()) {
        pii a = q.front();
        q.pop();
        //cout << "bfs: " << a << endl;
        for (auto b : adyList[a.fi]) {
            //cout << b << " " << level[b] << endl;
            if (level[b] == -5) {
                level[b] = a.se + 1;
                lift[b][0] = a.fi;
                q.push({b, a.se + 1});
            }
        }
    }
}

pii distanceToLCA(int n1, int n2) {
    pii distances(0, 0);
    bool swaped = false;
    if (level[n1] > level[n2]) {
        swap(n1, n2);
        swaped = true;
    }
    while (level[n1] < level[n2]) {
        int diff = level[n2] - level[n1];
        int i = 0;
        while ((1 << (i + 1)) <= diff) {
            i++;
        }
        distances.se += 1 << i;
        n2 = lift[n2][i];
    }

    if (n1 == n2) {
        if (swaped) {
            swap(distances.fi, distances.se);
        }
        return distances;
    }
    //cout << "d" << distances << endl;

    while (lift[n1][0] != lift[n2][0]) {
        int i = 0;
        while (lift[n1][i + 1] != lift[n2][i + 1]) {
            i++;
        }
        //cout << "ii" << i << endl;
        distances.fi += (1 << i);
        distances.se += (1 << i);
        n1 = lift[n1][i];
        n2 = lift[n2][i];
    }
    distances.fi++;
    distances.se++;
    if (swaped) swap(distances.fi, distances.se);
    return distances;
}

int goNup(int n, int orig) {
    //cout << "n" << n << "orig" << orig << endl;
    while (n) {
        int i = 0;
        while ((1 << (i + 1)) <= n) i++;
        //cout << "i" << i << endl;
        n -= (1 << i);
        orig = lift[orig][i];
    }
    return orig;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a, b;
    adyList.assign(n, vi());

    for (int i = 0; i < n; ++i) level[i] = -5;

    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--;
        b--;
        adyList[a].push_back(b);
        adyList[b].push_back(a);
    }

    bfs(0);
    for (int i = 1; i < 30; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lift[j][i - 1] != -1) {
                lift[j][i] = lift[lift[j][i - 1]][i - 1];
            } else {
                lift[j][i] = -1;
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << lift[i][j] << " ";
        }
        cout << endl;
    }*/

    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> a >> b >> c;
        a--, b--;
        pii data = distanceToLCA(a, b);
        //cout << "data " << data << endl;

        if (data.fi + data.se <= c) {
            cout << b + 1 << "\n";
        } else if (data.fi >= c) {
            cout << goNup(c, a) + 1 << "\n";
        } else if (data.fi + data.se > c) {
            //cout <<"a"<< data.se - (c - data.fi) << endl;
            cout << goNup(data.se - (c - data.fi), b) + 1 << "\n";
        }
    }

    return 0;
}
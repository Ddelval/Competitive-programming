//  001260__Sales.cpp
//  Created by David del Val on 25/11/2022
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



ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif
const int N = 5050;
ll tree[4 * N];

void add(int position, int value, int l, int r) {
    if (l > r) {
        return;
    }
    if (l == r) {
        tree[position]++;
        return;
    }
    if ((l + r) / 2 > value) {
        add(2 * position, value, l, (l + r) / 2);
    } else {
        add(2 * position + 1, value, (l + r) / 2 + 1, r);
    }
    tree[position] = tree[2 * position] + tree[2 * position + 1];
    // cout << position << " " << l << " " << r << " " << tree[position] <<
    // endl;
}
int query(int position, int l, int r, int cl, int cr) {
    if (l > cr || r < cl) {
        return 0;
    }
    if (l <= cl && r >= cr) {
        // cout << "include" << position << " " << cl << " " << cr << endl;
        return tree[position];
    } else {
        return query(2 * position, l, r, cl, (cl + cr) / 2) +
               query(2 * position + 1, l, r, (cl + cr) / 2 + 1, cr);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < N * 4; ++i) {
            tree[i] = 0;
        }
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vi b(n);
        add(1, a[0], 0, N - 1);
        ll accum = 0;
        for (int i = 1; i < n; ++i) {
            // cout << "i" << i << endl;
            // cout << "q " << query(1, 0, a[i]+1, 0, N - 1) << endl;
            accum += query(1, 0, a[i] + 1, 0, N - 1);
            add(1, a[i], 0, N - 1);
        }
        // cout << "a " << accum << endl;
        cout << accum << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll inf = LLONG_MAX / 10;
const int iinf = INT_MAX / 10;
const int M = 3e5 + 10;

// Range update and Point query
namespace seg1 {
ll tree[4 * M];
int qLeft;
int qRight;
int qDelta;

void _update(int current, int l, int r) {
    if (l > qRight || r < qLeft) {
        return;
    }
    if (l >= qLeft && r <= qRight) {
        tree[current] += qDelta;
        return;
    }
    int mid = (l + r) >> 1;
    _update(current << 1, l, mid);
    _update(current << 1 | 1, mid + 1, r);
}

ll _query(int current, int l, int r) {
    if (l == r) {
        return tree[current];
    }
    int mid = (l + r) >> 1;
    if (qLeft <= mid) {
        return tree[current] + _query(current << 1, l, mid);
    } else {
        return tree[current] + _query(current << 1 | 1, mid + 1, r);
    }
}

void update(int qLeft, int qRight, int qDelta) {
    seg1::qDelta = qDelta;
    seg1::qLeft = qLeft;
    seg1::qRight = qRight;
    _update(1, 0, M);
}


ll query(int position) {
    seg1::qLeft = position;
    return _query(1, 0, M);
}

} // namespace seg1
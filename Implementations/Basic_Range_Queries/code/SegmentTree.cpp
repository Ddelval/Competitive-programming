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
template <typename T, T (*merge)(T, T), T (*initialize)(int), const T &neutral>
class SegTree {
    int n;
    int ql, qr;
    T qValue;
    vector<T> tree;
    vector<T> lazy;

    void _build(int current, int l, int r) {
        lazy[current] = nil;
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
    }
    void push_down(int current) {
        if (lazy[current] == neutral) {
            return;
        }
        tree[current << 1] = merge(tree[current << 1], lazy[current]);
        tree[current << 1 | 1] = merge(tree[current << 1 | 1], lazy[current]);
        lazy[current << 1] = merge(lazy[current << 1], lazy[current]);
        lazy[current << 1 | 1] = merge(lazy[current << 1 | 1], lazy[current]);
        lazy[current] = neutral;
    }
    T _query(int current, int l, int r) {
        if (l > qr || r < ql) {
            return neutral;
        }
        if (l >= ql && r <= qr) {
            return tree[current];
        }
        push_down(current);
        int mid = (l + r) >> 1;
        T n1 = _query(current << 1, l, mid);
        T n2 = _query(current << 1 | 1, mid + 1, r);
        return merge(n1, n2);
    }

    void _update(int current, int l, int r) {
        if (l > qr || r < ql) {
            return;
        }
        if (l >= ql && r <= qr) {
            tree[current] = merge(tree[current], qValue);
            lazy[current] = merge(lazy[current], qValue);
            return;
        }
        push_down(current);
        int mid = (l + r) >> 1;
        _update(current << 1, l, mid);
        _update(current << 1 | 1, mid + 1, r);
        tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
    }

public:
    SegTree(int actualSize) : n(actualSize), tree(4 * n), lazy(4 * n) {
        _build(1, 0, n - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, n - 1);
    }
    void update(int l, int r, T value) {
        ql = l;
        qr = r;
        qValue = value;
        _update(1, 0, n - 1);
    }
};
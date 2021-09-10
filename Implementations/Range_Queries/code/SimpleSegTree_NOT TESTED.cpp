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


template <typename T, T (*merge)(T, T), T (*initialize)(int),
          T (*update_op)(T, T), const T &neutral>
class SimpleSegTree {
    int size;
    vector<T> tree;
    int ql, qr, uvalue, upos;

    void _build(int current, int l, int r) {
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merge(tree[current << 1], tree[current << 1 | 1]);
        }
    }
    T _query(int current, int l, int r) {
        if (l > qr || r < ql) {
            return neutral;
        }
        if (l >= ql && r <= qr) {
            return tree[current];
        }
        int mid = (l + r) >> 1;
        T n1 = _query(current << 1, l, mid);
        T n2 = _query(current << 1 | 1, mid + 1, r);
        return merge(n1, n2);
    }
    void _update(int current, int l, int r) {
        if (l == r) {
            tree[current] = update_op(tree[current], uvalue);
        } else {
            int mid = (l + r) >> 1;
            if (upos <= mid) {
                _update(current << 1, l, mid);
            } else {
                _update(current << 1 | 1, mid + 1, r);
            }
        }
    }

public:
    SimpleSegTree(int size) : size(size), tree(size, 0) {
        _build(1, 0, size - 1);
    }
    T query(int l, int r) {
        ql = l;
        qr = r;
        return query(1, 0, size - 1);
    }
    void updatePoint(int pos, int val) {
        upos = pos;
        uvalue = val;
        _update(1, 0, size - 1);
    }
};

/*
const ll zero = 0;
auto inizero = [](int index) { return 0ll; };
        auto mergesum = [](ll a, ll b) { return a + b; };
        auto updateInc = [](ll a, ll b) { return a + b; };
        SimpleSegTree<ll, mergesum, inizero, updateInc, zero> vertST(n),
            horST(m);
*/
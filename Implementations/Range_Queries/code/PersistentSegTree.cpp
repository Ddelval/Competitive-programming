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

struct node {
    node *l = nullptr, *r = nullptr;
    ll sum;
    node(ll val) : sum(val) {}
    node(node *l, node *r) : l(l), r(r), sum(0) {
        sum = (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};

struct PersistSegTree {
    static int ql, qr;
    static int pos, new_val;

    node *head = nullptr;
    int n;

    node *build(int l, int r) {
        if (l == r) {
            return new node(0);
        } else {
            int mid = (l + r) >> 1;
            return new node(build(l, mid), build(mid + 1, r));
        }
    }

    ll _query(node *current, int l, int r) {
        if (l > qr || r < ql) {
            return 0;
        }
        if (l >= ql && r <= qr) {
            return current->sum;
        }
        int mid = (l + r) >> 1;
        return _query(current->l, l, mid) + _query(current->r, mid + 1, r);
    }

    node *_update(node *current, int l, int r) {
        if (l == r) {
            return new node(new_val + current->sum);
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            node *n_l = _update(current->l, l, mid);
            return new node(n_l, current->r);
        } else {
            node *n_r = _update(current->r, mid + 1, r);
            return new node(current->l, n_r);
        }
    }

    PersistSegTree() {}
    PersistSegTree(int n) : n(n) { head = build(0, n - 1); }

    ll query(int left, int right) {
        ql = left;
        qr = right;
        return _query(this->head, 0, n - 1);
    }
    PersistSegTree update(int position, int increment) {
        pos = position;
        new_val = increment;
        PersistSegTree res;
        res.n = n;
        res.head = _update(this->head, 0, n - 1);
        return res;
    }
};
int PersistSegTree::ql, PersistSegTree::qr, PersistSegTree::pos,
    PersistSegTree::new_val;

int findKth(node *nl, node *nr, int l, int r, int target) {
    if (l == r) {
        return l;
    }
    int leftSum = nr->l->sum - nl->l->sum;
    int mid = (l + r) / 2;
    if (leftSum >= target) {
        // Going left
        return findKth(nl->l, nr->l, l, mid, target);
    } else {
        // Going right
        return findKth(nl->r, nr->r, mid + 1, r, target - leftSum);
    }
}
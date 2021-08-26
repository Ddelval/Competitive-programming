//  MKTHNUM.cpp
//  Created by David del Val on 26/08/2021
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

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T> struct subs_succeeded : std::true_type {};
template <> struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T> struct get_iter_res {
private:
    template <typename X> static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <> struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T> struct get_termination {
    static constexpr const char *get() { return sep1; }
};
template <typename U, typename S> struct get_termination<vector<U, S>> {
    static constexpr const char *get() { return sep2; }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator =
                get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll> inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) { return {a.fi + b.fi, a.se + b.se}; }

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

// gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi data = readVector<int>(n);
    unordered_map<int, int> toCompressed;
    unordered_map<int, int> fromCompressed;
    vi sdata = data;
    sort(all(sdata));
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || sdata[i] != sdata[i - 1]) {
            toCompressed[sdata[i]] = index;
            fromCompressed[index] = sdata[i];
            index++;
        }
    }
    vector<PersistSegTree> histograms;
    histograms.push_back(PersistSegTree(index));
    for (int i = 0; i < n; ++i) {
        int value = toCompressed[data[i]];
        echo(value);
        histograms.push_back(histograms.back().update(value, 1));
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        int res =
            findKth(histograms[l].head, histograms[r].head, 0, index - 1, k);
        echo(res);
        cout << fromCompressed[res] << "\n";
    }

    return 0;
}
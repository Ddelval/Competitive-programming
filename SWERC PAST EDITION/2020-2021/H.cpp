//  H.cpp
//  Created by David del Val on 23/08/2021
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
    int sum;
    node(int val) : sum(val) {}
    node(node *l, node *r) : l(l), r(r), sum(0) {
        sum = (l ? l->sum : 0) + (r ? r->sum : 0);
    }
};

class PersistSegTree {
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

    int _query(node *current, int l, int r) {
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
            return new node(new_val);
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

public:
    PersistSegTree() {}
    PersistSegTree(int n) : n(n) { head = build(0, n - 1); }

    int query(int left, int right) {
        ql = left;
        qr = right;
        return _query(this->head, 0, n - 1);
    }
    PersistSegTree update(int position, int newVal) {
        pos = position;
        new_val = newVal;
        PersistSegTree res;
        res.n = n;
        res.head = _update(this->head, 0, n - 1);
        return res;
    }
};
int PersistSegTree::ql, PersistSegTree::qr, PersistSegTree::pos,
    PersistSegTree::new_val;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    vector<PersistSegTree> versions;
    vi important;
    versions.push_back(PersistSegTree(n));
    important.push_back(0);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        stringstream ss(s);
        char c1;
        int p1;
        while (ss >> c1 >> p1) {
            int new_val;
            if (c1 == '+') {
                new_val = 1;
            } else {
                new_val = 0;
            }
            versions.push_back(versions.back().update(p1, new_val));
        }
        important.push_back(int(versions.size()) - 1);
    }
    int x = 0;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        echo(a);
        x = (x + versions[important[a]].query(x, n - 1)) % n;
        echo(x);
    }
    cout << x << "\n";

    return 0;
}
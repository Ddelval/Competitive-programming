//  D2.cpp
//  Created by David del Val on 12/09/2021
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
    int mi, minPos;
};
bool operator==(node n1, node n2) {
    return n1.mi == n2.mi && n1.minPos == n2.minPos;
}
const node nil = node{iinf, -1};
const node neutral = node{iinf, -1};

node merg(node a, node b) {
    if (a.mi <= b.mi) {
        return a;
    } else {
        return b;
    }
}
node merg(node a, int b) { return node{a.mi + b, a.minPos}; }
vi initial;
node initialize(int index) { return node{initial[index], index}; }

class SegTree {
    int n;
    int ql, qr;
    node qValue;
    int updateVal;
    vector<node> tree;
    vector<int> lazy;

    void _build(int current, int l, int r) {
        lazy[current] = 0;
        if (l == r) {
            tree[current] = initialize(l);
        } else {
            int mid = (l + r) >> 1;
            _build(current << 1, l, mid);
            _build(current << 1 | 1, mid + 1, r);
            tree[current] = merg(tree[current << 1], tree[current << 1 | 1]);
        }
    }
    void push_down(int current) {
        if (lazy[current] == 0) {
            return;
        }
        tree[current << 1] = merg(tree[current << 1], lazy[current]);
        tree[current << 1 | 1] = merg(tree[current << 1 | 1], lazy[current]);
        lazy[current << 1] = lazy[current << 1] + lazy[current];
        lazy[current << 1 | 1] = lazy[current << 1 | 1] + lazy[current];
        lazy[current] = 0;
    }
    node _query(int current, int l, int r) {
        if (l > qr || r < ql) {
            return neutral;
        }
        if (l >= ql && r <= qr) {
            return tree[current];
        }
        push_down(current);
        int mid = (l + r) >> 1;
        node n1 = _query(current << 1, l, mid);
        node n2 = _query(current << 1 | 1, mid + 1, r);
        return merg(n1, n2);
    }

    void _update(int current, int l, int r) {
        if (l > qr || r < ql) {
            return;
        }
        if (l >= ql && r <= qr) {
            tree[current] = merg(tree[current], updateVal);
            lazy[current] = lazy[current] + updateVal;
            return;
        }
        push_down(current);
        int mid = (l + r) >> 1;
        _update(current << 1, l, mid);
        _update(current << 1 | 1, mid + 1, r);
        tree[current] = merg(tree[current << 1], tree[current << 1 | 1]);
    }
    void _updatePoint(int current, int l, int r) {
        if (l == r) {
            tree[current] = qValue;
            return;
        }
        push_down(current);
        int mid = (l + r) >> 1;
        if (ql <= mid) {
            _updatePoint(current << 1, l, mid);
        } else {
            _updatePoint(current << 1 | 1, mid + 1, r);
        }
        tree[current] = merg(tree[current << 1], tree[current << 1 | 1]);
    }

public:
    SegTree(int actualSize) : n(actualSize), tree(4 * n), lazy(4 * n) {
        _build(1, 0, n - 1);
    }
    node query(int l, int r) {
        ql = l;
        qr = r;
        return _query(1, 0, n - 1);
    }
    void update(int l, int r, int val) {
        ql = l;
        qr = r;
        updateVal = val;
        _update(1, 0, n - 1);
    }
    void point_update(int pos, node n) {
        ql = pos;
        qr = pos;
        qValue = n;
        _updatePoint(1, 0, this->n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int totalSize = n * m;
        vi data = readVector<int>(totalSize);
        vi data2 = data;
        sort(all(data2));
        initial = vi(totalSize);
        for (int i = 0; i < n; ++i) {
            int value = 0;
            for (int j = m - 2; j >= 0; j--) {
                if (data2[i * m + j] < data2[i * m + j + 1]) {
                    value = m - 1 - j;
                }
                initial[i * m + j] = value;
            }
        }
        echo(initial);
        SegTree segTree(n * m);
        int start = 0;
        map<int, pii> ranges;
        map<int, int> cPos;
        map<int, int> prev;
        for (int i = 1; i < totalSize; ++i) {
            if (data2[i] != data2[i - 1]) {
                prev[data2[i]] = data2[i - 1];
            }
        }
        for (int i = 1; i < totalSize; ++i) {
            if (data2[i] != data2[i - 1]) {
                ranges[data2[i - 1]] = {start, i - 1};
                start = i;
            }
        }
        ranges[data2.back()] = {start, totalSize - 1};
        echo(ranges);

        ll ans = 0;
        for (int i = 0; i < totalSize; ++i) {
            int elem = data[i];
            int pos = ranges[elem].first + cPos[elem];
            cPos[elem]++;
            auto miNode = segTree.query(pos, pos);
            ans += miNode.mi;
            db(cout << elem << " " << ans << endl;);
            if (elem != 1) {
                int row = miNode.minPos / m;
                int prevEnd = ranges[prev[elem]].se;
                int prevEndRow = prevEnd / m;
                echo(row);
                echo(prevEndRow);
                if (row == prevEndRow) {
                    echo(m * row);
                    segTree.update(m * row, prevEnd, -1);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
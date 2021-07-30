//  11402__Ahoy, Pirates!_2.cpp
//  Created by David del Val on 30/07/2021
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

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

struct QueryData {
    int left;
    int right;
    int qtype;
};
int calculate(int size, int value, int qtype) {
    if (qtype == 0) {
        return size;
    } else if (qtype == 1) {
        return 0;
    } else if (qtype == 2) {
        return size - value;
    }
    return value;
}
int mergeOperation(int prev, int newOp) {
    if (prev == -1) {
        return newOp;
    }
    if (newOp == -1) {
        return prev;
    }
    if (newOp == 0 || newOp == 1) {
        return newOp;
    }
    // newOp=2 (switch)
    if (prev == 0) {
        return 1;
    }
    if (prev == 1) {
        return 0;
    } else {
        return -1;
    }
}
// Keeps track of the number of Buccanner Pirates in the range
class SegTree {
    struct node {
        int elem, lazy, size;
    };
    int n;
    node *nodes;

    QueryData qData;

    void build(vi &data, int vertex, int l, int r) {
        nodes[vertex].size = r - l + 1;
        nodes[vertex].lazy = -1;
        if (l == r) {
            nodes[vertex].elem = data[l];
        } else {
            int half = (l + r) >> 1;
            build(data, vertex << 1, l, half);
            build(data, (vertex << 1) + 1, half + 1, r);
            recalculate_node(vertex);
        }
    }
    void recalculate_node(int vertex) {
        nodes[vertex].elem =
            nodes[(vertex << 1)].elem + nodes[(vertex << 1) + 1].elem;
    }

    int _query(int vertex, int curr_l, int curr_r) {
        if (curr_r < qData.left || curr_l > qData.right) {
            return 0;
        }
        if (curr_l >= qData.left && curr_r <= qData.right) {
            return nodes[vertex].elem;
        }
        push(vertex);
        int half = (curr_l + curr_r) >> 1;
        return _query(vertex << 1, curr_l, half) +
               _query((vertex << 1) + 1, half + 1, curr_r);
    }

    void push(int parent, int child) {
        nodes[child].lazy =
            mergeOperation(nodes[child].lazy, nodes[parent].lazy);
        nodes[child].elem =
            calculate(nodes[child].size, nodes[child].elem, nodes[parent].lazy);
    }
    void push(int vertex) {
        if (nodes[vertex].lazy == -1)
            return;

        push(vertex, vertex << 1);
        push(vertex, vertex << 1 | 1);

        nodes[vertex].lazy = -1;
    }

    void _update(int vertex, int curr_l, int curr_r) {
        if (curr_r < qData.left || curr_l > qData.right) {
            return;
        }
        if (curr_l >= qData.left && curr_r <= qData.right) {
            nodes[vertex].elem =
                calculate(nodes[vertex].size, nodes[vertex].elem, qData.qtype);
            nodes[vertex].lazy =
                mergeOperation(nodes[vertex].lazy, qData.qtype);
        } else {
            push(vertex);
            int mid = (curr_l + curr_r) >> 1;
            _update(vertex << 1, curr_l, mid);
            _update((vertex << 1) + 1, mid + 1, curr_r);
            recalculate_node(vertex);
        }
    }
    void preorder(int vertex) {
        if (vertex < 2 * n && nodes[vertex].size != 0) {
            cout << "vertex: " << vertex << "| value = " << nodes[vertex].elem
                 << " "
                 << "lazy =" << nodes[vertex].lazy << endl;
            preorder(vertex << 1);
            preorder((vertex << 1) + 1);
        }
    }

public:
    SegTree(vi &data) : n(data.size()) {
        nodes = new node[4 * n];
        build(data, 1, 0, n - 1);
    }
    ~SegTree() { delete[] nodes; }

    // Query with both indeces included
    int query(int left, int right) {
        qData.left = left;
        qData.right = right;
        return _query(1, 0, n - 1);
    }

    void update(int l, int r, int type) {
        qData.left = l;
        qData.right = r;
        qData.qtype = type;
        _update(1, 0, n - 1);
    }
    void print() { preorder(1); }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int tt = 1;
    while (t--) {
        int m;
        cin >> m;
        string s;
        string s2;
        int n;
        for (int i = 0; i < m; ++i) {
            cin >> n;
            cin >> s2;
            while (n--) {
                s.append(s2);
            }
        }
        n = s.size();
        vi data(n);
        for (int i = 0; i < s.size(); ++i) {
            data[i] = (s[i] - '0');
        }
        SegTree segt(data);
        int q;
        cin >> q;
        char c;
        int a, b;
        int z = 0;
        /*
        cout << data << endl;
        for (int i = 0; i < n; ++i) {
            cout << segt.query(i, i);
        }
        cout << endl;
        */
        cout << "Case " << tt++ << ":\n";
        while (q--) {
            cin >> c >> a >> b;
            switch (c) {
            case 'F':
                segt.update(a, b, 0);
                break;
            case 'E':
                segt.update(a, b, 1);
                break;
            case 'I':
                segt.update(a, b, 2);
                break;
            case 'S':
                cout << "Q" << ++z << ": " << segt.query(a, b) << "\n";
                break;
            }
            /*
            segt.print();
            for (int i = 0; i < n; ++i) {
                cout << segt.query(i, i);
            }
            cout << endl;
            segt.print();
            cout << endl;
            cout << endl;
            */
        }
    }

    return 0;
}
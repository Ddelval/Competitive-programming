//  12532__Interval Product.cpp
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
    int target;
    int new_value;
};
class SegTree {
    int n;
    vi tree;
    QueryData qData;

    void build(vi &data, int vertex, int l, int r) {
        if (l == r) {
            tree[vertex] = data[l];
        } else {
            int half = (l + r) >> 1;
            build(data, vertex << 1, l, half);
            build(data, (vertex << 1) + 1, half + 1, r);
            recalculate_node(vertex);
        }
    }
    void recalculate_node(int vertex) {
        tree[vertex] = tree[(vertex << 1)] * tree[(vertex << 1) + 1];
    }
    int query(int vertex, int curr_l, int curr_r) {
        // cout << curr_l << " " << curr_r << endl;
        if (curr_r < qData.left || curr_l > qData.right) {
            return 1;
        }
        if (curr_l >= qData.left && curr_r <= qData.right) {
            return tree[vertex];
        }
        int half = (curr_l + curr_r) >> 1;
        return query(vertex << 1, curr_l, half) *
               query((vertex << 1) + 1, half + 1, curr_r);
    }

    void point_update(int vertex, int curr_l, int curr_r) {
        if (curr_l == curr_r) {
            tree[vertex] = qData.new_value;
        } else {
            int mid = (curr_l + curr_r) >> 1;
            if (qData.target <= mid) {
                point_update((vertex << 1), curr_l, mid);
            } else {
                point_update((vertex << 1) + 1, mid + 1, curr_r);
            }
            recalculate_node(vertex);
        }
    }

public:
    SegTree(vi &data) : n(data.size()), tree(4 * n, 0) {
        build(data, 1, 0, n - 1);
    }

    // Query with both indeces included
    int query(int left, int right) {
        qData.left = left;
        qData.right = right;
        return query(1, 0, n - 1);
    }

    void update(int position, int value) {
        qData.target = position;
        qData.new_value = value;
        point_update(1, 0, n - 1);
    }
};

int only_sign(int a) {
    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    while (cin >> n >> k) {
        vi data;
        data.reserve(n);
        int a;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            data.pb(only_sign(a));
        }
        // cout << data << endl;
        SegTree seg(data);
        char c;
        int b;
        for (int i = 0; i < k; ++i) {
            cin >> c;
            if (c == 'C') {
                cin >> a >> b;
                seg.update(a - 1, only_sign(b));
            } else {
                cin >> a >> b;
                a--, b--;
                int res = seg.query(a, b);
                if (res == 1) {
                    cout << "+";
                } else if (res == -1) {
                    cout << "-";
                } else {
                    cout << "0";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
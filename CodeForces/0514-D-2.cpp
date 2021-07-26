//  0514-D.cpp
//  Created by David del Val on 05/07/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
class rmq {
    vl data;
    int n, rowSize;
    vi mask, sparseTable;
    static const int blockSize = 30;
    std::function<ll(ll, ll)> f;

public:
    rmq(const vl &v, decltype(f) function) : data(v), n(v.size()), mask(n),
                                             sparseTable(n), f(function) {
        rowSize = n / blockSize;
        build_mask();
        build_sparse_table();
    }

    ll query(int l, int r) {
        // Small query
        if (r - l + 1 <= blockSize) {
            return data[small_query_index(r, r - l + 1)];
        }

        // Get the result for the endpoints
        int ans = op(small_query_index(l + blockSize - 1), small_query_index(r));

        // Query the sparse table
        int x = l / blockSize + 1, y = r / blockSize - 1;

        if (x <= y) {
            // Row to query
            int j = msb_index(y - x + 1);

            ans = op(ans, op(sparseTable[rowSize * j + x],
                             sparseTable[rowSize * j + y - (1 << j) + 1]));
        }
        return data[ans];
    }

private:
    int &SparseTable(int power, int elem) {
        return sparseTable[rowSize * power + elem];
    }
    static int lsb(int x) {
        return x & -x;
    }
    static int msb_index(int x) {
        return __builtin_clz(1) - __builtin_clz(x);
    }

    // Get the index that contains the answer for the small
    // query
    int small_query_index(int r, int size = blockSize) {
        int dist_from_r = msb_index(mask[r] & ((1 << size) - 1));

        return r - dist_from_r;
    }

    // Return the index that contins the result of the operation
    int op(int index1, int index2) {
        return f(data[index1], data[index2]) == data[index1] ? index1 : index2;
    }
    void build_mask() {
        int current_mask = 0;
        // We use this mask so that we only keep track of the at most
        // the size of the block bits
        int discard_mask = (1 << blockSize) - 1;
        for (int i = 0; i < n; ++i) {
            current_mask = (current_mask << 1) & discard_mask;

            while (current_mask > 0 && op(i, i - msb_index(lsb(current_mask))) == i) {
                // Current value is smaller than the value represented by the
                //last 1 in curr_mask, so that bit should be off
                current_mask ^= lsb(current_mask);
            }
            current_mask |= 1;
            mask[i] = current_mask;
        }
    }
    void build_sparse_table() {
        // Fill first row
        for (int i = 0; i < rowSize; ++i) {
            sparseTable[i] = small_query_index(blockSize * (i + 1) - 1);
        }
        for (int j = 1; (1 << j) <= rowSize; ++j) {
            for (int i = 0; i + (1 << j) <= rowSize; ++i) {
                int previousStep = 1 << (j - 1);
                sparseTable[rowSize * j + i] = op(sparseTable[rowSize * (j - 1) + i],
                                                  sparseTable[rowSize * (j - 1) + i + previousStep]);
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    ll a;
    vector<vl> drones(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            drones[j].pb(a);
        }
    }
    vector<rmq> tables;
    for (int j = 0; j < m; ++j) {
        tables.push_back(rmq(drones[j], [](ll a, ll b) { return max(a, b); }));
    }
    vi sol(m, 0);
    ll ans = 0;
    int right = 0;
    for (int left = 0; left < n; ++left) {
        while (right < left) {
            right++;
        }
        while (right < n) {
            ll shots = 0;
            for (auto &a : tables) {
                shots += a.query(left, right);
            }
            if (shots > k) {
                break;
            }
            if (right - left + 1 > ans) {
                for (int i = 0; i < m; ++i) {
                    sol[i] = tables[i].query(left, right);
                }
                ans = right - left + 1;
            }
            right++;
        }
    }

    cout << sol << endl;

    return 0;
}
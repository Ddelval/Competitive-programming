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

class rmq {
    vl data;
    int n, rowSize;
    vi mask, sparseTable;
    static const int blockSize = 30;
    std::function<ll(ll, ll)> f;

public:
    rmq(const vl &v, decltype(f) function)
        : data(v), n(v.size()), mask(n), sparseTable(n), f(function) {
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
        int ans =
            op(small_query_index(l + blockSize - 1), small_query_index(r));

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
    static int lsb(int x) { return x & -x; }
    static int msb_index(int x) { return __builtin_clz(1) - __builtin_clz(x); }

    // Get the index that contains the answer for the small query
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

            while (current_mask > 0 &&
                   op(i, i - msb_index(lsb(current_mask))) == i) {
                // Current value is smaller than the value represented by the
                // last 1 in curr_mask, so that bit should be off
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
                sparseTable[rowSize * j + i] =
                    op(sparseTable[rowSize * (j - 1) + i],
                       sparseTable[rowSize * (j - 1) + i + previousStep]);
            }
        }
    }
};
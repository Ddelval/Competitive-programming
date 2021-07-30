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

// Return lsb
int LSOne(int a) {
    return a & (-a);
}

template <typename T>
class FenwickTree {
private:
    vector<T> ft;

public:
    FenwickTree(const vector<T> &data)
        : ft(data.size() + 1, 0) {
        for (int i = 0; i < data.size(); ++i) {
            adjust(i, data[i]);
        }
    }

    //RSQ in range [0, index]
    T rsq(int index) {
        index++;
        T sum = 0;
        while (index != 0) {
            sum += ft[index];
            index -= LSOne(index); // Delete the lsb
        }
        return sum;
    }
    //RSQ in range [begin, end]
    T rsq(int begin, int end) {
        return begin == 0 ? rsq(end) : rsq(end) - rsq(begin - 1);
    }

    // Add the delta to the index element
    void adjust(int index, T delta) {
        index++;
        while (index < ft.size()) {
            ft[index] += delta;
            index += LSOne(index);
        }
    }
};
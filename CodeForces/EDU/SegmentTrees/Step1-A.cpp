//  Step1-A.cpp
//  Created by David del Val on 27/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

inline ostream& operator<<(ostream& o, pii p) {
    o << p.fi << " " << p.se;
    return o;
}

template <typename>
struct is_std_vector : std::false_type {};
template <typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type {};

template <typename T>
inline ostream& operator<<(ostream& o, vector<T>& p) {
    for (int i = 0; i < p.size(); ++i) {
        o << setw(3) << p[i];
        if (is_std_vector<T>::value) o << "\n";
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    int a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

struct SegTree {
    SegTree *right = nullptr, *left = nullptr;
    ll val = -1;
    int rlim, llim;

    SegTree(int llim, int rlim, vector<int>& vec) : rlim{rlim}, llim{llim} {
        if (rlim == llim)
            val = vec[rlim];
        else {
            int mid = (rlim + llim) / 2;
            left = new SegTree(llim, mid, vec);
            right = new SegTree(mid + 1, rlim, vec);
            recalc();
        }
    }
    void recalc() {
        this->val = right->val + left->val;
    }
    void OneUpdate(int index, int val) {
        if (rlim == llim)
            this->val = val;
        else {
            if (index <= left->rlim)
                left->OneUpdate(index, val);
            else
                right->OneUpdate(index, val);
            recalc();
        }
    }
    ll rangeSum(int llim, int rlim) {
        if (llim > this->rlim || rlim < this->llim) return 0;
        if (llim <= this->llim && rlim >= this->rlim) return this->val;
        return right->rangeSum(llim, rlim) + left->rangeSum(llim, rlim);
    }
    void print(string indent = "") {
        cout << indent << val << endl;
        if (left) left->print(indent + "--");
        if (right) right->print(indent + "--");
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vi data = readVector<int>(n);
    SegTree st(0, n - 1, data);

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            st.OneUpdate(b, c);
        } else {
            cout << st.rangeSum(b, c - 1) << "\n";
        }
        }

    return 0;
}
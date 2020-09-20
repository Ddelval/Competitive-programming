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

template <typename T, typename Q>
inline ostream& operator<<(ostream& o, pair<T, Q> p) {
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
    ll val;
    int rlim, llim;

    SegTree(int llim, int rlim, vector<int>& vec) : rlim{rlim}, llim{llim} {
        if (rlim == llim) {
            val = vec[rlim];
        }

        else {
            int mid = (rlim + llim) / 2;
            left = new SegTree(llim, mid, vec);
            right = new SegTree(mid + 1, rlim, vec);
            recalc();
        }
    }
    void recalc() {
        this->val = max(left->val, right->val);
    }
    void OneUpdate(int index, int value) {
        if (rlim == llim) {
            this->val = value;
        } else {
            if (index <= left->rlim)
                left->OneUpdate(index, value);
            else
                right->OneUpdate(index, value);
            recalc();
        }
    }

    ll Query(int value) {
        if (this->rlim == this->llim) {
            if (this->val >= value)
                return this->rlim;
            else
                return -1;
        }
        if (this->left->val >= value) {
            return this->left->Query(value);
        } else {
            return this->right->Query(value);
        }
    }

    void print(string indent = "") {
        cout << indent << val << "    ->" << this << endl;
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
    vi arr = readVector<int>(n);
    SegTree st(0, n - 1, arr);

    /*st.print();
    cout << "-----" << endl;*/
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a == 1) {
            cin >> c;
            st.OneUpdate(b, c);
        } else
            cout << st.Query(b) << "\n";
    }

    return 0;
}
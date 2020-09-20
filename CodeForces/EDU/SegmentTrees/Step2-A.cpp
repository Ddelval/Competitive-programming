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

pll operation(pll o1, pll o2) {
    pll a = o1;
    if (o2.fi < a.fi) {
        a = o2;
    } else if (o2.fi == o1.fi) {
        a.se += o2.se;
    }
    return a;
}
struct SegTree {
    SegTree *right = nullptr, *left = nullptr;
    ll val;
    ll sum;
    ll ending, begining;
    int rlim, llim;

    SegTree(int llim, int rlim, vector<int>& vec) : rlim{rlim}, llim{llim} {
        if (rlim == llim) {
            sum = vec[rlim];
            val = max(0ll, sum);
            ending = val;
            begining = val;
        }

        else {
            int mid = (rlim + llim) / 2;
            left = new SegTree(llim, mid, vec);
            right = new SegTree(mid + 1, rlim, vec);
            recalc();
        }
    }
    void recalc() {
        this->ending = max(right->ending, right->sum + left->ending);
        this->begining = max(left->begining, right->begining + left->sum);
        this->val = max(left->ending + right->begining, max(left->val, right->val));
        this->sum = right->sum + left->sum;
    }
    void OneUpdate(int index, int value) {
        if (rlim == llim) {
            sum = value;
            val = max(0ll, sum);
            ending = val;
            begining = val;
        } else {
            if (index <= left->rlim)
                left->OneUpdate(index, value);
            else
                right->OneUpdate(index, value);
            recalc();
        }
    }

    ll Query() {
        return val;
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

    /* st.print();
    cout << endl
         << "----------" << endl;*/
    int a, b, c;
    cout << st.Query() << "\n";
    for (int i = 0; i < m; ++i) {
        cin >> b >> c;
        st.OneUpdate(b, c);
        cout << st.Query() << "\n";
        /*st.print();
        cout << endl
             << "----------" << endl;*/
    }

    return 0;
}
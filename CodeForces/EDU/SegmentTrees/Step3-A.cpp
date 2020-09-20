//  Step3-A.cpp
//  Created by David del Val on 28/08/2020
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
    SegTree *left = nullptr, *right = nullptr;
    int leftmost, rightmost;
    int sum;

    SegTree(int l, int r, vector<int>& values) : leftmost{l}, rightmost{r} {
        if (l == r)
            sum = values[l];
        else {
            int mid = (l + r) / 2;
            left = new SegTree(l, mid, values);
            right = new SegTree(mid + 1, r, values);
            recalculate();
        }
    }
    void recalculate() {
        sum = right->sum + left->sum;
    }

    ll query(int l, int r) {
        if (l > rightmost || r < leftmost) return 0;
        if (l <= leftmost && r >= rightmost) return sum;
        return right->query(l, r) + left->query(l, r);
    }

    void set(int index, int val) {
        if (leftmost == rightmost)
            sum = val;
        else {
            if (index <= left->rightmost)
                left->set(index, val);
            else
                right->set(index, val);
            recalculate();
        }
    }
    void print(string s = "") {
        cout << s << sum << endl;
        if (left) left->print(s + "--");
        if (right) right->print(s + "--");
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vi data = readVector<int>(n);
    vi map = vi(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        map[data[i]] = i;
    }
    vi d2 = vi(n, 1);
    SegTree st(0, n - 1, d2);
    //st.print();
    //cout << "------\n";

    vi res(n, 0);
    for (int i = 1; i <= n; ++i) {
        //if (i) cout << " ";
        res[i-1] = st.query(0, map[i] - 1);
        st.set(map[i], 0);
        //st.print();
        //cout << "------\n";
    }
    //cout << res << endl;
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << res[data[i] - 1];
    }
    cout << "\n";
    return 0;
}
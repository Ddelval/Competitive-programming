//  1553-F.cpp
//  Created by David del Val on 05/08/2021
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
const int M = 3e5+10;

// Range update and Point query
namespace seg1 {
ll tree[4 * M];
int qLeft;
int qRight;
int qDelta;

void _update(int current, int l, int r) {
    if (l > qRight || r < qLeft) {
        return;
    }
    if (l >= qLeft && r <= qRight) {
        tree[current] += qDelta;
        return;
    }
    int mid = (l + r) >> 1;
    _update(current << 1, l, mid);
    _update(current << 1 | 1, mid + 1, r);
}

void update(int qLeft, int qRight, int qDelta) {
    seg1::qDelta = qDelta;
    seg1::qLeft = qLeft;
    seg1::qRight = qRight;
    _update(1, 0, M);
}

ll _query(int current, int l, int r) {
    if (l == r) {
        return tree[current];
    }
    int mid = (l + r) >> 1;
    if (qLeft <= mid) {
        return tree[current] + _query(current << 1, l, mid);
    } else {
        return tree[current] + _query(current << 1 | 1, mid + 1, r);
    }
}
ll query(int position) {
    seg1::qLeft = position;
    return _query(1, 0, M);
}

} // namespace seg1

// Point update and Range query
namespace seg2 {
ll tree[4 * M];
int qLeft, qRight, qValue;

void _update(int current, int l, int r) {
    if (l == r) {
        tree[current] += qValue;
        return;
    }
    int mid = (l + r) >> 1;
    if (qLeft <= mid) {
        _update(current << 1, l, mid);
    } else {
        _update(current << 1 | 1, mid + 1, r);
    }
    tree[current] = tree[current << 1] + tree[current << 1 | 1];
}
void update(int pos, int val) { qLeft = pos, qValue = val, _update(1, 0, M); }

ll _query(int current, int l, int r) {
    // db(cout << "seg2:_query " << current << " " << l << " " << r << endl);
    if (l > qRight || r < qLeft) {
        return 0;
    }
    if (l >= qLeft && r <= qRight) {
        return tree[current];
    }
    int mid = (l + r) >> 1;
    ll v1 = _query(current << 1, l, mid);
    return v1 + _query(current << 1 | 1, mid + 1, r);
}

ll query(int left, int right) {
    qLeft = left, qRight = right;
    return _query(1, 0, M);
}
} // namespace seg2

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll a;
    ll ans = 0;
    ll presum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ans += i * a;
        ans += presum;
        presum += a;

        ans += seg1::query(a);
        echo(seg1::query(a));

        for (int j = a; j <= M; j += a) {
            int l = j, r = min(j + (a - 1), (ll)M);
            ans -= a * seg2::query(l, r) * (j / a);

            seg1::update(l, r, -a * (j / a));
        }
        seg2::update(a, 1);
        cout << ans << " \n"[i == n - 1];
    }

    return 0;
}
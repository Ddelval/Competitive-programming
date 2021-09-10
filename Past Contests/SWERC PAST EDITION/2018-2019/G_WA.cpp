//  G.cpp
//  Created by David del Val on 12/02/2021
//
//

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

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
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

string s0;
int n;
vector<ll> presums0;
ll mod = 1000000007ll;

struct node {
    bool concatenate;
    ll r1, r2; //Concatenation indices;
    int targ;  // Substring target
    ll l, r;   // Substring indices;
    ll length;
    bool calculated = false;
    ll res;
    bool isZero = false;
    int id;

    friend ostream &operator<<(ostream &o, const node &n);
};

ostream &operator<<(ostream &o, const node &n) {
    o << "(";
    if (n.concatenate) {
        o << "Concatenating " << n.r1 << " " << n.r2;
    } else {
        o << "Substring of " << n.targ << " indices: " << n.l << " " << n.r;
    }
    o << "; " << n.length << " " << n.calculated << " " << n.res << ")";
    return o;
}

vector<node> nodes;
ll explore(node &n);

void calculate_length(node &node) {
    //cout << node << endl;
    if (node.concatenate) {
        node.length = nodes[node.r1].length + nodes[node.r2].length;
    } else {
        node.length = node.r - node.l;
    }
}
ll getPresum0(ll l, ll r) {
    return (presums0[r] - presums0[l] + mod) % mod;
}

ll calculate_substring(node &n, ll l, ll r) {
    //cout << "Substring: "<<l << " " << r << "\t\t" << n << endl;
    if (l < 0) {
        l = 0;
    }
    if (r > n.length) {
        r = n.length;
    }
    if (l >= r) {
        return 0;
    }
    if (l == 0 && r == n.length) {
        return explore(n) % mod;
    }

    if (n.isZero) {
        return getPresum0(l, r);
    } else {
        //cout << l << " " << r << "\t-\t" << n << endl;
        if (n.concatenate) {
            node &left = nodes[n.r1];
            node &right = nodes[n.r2];

            ll ans = 0;

            ans += calculate_substring(left, l, r);
            ans += calculate_substring(right, l - left.length, r - left.length);
            return ans % mod;

        } else {
            return calculate_substring(nodes[n.targ], n.l + l, n.l + r) % mod;
        }
    }
}

ll explore(node &n) {

    if (n.calculated) {
        return n.res;
    }
    //cout << "Explore " << n << endl;
    if (n.concatenate) {
        n.res = (explore(nodes[n.r1]) + explore(nodes[n.r2])) % mod;
        n.calculated = true;
    } else {
        n.res = calculate_substring(nodes[n.targ], n.l, n.r) % mod;
        n.calculated = true;
    }
    return n.res;
}
ll calculate(string s) {
    ll ans = 0;
    for (auto a : s) {
        ans += ll(a);
        ans %= mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s0;

    presums0 = vl(s0.length() + 1, 0);
    presums0[0] = 0;
    for (int i = 0; i < s0.length(); ++i) {
        presums0[i + 1] = (presums0[i] + ll(s0[i])) % mod;
    }
    //cout << "hi" << endl;

    node n0;
    n0.length = s0.length();
    n0.calculated = true;
    n0.isZero = true;
    n0.res = presums0[s0.length()];
    n0.id = 0;
    nodes.pb(n0);

    string s;
    for (int i = 1; i < n; ++i) {
        cin >> s;
        node a;
        if (s == "SUB") {
            ll a1, a2, a3;
            a.concatenate = false;
            cin >> a1 >> a2 >> a3;
            a.targ = a1;
            a.l = a2;
            a.r = a3;
        } else {
            a.concatenate = true;
            ll a1, a2;
            cin >> a1 >> a2;
            a.r1 = a1;
            a.r2 = a2;
        }
        a.id = i;

        nodes.pb(a);
    }

    for (int i = 1; i < n; ++i) {
        calculate_length(nodes[i]);
    }

    cout << explore(nodes.back()) % mod << "\n";
    /*for (int i = 0; i < n; ++i) {
        cout << i << "->" << nodes[i] << endl;
    }
    cout << calculate("foobar") << endl;

    cout << mod << endl;*/
    return 0;
}

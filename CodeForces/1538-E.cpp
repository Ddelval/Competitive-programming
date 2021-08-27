//  1538-E.cpp
//  Created by David del Val on 27/08/2021
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

ll countApear(string const &s) {
    ll index = 0;
    ll res = 0;
    while (index = s.find("haha", index), index != string::npos) {
        res++;
        index++;
        if (index == s.length()) {
            break;
        }
    }
    return res;
}
struct node {
    string ending; // Only length 3
    string begining;
    node *left = nullptr, *right = nullptr;
    ll ocur = 0;
    node() {}
    node(node *l, node *r) : left(l), right(r) {
        if (r->ending.length() < 3) {
            string c1 = l->ending + r->ending;
            int l = min(3, (int)c1.length());
            ending = c1.substr((int)c1.length() - l, l);
        } else {
            ending = r->ending;
        }
        if (l->begining.length() < 3) {
            string c1 = l->begining + r->begining;
            int l = min(3, (int)c1.length());
            begining = c1.substr(0, l);
        } else {
            begining = l->begining;
        }
        string c = l->ending + r->begining;
        ocur = countApear(c) + l->ocur + r->ocur;
    }
    node(string s) {
        int len = min((int)s.length(), 3);
        begining = s.substr(0, len);
        ending = s.substr(int(s.length()) - len, len);
        ocur = countApear(s);
        echo(ocur);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<node> nodes(2 * n);
        map<string, node *> variables;
        for (int i = 0; i < n; ++i) {
            string as;
            string op;
            echo(i);
            cin >> as >> op;
            if (op == ":=") {
                string val;
                cin >> val;
                nodes.push_back(node(val));
                variables[as] = &nodes.back();
            } else {
                string c1, o, c2;
                cin >> c1 >> o >> c2;

                nodes.push_back(node(variables[c1], variables[c2]));
                variables[as] = &nodes.back();
            }
        }
        cout << nodes.back().ocur << "\n";
    }
    return 0;
}
//  1535-E.cpp
//  Created by David del Val on 07/08/2021
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
const int limit = 3e5 + 20;
const int maxK = 20;

ll quantities[limit];
ll prices[limit];
ll max_lift[limit];

int lifting[limit][maxK];
int currentSize;

void addNode(int current, int parent, int quantity, int price) {
    current++;
    quantities[current] = quantity;
    prices[current] = price;
    lifting[current][0] = parent;

    max_lift[current] = maxK - 1;
    for (int i = 1; i < maxK; ++i) {
        int intermediate = lifting[current][i - 1];
        if (lifting[intermediate][i - 1] == -1) {
            max_lift[current] = i - 1;
            break;
        }
        lifting[current][i] = lifting[intermediate][i - 1];
    }

    currentSize = current + 1;
}

pll queryCost(int cnode, ll amount) {
    ll accumCost = 0;
    ll accumBought = 0;
    while (amount) {
        int targetNode = cnode;
        for (int k = max_lift[cnode]; k >= 0; --k) {
            if (lifting[targetNode][k] != -1 &&
                quantities[lifting[targetNode][k]]) {
                targetNode = lifting[targetNode][k];
            }
        }

        ll toBuy = min(quantities[targetNode], amount);
        db(cout << "Buying " << toBuy << " from node " << targetNode << endl);
        accumBought += toBuy;
        accumCost += toBuy * prices[targetNode];
        quantities[targetNode] -= toBuy;
        amount -= toBuy;
        if (targetNode == cnode) {
            break;
        }
    }
    return {accumCost, accumBought};
}
void print() {
    cout << "quantites: ";
    for (int i = 0; i < currentSize; ++i) {
        cout << quantities[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, a, c;
    cin >> q >> a >> c;

    lifting[0][0] = -1;
    quantities[0] = a;
    prices[0] = c;
    currentSize = 1;

    int b;
    for (int i = 0; i < q; ++i) {
        db(print());
        cin >> a;
        if (a == 1) {
            cin >> a >> b >> c;
            addNode(i, a, b, c);
        } else {
            cin >> a >> b;
            pll res = queryCost(a, b);
            cout << res.se << " " << res.fi << "\n";
            cout.flush();
        }
    }

    return 0;
}
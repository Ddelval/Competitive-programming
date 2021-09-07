//  1510-D.cpp
//  Created by David del Val on 07/09/2021
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
typedef vector<double> vl;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    vl opts(10, 0);
    map<int, map<int, pii>> prev;
    vi lastModified(10, -1);
    vi data = readVector<int>(n);

    for (int i = 0; i < n; ++i) {
        int last = data[i] % 10;
        vl opts2 = opts;
        vi lmod = lastModified;

        for (int j = 0; j < 10; ++j) {
            int ne = (last * j) % 10; 
            echo(ne);
            echo(last);
            double newVal = opts[j] * data[i];
            echo(newVal);
            if (opts2[ne] < newVal) {
                opts2[ne] = newVal;
                lastModified[ne] = i;
                prev[i][ne] = {lmod[j], j};
            }
        }
        if (opts2[last] < data[i]) {
            opts2[last] = data[i];
            lastModified[last] = i;
            prev[i][last] = {-1, -1};
        }

        swap(opts, opts2);
        echo(opts);
        echo(lastModified);
    }

    int lastIndex = lastModified[d];
    int currentCol = d;
    vi ans;
    while (lastIndex != -1) {
        echo(lastIndex);
        ans.pb(data[lastIndex]);
        pii previous = prev[lastIndex][currentCol];
        lastIndex = previous.fi;
        currentCol = previous.se;
    }
    if (ans.size() == 0) {
        cout << "-1\n";
    } else {
        cout << ans.size() << "\n" << ans << "\n";
    }
    return 0;
}
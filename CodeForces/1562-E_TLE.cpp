//  1562-E.cpp
//  Created by David del Val on 26/08/2021
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

template <typename T>
vector<int> counting_sort(T const source, int max_dif,
                          vi *previousOrder = nullptr) {
    vi cnt(max_dif);
    vi res(source.size());
    int n = source.size();

    for (int i = 0; i < n; ++i) {
        cnt[source[i]]++;
    }
    for (int i = 1; i < max_dif; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        if (previousOrder) {
            res[--cnt[source[i]]] = previousOrder->operator[](i);
        } else {
            res[--cnt[source[i]]] = i;
        }
    }
    return res;
}

template <typename T> struct SuffixArray {
    T s;
    int n;
    vi sa;
    vector<vi> classes;

    int &operator[](int index) { return sa[index]; }
    int const &operator[](int index) const { return sa[index]; }
    SuffixArray() {}
    SuffixArray(T const &s) : s(s), n(s.size()) {
        const int alphabet = 256;
        vi p, c(n);

        p = counting_sort(s, alphabet);

        int classes = 1; // At least one class (one element)
        c[p[0]] = classes - 1;
        for (int i = 1; i < n; ++i) {
            classes += s[p[i]] != s[p[i - 1]]; // We have a new class
            c[p[i]] = classes - 1;
        }

        this->classes.pb(c);
        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = (p[i] - (1 << h) + n) % n;
                // New classes after ordering by second element:
                cn[i] = c[pn[i]];
            }
            p = counting_sort(cn, classes, &pn);

            classes = 1;
            cn[p[0]] = classes - 1;
            for (int i = 1; i < n; ++i) {
                pii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};

                classes += cur != prev; // We have a new class
                cn[p[i]] = classes - 1;
            }
            swap(c, cn);
            this->classes.pb(c);
        }
        this->sa = p;
    }

    vi computeLCP() {
        vi rank(n, 0), lcp(n - 1, 0);
        for (int i = 0; i < n; ++i) {
            rank[sa[i]] = i;
        }
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
                k++;
            }
            lcp[rank[i]] = k;
            k = max(k - 1, 0);
        }
        return lcp;
    }
};

SuffixArray<string> sf;
int msb_index(int x) { return __builtin_clz(1) - __builtin_clz(x); }
bool cmp_less(pii a, pii b) {
    // cout << a << " " << b << endl;
    if (a.se == -1) {
        return false;
    }
    if (b.se == -1) {
        return true;
    }
    int lenToCmp = min(a.se, b.se);
    int j = msb_index(lenToCmp);
    lenToCmp -= (1 << j);

    int cla11 = sf.classes[j][a.fi];
    int cla21 = sf.classes[j][b.fi];
    if (cla11 != cla21) {
        return cla11 < cla21;
    }
    int cla12 = sf.classes[j][a.fi + lenToCmp];
    int cla22 = sf.classes[j][b.fi + lenToCmp];
    if (cla12 != cla22) {
        return cla12 < cla22;
    }
    return a.se < b.se;
}

int lis(vector<pii> const &ve) {
    int n = ve.size();

    vector<pii> d(n + 1, {-1, -1});

    d[0] = ve[0];
    int max_index = 0;
    for (int i = 1; i < n; ++i) {
        // cout << "iter " << i << " " << ve[i] << " | " << d << endl;
        int j =
            upper_bound(d.begin(), d.begin() + max(n, max_index + 1), ve[i], cmp_less) -
            d.begin();
        if (j == max_index) {
            max_index++;
        }
        if (j == 0 && cmp_less(ve[i], d[j])) {
            d[j] = ve[i];
        } else if (j && cmp_less(d[j - 1], ve[i]) && cmp_less(ve[i], d[j])) {
            d[j] = ve[i];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (d[i] != pii{-1, -1}) {
            ans = i;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        sf = SuffixArray<string>(s + '$');
        // cout << sf.classes << endl;
        vector<pii> pairs;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= n - i; ++j) {
                pairs.pb({i, j});
            }
        }
        cout << lis(pairs) + 1 << endl;
    }

    return 0;
}
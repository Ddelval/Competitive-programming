//  K.cpp
//  Created by David del Val on 23/08/2021
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
    T const s;
    int n;
    vi sa;

    int &operator[](int index) { return sa[index]; }
    int const &operator[](int index) const { return sa[index]; }

    SuffixArray(T const &s) : s(s), n(s.size()) {
        const int alphabet = 726;
        vi p(n), c(n);

        p = counting_sort(s, alphabet);

        int classes = 1; // At least one class (one element)
        c[p[0]] = classes - 1;
        for (int i = 1; i < n; ++i) {
            classes += s[p[i]] != s[p[i - 1]]; // We have a new class
            c[p[i]] = classes - 1;
        }

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    SuffixArray<string> sf(s + '$');
    vi lcp = sf.computeLCP();

    int mi = s.length();
    int occurr = 0;
    echo(lcp);
    db({
        for (int i = 1; i < s.length() + 1; ++i) {
            cout << lcp[i - 1] << " " << sf[i] << " " << s.substr(sf[i])
                 << endl;
        }
    });
    for (int i = 1; i < lcp.size(); ++i) {
        int rval = lcp[i];
        if (i != int(lcp.size()) - 1) {
            if (lcp[i + 1] > lcp[i]) {
                rval = lcp[i + 1];
                if (lcp[i + 1] + sf[i + 1] == s.length()) {
                    rval = iinf;
                }
            }
        }
        if (rval < mi) {
            mi = rval;
            echo(i);
            echo(sf[i + 1]);
            echo(mi);
            occurr = sf[i + 1];
        } else if (rval == mi) {
            occurr = min(sf[i + 1], occurr);
        }
    }
    echo(occurr);
    echo(mi);
    cout << s.substr(occurr, min(mi + 1, (int)s.length())) << endl;

    return 0;
}
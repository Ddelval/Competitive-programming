//  D.cpp
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
const int lim = 3e5 + 10;
const int lim2 = 3e5;
ll tree[4 * lim];
ll tree2[4 * lim];
ll val[lim];
ll accum[lim];
vi accumPos[2 * lim];

void build(int current, int l, int r) {
    if (l == r) {
        tree[current] = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(current << 1, l, mid);
    build(current << 1 | 1, mid + 1, r);
    tree[current] = tree[current << 1] + tree[current << 1 | 1];
}

int ql, qr;
ll query(int current, int l, int r) {
    if (r < ql || l > qr) {
        return 0;
    }
    if (l >= ql && r <= qr) {
        return tree[current];
    }
    int mid = (l + r) / 2;
    ll res = query(current << 1, l, mid);
    return res + query(current << 1 | 1, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char c;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (c == '+') {
                val[i] = 1;
            } else {
                val[i] = -1;
            }
            if (i % 2) {
                val[i] *= -1;
            }
            accum[i] = val[i];
            if (i) accum[i] += accum[i - 1];
            //cout << accum[i] << " ";
        }
        //cout << endl;

        for (int i = 0; i < 2 * lim; ++i) {
            accumPos[i].clear();
        }

        for (int i = 0; i < n; ++i) {
            accumPos[accum[i] + lim2].pb(i);
        }

        build(1, 0, n - 1);
        while (m--) {
            cin >> ql >> qr;
            ql--, qr--;
            ll resS = query(1, 0, n - 1);
            echo(resS);
            ll res = abs(resS);
            ll ou = 0;
            vi ans;
            echo(res);

            if (res == 0) {
                ou = 0;
            } else {
                if (res % 2) {
                    ou = 1;
                    ll lookingFor = res / 2 + 1;
                    if (resS < 0) {
                        lookingFor = -lookingFor;
                    }
                    if (ql) {
                        lookingFor += accum[ql-1];
                    }
                    lookingFor += lim2;
                    echo(lookingFor);
                    echo(accumPos[lookingFor]);
                    int index = lower_bound(all(accumPos[lookingFor]), ql) -
                                accumPos[lookingFor].begin();
                    index = accumPos[lookingFor][index];
                    index++;
                    ans.push_back(index);

                } else {
                    ou = 2;
                    ll lookingFor = res / 2;
                    echo(val[qr]);
                    if (resS < 0 && val[qr] == 1) {
                        lookingFor += 1;
                    }
                    if (resS > 0 && val[qr] == -1) {
                        lookingFor += 1;
                    }
                    if (resS < 0) {
                        lookingFor = -lookingFor;
                    }
                    echo(lookingFor);
                    if (ql) {
                        lookingFor += accum[ql-1];
                    }
                    lookingFor += lim2;
                    echo(lookingFor);
                    echo(accumPos[lookingFor]);
                    int index = lower_bound(all(accumPos[lookingFor]), ql) -
                                accumPos[lookingFor].begin();
                    index = accumPos[lookingFor][index];
                    index++;
                    ans.push_back(index);
                    ans.push_back(qr + 1);
                }
            }
            cout << ou << "\n";
            if (ou) {
                cout << ans << "\n";
            }
        }
    }

    return 0;
}
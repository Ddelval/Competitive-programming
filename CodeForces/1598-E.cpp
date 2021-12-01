//  1598-E.cpp
//  Created by David del Val on 26/11/2021
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

const int lim = 1000;
vii deltas({{1, 0}, {0, 1}});
int n, m, q;
int orderD[lim][lim];
int flipped[lim][lim];
int idD[lim][lim];
map<int, map<int, ll>> pos_len;
map<int, ll> lens;

int orderA[lim][lim];
int idA[lim][lim];

void fill_orderD() {
    for (int i = 0; i < n; ++i) {
        pii pos = {i, 0};
        int d = 0;
        int cnt = 1;
        while (pos.fi < n && pos.se < m) {
            if (d == 0) {
                orderD[pos.fi][pos.se] = cnt;
                idD[pos.fi][pos.se] = i + 1;
            } else {
                orderA[pos.fi][pos.se] = cnt;
                idA[pos.fi][pos.se] = i + 1;
            }
            cnt++;
            pos = pos + deltas[d];
            d = (d + 1) % 2;
        }
        pos_len[i + 1][1] = cnt - 1;
        lens[i + 1] = cnt - 1;
    }
}

const int offset = 1e4;
void fill_orderA() {
    for (int i = 0; i < m; ++i) {
        pii pos = {0, i};
        int d = 1;
        int cnt = 1;
        while (pos.fi < n && pos.se < m) {
            if (d == 0) {
                orderD[pos.fi][pos.se] = cnt;
                idD[pos.fi][pos.se] = i + 1 + offset;
            } else {
                orderA[pos.fi][pos.se] = cnt;
                idA[pos.fi][pos.se] = i + 1 + offset;
            }
            cnt++;
            pos = pos + deltas[d];
            d = (d + 1) % 2;
        }
        pos_len[i + 1 + offset][1] = cnt - 1;
        lens[i + 1 + offset] = cnt - 1;
    }
}

ll calc(ll l) { return (l * (l - 1)) / 2; }
ll get_merge(ll len1, ll len2) {
    ll accum = 0;
    accum -= calc(len1);
    accum -= calc(len2);
    accum += calc(len1 + len2);
    return accum;
}

ll undo_flip(int id, int index) {
    ll accum = 0;
    map<int, ll> &sequence = pos_len[id];
    sequence[index] = 1;
    auto it = sequence.find(index);

    auto it2 = it;
    it2++;
    if (it2 != sequence.end()) {
        if (it2->fi == index + 1) {
            accum += get_merge(it->se, it2->se);
            it->se += it2->se;
            sequence.erase(it2);
        }
    }
    if (it != sequence.begin()) {
        it2 = it;
        it2--;
        if (it2->first + it2->second == index) {
            accum += get_merge(it->se, it2->se);
            it2->se += it->se;
            sequence.erase(it);
        }
    }
    return accum;
}
ll make_flip(int id, int index) {
    ll accum = 0;
    map<int, ll> &sequence = pos_len[id];
    auto it = sequence.lower_bound(index);

    db({ cout << sequence << " " << index << endl; });
    if (it != sequence.end() && it->first == index) {
        // The first of a segment
        accum -= calc(it->second);
        if (it->second == 1) {
            sequence.erase(it);
        } else {
            it->second--;
            accum += calc(it->second);
            sequence[index + 1] = it->second;
            sequence.erase(it);
        }
        return accum;
    }
    it--;
    if (index == it->first + it->second - 1) {
        echo("last");
        // The last of a segment
        accum -= calc(it->second);
        it->second--;
        accum += calc(it->second);
    } else {
        // In the middle of a segment
        accum -= calc(it->second);
        int l1 = index - it->first;
        int l2 = it->second - l1 - 1;
        accum += calc(l1) + calc(l2);
        it->second = l1;
        sequence[index + 1] = l2;
    }
    return accum;
}
ll flip(int x, int y) {
    ll accum = 0;
    if (flipped[x][y]) {
        // Undo the flip
        accum += undo_flip(idA[x][y], orderA[x][y]);
        accum += undo_flip(idD[x][y], orderD[x][y]);
        accum++;
        flipped[x][y] = false;
    } else {
        accum += make_flip(idA[x][y], orderA[x][y]);
        accum += make_flip(idD[x][y], orderD[x][y]);
        accum--;
        flipped[x][y] = true;
    }
    return accum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;

    fill_orderA();
    fill_orderD();

    db({
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << "(" << orderD[i][j] << " " << idD[i][j] << " "
                     << orderA[i][j] << " " << idA[i][j] << ")\t";
            }
            cout << endl;
        }
    });
    ll current = n * m;
    for (auto len : lens) {
        current += calc(len.se);
    }
    echo(current);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        db({ cout << x << " " << y << "\n" << pos_len << endl; });
        current += flip(x, y);
        cout << current << "\n";
        db({ cout << endl << endl; });
    }

    return 0;
}
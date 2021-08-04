//  10459__The Tree Root.cpp
//  Created by David del Val on 04/08/2021
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

int n;
vector<vi> adyList;
vi bestOption;
vector<int> length;
vi findEnding(int start) {
    queue<int> q;
    q.push(start);
    length = vi(n, -1);
    length[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (auto adyacent : adyList[current]) {
            if (length[adyacent] == -1) {
                length[adyacent] = length[current] + 1;
                q.push(adyacent);
            }
        }
    }
    int max_length = *max_element(all(length));
    vi result;
    for (int i = 0; i < n; ++i) {
        if (length[i] == max_length) {
            result.pb(i);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        adyList = vector<vi>(n);
        int k;
        for (int i = 0; i < n; ++i) {
            cin >> k;
            int a;
            for (int j = 0; j < k; ++j) {
                cin >> a;
                a--;
                adyList[a].pb(i);
            }
        }
        vi firtsStep = findEnding(0);
        echo(length);
        echo(firtsStep[0]);
        vi secondStep = findEnding(firtsStep[0]);
        vi length2 = length;
        vi thirdStep = findEnding(secondStep[0]);
        echo(length);
        echo(length2);
        int ma_length = length[thirdStep[0]];
        set<int> targets;
        if (ma_length % 2) {
            targets.insert(ma_length / 2 + 1);
        }
        targets.insert(ma_length / 2);
        echo(targets);

        vi res2;
        for (int i = 0; i < n; ++i) {
            if (length[i] == length2[i] && targets.count(length[i])) {
                res2.pb(i + 1);
            }
        }
        if (res2.empty()) {
            for (int i = 0; i < n; ++i) {
                if (abs(length[i] - length2[i]) == 1 &&
                    (targets.count(length[i]) && targets.count(length2[i]))) {
                    res2.pb(i + 1);
                }
            }
        }
        set<int> res3;
        for (auto a : secondStep) {
            res3.insert(a + 1);
        }
        for (auto a : thirdStep) {
            res3.insert(a + 1);
        }
        cout << "Best Roots  : " << res2 << "\n";
        cout << "Worst Roots : " << res3 << "\n";
    }

    return 0;
}
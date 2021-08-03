//  12083__Guardian of Decency.cpp
//  Created by David del Val on 02/08/2021
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
struct stud {
    int height, music, sport;
};
ostream &operator<<(ostream &o, stud &a) {
    o << "(" << a.height << " " << a.music << " " << a.sport << ")";
    return o;
}
int get(map<string, int> &ma, string s, int &nextIndex) {
    if (ma.count(s)) {
        return ma[s];
    } else {
        ma[s] = nextIndex;
        return nextIndex++;
    }
}

// List of vertices in the 2nd component connected to
// the i-th vertex in the first component
vector<vi> adyList;
// Index of the vertex in 1st component connected to the
// i-th vertex in the second component
vector<int> match;
vector<bool> used;
bool augmentPath(int current) {
    if (used[current]) {
        return false;
    }
    used[current] = 1;
    for (int to : adyList[current]) {
        if (match[to] == -1 || augmentPath(match[to])) {
            match[to] = current;
            return true;
        }
    }
    return false;
}
int calculateMCBM(int n1, int n2) {
    match = vi(n2, -1);
    int res = 0;
    for (int i = 0; i < n1; ++i) {
        used.assign(n1, false);
        res += augmentPath(i);
    }
    echo(match);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        map<string, int> music;
        int mCount = 0;
        map<string, int> sport;
        int sCount = 0;
        int n;
        cin >> n;
        vector<stud> male;
        vector<stud> female;
        male.reserve(n);
        female.reserve(n);

        int a;
        string s1, s2, s3;

        for (int i = 0; i < n; ++i) {
            cin >> a >> s1 >> s2 >> s3;
            if (s1 == "M") {
                male.push_back(
                    stud{a, get(music, s2, mCount), get(sport, s3, sCount)});
            } else {
                female.push_back(
                    stud{a, get(music, s2, mCount), get(sport, s3, sCount)});
            }
        }
        echo(male);
        echo(female);
        if (male.size() > female.size()) {
            swap(male, female);
        }

        adyList = vector<vi>(n, vi());
        for (int i = 0; i < male.size(); ++i) {
            for (int j = 0; j < female.size(); ++j) {
                if (abs(male[i].height - female[j].height) > 40) {
                    continue;
                }
                if (male[i].music != female[j].music) {
                    continue;
                }
                if (male[i].sport == female[j].sport) {
                    continue;
                }
                adyList[i].pb(j);
            }
        }
        echo(adyList);

        cout << n - calculateMCBM(male.size(), female.size()) << "\n";
    }

    return 0;
}
//  1526-D.cpp
//  Created by David del Val on 08/08/2021
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

ll countInversion(int left, int right, vi &elems) {
    if (left == right) {
        return 0;
    }
    int mid = (left + right) / 2;
    ll res = countInversion(left, mid, elems);
    res += countInversion(mid + 1, right, elems);

    int index = 0;
    vi aux(right - left + 1, 0);
    int i1 = left, i2 = mid + 1;
    while (i1 != mid + 1 || i2 != right + 1) {
        int *picked;
        if (i1 > mid) {
            picked = &i2;
        } else if (i2 > right) {
            picked = &i1;
        } else if (elems[i1] > elems[i2]) {
            picked = &i2;
            res += abs((*picked) - (left + index));
        } else {
            picked = &i1;
        }
        aux[index++] = elems[*picked];
        (*picked)++;
    }
    for (int i = 0; i < right - left + 1; ++i) {
        elems[i + left] = aux[i];
    }
    // db(cout << left << " " << right << " " << elems << endl);
    return res;
}
int ch2int[254];
char int2ch[4] = {'A', 'N', 'T', 'O'};

ll findSwaps(string s1, string s2) {
    int n = s1.length();
    queue<int> posA, posN, posT, posO;
    queue<int> positions[4];
    for (int i = 0; i < n; ++i) {
        int index = ch2int[s1[i]];
        positions[ch2int[s1[i]]].push(i + 1);
    }
    vi perm2(n);
    for (int i = 0; i < n; ++i) {
        int index = ch2int[s2[i]];
        perm2[i] = positions[index].front();
        positions[index].pop();
    }
    return countInversion(0, n - 1, perm2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ch2int['A'] = 0;
    ch2int['N'] = 1;
    ch2int['T'] = 2;
    ch2int['O'] = 3;
    int t;
    cin >> t;
    while (t--) {
        string given;
        cin >> given;
        int count[4] = {0, 0, 0, 0};
        for (auto a : given) {
            count[ch2int[a]]++;
        }
        vi perm = {1, 2, 3, 4};
        ll ans = 0;
        string sans;
        do {
            string s;
            for (int i = 0; i < 4; ++i) {
                char letter = int2ch[perm[i] - 1];
                int reps = count[perm[i] - 1];
                while (reps--) {
                    s += letter;
                }
            }
            echo(s);
            echo(given);
            ll res = findSwaps(s, given);
            if (res >= ans) {
                ans = res;
                sans = s;
            }
            echo(res);

        } while (std::next_permutation(all(perm)));
        // echo(ans);
        cout << sans << "\n";
    }

    return 0;
}
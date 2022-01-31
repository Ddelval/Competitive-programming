//  B.cpp
//  Created by David del Val on 27/01/2022
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
int n, k;
void printRanges(vi &datt, int x, int y) {
    int before = 0;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        bal += (datt[i] >= x && datt[i] <= y);
        bal -= !(datt[i] >= x && datt[i] <= y);
        if (bal == 1 && k > 1) {
            cout << before + 1 << " " << i + 1 << "\n";
            bal=0;
            before = i + 1;
            k--;
        }
    }
    if (k) {
        cout << before + 1 << " " << n << "\n";
        k--;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        echo(t);
        cin >> n >> k;
        vi datt = readVector<int>(n);
        map<int, int> freq;
        map<int, int> before;
        for (auto a : datt) {
            freq[a]++;
        }
        int accum = 0;
        int ma = 0;
        int maInd = -1;
        for (auto elem : freq) {
            before[elem.fi] = accum;
            accum += elem.se;
            if (elem.se > ma) {
                ma = elem.se;
                maInd = elem.fi;
            }
        }
        if (ma >= n - ma + k) {
            cout << maInd << " " << maInd << "\n";
            printRanges(datt, maInd, maInd);
            continue;
        }
        int l = 0;
        int r = n;
        int xx, yy;
        xx = freq.begin()->fi;
        yy = freq.rbegin()->fi;

        while (r - l > 1) {
            int mid = (r + l) / 2;
            bool possible = false;
            for (auto a : freq) {
                //  check range [a.fi, a.fi+mid]
                int in = 0;
                auto it = before.lower_bound(a.fi + mid);
                if (it == before.end()) {
                    in += n;
                } else {
                    in += it->se;
                }
                if (freq.count(a.fi + mid)) {
                    in += freq[a.fi + mid];
                }
                in -= before[a.fi];
                if (in >= n - in + k) {
                    possible = true;
                    xx = a.fi;
                    yy = a.fi + mid;
                    break;
                }
            }
            if (possible) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << xx << " " << yy << "\n";
        printRanges(datt, xx, yy);
    }

    return 0;
}
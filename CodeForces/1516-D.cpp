//  1516-D.cpp
//  Created by David del Val on 22/08/2021
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
const int lim = 1e5;
vl primes;
vector<vl> divisors;
bitset<lim> bs;
void sieve() {
    bs.set();
    divisors = vector<vl>(lim + 1, vl());
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= lim; ++i) {
        if (bs[i]) {
            // j = i * i if we are not keeping track of the divisors
            for (ll j = i; j <= lim; j += i) {
                bs[j] = 0;
                divisors[j].push_back(i);
            }
            primes.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vi data = readVector<int>(n);
    sieve();

    vi nextAppearance(lim, -1);
    vi lastOfRange(n);
    lastOfRange[n - 1] = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        int nextAvailable = n;
        int j = data[i];

        echo(j);
        echo(divisors[j]);
        for (auto prime : divisors[j]) {
            if (nextAppearance[prime] != -1) {
                nextAvailable = min(nextAvailable, nextAppearance[prime]);
            }
            nextAppearance[prime] = i;
        }
        lastOfRange[i] = nextAvailable;
        if (i != n - 1) {
            lastOfRange[i] = min(lastOfRange[i], lastOfRange[i + 1]);
        }
    }
    echo(lastOfRange);
    vector<vi> binLift;
    binLift.push_back(lastOfRange);
    int Loglim = 20;
    for (int j = 1; j <= Loglim; ++j) {
        vi nextRow(n);
        for (int i = 0; i < n; ++i) {
            if (binLift.back()[i] >= n) {
                nextRow[i] = n + 1;
            } else {
                nextRow[i] = binLift.back()[binLift.back()[i]];
            }
        }
        binLift.push_back(std::move(nextRow));
    }
    echo(binLift);
    while (q--) {
        int l, r;
        cin >> l >> r;
        int steps = 1;
        l--, r--;
        int stepper = Loglim;
        for (int stepper = Loglim; stepper >= 0; stepper--) {
            if (binLift[stepper][l] < r + 1) {
                steps += (1 << stepper);
                l = binLift[stepper][l];
            }
        }

        /*
                while (true) {
                    if (l == r) {
                        steps++;
                        break;
                    }
                    if (l > r) {
                        break;
                    }
                    echo(l);
                    while (stepper >= 0 && binLift[stepper][l] > r + 1) {
                        stepper--;
                    }
                    echo(stepper);
                    if (stepper == -1) {
                        steps++;
                        break;
                    } else {
                        steps += 1 << stepper;
                        l = binLift[stepper][l];
                        stepper++;
                        db(cout << "lnext" << l << endl);
                    }
                }
                */
        cout << steps << "\n";
    }

    return 0;
}
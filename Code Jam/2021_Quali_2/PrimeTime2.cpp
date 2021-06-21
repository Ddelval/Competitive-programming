//  PrimeTime.cpp
//  Created by David del Val on 10/04/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

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

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
vi g_primes;
void calculatePrimes() {
    int lim = 500;
    for (int i = 2; i < lim; ++i) {
        bool valid = true;
        int l2 = sqrt(i);
        for (auto p : g_primes) {
            if (p > l2) {
                break;
            }
            if (i % p == 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            g_primes.pb(i);
        }
    }
    reverse(all(g_primes));
}
vector<pii> decompose(int n) {
    vector<pii> res;
    for (auto a : g_primes) {
        int cnt = 0;
        while (a <= n && n % a == 0) {
            cnt++;
            n /= a;
        }
        if (cnt) {
            res.pb({a, cnt});
        }
        if (n == 1) {
            break;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    calculatePrimes();
    //cout << g_primes << endl;
    cin >> t;
    int z = 1;
    while (t--) {
        int m;
        cin >> m;
        vi primes;
        map<int, int> pc;
        ll sum = 0;
        for (int i = 0; i < m; ++i) {
            int p, n;
            cin >> p >> n;
            pc[p] = n;
            sum += p * n;
        }

        ll ans = 0;
        //cout << "sum " << sum << endl;
        //cout << pc << endl;

        for (ll psum = 2; psum <=; --psum) {
            auto r = decompose(psum);
            //cout << psum << " " << r << endl;
            int possible = true;
            ll comp = 0;
            ll prod = 1;
            for (auto it : r) {
                if (pc[it.fi] < it.se) {
                    possible = false;
                }
                comp += it.fi * it.se;
                prod *= pow(it.fi, it.se);
            }
            if ((sum - comp) == prod && possible) {
                ans = prod;
                break;
            }
        }
        cout << "Case #" << z << ": " << ans << "\n";
        z++;
    }

    return 0;
}
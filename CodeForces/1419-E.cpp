//  1419-E.cpp
//  Created by David del Val on 21/09/2020
//
//

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
inline ostream& operator<<(ostream& o, pair<T, Q> p);

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
    static auto check(X const& x) -> decltype(x.begin());
    static subs_fail check(...);

   public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream&> operator<<(ostream& o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    int a;
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
inline ostream& operator<<(ostream& o, pair<T, Q> p) {
    o << p.fi << " " << p.se;
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

const int siz = 2e5;
vector<ll> primes;
int discarded[siz];

void linearSieve() {
    primes.push_back(2);
    for (int i = 3; i <= siz; i += 2) {
        if (discarded[i]) continue;
        primes.push_back(i);

        ll j = 2;
        while (i * j <= siz) {
            discarded[i * j] = true;
            j++;
        }
    }
}

vector<pll> decompose(ll val) {
    vector<pll> decomposition;
    for (auto p : primes) {
        ll exp = 0;
        while (val % p == 0) {
            exp++;
            val /= p;
        }
        if (exp) {
            decomposition.push_back({p, exp});
        }
        if (val == 1) break;
    }
    if (val != 1) decomposition.push_back({val, 1});
    return decomposition;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    linearSieve();

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll decomposition = decompose(n);
        if (decomposition.size() == 1) {
            ll num = decomposition[0].fi;
            for (int i = 0; i < decomposition[0].second; ++i) {
                if (i) cout << " ";
                cout << num;
                num = num * decomposition[0].fi;
            }
            cout << "\n0\n";
            return 0;
        }
        if (decomposition.size() == 2 && decomposition[0].se == 1 && decomposition[1].se == 1) {
            cout << decomposition[0].fi << " " << decomposition[0].fi * decomposition[1].fi << " " << decomposition[1].fi << " " << _gcd(decomposition[0].fi, decomposition[1].fi) << "\n1\n";
            return 0;
        }

        for(int )
    }

    return 0;
}
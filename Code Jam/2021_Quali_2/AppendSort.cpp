//  AppendSort.cpp
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

double n9(int n) {
    double res = 0;
    for (int i = 0; i < n; ++i) {
        res += 9 * pow(10, i);
    }
    return res;
}

ll ans;
void comp_elem(double e1, double &e2) {
    if (e2 > e1) {
        return;
    }
    if (e2 == e1) {
        e2 *= 10;
        ans++;
        return;
    }
    int dig1 = log10(e1);
    int dig2 = log10(e2);

    if (dig1 == dig2) {
        e2 *= 10;
        ans++;
        return;
    }
    auto dd2 = e2;
    double dif = dig1 - dig2;
    dd2 *= pow(10, dif);
    //cout << "dd2 " << dd2 << endl;
    if (dd2 > e1) {
        ans += dif;
        e2 = dd2;
        return;
    }
    // dd2 < e1
    //cout << "dd2 " << dd2 << " dif " << dif << " n9 " << n9(dif) << endl;
    if (dd2 + n9(dif) > e1) {
        if (dif < 4) {
            ll val = (ll)n9(dif);
            while (dd2 + val - 1 > e1) {
                val--;
            }
            e2 = dd2 + val;
        } else {
            e2 = dd2;
        }
        ans += dif;

    } else {
        // Impossible
        ans += dif + 1;
        e2 = dd2 * 10;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int z = 1;
    while (t--) {
        ans = 0;
        int n;
        cin >> n;
        vl data = readVector<ll>(n);

        vector<double> elements;
        for (auto a : data) {
            elements.pb(a);
        }
        for (int i = 1; i < n; ++i) {
            comp_elem(elements[i - 1], elements[i]);
        }
        //cout << elements << endl;
        cout << "Case #" << z << ": " << ans << "\n";
        z++;
    }

    return 0;
}
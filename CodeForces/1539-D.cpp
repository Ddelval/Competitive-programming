//  1539-D.cpp
//  Created by David del Val on 06/07/2021
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

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll a, b;
    vll data;
    data.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        data.pb({a, b});
    }
    sort(all(data), [](pll &a, pll &b) {
        if (a.se != b.se) {
            return a.se < b.se;
        }
        return a.fi > b.fi;
    });
    ll cheapIndex = 0;
    ll prod1 = 0;
    ll prod2 = 0;
    ll productsTaken = 0;
    //cout << data << endl;
    for (int i = n - 1; i >= 0; --i) {
        if (data[i].fi == 0 || cheapIndex > i) {
            break;
        }
        /*
        cout << "Check"
             << " " << (cheapIndex <= i) << " " << data[cheapIndex].first << " " << (data[cheapIndex].second <= productsTaken) << endl;
             */
        // Get the product at price 1
        while (cheapIndex <= i && data[cheapIndex].first && data[cheapIndex].second <= productsTaken) {
            //cout << "Taken product " << cheapIndex << ": " << data[cheapIndex] << " with " << productsTaken << " products taken" << endl;
            productsTaken += data[cheapIndex].first;
            prod1 += data[cheapIndex].first;
            data[cheapIndex].first = 0;
            cheapIndex++;
        }
        if (cheapIndex > i) {
            break;
        }
        if (data[cheapIndex].second - productsTaken < data[i].fi) {
            //cout << "Taken part of product " << i << ": " << data[i] << "; " << data[cheapIndex].second - productsTaken << " units" << endl;
            data[i].fi -= data[cheapIndex].second - productsTaken;
            prod2 += data[cheapIndex].second - productsTaken;
            productsTaken += data[cheapIndex].second - productsTaken;
            i++; // Do not advance i

        } else {
            //cout << "Paying full price for product " << i << ": " << data[i] << endl;
            prod2 += data[i].fi;
            productsTaken += data[i].fi;
        }
    }
    cout << prod1 + 2 * prod2 << "\n";

    return 0;
}
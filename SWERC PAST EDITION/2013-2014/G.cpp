//  G.cpp
//  Created by David del Val on 13/02/2021
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll d, p;
    while (cin >> d >> p) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string a;
        vector<ll> values;
        while (ss >> a) {
            if (a.length() > 10) {
                values.pb(iinf);
            } else {
                values.pb(atol(a.c_str()));
            }
        }
        //cout << "v" << values << endl;
        vl values2;
        if (values.size() < d + 1) {
            for (int j = 0; j < 4; ++j) {
                values2.pb(values[j]);
            }
            ll a1, a2, b1, b2; // a=a1/a2
            a1 = values[3] * values[1] - values[2] * values[2];
            a2 = values[1] * values[1] - values[2] * values[0];

            b1 = values[2] * values[1] - values[3] * values[0];
            b2 = values[1] * values[1] - values[2] * values[0];

            // s[i]= a*s[i-2]+ b*s[i-1]
            bool b = false;
            if (b2 == 0 || a2 == 0) {
                b = true;
            }

            for (int j = 4; j < d + 1; ++j) {
                ll an;
                if (b) {
                    if (values[0] == 0) {
                        an = 0;
                    } else {
                        an = (values2[1] * values2[j - 1]) / values2[0];
                    }

                } else {
                    an = (a1 * values2[j - 2]) / a2 + (b1 * values2[j - 1]) / b2;
                }

                an = min((ll)iinf, an);
                values2.pb(an);
            }
        } else {
            values2 = values;
        }
        //cout << values2 << endl;
        if (values2[0] > p) {
            cout << "The spider is going to fall!\n";
        } else if (values2.back() < p) {
            cout << "The spider may fall!\n";
        } else {
            int index = 0;
            while (index < values2.size() && values2[index] <= p)
                index++;

            cout << d - index + 1 << "\n";
        }
    }

    return 0;
}
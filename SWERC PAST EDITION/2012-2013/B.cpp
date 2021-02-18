//  B.cpp
//  Created by David del Val on 14/02/2021
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
string s1;
string s2;

int sfind(char c1, char c2) {
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == c1 && s2[i] == c2) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    int z = 0;
    while (t--) {
        z++;
        cin >> s1 >> s2;
        int n = s1.length();

        int n01, nI1, n02;
        n01 = nI1 = n02 = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] == '0') {
                n01++;
            }

            if (s1[i] == '?') {
                nI1++;
            }

            if (s2[i] == '0') {
                n02++;
            }
        }
        int rem0 = n01 + nI1 - n02;
        if (rem0 < 0) {
            cout << "Case " << z << ": -1\n";
            continue;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '0' && s2[i] == '1') {
                int res = sfind('1', '0');
                if (res != -1) {
                    swap(s1[i], s1[res]);
                    ans += 1;
                    continue;
                }
            }
            if (s1[i] == '1' && s2[i] == '0') {
                int res = sfind('0', '1');
                if (res != -1) {
                    swap(s1[i], s1[res]);
                    ans += 1;
                    continue;
                }
                res = sfind('?', '1');
                if (res != -1) {
                    swap(s1[i], s1[res]);
                    ans += 1;
                    continue;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ans++;
            }
        }
        cout << "Case " << z << ": " << ans << "\n";
    }

    return 0;
}
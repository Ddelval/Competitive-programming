//  D.cpp
//  Created by David del Val on 16/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b) b %= a ^= b ^= a ^= b;
    return a;
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

inline ostream& operator<<(ostream& o, pii p) {
    o << p.fi << " " << p.se;
    return o;
}
template <typename T, typename A>
inline ostream& operator<<(ostream& o, pair<T, A> p) {
    o << "{" << p.fi << " " << p.se << "}";
    return o;
}

template <typename>
struct is_std_vector : std::false_type {};
template <typename T, typename A>
struct is_std_vector<std::vector<T, A>> : std::true_type {};

template <typename T>
inline ostream& operator<<(ostream& o, vector<T>& p) {
    for (int i = 0; i < p.size(); ++i) {
        o << setw(3) << p[i];
        if (is_std_vector<T>::value) o << "\n";
    }
    return o;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<char, int>> lengths;
        int clen = 0;
        char ch = s[0];
        for (int i = 0; i < n; ++i) {
            if (s[i] == ch) {
                clen++;
            } else {
                lengths.push_back({ch, clen});
                clen = 1;
                ch = s[i];
            }
        }
        lengths.push_back({ch, clen});
        if (lengths.size() > 1 && lengths.back().fi == lengths[0].fi) {
            lengths[0].se += lengths.back().se;
            lengths.pop_back();
        }
        ll res = 0;
        if(lengths.size()==1 && n>2){
            res++;
            lengths[0].se--;
        }
        //cout << lengths;
        for (auto p : lengths) {
            res += p.se / 3;
        }
        cout << res << "\n";
    }
    return 0;
}
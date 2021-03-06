//  1389-C.cpp
//  Created by David del Val on 11/08/2020
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
template <typename T, typename R, typename S, typename A>
inline ostream& operator<<(ostream& o, map<T, A, S, R>& m) {
    for (auto a : m) {
        o << "{" << a.fi << " = " << a.se << "}";
    }
    return o;
}

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
string s;

int testPattern(vector<char> pat) {
    int counter = 0;
    int pos = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == pat[pos]) {
            counter++;
            pos = (pos + 1) % 2;
        }
    }
    return counter;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        vector<char> pat(2);
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            pat[0] = i + '0';
            for (int j = 0; j < 10; ++j) {
                if (j == i) continue;
                pat[1] = j + '0';
                int c = testPattern(pat);
                if (c % 2 == 0) ans = max(ans, c);
            }
        }
        vi cnt = vi(10, 0);
        for (auto c : s) {
            cnt[c - '0']++;
        }
        ans = max(ans, *max_element(all(cnt)));
        cout << s.length() - ans << "\n";
    }

    return 0;
}
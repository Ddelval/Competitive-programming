//  1381-A.cpp
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

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif
string s1, s2;
int n;
string s3;
void swapStr(int len) {
    char c = s1[0];
    if (s1[len - 1] == '1')
        s1[0] = '0';
    else
        s1[0] = '1';

    if (c == '1') {
        s1[len - 1] = '0';
    } else {
        s1[len - 1] = '1';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s1;
        cin >> s2;
        vi swaps;
        swaps.reserve(2 * n);
        bool flip = false;
        int idx = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (flip ^ (s1[idx] == s2[i])) {
                swaps.push_back(1);
            }
            /*if (s1[0] == s2[i]) {
                swaps.push_back(1);
                swapStr(1);
            } */
            swaps.push_back(i + 1);
            //swapStr(i + 1);
            if (flip) {
                idx -= i;
            } else
                idx += i;
            flip = !flip;
        }
        cout << swaps.size();
        for (auto a : swaps) {
            cout << " " << a;
        }
        cout << "\n";
        // cout << s1 << endl;
    }
    return 0;
}
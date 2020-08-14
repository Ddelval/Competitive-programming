//  1352-F.cpp
//  Created by David del Val on 04/07/2020
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string s;
        if (!n1) {
            if (n0) {
                for (int i = 0; i < n0+1; ++i) cout << "0";
                cout << endl;
            }
            if (n2) {
                for (int i = 0; i < n2+1; ++i) cout << "1";
                cout << endl;
            }
        } else {
            for (int i = 0; i < n2; ++i) cout << "1";
            cout << 1;
            for (int i = 0; i < n0; ++i) cout << "0";
            cout << 0;
            for (int i = 2; i < n1+1; ++i) {
                if (i % 2)
                    cout << 0;
                else
                    cout << 1;
            }
            cout << endl;
        }
    }

    return 0;
}
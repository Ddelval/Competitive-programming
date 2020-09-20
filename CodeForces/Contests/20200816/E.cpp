//  E.cpp
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

const int lim = 26;
ll arr[lim][lim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j % 2 == 1) arr[j][i - j] = (1ll << i);
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (j % 2 == 1) arr[i + j][n - j - 1] = (1ll << (n - 1 + i));
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) cout << " ";
            cout << arr[i][j];
        }
        cout << "\n";
    }
    cout.flush();

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        int ipos = 0;
        int jpos = 0;

        cout << ipos+1 << " " << jpos+1 << "\n";
        for (int i = 1; i < 2 * n - 1; ++i) {
            ll disc = (k & (1ll << i));
            //cout << "disc " << disc<<endl;
            if (ipos == n - 1) {
                jpos++;
            }
            else if (jpos == n - 1) {
                ipos++;
            }
            else if(disc==arr[ipos+1][jpos]){
                ipos++;
            }
            else if(disc==arr[ipos][jpos+1]){
                jpos++;
            }
            cout << ipos+1 << " " << jpos+1 << "\n";
        }
        cout.flush();
    }

    return 0;
}
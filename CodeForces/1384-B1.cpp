//  1384-B1.cpp
//  Created by David del Val on 12/08/2020
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

const int lim = 100 + 10;
int n, k, l;
int depths[lim];
int mem[lim][2 * lim];
int p[2 * lim];
bool explore(int n, int k) {
    //cout << "exploring: " << n << " " << k << endl;
    //cout << "Current tide: " << depths[n] + p[k] << endl;
    if (n == ::n + 1) return true;
    if (mem[n][k] != -1) return mem[n][k];
    if (depths[n] + p[k] > l) return mem[n][k] = false;
    mem[n][k] = false;
    if (explore(n + 1, (k + 1) % (2 * ::k)) || explore(n, (k + 1) % (2 * ::k))) return mem[n][k] = true;
    /*     //cout << "T";
    for (int i = 1; i <= 2 * ::k; ++i) {
        //cout << "test";
        if (depths[n] + k + (i - 1) > l) break;
        if (explore(n + 1, k + i))
            return mem[n][k] = 1;
    } */
    return mem[n][k] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k >> l;
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < 2 * k; ++j) {
                mem[i][j] = -1;
            }
        }
        for (int i = 0; i <= k; ++i) {
            p[i] = i;
        }
        for (int j = k - 1; j > 0; --j) {
            p[k+1 + (k - 1 - j)] = j;
        }
        for (int i = 1; i <= n; ++i) cin >> depths[i];
        depths[0] = numeric_limits<int>::min();
        if (explore(0, 0)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
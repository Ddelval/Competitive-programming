//  D.cpp
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

const int lim = 1e5 + 10;
int n, d, m;
vi great;
vi smal;
vi sol;

ll fill() {
    if (great.size() > 0) sol[n - 1] = great[0];
    int fpos = 0;
    for (int i = 0; i < (int)great.size() - 1; ++i) {
        if ((d + 1) * (i + 1) > n - 1) break;
        //cout << (int)great.size() - 1 - i<<endl;
        sol[(d + 1) * i] = great[(int)great.size() - 1 - i];
        great[(int)great.size() - 1 - i] = -1;
        fpos = (d + 1) * (i + 1);
    }
    int i = 0;
    //cout << smal<<endl;
    //cout << sol<<endl;
    if (smal.size() > 0) {
        for (int p = fpos; p < n - (great.size() > 0); ++p) {
            sol[p] = smal[i];
            smal[i] = -1;
            i++;
        }
        //cout << sol << endl;
        for (int j = 0; j < n; j += d + 1) {
            if (j > n - (d + 1)) break;
            if ((int)smal.size() - i < d + 1) break;
            if (sol[j] <= m || sol[j] == -1) break;
            ll eqsum = 0;
            for (int w = 0; w < d + 1; ++w) eqsum += smal[i + w];
            if (sol[j] < eqsum) {
                for (int w = 0; w < d + 1; ++w) {
                    sol[j + w] = smal[i + w];
                    smal[i + w] = -1;
                }
                i += d + 1;
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (sol[i] != -1) cnt += sol[i];
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> m;

    great = vi();
    smal = vi();
    great.reserve(n);
    smal.reserve(n);
    sol = vi(n, -1);
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > m) {
            great.push_back(a);
        } else {
            smal.push_back(a);
        }
    }
    sort(all(great), greater<int>());
    sort(all(smal), greater<int>());
    //cout << great << endl;
    //cout << smal << endl;
    cout << fill() << "\n";
    /*for (auto a : sol) {
        cout << a << " ";
    }*/

    return 0;
}
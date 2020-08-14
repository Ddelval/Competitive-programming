//  D.cpp
//  Created by David del Val on 14/08/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
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

int sizes[3];
vl elems[3];

const int siz = 200 + 10;
int dp[siz][siz][siz];
ll ma;
void explore(ll val, ll used1, ll used2, ll used3);

void explore1(ll val, ll used1, ll used2, ll used3) {
    if (used1 == sizes[0] || used2 == sizes[1]) {
    } else {
        ll nval = val + elems[0][used1] * elems[1][used2];
        explore(nval, used1 + 1, used2 + 1, used3);
    }
}
void explore2(ll val, ll used1, ll used2, ll used3) {
    if (used2 == sizes[1] || used3 == sizes[2]) {
    } else {
        ll nval = val + elems[1][used2] * elems[2][used3];
        explore(nval, used1, used2 + 1, used3 + 1);
    }
}
void explore3(ll val, ll used1, ll used2, ll used3) {
    if (used1 == sizes[0] || used3 == sizes[2]) {
    } else {
        ll nval = val + elems[0][used1] * elems[2][used3];
        explore(nval, used1 + 1, used2, used3 + 1);
    }
}

void explore(ll val, ll used1, ll used2, ll used3) {
    ma = max(ma, val);
    if (used1 == sizes[0] && used2 == sizes[1]) return;
    if (used2 == sizes[1] && used3 == sizes[2]) return;
    if (used1 == sizes[0] && used3 == sizes[2]) return;

    if (dp[used1][used2][used3] > val) return;
    dp[used1][used2][used3] = val;
    pii arr[3];
    arr[0] = {-1, 0};
    arr[1] = {-1, 1};
    arr[2] = {-1, 2};

    if (used1 != sizes[0] && used2 != sizes[1]) arr[0] = {elems[0][used1] * elems[1][used2], 0};
    if (used2 != sizes[1] && used3 != sizes[2]) arr[1] = {elems[1][used2] * elems[2][used3], 1};
    if (used3 != sizes[2] && used1 != sizes[0]) arr[2] = {elems[2][used3] * elems[0][used1], 2};
    sort(arr, arr + 3, greater<pii>());
    for (int i = 0; i < 3; ++i) {
        if (arr[i].se == 0) explore1(val, used1, used2, used3);
        if (arr[i].se == 1) explore2(val, used1, used2, used3);
        if (arr[i].se == 2) explore3(val, used1, used2, used3);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));

    for (int i = 0; i < 3; ++i) {
        cin >> sizes[i];
    }
    for (int i = 0; i < 3; ++i) {
        elems[i] = vl(sizes[i]);
        for (int j = 0; j < sizes[i]; ++j) {
            cin >> elems[i][j];
        }
        sort(all(elems[i]), greater<int>());
    }
    explore(0, 0, 0, 0);
    cout << ma << "\n";
    return 0;
}
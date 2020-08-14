//  1393-B.cpp
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

const int len = 1e5 + 10;
int boards[len];
int o2, o4, o6, o8;

void ref(int val, int inc) {
    int v = boards[val];
    if (v >= 2 && v < 4)
        o2 += inc;
    else if (v >= 4 && v < 6)
        o4 += inc;
    else if (v >= 6 && v < 8)
        o6 += inc;
    else if (v >= 8)
        o8 += inc;
}
void updateCounters(int val, int delta) {
    ref(val, -1);
    boards[val] += delta;
    ref(val, 1);
}

bool check() {
    if (o8) return true;
    if (o6 >= 2) return true;
    if (o6 && o2) return true;
    if (o6 && o4) return true;
    if (o4 >= 2) return true;
    if (o4 && o2 >= 2) return true;

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    o2 = o4 = o6 = o8 = 0;

    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        updateCounters(a, 1);
    }
    int q;
    cin >> q;
    char c;
    for (int i = 0; i < q; ++i) {
        cin >> c >> a;
        updateCounters(a, 2 * (c == '+') - 1);
        bool b = check();
        if (b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
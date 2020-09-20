//  1388-D.cpp
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
const int lim = 2e5 + 10;
int n;
ll arr[lim];
ll b[lim];
ll referenced[lim];
ll seqVal[lim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    set<int> procesable;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        referenced[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a;
        b[i] = a - 1;
        if (b[i] == -2) {
            b[i]++;
        } else {
            referenced[b[i]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (referenced[i] == 0) procesable.insert(i);
    }

    ll res = 0;
    vl good, bad;
    while (!procesable.empty()) {
        int index = *procesable.begin();
        procesable.erase(procesable.begin());
        res += arr[index];
        if (arr[index] > 0) {
            good.push_back(index);
            if (b[index] >= 0) arr[b[index]] += arr[index];
        } else
            bad.push_back(index);
        if (b[index] >= 0) {
            referenced[b[index]]--;
            if (referenced[b[index]] == 0) {
                procesable.insert(b[index]);
            }
        }
    }

    good.insert(good.end(), bad.rbegin(), bad.rend());

    cout << res << "\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << good[i] + 1;
    }
    cout << "\n";

    return 0;
}
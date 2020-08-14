//  D.cpp
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
        int n;
        cin >> n;
        vi data(n);
        vi data2(n);
        for (int i = 0; i < n; ++i) cin >> data[i];
        map<int, int> present;
        for (auto a : data) present[a]++;
        set<int> s;
        for (int i = 0; i <= n; ++i) {
            if (present.count(i)) continue;
            s.insert(i);
        }

        vector<pii> vec;
        for (int i = 0; i < n; ++i) {
            vec.pb({data[i], i});
        }
        sort(all(vec));

        for (int i = 0; i < n; ++i) {
            int index = vec[i].se;
            data2[index] = *s.begin();
            s.erase(s.begin());
            present[data[index]]--;
            if (present[data[index]] == 0) {
                s.insert(data[index]);
            }
        }
        cout << "d2" << data2 << endl;
        vi data3(data2);
        sort(all(data3));
        vi data4(n);
        map<int, int> poss;
        for (int i = 0; i < n; ++i) {
            poss[data3[i]] = i;
        }
        vi r;
        int cpos = n - 1;
        int cinsert;
        for (int i = 0; i < n; ++i) {
            cinsert = *s.begin();
            r.push_back(cinsert);
            data4[cinsert] = *s.begin();
            s.erase(s.begin());
            s.insert(data2[cinsert]);
        }
        cout << "d4" << data4 << endl;
        cout << 2 * n << endl;
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            cout << i + 1;
        }
        for (auto a : r) {
            cout << " " << a + 1;
        }
        cout << endl;
    }

    return 0;
}
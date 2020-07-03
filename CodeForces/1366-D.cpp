//  1366-D.cpp
//  Created by David del Val on 03/07/2020
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
const int lim = 1e7+10;
bool composite[lim];
int firstDiv[lim];

void sieve() {
    for (int i = 2; i <lim; ++i) {
        if (!composite[i]) {
            int op = i+i;
            while(op<lim) {
                if (!composite[op]) firstDiv[op] = i;
                composite[op] = true;
                op += i;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();

    int n;
    cin >> n;
    vi inp(n);
    for (int i = 0; i < n;++i){
        cin >> inp[i];
    }
    vi val1, val2;
    for (int i = 0; i < n;++i){
        int div = firstDiv[inp[i]];
        if (!div) div = inp[i];
        int num = inp[i];
        int div1 = 1;
        while(num%div==0){
            div1 *= div;
            num /= div;
        }
        if(num==1){
            val1.pb(-1);
            val2.pb(-1);
            continue;
        }
        else{
            val1.pb(div1);
            val2.pb(num);
        }
    }
    for (int i = 0; i < n;++i){
        if (i) cout << " ";
        cout << val1[i];
    }
    cout << endl;
    for (int i = 0; i < n;++i){
        if (i) cout << " ";
        cout << val2[i];
    }

    return 0;
}
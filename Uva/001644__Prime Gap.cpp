//  001260__Prime Gap.cpp
//  Created by David del Val on 25/11/2022
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

#ifdef DEBUG
#define db(x) x
#define echo(x) cout << #x << ": " << x << endl;
#else
#define db(x)
#define echo(x)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif

vector<ll> primes;
const int lim = 1300000;
bool notPrime[lim];
void fill() {
    for (ll i = 2; i < lim; ++i) {
        if (notPrime[i] == 0) {
            for (ll j = 2; i * j < lim; ++j) {
                notPrime[i * j] = 1;
            }
        }
    }
    primes.reserve(100005);
    for (ll i = 2; i < lim; ++i) {
        if (notPrime[i] == 0) {
            primes.push_back(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill();
    ll n;
    while (cin >> n && n) {
        auto next_prime = lower_bound(primes.begin(), primes.end(), n);
        ll dist;
        if (*next_prime == n) {
            dist = 0;
        } else {
            ll pos = next_prime - primes.begin();
            dist = primes[pos] - primes[pos - 1];
        }
        cout << dist << endl;
    }

    return 0;
}
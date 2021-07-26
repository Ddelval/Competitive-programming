#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
const ll inf = LLONG_MAX / 10;
const int iinf = INT_MAX / 10;
const int mod = 10;
ll power(ll base, ll exp) {
    if (exp == 0) {
        return 1;
    }
    ll res = power(base, exp / 2);
    res = (res * res) % mod;
    if (exp % 2) {
        res *= base;
    }
    return res % mod;
}
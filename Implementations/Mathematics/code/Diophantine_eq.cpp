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

pll restrictRange(pll range, ll n, ll m, pll imageRange) {
    int sign = m > 0 ? 1 : -1;
    ll low = -sign * inf, high = sign * inf;

    if (imageRange.fi != -inf) {
        low = ((imageRange.fi - n) / m);
        if (low * m + n < imageRange.fi) {
            low += sign;
        }
    }

    if (imageRange.se != inf) {
        high = ((imageRange.se - n) / m);
        if (high * m + n > imageRange.se) {
            high -= sign;
        }
    }

    // Maybe reverse the endpoints
    std::tie(low, high) = pll(min(low, high), max(low, high));

    return {max(low, range.fi), min(high, range.se)};
}

// Let the result be {g,{x,y}}. Then x*a + y*b = g
ll gcdEx(ll a, ll b, ll &x, ll &y) {
    ll x1 = 0, y1 = 1;
    ll a1 = a, b1 = b;
    x = 1;
    y = 0;

    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = pii(x1, x - q * x1);
        tie(y, y1) = pii(y1, y - q * y1);
        tie(a1, b1) = pii(b1, a1 - q * b1);
    }
    return a1;
}

struct DioEq {
    // Equation of the form ax + by = c
    // where x,y are the unknowns
    ll a, b, c;
    ll x0, y0, g;
    pll rangeOfK = {0, -1};
    bool solvable = true;

    DioEq(){};
    DioEq(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {
        // Find a solution
        ll xg, yg;
        g = gcdEx(abs(a), abs(b), xg, yg);
        if (c % g != 0) {
            this->solvable = false;
        }
        x0 = xg * (c / g);
        y0 = yg * (c / g);
        if (a < 0) x0 = -x0;
        if (b < 0) y0 = -y0;
    }

    pll findRangeOfK(pll rangeX, pll rangeY) {
        pll rangeK(-inf, inf);
        if (!this->solvable) {
            return {0, -1};
        }
        rangeK = restrictRange(rangeK, x0, b / g, rangeX);
        rangeK = restrictRange(rangeK, y0, -a / g, rangeY);
        return rangeK;
    }
};
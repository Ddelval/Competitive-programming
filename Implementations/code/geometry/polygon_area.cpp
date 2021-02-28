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

double calcAreaSegment(pii a1, pii a2) {
    if (a1.fi == a2.fi)
        return 0;

    return (a2.fi - a1.fi) * (max(a1.se, a2.se) - abs(a1.se - a2.se) / 2.0);
}
double calcAreaPolygon(vector<pii> points) {
    double ans = 0;
    for (int i = 1; i < points.size(); ++i) {
        ans += calcAreaSegment(points[i - 1], points[i]);
    }
    ans += calcAreaSegment(points.back(), points[0]);
    return abs(ans);
}
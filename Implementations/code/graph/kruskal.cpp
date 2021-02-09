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

//
ll kruskal(vector<pair<pii, int>> &edgeList) {
    int cost = 0;

    auto cmp = [](pair<pii, int> a, pair<pii, int> b) { return a.se < b.se; };
    sort(all(edgeList), cmp);
    
    for (auto a : edgeList) {
        if (find(a.fi.fi) != find(a.fi.se)) {
            //Not connected already -> connect them
            Union(a.fi.fi, a.fi.se);
            cost += a.se;
        }
    }
    return cost;
}
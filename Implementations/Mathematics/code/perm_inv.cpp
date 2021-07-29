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
namespace UFDS {
const int lim = 3 * 10e5;
int parent[lim];
int rankk[lim];

void initialize(int n) {
    for (int i = 0; i < n; ++i) {
        rankk[i] = 0;
        parent[i] = i;
    }
}
int find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) {
        return;
    }
    if (rankk[pa] > rankk[pb]) {
        parent[pb] = pa;
    } else if (rankk[pa] < rankk[pb]) {
        parent[pa] = pb;
    } else {
        parent[pa] = pb;
        rankk[pb]++;
    }
}
}; // namespace UFDS

int swapsPermutation(vi perm1, vi perm2) {
    int n = perm1.size();
    UFDS::initialize(n + 1);
    int components = n;
    for (int i = 0; i < n; ++i) {
        if (UFDS::find(perm1[i]) != UFDS::find(perm2[i])) {
            components--;
            UFDS::Union(perm1[i], perm2[i]);
        }
    }
    return n - components;
}
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
const int lim = 200000;
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
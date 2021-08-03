#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

//
//
// List of vertices in the 2nd component connected to
// the i-th vertex in the first component
vector<vi> adyList;

// Index of the vertex in 1st component connected to the
// i-th vertex in the second component
vector<int> match;
vector<bool> used;
bool augmentPath(int current) {
    if (used[current]) {
        return false;
    }
    used[current] = 1;
    for (int to : adyList[current]) {
        if (match[to] == -1 || augmentPath(match[to])) {
            match[to] = current;
            return true;
        }
    }
    return false;
}
int calculateMCBM(int n1, int n2) {
    match = vi(n2, -1);
    int res = 0;
    for (int i = 0; i < n1; ++i) {
        used.assign(n1, false);
        res += augmentPath(i);
    }
    return res;
}
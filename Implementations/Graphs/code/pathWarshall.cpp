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

const int lim = 1;
ll adyList[lim][lim];
ll lastInPath[lim][lim];

void warshall(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adyList[i][j] > adyList[i][k] + adyList[k][j]) {
                    adyList[i][j] = adyList[i][k] + adyList[k][j];
                    lastInPath[i][j] = lastInPath[k][j];
                }
            }
        }
    }
}

// Give an empty vector
void getPath(int i, int j, vector<int> &path) {
    if (i != j) {
        getPath(i, lastInPath[i][j], path);
        path.push_back(j);
    }
}
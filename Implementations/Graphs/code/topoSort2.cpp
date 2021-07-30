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

vi topoSort;
vector<vi> adyList;
void kahnTopoSort() {
    int n = adyList.size();
    topoSort.clear();

    vi noIncoming;
    vi hasincoming(n, 0);
    for (auto a : adyList) {
        for (auto b : a) {
            hasincoming[b]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!hasincoming[i]) {
            noIncoming.push_back(i);
        }
    }
    while (noIncoming.size() != 0) {
        int curr = noIncoming.back();
        noIncoming.pop_back();
        topoSort.push_back(curr);
        for (auto a : adyList[curr]) {
            hasincoming[a]--;
            if (!hasincoming[a]) {
                noIncoming.push_back(a);
            }
        }
    }
    for (auto a : hasincoming) {
        if (a != 0) {
            cout << "graph has at least one cycle";
        }
    }
}
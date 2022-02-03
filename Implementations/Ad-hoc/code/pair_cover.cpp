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

set<int> minimal_cover(vector<pii> &pairs) {
    sort(all(pairs), [](pii a, pii b) {
        if (a.fi != b.fi) {
            return a.fi < b.fi;
        } else {
            return a.se > b.se;
        }
    });

    set<int> picked;
    int current = 0;       // Index of the current pair picked
    int end = pairs[0].se; // End of the current pair
    int max_r = end;       // Max right limit of the explored pairs
    int max_current = 0;   // Index of the pair with the max right limit

    picked.insert(0);
    for (int i = 1; i < pairs.size(); ++i) {
        while (pairs[i].fi > end) {
            // The starting point of the pair that we are exploring now.
            current = max_current;
            picked.insert(max_current);
            end = pairs[max_current].se;

            if (pairs[i].se > max_r) {
                max_r = pairs[i].se;
                max_current = i;
            }
        }
        if (pairs[i].se > max_r) {
            max_r = pairs[i].se;
            max_current = i;
        }
    }
    if (end < pairs[max_current].se) {
        picked.insert(max_current);
    }
    return picked;
}
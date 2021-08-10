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
//

ll mergeSort(int left, int right, vi &elems) {
    if (left == right) {
        return 0;
    }
    int mid = (left + right) / 2;
    ll res = 0;
    res += mergeSort(left, mid, elems);
    res += mergeSort(mid + 1, right, elems);

    int index = 0;
    vi aux(right - left + 1, 0);
    int i1 = left, i2 = mid + 1;
    while (i1 != mid + 1 || i2 != right + 1) {
        int *picked;
        if (i1 > mid) {
            picked = &i2;
        } else if (i2 > right) {
            picked = &i1;
        } else if (elems[i1] <= elems[i2]) {
            picked = &i1;
        } else {
            picked = &i2;
            res += abs((*picked) - (left + index));
        }
        aux[index++] = elems[*picked];
        (*picked)++;
    }
    for (int i = 0; i < right - left + 1; ++i) {
        elems[i + left] = aux[i];
    }
    return res;
}

ll countAdjacentSwaps(vi &elems) {
    return mergeSort(0, int(elems.size()) - 1, elems);
}
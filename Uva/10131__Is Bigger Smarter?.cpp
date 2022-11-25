//  10131__Is Bigger Smarter?.cpp
//  Created by David del Val on 25/11/2022
//
//
// https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

#ifdef DEBUG
#define db(x) x
#define echo(x) cout << #x << ": " << x << endl;
#else
#define db(x)
#define echo(x)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<pair<ll, ll>, ll>> elem;

    ll a1, a2;
    int counter = 0;
    while (cin >> a1 >> a2) {
        elem.push_back({{a1, a2}, counter});
        counter++;
    }
    sort(all(elem));
    int n = elem.size();

    vi len(n);
    vi from(n);
    for (int i = 0; i < n; ++i) {
        len[i] = 1;
        from[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int cprev = 0;
        for (int j = 0; j < i; ++j) {
            if (elem[j].fi.fi < elem[i].fi.fi &&
                elem[j].fi.se > elem[i].fi.se) {
                if (len[j] > cprev) {
                    len[i] = len[j] + 1;
                    from[i] = j;
                    cprev = len[j];
                }
            }
        }
    }
    int ma = 0;
    int maidx = -1;
    for (int i = 0; i < n; ++i) {
        if (len[i] > ma) {
            ma = len[i];
            maidx = i;
        }
    }
    vi indeces;
    int index = maidx;
    indeces.push_back(maidx);
    while (from[index] != -1) {
        indeces.push_back(from[index]);
        index = from[index];
    }
    cout << ma << "\n";
    reverse(all(indeces));
    for (int i = 0; i < indeces.size(); ++i) {
        cout << elem[indeces[i]].se + 1 << "\n";
    }

    return 0;
}
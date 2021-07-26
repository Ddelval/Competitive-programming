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

class SparseTable {
private:
    vl logs;
    vector<vl> table;
    std::function<ll(ll, ll)> f;

public:
    SparseTable(vl &data, std::function<ll(ll, ll)> f) : f(f) {
        int n = data.size();
        table.pb(data);
        for (int j = 1; (1ll << j) <= n; ++j) {
            vl nextRow(n);
            for (int i = 0; i + (1ll << j) <= n; ++i) {
                int otherIndex = i + (1ll << (j - 1));
                nextRow[i] = f(table.back()[i], table.back()[otherIndex]);
            }
            table.push_back(std::move(nextRow));
        }

        logs = vl(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            logs[i] = logs[i / 2] + 1;
        }
    }

    ll valueInRange(int left, int right) {
        ll j = logs[right - left + 1];
        ll intervalSize = 1ll << j;
        return f(table[j][left], table[j][right - intervalSize + 1]);
    }
};
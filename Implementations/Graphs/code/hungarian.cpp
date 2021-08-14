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
ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

// The rows are jobs, the columns are workers
pair<ll, vl> hungarian(vector<vl> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vl jobP(n), workerP(m + 1), matched(m + 1, -1);

    vl dist(m + 1, inf);
    vi from(m + 1, -1), seen(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        int cWorker = m;
        matched[cWorker] = i;
        std::fill(all(dist), inf);
        std::fill(all(from), -1);
        std::fill(all(seen), false);

        while (matched[cWorker] != -1) {
            seen[cWorker] = true;
            int i0 = matched[cWorker], nextWorker = -1;
            ll delta = inf;

            for (int worker = 0; worker < m; ++worker) {
                if (seen[worker])
                    continue;
                ll candidateDistance = matrix[i0][worker];
                candidateDistance += -jobP[i0] - workerP[worker];

                if (candidateDistance < dist[worker]) {
                    dist[worker] = candidateDistance;
                    from[worker] = cWorker;
                }
                if (dist[worker] < delta) {
                    delta = dist[worker];
                    nextWorker = worker;
                }
            }
            for (int j = 0; j <= m; ++j) {
                if (seen[j]) {
                    jobP[matched[j]] += delta;
                    workerP[j] -= delta;
                } else {
                    dist[j] -= delta;
                }
            }
            cWorker = nextWorker;
        }
        while (cWorker != m) {
            int prevWorker = from[cWorker];
            matched[cWorker] = matched[prevWorker];
            cWorker = prevWorker;
        }
    }
    ll ans = -workerP[m];
    vl rowMatchesWith(n);
    for (int j = 0; j < m; ++j) {
        if (matched[j] != -1) {
            rowMatchesWith[matched[j]] = j;
        }
    }
    return {ans, std::move(rowMatchesWith)};
}
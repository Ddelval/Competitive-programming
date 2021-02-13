//  H.cpp
//  Created by David del Val on 11/02/2021
//
//

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

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T>
struct subs_succeeded : std::true_type {};
template <>
struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T>
struct get_iter_res {
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <>
struct Has_iterator<string> : subs_fail {};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size) {
    vector<T> v;
    v.reserve(size);
    T a;
    for (int i = 0; i < size; ++i) {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// ====================================================== //
// ================== Pairs operations ================== //
// ====================================================== //
inline pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

int n, m;
vector<vector<pii>> adyList; // dest,weight

vl dijkstra(int ini) {

    vl dists(n, inf);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, ini});
    dists[ini] = 0;
    while (!q.empty()) {
        auto a = q.top();
        q.pop();

        if (dists[a.se] != a.fi) {
            continue;
        }
        for (auto b : adyList[a.se]) {
            if (dists[b.fi] > dists[a.se] + b.se) {
                dists[b.fi] = dists[a.se] + b.se;
                q.push({dists[b.fi], b.fi});
            }
        }
    }

    return dists;
}

vi possible;
void process(vector<pair<pii, pii>> dist) {
    map<int, int> points;

    //cout << dist << endl;

    for (auto a : dist) {
        //cout << points << endl;
        pii point = {a.fi.se, a.se.fi};
        //cout << "inserting " << point << endl;
        if (points.count(point.fi)) {
            if (points[point.fi] < point.se) {
                possible[a.se.se] = 0;
                continue;
            }
            points.erase(point.fi);
            //cout << "erased" << points << endl;
            //cout << "erased";
            //cout << points << endl;
        }
        auto it = points.lower_bound(point.fi);
        if (it != points.begin()) {
            it--;
            if (it->se <= point.second) {
                possible[a.se.se] = 0;
                continue;
            }
            it++;
        }
        //int cnt = 0;
        for (auto it2 = it; it2 != points.end();) {
            if (it2->second >= point.se) {
                it2 = points.erase(it2);
                //cout << "erasing " << points << endl;
            } else {
                break;
            }
        }
        points[point.fi] = point.se;
    }
    //cout << points << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    possible = vi(n, 1);

    adyList = decltype(adyList)(n, vector<pii>());

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adyList[a].pb({b, c});
        adyList[b].pb({a, c});
    }
    vl d1 = dijkstra(0);
    vl d2 = dijkstra(1);
    vl d3 = dijkstra(2);
    vector<pair<pii, pii>> dist;
    for (int i = 0; i < n; ++i) {
        dist.pb({{d1[i], d2[i]}, {d3[i], i}});
    }
    sort(all(dist));
    process(dist);
    //cout << "pos " << possible << endl;
    dist.clear();
    for (int i = 0; i < n; ++i) {
        dist.pb({{d2[i], d1[i]}, {d3[i], i}});
    }
    sort(all(dist));
    process(dist);
    //cout << "pos " << possible << endl;
    dist.clear();
    for (int i = 0; i < n; ++i) {
        dist.pb({{d3[i], d2[i]}, {d1[i], i}});
    }
    sort(all(dist));
    process(dist);
    //cout << "pos " << possible << endl;

    ll ans = 0;
    for (auto a : possible) {
        ans += a;
    }
    cout << ans << "\n";

    return 0;
}
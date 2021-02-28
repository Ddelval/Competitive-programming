//  C.cpp
//  Created by David del Val on 20/02/2021
//
//

#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
int n;
const int lim = 1000 + 10;
vector<vi> adyList(n);

ll width[lim];
ll parent[lim];

void setParents(int node) {
    for (auto a : adyList[node]) {
        if (parent[a] == 0) {
            parent[a] = node;
            setParents(a);
        }
    }
}

ll getWidth(int node) {
    if (width[node] != -1) {
        return width[node];
    }
    ll wid = 0;
    for (auto e : adyList[node]) {
        if (e != parent[node]) {
            wid += getWidth(e);
        }
    }
    return width[node] = max(wid, 1ll);
}

vector<pair<double, double>> bfs() {
    vector<pair<double, double>> locations(n, {0, 0});
    queue<pair<int, pair<double, double>>> q;
    vi visit(n, 0);
    //cout << visit << endl;
    visit[1] = 1;
    q.push({1, {-M_PI, M_PI}});
    while (!q.empty()) {

        auto a = q.front();
        q.pop();

        double angularrange = a.se.se - a.se.fi;
        double angularstep = angularrange / getWidth(a.fi);
        //cout << a.fi << " " << angularstep << " " << getWidth(a.fi) << " " << parent[a.fi] << endl;
        if (angularstep < 1.5 * 1e-4) {
            angularstep = 1.5 * 1e-4;
        }
        double angularpos = a.se.fi;
        pair<double, double> nodeloc = locations[a.fi];

        for (auto edge : adyList[a.fi]) {
            if (visit[edge]) {
                continue;
            }
            double angularlimit1 = angularpos;

            angularpos += (angularstep * getWidth(edge)) / 2;

            visit[edge] = true;
            pair<double, double> location = nodeloc;
            location.fi += cos(angularpos);
            location.se += sin(angularpos);

            locations[edge] = location;

            angularpos += (angularstep * getWidth(edge)) / 2;
            
            double angularlimit2 = angularpos;
            q.push({edge, {angularlimit1, angularlimit2}});
        }
    }
    return locations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n++;
    adyList = vector<vi>(n, vi());
    int a, b;
    for (int i = 1; i < n - 1; ++i) {
        cin >> a >> b;
        adyList[a].pb(b);
        adyList[b].pb(a);
    }

    parent[1] = 1;
    setParents(1);

    for (int i = 0; i < lim; ++i) {
        width[i] = -1;
    }

    auto v = bfs();

    for (int i = 1; i < n; ++i) {
        auto a = v[i];
        printf("%.12lf %.12lf\n", a.fi, a.se);
    }

    return 0;
}
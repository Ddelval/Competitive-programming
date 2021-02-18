//  K.cpp
//  Created by David del Val on 17/02/2021
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
const int lim = 1e5 + 10;

int n, m, t;
vector<vi> adyList;
vector<vi> revAdyList;
int from[lim];
bool visited[lim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    int a, b;
    adyList = vector<vi>(n);
    revAdyList = vector<vi>(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adyList[a].pb(b);
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << i << " " << adyList[i] << endl;
    }
    */

    set<int> neigh;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        for (auto b : adyList[i]) {
            if (i != t && b != t)
                revAdyList[b].pb(i);
            if (b == t) {
                neigh.insert(i);
                q.push(i);
            }
        }
    }
    /*
    cout << "revAdy";
    for (int i = 0; i < n; ++i) {
        cout << i << " " << revAdyList[i] << endl;
    }
    cout << endl;
    cout << "n1 " << neigh << endl;
    */
    for (int i = 0; i < n; ++i) {
        from[i] = -1;
    }
    set<int> neigh2 = neigh;

    for (auto a : neigh) {
        from[a] = a;
    }

    set<int> found_from_both;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == t) {
            continue;
        }
        //cout << "exploring " << current << endl;

        for (auto a : revAdyList[current]) {
            if (a == t) {
                continue;
            }
            //cout <<current<< " connected to " << a << " "<<from[current]<<" "<<from[a]<<" ";

            if (from[a] == -1) {
                from[a] = from[current];
                q.push(a);
                //cout << 1;
            } else if (from[a] != from[current] && neigh2.count(a)) {
                auto it = neigh.find(a);
                if (it != neigh.end()) {
                    neigh.erase(it);
                }
                //cout << 2;
            } else if (from[a] != from[current]) {
                found_from_both.insert(a);
                //cout << 3;
            }
            //cout << endl;
        }
    }

    // cout << "f ";
    for (auto a : found_from_both) {
        q.push(a);
        //cout << a << " ";

        visited[a] = true;
    }
    //cout << endl;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto a : revAdyList[current]) {
            if (!visited[a] && a != t) {
                visited[a] = true;
                q.push(a);
                if (neigh.count(a)) {
                    neigh.erase(neigh.find(a));
                }
            }
        }
    }
    cout << neigh.size() << "\n";
    for (auto a : neigh) {
        cout << a << "\n";
    }

    return 0;
}
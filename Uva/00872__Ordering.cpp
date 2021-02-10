//  00872__Ordering.cpp
//  Created by David del Val on 14/01/2021
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

vector<vi> adyList;
vi indegrees;

vector<vi> paths;

void explore(vi &currentPath, vi &taken, int n) {

    for (int i = 0; i < n; ++i) {
        if (indegrees[i] || taken[i]) {
            continue;
        }

        for (auto a : adyList[i]) {
            indegrees[a]--;
        }
        currentPath.push_back(i);
        taken[i] = true;

        explore(currentPath, taken, n);

        taken[i] = false;
        currentPath.pop_back();
        for (auto a : adyList[i]) {
            indegrees[a]++;
        }
    }
    if (currentPath.size() == n) {
        for (int i = 0; i < n; ++i) {
            if (indegrees[i]) {
                return;
            }
        }
        paths.push_back(currentPath);
    }
}

void findallTopoSorts() {
    int n = adyList.size();
    vi currentPath;
    vi taken(n, 0);
    indegrees = vi(n, 0);
    paths.clear();

    for (auto a : adyList) {
        for (auto b : a) {
            indegrees[b]++;
        }
    }

    explore(currentPath, taken, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        vector<string> strings;
        while (getline(cin, s)) {
            stringstream ss(s);
            string s2;
            while (ss >> s2) {
                strings.push_back(s2);
            }
            if (strings.size()) {
                break;
            }
        }
        map<string, int> sti;
        map<int, string> its;
        int index = 0;
        for (string s2 : strings) {
            sti[s2] = index;
            its[index++] = s2;
        }

        int n = index;
        adyList = vector<vi>(n, vi());

        getline(cin, s);
        stringstream ss(s);
        string s2;
        while (ss >> s2) {
            string c1;
            string c2;
            c1 += s2[0];
            c2 += s2[2];
            adyList[sti[c1]].push_back(sti[c2]);
        }
        findallTopoSorts();

        vector<string> solutions;
        for (auto a : paths) {
            vector<string> vc;
            for (auto el : a) {
                vc.push_back(its[el]);
            }
            stringstream sts("");
            sts << vc;
            solutions.push_back(sts.str());
        }
        sort(all(solutions));

        if (paths.size() == 0) {
            cout << "NO\n";
        } else {
            for (auto a : solutions) {
                cout << a << "\n";
            }
        }
        if (t) {
            cout << "\n";
        }
    }

    return 0;
}
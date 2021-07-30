//  00186__Trip Routing.cpp
//  Created by David del Val on 03/07/2021
//
//
//https://github.com/Ddelval/Competitive-programming/blob/master/template.cpp

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

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T>
struct get_termination {
    static constexpr const char *get() {
        return sep1;
    }
};
template <typename U, typename S>
struct get_termination<vector<U, S>> {
    static constexpr const char *get() {
        return sep2;
    }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator = get_termination<typename T::value_type>::get();
            o << terminator;
        }
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

map<string, int> cities;
map<int, string> revCity;
int indexx = 0;
int getCityIndex(string city) {
    if (!cities.count(city)) {
        revCity[indexx] = city;
        cities[city] = indexx;
        indexx++;
    }
    return cities[city];
}

const int lim = 101;
string roads[lim][lim];
ll dist[lim][lim];
ll lastInPath[lim][lim];

void warshall() {
    int n = cities.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    lastInPath[i][j] = lastInPath[k][j];
                }
            }
        }
    }
}

void getPath(int i, int j, vector<int> &path) {
    if (i != j) {
        getPath(i, lastInPath[i][j], path);
        path.push_back(j);
    }
}

void printHeader() {
    cout << "\n\n";

    printf("%-20s %-20s %-10s %s\n", "From", "To", "Route", "Miles");
    int distances[] = {20, 20, 10, 5};
    for (int i = 0; i < 4; ++i) {
        if (i)
            printf(" ");
        for (int j = 0; j < distances[i]; ++j) {
            printf("-");
        }
    }
    printf("\n");
}
int main() {
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < lim; ++i) {
        for (int j = 0; j < lim; ++j) {
            dist[i][j] = inf;
            lastInPath[i][j] = i;
        }
    }

    string s;
    while (getline(cin, s) && s.length() > 0) {
        stringstream ss(s);
        string s2;
        getline(ss, s2, ',');
        int i1, i2;
        i1 = getCityIndex(s2);
        getline(ss, s2, ',');
        i2 = getCityIndex(s2);
        string road;
        getline(ss, road, ',');
        int miles;
        ss >> miles;
        if (miles < dist[i1][i2]) {
            dist[i1][i2] = miles;
            roads[i1][i2] = road;
        }
        if (miles < dist[i2][i1]) {
            dist[i2][i1] = miles;
            roads[i2][i1] = road;
        }
    }
    warshall();
    vector<pii> paths;
    while (getline(cin, s) && s.length() > 0) {
        stringstream ss(s);
        string s2;
        getline(ss, s2, ',');
        int i1, i2;
        i1 = getCityIndex(s2);
        getline(ss, s2, ',');
        i2 = getCityIndex(s2);
        paths.push_back({i1, i2});
        vector<int> path = {i1};
        getPath(i1, i2, path);

        printHeader();
        for (int i = 1; i < path.size(); ++i) {
            printf("%-20s %-20s %-10s %5d\n", revCity[path[i - 1]].c_str(), revCity[path[i]].c_str(),
                   roads[path[i - 1]][path[i]].c_str(), dist[path[i - 1]][path[i]]);
        }
        printf("%58s\n", "-----");
        printf("%-20s %-20s %-10s %5d\n", "", "", "Total", dist[i1][i2]);
    }


    return 0;
}
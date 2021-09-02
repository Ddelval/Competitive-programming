//  L.cpp
//  Created by David del Val on 01/09/2021
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

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p);

// ====================================================== //
// ===================  Container IO  =================== //
// ====================================================== //
template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;
struct subs_fail {};

template <typename T> struct subs_succeeded : std::true_type {};
template <> struct subs_succeeded<subs_fail> : std::false_type {};

template <typename T> struct get_iter_res {
private:
    template <typename X> static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type> {};
template <> struct Has_iterator<string> : subs_fail {};

constexpr const char *sep1 = " ";
constexpr const char *sep2 = "\n";
template <typename T> struct get_termination {
    static constexpr const char *get() { return sep1; }
};
template <typename U, typename S> struct get_termination<vector<U, S>> {
    static constexpr const char *get() { return sep2; }
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val) {
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it) {
        if (!first) {
            constexpr const char *terminator =
                get_termination<typename T::value_type>::get();
            o << terminator;
        }
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll> inline vector<T> readVector(int size) {
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
inline pii operator+(pii a, pii b) { return {a.fi + b.fi, a.se + b.se}; }

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p) {
    o << "(" << p.fi << "," << p.se << ")";
    return o;
}

// gcd(0, n) = n
inline long long _gcd(long long a, long long b) {
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;
int iinf = INT_MAX / 10;

#ifdef _LOCAL_
// Local constraints

#else
// Judge constraints
#endif

int n, m;
vector<vi> reservationsCustomer;
vector<unordered_map<int, int>> preferenceOfRest;
vector<priority_queue<pii>> restaurantSeats;
vi capacities;

void solve() {
    set<int> unallocated;
    set<int> allocated;
    for (int i = 0; i < n; ++i) {
        unallocated.insert(i);
    }

    while (unallocated.size()) {
        int nextCustomer = *unallocated.begin();
        echo(nextCustomer + 1);
        unallocated.erase(nextCustomer);
        int restaurant = -1;
        while (reservationsCustomer[nextCustomer].size() != 0) {
            int candidateRestaurant = reservationsCustomer[nextCustomer].back();
            pii possible = {preferenceOfRest[candidateRestaurant][nextCustomer],
                            nextCustomer};
            reservationsCustomer[nextCustomer].pop_back();
            echo(candidateRestaurant);
            echo(restaurantSeats[candidateRestaurant].size());

            if (restaurantSeats[candidateRestaurant].size() <
                capacities[candidateRestaurant]) {
                restaurantSeats[candidateRestaurant].push(possible);
                restaurant = candidateRestaurant;
                break;
            }

            db({
                cout << restaurantSeats[candidateRestaurant].top() << " "
                     << possible << endl;
            });

            if (restaurantSeats[candidateRestaurant].top() > possible) {
                pii pref = restaurantSeats[candidateRestaurant].top();
                unallocated.insert(pref.se);
                allocated.erase(pref.se);
                restaurantSeats[candidateRestaurant].pop();
                restaurantSeats[candidateRestaurant].push(possible);
                restaurant = candidateRestaurant;
                break;
            }
        }
        echo(restaurant + 1);
        db({ cout << endl; });
        if (restaurant != -1) {
            allocated.insert(nextCustomer);
        }
    }
    for (auto a : allocated) {
        cout << a + 1 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    reservationsCustomer = decltype(reservationsCustomer)(n);
    preferenceOfRest = decltype(preferenceOfRest)(n);
    restaurantSeats = decltype(restaurantSeats)(n);
    capacities = readVector<int>(m);

    string s;
    getline(cin, s);

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        stringstream ss(s);
        int a;
        while (ss >> a) {
            reservationsCustomer[i].pb(a - 1);
        }
        reverse(all(reservationsCustomer[i]));
        echo(reservationsCustomer[i]);
    }
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        stringstream ss(s);
        int cnt = 0;
        int a;
        while (ss >> a && a) {
            preferenceOfRest[i][a - 1] = cnt++;
        }
        echo(preferenceOfRest[i]);
    }
    solve();

    return 0;
}
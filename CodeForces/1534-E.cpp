//  1534-E.cpp
//  Created by David del Val on 21/06/2021
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

const int lim = 501;
int dist[lim];
int previous[lim];
int transition[lim];
int nextt[lim];

int bfs(int n, int k) {
    for (int i = 0; i <= n; ++i) {
        dist[i] = iinf;
        previous[i] = -1;
        transition[i] = -1;
    }
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int current = q.front();
        //cerr << "Current " << current << ":";
        q.pop();
        if (current == 0) {
            return 0;
        }
        for (int i = 1; i <= min(k, current); ++i) {
            if (current - i < 0) {
                continue;
            }
            if (k - i > n - current) {
                continue;
            }
            int next = current - i;
            next += k - i;
            if (next < 0 || next > n || dist[next] <= dist[current] + 1) {
                continue;
            }
            dist[next] = dist[current] + 1;
            previous[next] = current;
            transition[next] = i;
            //cerr << next << endl;
            q.push(next);
        }
    }
    return -1;
}
void reverses(int n) {
    int current = 0;
    while (previous[current] != -1) {
        nextt[previous[current]] = transition[current];
        current = previous[current];
    }
}

int sendQueries(int n, int k) {
    int solution = 0;
    int current = n;
    vector<int> evens;
    vector<int> odds;
    evens.reserve(k);
    odds.reserve(k);
    vi oddsbuffer;
    oddsbuffer.reserve(k);

    for (int i = 0; i < n; ++i) {
        evens.push_back(i + 1);
    }

    while (current != 0) {
        cout << "?";
        for (int i = 0; i < nextt[current]; ++i) {
            cout << " " << evens.back();
            oddsbuffer.push_back(evens.back());
            evens.pop_back();
        }
        for (int i = 0; i < k - nextt[current]; ++i) {
            cout << " " << odds.back();
            evens.push_back(odds.back());
            odds.pop_back();
        }
        while (!oddsbuffer.empty()) {
            odds.push_back(oddsbuffer.back());
            oddsbuffer.pop_back();
        }
        cout << "\n";
        cout.flush();
        int a;
        cin >> a;
        solution ^= a;

        int cnst = current;
        current = current - nextt[current];
        current += (k - nextt[cnst]);
    }
    return solution;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (bfs(n, k) < 0) {
        cout << "-1\n";
        return 0;
    }
    reverses(n);
    int res = sendQueries(n, k);
    cout << "! " << res << "\n";
    cout.flush();

    return 0;
}
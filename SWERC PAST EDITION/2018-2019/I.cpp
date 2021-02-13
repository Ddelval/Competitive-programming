//  I.cpp
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

const int lim = 1000;
int board[lim][lim];
bool explored[lim][lim];
int h, w;

void flood_fill_8(int i, int j, int target) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return;

    if (board[i][j] != target)
        return;
    if (explored[i][j])
        return;
    explored[i][j] = true;

    for (int a = -1; a < 2; ++a) {
        for (int b = -1; b < 2; ++b) {
            flood_fill_8(i + a, j + b, target);
        }
    }
}

void flood_fill_4(int i, int j, int target) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return;

    if (board[i][j] != target)
        return;
    if (explored[i][j])
        return;
    explored[i][j] = true;

    flood_fill_4(i + 1, j, target);
    flood_fill_4(i - 1, j, target);
    flood_fill_4(i, j - 1, target);
    flood_fill_4(i, j + 1, target);
}

int flood_fill_mark(int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return 0;

    if (explored[i][j]) {
        return 0;
    }
    if (board[i][j] == 1) {
        flood_fill_4(i, j, 1);
        return 1;
    }
    explored[i][j] = true;
    int ans = 0;
    ans += flood_fill_mark(i + 1, j);
    ans += flood_fill_mark(i - 1, j);
    ans += flood_fill_mark(i, j + 1);
    ans += flood_fill_mark(i, j - 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h;
    char c;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c;
            if (c == '#') {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
    flood_fill_8(0, 0, 0); // Fill the borders
    int aa, ab, ac;
    aa = ab = ac = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (explored[i][j]) {
                continue;
            }
            if (board[i][j] == 1) {
                flood_fill_4(i, j, 1);
            }
            if (board[i][j] == 0) {
                bool isnoise = true;
                for (int a = -1; a < 2; ++a) {
                    for (int b = -1; b < 2; ++b) {
                        if ((a || b) && board[i + a][j + b] != 1) {
                            isnoise = false;
                        }
                    }
                }
                if (isnoise) {
                    continue;
                }
                //We are in a mark
                //cout << i << " " << j << endl;
                int res = flood_fill_mark(i, j);
                //cout << res << endl;
                if (res == 0)
                    ac++;
                else if (res == 1) {
                    aa++;
                } else {
                    ab++;
                }
            }
        }
    }
    cout << aa << " " << ab << " " << ac << "\n";

    return 0;
}
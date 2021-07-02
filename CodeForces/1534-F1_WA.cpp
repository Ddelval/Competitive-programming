//  1534-F1.cpp
//  Created by David del Val on 01/07/2021
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

const int lim = 400010;
int board[lim];
int first[lim];

int rankk[lim];
int needed[lim];
int parentt[lim];

int findParent(int n) {
    if (parentt[n] == n) {
        return n;
    }
    return parentt[n] = findParent(parentt[n]);
}
void Union(int n1, int n2) {
    n1 = findParent(n1);
    n2 = findParent(n2);
    if (n1 == n2) {
        return;
    }
    if (rankk[n1] > rankk[n2]) {
        parentt[n2] = n1;
    } else if (rankk[n1] < rankk[n2]) {
        parentt[n1] = n2;
    } else {
        parentt[n1] = n2;
        rankk[n2]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        first[i] = -1;
    }
    int index = 1;
    char a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            if (a == '#') {
                needed[index] = 1;
                parentt[index] = index;
                rankk[index] = 1;
                board[i * m + j] = index++;
                if (first[j] == -1) {
                    first[j] = i;
                }
            }
            //cout << board[i * m + j] << " ";
        }
        //cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i * m + j] == 0) {
                continue;
            }
            if (j != m - 1 && board[i * m + j + 1] != 0) {
                Union(board[i * m + j], board[i * m + j + 1]);
            }
            if (i != n - 1 && board[(i + 1) * m + j] != 0) {
                Union(board[i * m + j], board[(i + 1) * m + j]);
            }
        }
    }

    /*
    for (int i = 0; i < index; ++i) {
        cout << "(" << i << ", " << findParent(i) << ") ";
    }
    cout << endl;
    */

    vi sizes = readVector<int>(m);

    for (int j = 0; j < m; ++j) {
        if (first[j] == -1) {
            continue;
        }
        for (int i = first[j]; i < n; ++i) {
            if (j && board[i * m + j - 1]) {
                if (findParent(board[first[j] * m + j]) != findParent(board[i * m + j - 1]))
                    needed[findParent(board[i * m + j - 1])] = 0;
            }
            if (j < m - 1 && board[i * m + j + 1]) {
                if (findParent(board[first[j] * m + j]) != findParent(board[i * m + j + 1]))
                    needed[findParent(board[i * m + j + 1])] = 0;
            }
            if (board[i * m + j]) {
                if (findParent(board[first[j] * m + j]) != findParent(board[i * m + j]))
                    needed[findParent(board[i * m + j])] = 0;
            }
        }
    }
    /*
    for (int i = 0; i < index; ++i) {
        cout << needed[i] << " ";
    }
    cout << endl;
    */
    int ans = 0;
    for (int i = 0; i < index; ++i) {
        ans += needed[findParent(i)];
        needed[findParent(i)] = 0;
    }
    cout << ans << "\n";

    return 0;
}
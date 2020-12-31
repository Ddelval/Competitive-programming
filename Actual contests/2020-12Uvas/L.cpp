//  L.cpp
//  Created by David del Val on 31/12/2020
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

char board[400][400];
int visited[400][400];

pii nextmove(int orient) {
    if (orient == 1) {
        return {-1, 0};
    }
    if (orient == 0) {
        return {0, 1};
    }
    if (orient == 3) {
        return {1, 0};
    }
    if (orient == 2) {
        return {0, -1};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    while (cin >> x >> y) {
        int ti, tj;
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                cin >> board[i][j];
                if (board[i][j] == 'T') {
                    ti = i;
                    tj = j;
                    board[i][j] = '.';
                }

                visited[i][j] = 0;
            }
        }

        int ipos = 0;
        for (int i = 0; i < x; ++i) {
            if (board[y - 1][i] == '.') {
                ipos = i;
            }
        }

        int posi = y - 1;
        int posj = ipos;
        int tmano = -1;
        int t = 0;
        int orient = 1;
        //cout << ti << " " << tj << endl;
        while (true) {
            //cout << posi << " " << posj << endl;
            t++;
            int norient = (orient - 1 + 4) % 4;
            for (int i = 0; i < 4; ++i) {
                pii ne = nextmove(norient);
                int pos2i, pos2j;
                pos2i = posi + ne.fi;
                pos2j = posj + ne.se;
                //cout << "checking" << pos2i << " " << pos2j << endl;
                if (board[pos2i][pos2j] == '.') {
                    posi = pos2i;
                    posj = pos2j;
                    orient = norient;
                    break;
                }
                norient = (norient + 1) % 4;
            }

            if (posi == ti && posj == tj) {
                tmano = t;
                break;
            }
            if (posi == y - 1 && posj == ipos) {
                break;
            }
        }
        if (y - 1 == ti && ipos == tj) {
            tmano = 0;
        }
        int tb = -1;
        queue<pair<pii, int>> q;
        q.push({{y - 1, ipos}, 0});

        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            if (a.fi.fi == ti && a.fi.se == tj) {
                tb = a.se;
                break;
            }
            if (visited[a.fi.fi][a.fi.se]) {
                continue;
            }
            visited[a.fi.fi][a.fi.se] = true;

            int ai = a.fi.fi;
            int aj = a.fi.se;

            if (board[ai + 1][aj] == '.') {
                q.push({{ai + 1, aj}, a.se + 1});
            }
            if (board[ai - 1][aj] == '.') {
                q.push({{ai - 1, aj}, a.se + 1});
            }
            if (board[ai][aj + 1] == '.') {
                q.push({{ai, aj + 1}, a.se + 1});
            }
            if (board[ai][aj - 1] == '.') {
                q.push({{ai, aj - 1}, a.se + 1});
            }
        }

        if (tb == -1) {
            cout << "IMPOSIBLE\n";
        } else if (tmano == -1) {
            cout << "INF\n";
        } else if (tmano > tb) {
            cout << tmano - tb << "\n";
        } else if (tmano == tb) {
            cout << "IGUAL\n";
        }
    }

    return 0;
}
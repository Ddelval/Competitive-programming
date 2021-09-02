//  M.cpp
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

const int limH = 65, limW = 105;
vector<vi> iniBoard;
vector<vi> destBoard;
int h, w;
vector<pii> deltas = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(int i, int j) { return i >= 0 && j >= 0 && i < h && j < w; }

pair<int, vector<vi>> countComponents(vector<vi> const board) {
    vector<vi> component(board.size(), vi(board[0].size()));
    stack<pii> dfs;
    int cComp = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (component[i][j]) continue;
            cComp++;
            dfs.push({i, j});
            component[i][j] = cComp;
            while (!dfs.empty()) {
                pii current = dfs.top();
                dfs.pop();
                for (auto d : deltas) {
                    int ii = d.fi + current.fi, jj = d.se + current.se;
                    if (check(ii, jj) &&
                        board[ii][jj] == board[current.fi][current.se] &&
                        !component[ii][jj]) {
                        dfs.push({ii, jj});
                        component[ii][jj] = cComp;
                    }
                }
            }
        }
    }
    echo(component);
    // echo(cComp);
    return {cComp, component};
}
vector<pii> reachableFrom(set<pii> start, vector<vi> const &board) {
    queue<pii> q;
    vector<vi> visited = vector<vi>(h, vi(w));
    vector<pii> result;
    for (auto e : start) {
        q.push(e);
        result.pb(e);
        visited[e.fi][e.se] = 1;
    }

    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        for (auto d : deltas) {
            int ii, jj;
            tie(ii, jj) = d + current;
            if (check(ii, jj) &&
                board[ii][jj] == board[current.fi][current.se] &&
                !visited[ii][jj]) {

                result.push_back({ii, jj});
                q.push({ii, jj});
                visited[ii][jj] = 1;
            }
        }
    }
    db({ cout << "visited:\n" << visited << endl << endl; });
    return result;
}
int belongToRect(pii point) {
    vi dist = {point.fi, point.se, w - point.se - 1, h - point.fi - 1};
    return *min_element(all(dist));
}
vii toRectangles(vector<vi> const &board, int comptCount, vector<vi> compts) {
    vector<vi> currentBoard = board;
    vii res;
    for (int i = 0; i < comptCount - 1; ++i) {
        auto vec = reachableFrom({{i, i}}, currentBoard);
        reverse(all(vec));
        while (!vec.empty()) {
            vector<pii> v2;
            for (auto elem : vec) {
                bool valid = false;
                for (auto d : deltas) {
                    int iii, jjj;
                    tie(iii, jjj) = elem + d;
                    if (check(iii, jjj) &&
                        currentBoard[iii][jjj] == 1 - currentBoard[i][i]) {
                        valid = true;
                        break;
                    }
                }
                if (valid && belongToRect(elem) != i) {
                    db({
                        cout << "Flip: " << elem << endl
                             << currentBoard << "\n\n";
                    });

                    currentBoard[elem.fi][elem.se] = 1 - currentBoard[i][i];
                    res.pb(elem);
                } else if (belongToRect(elem) != i) {
                    v2.push_back(elem);
                    db(cout << "saving " << elem << endl);
                }
            }
            swap(v2, vec);
        }
        
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> h;
    char c;
    iniBoard = destBoard = vector<vi>(h, vi(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c;
            iniBoard[i][j] = c == '#';
        }
    }
    bool flip = iniBoard[0][0];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c;
            destBoard[i][j] = c == '#';

            if (flip) {
                iniBoard[i][j] = 1 - iniBoard[i][j];
                destBoard[i][j] = 1 - destBoard[i][j];
            }
        }
    }
    auto cini = countComponents(iniBoard);
    auto dini = countComponents(destBoard);
    if (cini.fi != dini.fi || iniBoard[0][0] != destBoard[0][0]) {
        cout << "IMPOSSIBLE\n";
    } else {
        vii p1 = toRectangles(iniBoard, cini.fi, cini.se);
        for (auto ele : p1) {
            cout << ele.se << " " << ele.fi << "\n";
        }
        vii p2 = toRectangles(destBoard, dini.fi, dini.se);
        reverse(all(p2));
        for (auto ele : p2) {
            cout << ele.se << " " << ele.fi << "\n";
        }
    }

    return 0;
}
//  G.cpp
//  Created by David del Val on 28/02/2021
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
const int lim = 110;
bool alzado[lim][lim];
bool perfil[lim][lim];
vi maxcubes;

bool board[lim][lim];
bool board2[lim][lim];
int n, m, h;

vector<pair<int, pii>> maxSol;
vector<pair<int, pii>> minSol;

bool calculateHeight(int z) {
    bool *front = alzado[z]; //Top header
    bool *side = perfil[z];  //Side header

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            board[i][j] = 0;
            if (front[j] && side[i]) {
                board[i][j] = 1;
            }
            //cout << board[i][j] << " ";
            board2[i][j] = 0;
        }
        //cout << endl;
    }

    int ch = 0;
    for (int i = 0; i < h; ++i) {
        ch += side[i];
    }
    int cm = 0;
    for (int j = 0; j < m; ++j) {
        cm += front[j];
    }
    if (cm * ch == 0 && cm + ch != 0) {
        return false;
    }

    if (ch == cm) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m; ++j) {
                if (front[j] & side[i]) {
                    board2[i][j] = 1;
                    front[j] = 0;
                    break;
                }
            }
        }
    } else if (ch < cm) {
        int rem = cm - ch;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m; ++j) {
                if (front[j] & side[i]) {
                    board2[i][j] = 1;
                    front[j] = 0;
                    if (rem > 0) {
                        rem--;
                        continue;
                    }
                    break;
                }
            }
        }
    } else {
        int rem = ch - cm;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m; ++j) {
                if (front[j] & side[i]) {
                    board2[i][j] = 1;
                    if (rem > 0) {
                        rem--;
                        continue;
                    }
                    front[j] = 0;
                    break;
                }
            }
        }
    }
    //cout << endl;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j]) {
                maxSol.pb({z, {j, i}});
            }
            if (board2[i][j]) {
                minSol.pb({z, {j, i}});
            }
            //cout << board2[i][j] << " ";
        }
        //cout << endl;
    }
    /*
    cout << endl
         << endl;
         */
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            alzado[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < h; ++j) {
            perfil[i][j] = s[j] - '0';
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << alzado[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            cout << perfil[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
*/
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        possible = calculateHeight(i);
        if (!possible) {
            break;
        }
    }
    sort(all(maxSol));
    sort(all(minSol));
    if (!possible) {
        cout << "-1\n";
    } else {
        cout << maxSol.size() << "\n";
        for (auto a : maxSol) {
            cout << a.fi << " " << a.se.fi << " " << a.se.se << "\n";
        }

        cout << minSol.size() << "\n";
        for (auto a : minSol) {
            cout << a.fi << " " << a.se.fi << " " << a.se.se << "\n";
        }
    }

    return 0;
}
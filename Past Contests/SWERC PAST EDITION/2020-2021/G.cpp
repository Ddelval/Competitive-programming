//  G.cpp
//  Created by David del Val on 23/08/2021
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
const int lim = 20;
const int limLog = 5;

#else
const int lim = 1e6 + 5;
const int limLog = 21;
// Judge constraints
#endif
bitset<lim> bs;
vl primes;
void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < lim; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}
ll numPF(ll n) {
    ll index_pf = 0;
    ll pf = primes[index_pf];
    ll ans = 1;
    while (pf * pf <= n) {
        int power = 0;
        while (n % pf == 0) {
            n /= pf;
            power++;
        }
        ans *= (power + 1);
        pf = primes[++index_pf];
    }
    if (n != 1) {
        ans *= 2;
    }
    return ans;
}
int n, k;

int nextt[limLog][lim];
ll sumAccum[limLog][lim];
int inLoop[lim];

vi visited, inStack;
set<int> presentInLoop;
void dfs(int cnode) {
    inStack[cnode] = true;
    visited[cnode] = true;
    int ne = nextt[0][cnode];
    if (inStack[ne]) {
        presentInLoop.insert(ne);
    } else if (!visited[ne]) {
        dfs(ne);
    }
    inStack[cnode] = false;
}
void countElemsInLoop() {
    while (!presentInLoop.empty()) {
        int cnode = *presentInLoop.begin();
        int target = *presentInLoop.begin();
        presentInLoop.erase(presentInLoop.begin());
        cnode = nextt[0][cnode];
        int count = 1;
        while (cnode != target) {
            presentInLoop.erase(cnode);
            count++;
            cnode = nextt[0][cnode];
        }
        inLoop[cnode] = count;
        cnode = nextt[0][cnode];
        while (cnode != target) {
            inLoop[cnode] = count;
            cnode = nextt[0][cnode];
        }
    }
}
void findLoops() {
    visited = vi(n + 1, 0);
    inStack = vi(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    echo(presentInLoop);
    countElemsInLoop();
    /*
    for (int i = 0;i<=n;++i){
        cout << inLoop[i] << " ";
    }
    cout << endl;
    */
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();

    cin >> n >> k;
    nextt[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        nextt[0][i] = (i + numPF(i)) % n;
        //cout << i << " " << (i + numPF(i)) % n << endl;
    }
    findLoops();

    for (int j = 1; j < limLog; ++j) {
        for (int i = 0; i <= n; ++i) {
            nextt[j][i] = nextt[j - 1][nextt[j - 1][i]];
            //cout << nextt[j][i] << " ";
        }
        //cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        sumAccum[0][i] = i;
        sumAccum[1][i] = i + nextt[0][i];
    }
    //cout << endl;
    for (int j = 2; j < limLog; ++j) {
        for (int i = 0; i <= n; ++i) {
            sumAccum[j][i] =
                sumAccum[j - 1][i] + sumAccum[j - 1][nextt[j - 1][i]];
           // cout << sumAccum[j][i] << " ";
        }
        //cout << endl;
    }

    ll minSum = inf;
    int index = -1;
    for (int i = 0; i <= n; ++i) {
        int lengthOfSequence = 0;
        int cnode = i;
        echo(i);
        if (inLoop[cnode]) {
            lengthOfSequence = inLoop[cnode];
        } else {
            lengthOfSequence = 1;
            for (int j = limLog - 1; j >= 0; --j) {
                int ne = nextt[j][cnode];
                if (inLoop[ne] == 0) {
                    cnode = ne;
                    lengthOfSequence += (1 << j);
                }
            }
            lengthOfSequence += inLoop[nextt[0][cnode]];
        }
        // cout << i << " " << lengthOfSequence << endl;
        if (lengthOfSequence >= k) {
            cnode = i;
            int rem = k;
            ll s1 = 0;
            for (int j = limLog - 1; j >= 0; --j) {
                if ((1 << j) <= rem) {
                    rem -= (1 << j);
                    s1 += sumAccum[j][cnode];
                    cnode = nextt[j][cnode];
                }
            }
            ll sum = s1;

            echo(sum);
            echo(s1);
            if (sum < minSum) {
                index = i;
                minSum = sum;
            }
        }
    }
    if (minSum == inf) {
        cout << "-1\n";
    } else {

        int cnode = index;
        for (int w = 0; w < k; ++w) {
            if (w) {
                cout << " ";
            }
            cout << cnode;
            cnode = nextt[0][cnode];
        }
    }

    return 0;
}

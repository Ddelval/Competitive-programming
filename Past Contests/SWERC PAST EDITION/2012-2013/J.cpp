//  J.cpp
//  Created by David del Val on 15/02/2021
//
//
#define NDEBUG

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

ll dif;
ll ans;
int T;

int res[6];
bool taken[6];
vector<int> starts;
stack<pair<pii, char>> operations;

stack<pair<pii, char>> op2;
vector<int> dat;

stack<ll> st;
void calculate(int index, int size) {
    if (!st.empty() && (abs(st.top()) > 99900 || st.top() == 0)) {
        return;
    }
    if (ans == T) {
        return;
    }

    if (index == size && st.size() == 1) {
        //cout << "finished" << st.top() << endl;
        if (abs(st.top() - T) < dif) {
            ans = st.top();
            dif = abs(st.top() - T);
            op2 = operations;
            dat.clear();
            for (int i = 0; i < size; ++i) {
                dat.pb(res[i]);
            }
        }
        return;
    }

    if (index != size) {
        st.push(res[index]);
        calculate(index + 1, size);
        assert(st.top() == res[index]);
        st.pop();
    }

    if (st.size() > 1) {
        const ll r1 = st.top();
        st.pop();
        const ll r2 = st.top();
        st.pop();

        if (r1 && r2) {
            st.push(r1 + r2);
            operations.push({{r1, r2}, '+'});
            calculate(index, size);
            operations.pop();
            assert(st.top() == r1 + r2);
            st.pop();

            st.push(r1 - r2);
            operations.push({{r1, r2}, '-'});
            calculate(index, size);
            operations.pop();
            assert(st.top() == r1 - r2);
            st.pop();
        }

        if (r1 != 1 && r2 != 1) {
            st.push(r1 * r2);
            operations.push({{r1, r2}, '*'});
            calculate(index, size);
            assert(st.top() == r1 * r2);
            operations.pop();
            st.pop();
        }

        if (r2 && r1 % r2 == 0) {
            st.push(r1 / r2);
            operations.push({{r1, r2}, '/'});
            calculate(index, size);
            assert(st.top() == r1 / r2);
            operations.pop();
            st.pop();
        }

        st.push(r2);
        st.push(r1);
    }
}

void explore(int index, int lim) {
    if (index == lim) {
        calculate(0, lim);
        return;
    }
    for (int i = 0; i < 6; ++i) {
        if (!taken[i]) {
            taken[i] = true;
            res[index] = starts[i];
            explore(index + 1, lim);
            taken[i] = false;
            if (ans == T) {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a;
        starts.clear();
        for (int i = 0; i < 6; ++i) {
            cin >> a;
            starts.pb(a);
        }
        dif = INT_MAX;
        cin >> T;

        /*
        explore(0, 2);
        cout << ans << "\n";
        continue;
        */
        for (int i = 0; i < 6; ++i) {
            explore(0, i + 1);
            if (ans == T) {
                break;
            }
        }
        vector<string> vs;
        while (!op2.empty()) {
            auto a = op2.top();
            int res;
            if (a.se == '+') {
                res = a.fi.fi + a.fi.se;
            } else if (a.se == '-') {
                res = a.fi.fi - a.fi.se;
            } else if (a.se == '*') {
                res = a.fi.fi * a.fi.se;
            } else {
                res = a.fi.fi / a.fi.se;
            }
            vs.push_back(to_string(a.fi.fi) + " " + a.se + " " + to_string(a.fi.se) + " = " + to_string(res));
            op2.pop();
        }
        reverse(all(vs));
        cout << "Target: " << T << "\n";
        for (auto a : vs) {
            cout << a << "\n";
        }
        cout << "Best approx: " << ans << "\n";
        cout << "\n";
    }

    return 0;
}
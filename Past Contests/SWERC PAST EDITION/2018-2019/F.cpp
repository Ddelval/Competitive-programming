//  F.cpp
//  Created by David del Val on 10/02/2021
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

vector<pair<pll, ll>> monuments;

enum class Rotation {
    Left,
    Right,
    Aligned
};

Rotation turn(pll ref, pll a, pll b) {
    ll ans = (a.fi - ref.fi) * (b.se - ref.se) - (b.fi - ref.fi) * (a.se - ref.se);
    if (ans == 0)
        return Rotation::Aligned;
    return ans > 0 ? Rotation::Left : Rotation::Right;
}

int getCuad(pll ref, pll a) {
    a.fi -= ref.fi;
    a.se -= ref.se;
    if (a.fi >= 0 && a.se >= 0) {
        return 1;
    }
    if (a.fi >= 0 && a.se < 0) {
        return 4;
    }

    if (a.fi < 0 && a.se < 0) {
        return 3;
    }
    if (a.fi < 0 && a.se >= 0) {
        return 2;
    }
    return -1;
}

// Sort anti-clockwise starting from 3h
bool angleSort(pll ref, pll a, pll b) {
    Rotation ans = turn(ref, a, b);

    if (getCuad(ref, a) < getCuad(ref, b)) {
        return true;
    }
    if (getCuad(ref, a) > getCuad(ref, b)) {
        return false;
    }

    if (ans == Rotation::Aligned)
        return a.fi < b.fi;

    return ans == Rotation::Left;
}

bool angleSort9(pll ref, pll a, pll b) {
    Rotation ans = turn(ref, a, b);

    if ((getCuad(ref, a) + 2) % 4 < (getCuad(ref, b) + 2) % 4) {
        return true;
    }
    if ((getCuad(ref, a) + 2) % 4 > (getCuad(ref, b) + 2) % 4) {
        return false;
    }

    if (ans == Rotation::Aligned)
        return a.fi < b.fi;

    return ans == Rotation::Left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll tot = 0;
    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        monuments.push_back({{a, b}, c});
        tot += c;
    }

    ll ans = inf;

    for (int i = 0; i < n; ++i) {

        auto mcopy = monuments;
        auto it = mcopy.begin() + i;
        auto mon = *it;
        mcopy.erase(it);
        tot -= mon.se;
        //cout << "Center: " << mon << endl;

        for (auto &a : mcopy) {
            a.fi.fi -= mon.fi.fi;
            a.fi.se -= mon.fi.se;
        }

        sort(all(mcopy), [&](pair<pll, ll> a, pair<pll, ll> b) {
            return angleSort({0, 0}, a.fi, b.fi);
        });

        //cout << mon << ":  " << mcopy << endl;

        int i1 = 0;
        ll csum = mcopy[0].se;

        for (int i = 0; i < n - 1; ++i) {
            pll reflect = mcopy[i].fi;
            reflect.fi = -reflect.fi;
            reflect.se = -reflect.se;
            csum -= mcopy[i].se;
            //cout << "Vertex: " << mcopy[i] << endl;
            if (i1 == i)
                csum = 0;
            while (turn({0, 0}, mcopy[i1].fi, reflect) != Rotation::Right) {
                //cout << "turn " << mcopy[i1] << " " << reflect << " " << (int)turn({0, 0}, mcopy[i1].fi, reflect) << endl;
                if (i != i1)
                    csum += mcopy[i1].se;

                i1++;
                i1 %= (n - 1);
                if (i1 == i) {
                    i1++;
                    i1 %= (n - 1);
                    break;
                }
            }
            //cout << "Pointer: " << mcopy[i1] << " " << csum - (tot - csum - mcopy[i].se) << endl;
            ans = min(ans, abs(csum - (tot - csum - mcopy[i].se)));
        }
        tot += mon.se;
    }
    cout << ans << "\n";

    return 0;
}
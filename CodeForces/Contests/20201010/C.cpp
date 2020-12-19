//  C.cpp
//  Created by David del Val on 10/10/2020
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
struct subs_fail
{
};

template <typename T>
struct subs_succeeded : std::true_type
{
};
template <>
struct subs_succeeded<subs_fail> : std::false_type
{
};

template <typename T>
struct get_iter_res
{
private:
    template <typename X>
    static auto check(X const &x) -> decltype(x.begin());
    static subs_fail check(...);

public:
    using type = decltype(check(std::declval<T>()));
};

template <typename T>
struct Has_iterator : subs_succeeded<typename get_iter_res<T>::type>
{
};

template <typename T>
Enable_if<Has_iterator<T>::value, ostream &> operator<<(ostream &o, T val)
{
    bool first = true;
    for (auto it = val.begin(); it != val.end(); ++it)
    {
        if (!first)
            o << " ";
        first = false;
        o << *it;
    }
    return o;
}

template <typename T = ll>
inline vector<T> readVector(int size)
{
    vector<T> v;
    v.reserve(size);
    T a;
    for (int i = 0; i < size; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    return v;
}

// ====================================================== //
// ================== Pairs operations ================== //
// ====================================================== //
inline pii operator+(pii a, pii b)
{
    return {a.fi + b.fi, a.se + b.se};
}

template <typename T, typename Q>
inline ostream &operator<<(ostream &o, pair<T, Q> p)
{
    o << "(" << p.fi << " " << p.se << ")";
    return o;
}

//gcd(0, n) = n
inline long long _gcd(long long a, long long b)
{
    while (b)
        b %= a ^= b ^= a ^= b;
    return a;
}

ll inf = LLONG_MAX / 10;

#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

const int lim = 100000 + 10;

map<int, int> m;

vector<pair<int, pii>> locations;

int dist(pii e1, pii e2)
{
    return abs(e1.fi - e2.fi) + abs(e1.se - e2.se);
}

bool connected(int i, int j)
{
    if (i > j)
        swap(i, j);
    return dist(locations[i].se, locations[j].se) <= locations[j].fi - locations[i].fi;
}
int f(int pos)
{
    ll res;
    if (pos >= locations.size())
        return 0;

    if (m.count(pos))
        return m[pos];

    else
    {
        int ma = 0;
        for (int targ = pos + 1; targ < locations.size(); ++targ)
        {
            if (dist(locations[pos].se, locations[targ].se) <= locations[targ].fi - locations[pos].fi)
            {
                ma = max(ma, 1 + f(targ));
            }
        }
        return m[pos] = ma;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r;
    cin >> r;
    int n;
    cin >> n;
    locations.reserve(n + 1);
    locations.push_back({0, {1, 1}});
    int a, b, c;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        locations.push_back({a, {b, c}});
    }

    set<pii, greater<pii>> hist;
    hist.insert({0, 0});
    for (int i = 1; i < n + 1; ++i)
    {
        for (auto it = hist.begin(); it != hist.end();++it)
        {
            if(connected(it->se,i)){
                hist.insert({it->fi+1, i});
                break;
            }
        }
    }
    cout << hist.begin()->fi << "\n";
    return 0;
}

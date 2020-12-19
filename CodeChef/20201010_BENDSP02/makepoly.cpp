//  makepoly.cpp
//  Created by David del Val on 12/12/2020
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
    o << p.fi << " " << p.se;
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

bool compare(pair<pii, int> aa, pair<pii, int> bb)
{
    pii a = aa.fi;
    pii b = bb.fi;
    ll val = ll(a.se) * ll(b.fi) - ll(a.fi) * ll(b.se);
    return compare < 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vii data(n);
        int a, b;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            data[i].fi = a;
            data[i].se = b;
        }
        vector<pair<pii, int>> data2(n);
        for (int i = 0; i < n; ++i)
        {
            data2[i].fi = data[i];
            data2[i].se = i;
        }
        sort(all(data2), compare);
        for (int i = 1; i < n - 1; ++i)
        {
            pii p1 = data2[i - 1].fi;
            pii p2 = data2[i].fi;
            pii p3 = data2[i + 1].fi;

            pii v1 = {p2.fi - p1.fi, p2.se - p1.se};
            pii v2 = {p3.fi - p2.fi, p3.se - p2.se};
            if (v1.fi * v2.se == v1.se * v2.fi)
            {
                data[data2[i + 1].se].fi *= 2;
                data[data2[i + 1].se].se *= 2;
                data2[i + 1].fi.fi *= 2;
                data2[i + 1].fi.se *= 2;
            }
        }
        data[0].fi *= 100;
        data[0].se *= 100;
        for (int i = 0; i < n; ++i)
        {
            cout << data[i].fi << " " << data[i].se << "\n";
        }
    }
    return 0;
}
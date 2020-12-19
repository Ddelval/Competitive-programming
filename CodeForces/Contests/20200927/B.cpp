//  B.cpp
//  Created by David del Val on 27/09/2020
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl data = readVector(n);
        map<ll, int> occurr;
        for (ll a : data)
            occurr[a]++;

        map<ll, int> cols;
        for (auto a : occurr)
        {
            if (k % 2 == 0 && a.fi == k / 2)
                continue;

            if (cols.count(a.fi) == 0)
            {
                cols[a.fi] = 0;
                if (occurr.count(k - a.fi))
                {
                    cols[k - a.fi] = 1;
                }
            }
        }

        //cout << cols << endl;
        
        int eq = occurr[k / 2] / 2;

        vi res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            if (data[i] == k / 2 && k % 2 == 0)
            {
                if (eq)
                {
                    res.push_back(1);
                    eq--;
                }
                else
                    res.push_back(0);
            }
            else
            {
                res.push_back(cols[data[i]]);
            }
        }
        cout << res << "\n";
    }

    return 0;
}
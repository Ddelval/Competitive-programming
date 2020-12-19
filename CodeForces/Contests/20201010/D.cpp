//  D.cpp
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

    int n;
    cin >> n;
    vi data = readVector<int>(n);

    for (int i = 0; i < n; ++i)
    {
        vi lengths;
        lengths.reserve(n);
        int len = 1;
        vector<vi> data2(lengths.size());
        vector<int> buf;
        buf.push_back(data[0]);
        for (int j = 1; j < n; ++j)
        {
            if (data[j] == data[j - 1] + 1)
            {
                len++;
                buf.push_back(data[j]);
            }
            else
            {
                lengths.push_back(len);
                len = 1;
                data2.push_back(buf);
                buf = vi();
                buf.push_back(data[j]);
            }
        }
        lengths.push_back(len);
        data2.push_back(buf);
        cout << lengths.size() << "\n";
        cout << lengths << "\n";
        vi datR;
        datR.reserve(n);
        reverse(all(data2));

        for(auto a:data2){
            for(auto b:a){
                datR.push_back(b);
            }
        }
        data = datR;
    }
    cout << data << endl;

    return 0;
}
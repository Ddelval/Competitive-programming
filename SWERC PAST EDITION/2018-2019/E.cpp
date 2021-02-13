//  E.cpp
//  Created by David del Val on 11/02/2021
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> places;
    vi dat;
    vi res1(n), res2(n);
    int a;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        places.pb(s);
        cin >> a;
        dat.pb(a);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += dat[i];
    }
    
    int rinf = sum * 100 + 49 * (n - 1) - 100 * 100;
    if (rinf < -49) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (rinf > 50)
        rinf = 50;

    int rsup = 100 * 100 - (sum * 100 - 50 * (n - 1));
    if(rsup < -50){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    if(rsup > 49){
        rsup=49;
    }
    for(int i=0;i<n;++i){
        if(dat[i]!= 0 || rinf<0){
            res1[i]=dat[i]*100 -rinf;
        }

        if(dat[i]==100 && rsup >0){
            res2[i]=100*100;
        }
        else{
            res2[i]=dat[i]*100 + rsup;
        }
    }


    for (int i = 0; i < n; ++i) {
        printf("%s %.02f %.02f\n",places[i].c_str(), float(res1[i]) / 100, float(res2[i]) / 100);
    }

    return 0;
}
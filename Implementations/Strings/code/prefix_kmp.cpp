#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

//
template <typename T> vi prefixFun(const T &s, int n) {
    vi res(n);
    for (int i = 1; i < n; ++i) {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = res[j - 1];
        }
        res[i] = j + (s[i] == s[j]);
    }
    return res;
}

template <typename T>
int kmpSearch(const T &text, int n, const T &pattern, int m,
              const vi &patternPre) {

    int count = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = max(0, patternPre[j] - 1);
        }
        j += (text[i] == pattern[j]);
        if (j == m) {
            count++;
            j = patternPre[j - 1];
        }
    }
    return count;
}
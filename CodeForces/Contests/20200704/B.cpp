//  B.cpp
//  Created by David del Val on 04/07/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
inline pii operator + (pii a, pii b){
    return {a.fi+b.fi,a.se+b.se};
}

inline ostream& operator << (ostream& o, pii p){
    o<<p.fi<<" "<<p.se;
    return o;
}

template<typename>
struct is_std_vector : std::false_type {};
template<typename T, typename A>
struct is_std_vector<std::vector<T,A>> : std::true_type {};

template <typename T>
inline ostream& operator << (ostream& o, vector<T> &p){
    for(int i=0;i<p.size();++i){
        o<<setw(3)<<p[i];
        if(is_std_vector<T>::value)o<<"\n";
    }
    return o;
}



#ifdef _LOCAL_
//Local constraints

#else
// Judge constraints
#endif

const int lim = 300 + 10;
int board[lim][lim];
int n, m;
int countAdy(int i, int j) {
    int count = 4;
    if (i == 0) count--;
    if (j == 0) count--;
    if (i == n - 1) count--;
    if (j == m - 1) count--;
    return count;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int doable = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m;++j){
                cin >> board[i][j];
                if (board[i][j] > countAdy(i, j)) doable = false;
            }
        }
        if(!doable){
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n;++i){
            for (int j = 0; j < m;++j){
                //if(board[i][j]){
                    board[i][j] = countAdy(i, j);
                    /*if (i) board[i - 1][j] = max(1, board[i - 1][j]);
                    if (j) board[i][j-1] = max(1, board[i][j-1]);
                    if (i != n - 1) board[i + 1][j] = max(1, board[i + 1][j]);
                    if (j != m - 1) board[i][j+1] = max(1, board[i][j+1]);*/
                //}
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n;++i){
            for (int j = 0; j < m;++j){
                if (j) cout << " ";
                cout << board[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
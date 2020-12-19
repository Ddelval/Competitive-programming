#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;


int main(){
    ll h[82], f[82], i, n;
    h[0] = 1;
    f[0] = 0;
    for(i = 1; i < 82; i++) {
        f[i] = h[i] = 0;
        f[i] += h[i-1];
        f[i] += f[i-1];
        h[i] += f[i-1];
    }
    while(true) {
        cin >> n;
        if(!n) return 0;
        cout << f[n] + h[n] << "\n";
    }



    return 0;
}
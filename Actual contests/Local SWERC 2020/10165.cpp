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
    ll i, n, num;
    while(true) {
        cin >> n;
        if(!n) return 0;
        ll sum = 0;
        for(i = 0; i < n; i++) {
            cin >> num;
            sum ^= num;
        }
        if(sum) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
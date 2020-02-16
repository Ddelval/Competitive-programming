//10763
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    int n;
    while(cin>>n&&n){
        vector<int> dat;
        int a,b;
        for(int i=0;i<n;++i){
            cin>>a>>b;
            dat.pb(a);
            dat.pb(b);
        }
        sort(dat.begin(),dat.end());
        bool flag=(n%2==0);
        for(int i=0;i<n;++i){
            if(dat[2*i]!=dat[2*i+1]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
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
    ll n;
    while(cin>>n && n){
        ll res;
        if(n<=100){
            res=91;
        }
        else{
            res=n-10;
        }
        cout<<"f91("<<n<<") = "<<res<<"\n";
    }
    return 0;
}
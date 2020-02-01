//10364
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vi len;

ll dp[1048576];

ll calc(ll mas){

    int msb=log2(mas);

    return dp[mas]=len[msb]+dp[mas-(1<<msb)];
}
vll dat;
bool can(ll ma,int target){
    for(ll i=1LL;i<=ma;++i){
        if(calc(i)==target){
            dat.pb(i);
        }
    }
    return false;
}

bool find_possible(ll taken, int index, int need){
    if(need==0)return true;
    for(int i=index;i<dat.size();++i){
        if((taken&dat[i])==0LL){
            if(find_possible(taken+dat[i],i+1,need-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    for(int j=0;j<n;++j){
        int m;
        dat=vll();
        cin>>m;
        len=vi(m);
        ll sum=0;
        for(int i=0;i<m;++i){
            cin>>len[i];
            sum+=len[i];
        }
        if(sum%4){
            cout<<"no\n";
            continue;
        }
        sum/=4;
        ll mas=(1LL<<m)-1LL;
        int counter=0;
        ll used=0;
        can(mas,sum);

        if(find_possible(used,0,4))cout<<"yes\n";
        else cout<<"no\n";
    }


    return 0;
}
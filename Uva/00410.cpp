//00410
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

    int c;
    int s;
    int cas=0;
    while(cin>>c>>s){
        cas++;
        vi spec(2*c,0);
        vector<pii> chamb(c,{0,0});
        for(int i=0;i<s;++i)cin>>spec[i];
        double average=accumulate(spec.begin(),spec.end(),0)/(double)c;
        sort(spec.begin(),spec.end());
        for(int i=0;i<c;++i){
            chamb[i].se=spec[i];
            chamb[i].fi=spec[2*c-i-1];
        }
        printf("Set #%d\n",cas);
        double imb=0;
        for(int i=0;i<c;++i){
            cout<<" "<<i<<":";
            if(chamb[i].fi)cout<<" "<<chamb[i].fi;
            if(chamb[i].se)cout<<" "<<chamb[i].se;
            cout<<"\n";
            imb+=abs(average-chamb[i].fi-chamb[i].se);
        }
        printf("IMBALANCE = %.5lf\n\n",imb);

    }



    return 0;
}
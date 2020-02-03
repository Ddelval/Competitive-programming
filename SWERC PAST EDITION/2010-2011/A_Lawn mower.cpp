#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define fi first
#define se second
double wid;
bool check(int n_cuts, int ma){
    vector<pair<double,double>> cuts;
    double a;
    for(int i=0;i<n_cuts;++i){
        cin>>a;
        cuts.pb({a-wid/2,a+wid/2});
    }
    sort(cuts.begin(),cuts.end());
    /*for(auto a:cuts){
        cout<<a.fi<<" "<<a.se<<"; ";
    }*/
    //cout<<"\n";
    if(cuts[0].fi>0)return false;
    if(cuts.back().se<ma)return false;
    for(int i=0;i<n_cuts-1;++i){
        if(cuts[i].se<cuts[i+1].fi)return false;
    }
    return true;
        
}
int main(){
    int x_cuts,y_cuts;
    
    while(cin>>x_cuts>>y_cuts>>wid&&wid){
        bool b=check(x_cuts,75);
        bool b2=check(y_cuts,100);
        if(b&&b2){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        
    }
}
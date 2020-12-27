#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;

int n;
bool check(int i,vector<pii> &dat){
    int dim=dat[i].se-dat[i].fi+1;
    int cnt=1;
    for(int j=1;j+i<n&&j<dim;++j){
        if(dat[j+i].fi<=dat[i].fi&&dat[j+i].se>=dat[i].se){
            cnt++;
        }
        else break;
    }
    for(int j=-1;j+i>=0&&j>-dim;--j){
        if(cnt==dim)break;
        if(dat[j+i].fi<=dat[i].fi&&dat[j+i].se>=dat[i].se){
            cnt++;
        }
        else break;
    }
    return cnt>=dim;
}
int main(){
    cin>>n;
    int a,b;
    vector<pii> dat;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        dat.pb({a,b});
    }
    int ma=1;
    for(int i=0;i<n;++i){
        if(check(i,dat))ma=max(ma,dat[i].se-dat[i].fi+1);    
    }
    vector<pii> dat2;
    for(int i=0;i<n;++i){
        int a=-1;
        int b=-1;
        for(int j=0;j<n;++j){
            if(dat[j].fi<=i&&i<=dat[j].se){
                if(a==-1)a=j;
                b=j;
            }
            else if(a!=-1)break;
        }
        dat2.pb({a,b});
    }
    for(int i=0;i<n;++i){
        if(check(i,dat2))ma=max(ma,dat2[i].se-dat2[i].fi+1);    
    }
    cout<<ma<<"\n";
}
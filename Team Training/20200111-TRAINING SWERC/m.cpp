//12686
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

int main(){
    string s;
    map<string,int> hist[11];
    map<string,int> curr;
    int ipos=0;
    bool flag=false;
    while(getline(cin,s)){
        if(s.length()<3)continue;
        if(s=="<text>"){
            hist[ipos]=map<string,int>();
            while(getline(cin,s)&&s!="</text>"){
                stringstream ss(s);
                string a;
                while(ss>>a){
                    if(a.length()>=4)hist[ipos][a]++;
                    if(a.length()>=4)curr[a]++;
                }
                
            }
            if(ipos==7){
                flag = true;
            }
            ipos=(ipos+1)%8;
            if(flag){
                for(auto a:hist[ipos]){
                    curr[a.fi]-=a.se;
                    auto it=curr.find(a.fi);
                    if(it->se<=0)curr.erase(it);
                }
            }

        }
        if(s.substr(1,3)=="top"){
            int n=stoi(s.substr(4,3));
            vector<pair<int,string>> vec;
            for(auto a:curr)vec.pb(mp(a.se,a.fi));
            sort(vec.begin(),vec.end(),[](pair<int,string> a, pair<int,string> b){
                if(a.fi!=b.fi)return a.fi>b.fi;
                else return a.se<b.se;
            });
            
            cout<<"<top "<<n<<">\n";
            if(n>vec.size())n=vec.size();
            int i;
            for(i=0;i<n;++i){
                cout<<vec[i].se<<" "<<vec[i].fi<<"\n";
            }
            while(i<vec.size()&&vec[i].fi==vec[n-1].fi){
                cout<<vec[i].se<<" "<<vec[i].fi<<"\n";
                i++;
            }
            cout<<"</top>\n";
        }
    }
}
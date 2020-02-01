//12684
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

#define ml 102
int color[ml];
vector<vector<int>> adyList;
int n;

bool got(int index){
    if(index>=n)return true;
    vector<int> tr(5,0);
    for(auto a:adyList[index])tr[color[a]]|=1;
    bool b=0;
    for(int j=1;j<5;++j){
        if(!tr[j]){
            color[index]=j;
            if(got(index+1))return true;
        }
    }
    color[index]=0;
    return false;
}


int main(){
    string s;
    bool f=false;
    while(getline(cin,s)){
        if(f)cout<<"\n";
        n=stoi(s);
        adyList=vector<vector<int>>(n,vector<int>());
        for(int i=0;i<n;++i)color[i]=0;
        int a,b,c;
        while(getline(cin,s)&&s.find('-')!=string::npos){
            a=stol(s,(std::size_t*)&c,10);
            c++;
            b=stol(s.substr(c,s.length()-c));
            a--;
            b--;
            adyList[a].pb(b);
            adyList[b].pb(a);
        }
        
        bool possible=true;
        got(0);

        if(possible){
            for(int i=0;i<n;++i){
                cout<<i+1<<" "<<color[i]<<"\n";
            }
        }

        f=true;
        
    }


    return 0;
}

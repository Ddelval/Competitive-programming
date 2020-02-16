// AceptaElReto 209:  Pánico en el túnel
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
//int llength[1000002];
//int rlength[1000002];
vector<int> tels;
int main(){
    ios::sync_with_stdio(false);
    string s;
    int r,l,b,e,pos;
    int minr,minl;
    while(getline(cin,s)){
        tels.clear();
        for(int i=0;i<s.length();++i){
            if(s[i]=='T') tels.push_back(i);
        }
        int consul;
        cin>>consul;
        for(int i=0;i<consul;++i){
            cin>>pos;
            if(s[pos-1]=='T') cout<<"AQUI\n";
            else{
                pos--;
                vector<int>::iterator it;
                it=lower_bound(tels.begin(),tels.end(),pos);
                if(it!=tels.begin()){
                    it--;
                    l=(int)(pos-*it);
                }
                else{
                    l=pos+1;
                }
                
                it=upper_bound(tels.begin(),tels.end(),pos);
                if(it==tels.end()){
                    r=(int)s.length()-pos;
                }
                else{
                    r=(int)(*it-pos);
                }

                b=pos+1;
                e=(int)s.length()-pos;
                minl=min(l,b);
                minr=min(r,e);
                int minsalida=min(e,b);
                int mintel= min(r,l);
                if(minsalida<=mintel){
                    if(b<=e){
                        cout<<"PENINSULA\n";
                    }
                    else{
                        cout<<"ISLAS\n";
                    }
                }
                else{
                    if(l<r){
                         cout<<"PENINSULA\n";
                    }
                    else if(l==r){
                        if(b<=e){
                            cout<<"PENINSULA\n";
                        }
                        else{
                            cout<<"ISLAS\n";
                        }
                    }
                    else{
                        cout<<"ISLAS\n";
                    }
                }
                
            }
        }
        getline(cin,s);
    }
    
    return 0;
}


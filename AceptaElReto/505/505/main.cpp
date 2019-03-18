#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#include <string>
#include <utility>



using namespace std;

typedef vector<int> vi;
typedef long long lli;
typedef pair<int,int> ii;

priority_queue<int> izq, der;
int a, b, n,i,temp;
int horas;
string s;


int main(void) {
    vector<int> bd,bi;
    
    while(cin>>n){
        cin>>a>>b;
        bd.clear();
        bi.clear();
        while(!izq.empty()) izq.pop();
        while(!der.empty()) der.pop();
        s="";
        
        for(i=0;i<a;++i){
            cin>>temp;
            izq.push(temp);
        }
        
        for(i=0;i<b;++i){
            cin>>temp;
            der.push(temp);
        }
        int lim;
        while(!izq.empty()&&!der.empty()){
            horas=0;
            lim=min(izq.size(),der.size());
            lim=min(lim,n);
            for(int i=0;i<lim;++i){
                int iz=izq.top(), de=der.top();
                izq.pop();der.pop();
                if(iz>de){
                    horas+=de;
                    iz-=de;
                    if(iz) bi.push_back(iz);
                    
                }
                else{
                    horas+=iz;
                    de-=iz;
                    if(de) bd.push_back(de);
                    
                }
            }
            s+=to_string(horas);
            s+=" ";
            
            for(int el:bi)izq.push(el);
            for(int el:bd)der.push(el);
            bi.clear();
            bd.clear();
            
        }
        s=s.substr(0,s.length()-1);
        cout<<s<<"\n";
        
        
    }
    
    return 0;
}

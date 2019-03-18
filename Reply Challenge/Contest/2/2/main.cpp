#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>
#include <fstream>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll modInverse(int a, int m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    
    if (m == 1)
        return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

int main(){
    ios::sync_with_stdio(false);
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    
    ll r, n, m, i, res, z, t;
    
    //r=3; n=2; m=13;
    //r=2; n=3; m=100;
    //r=2; n=3; m=73;
    
    /*
     *
     
     
     
     */
    
    in>>t;
    
    
    for(z=0;z<t;++z){
        in>>r>>n>>m;
        
        
        n*=n;
        
        res=1;
        
        for(i=1;i<=n;++i){
            
            res*=r;
            res%=m;
        }
        
        
        res=res-1+m;
        res%=m;
        
        
        res*=modInverse(r-1, m);
        
        res%=m;
        
        
        
        
        //out<<res<<"\n";
        out<<"Case #"<<z+1<<": "<<res<<"\n";
        
    }
    
    return 0;
}


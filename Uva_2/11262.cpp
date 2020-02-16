//11262
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<pii> pol;

vector<int> red,blue;

int dist (int i,int j){
    return (int)ceil( sqrt(pow(pol[i].fi-pol[j].fi,2)+pow(pol[i].se-pol[j].se,2)) );
}

vll parent;
ll graph[102][102];
int n,k;
bool BFS(){
    ll u,v;
    vector<bool> visited(n+2,false);
    queue<ll> q;
    q.push(0);
    visited[0]=true;
    while(q.empty()==false){
        u=q.front();
        q.pop();

        for(int v=1;v<n+2;++v){
            if(visited[v]==false && graph[u][v]>0){
                parent[v]=u;
                visited[v]=true;
                if(v==n+1)return true;
                q.push(v);
            }
        }
    }
    return false;
}
int maxFlow(int s, int t){
    ll max_flow=0;
    ll m;
    parent=vll(n+2,-1);
    while(BFS()){
        m=LLONG_MAX;
        for(int v=n+1;v!=0;v=parent[v]){
            m=min(m,graph[parent[v]][v]);
        }
        max_flow+=m;
        for(int v=n+1; v!=0;v=parent[v]){
            graph[parent[v]][v]-=m;
            graph[v][parent[v]]+=m;
        }
            
    }
    //cout<<max_flow<<" "<<k<<"\n";
    return max_flow;
}

bool check(int di){
    //cout<<"di "<<di<<"\n";
    for(int i=0;i<n+2;++i){
        for(int j=0;j<n+2;++j){
            graph[i][j]=0;
        }
    }
    for(auto a:red){
        graph[0][a]=1;
    }
    for(auto a:blue){
        graph[a][n+1]=1;
    }
    for(auto a:red){
        for(auto b:blue){
            if(dist(a,b)<=di){
                //cout<<"pick: "<<a<<" "<<b<<"\n";
                graph[a][b]=1;
                //graph[b][a]=1;
            }
        }
    }
    
    if(maxFlow(0,n+1)>=k)return true;
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a,b;
        pol=vector<pii>(n+2);
        red.clear();
        blue.clear();
        
        string s;
        for(int i=0;i<n;++i){
            cin>>a>>b>>s;
            pol[i+1]={a,b};
            if(s=="blue")red.pb(i+1);
            else blue.pb(i+1);
        }
        int r=2000;
        int l=0;
        while(r!=l+1){
            int mid=(r+l)/2;
            if(check(mid))r=mid;
            else l=mid; 
        }
        if(r==2000)cout<<"Impossible\n";
        else cout<<r<<"\n";
    }


    return 0;
}
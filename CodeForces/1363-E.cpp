//  1363-E.cpp
//  Created by David del Val on 01/06/2020
//
//

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
//gcd(0, n) = n
inline long long _gcd(long long a, long long b){ while(b) b %= a ^= b ^= a ^= b; return a;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

struct Node{
    Node(int a, int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    int a,b,c;
    int v=0;
    ll to[2]={0,0};
    ll changed=0,cost=0;
    vector<Node*> ady;
};


vector<Node> nodeList;
int n;

void bfs(Node& node){
    node.v=1;
    if(node.b!=node.c){
        node.to[node.c]++;
    }

    for(Node* n: node.ady){
        if(n->v==0){
            if(node.a<n->a)n->a=node.a;
            bfs(*n);

            node.changed+=n->changed;
            node.to[0]+=n->to[0];
            node.to[1]+=n->to[1];
            node.cost+=min(n->cost,node.a*n->changed);
        }
        
    }
   
    ll toChange=min(node.to[0],node.to[1]);
    node.to[0]-=toChange;
    node.to[1]-=toChange;
    node.changed+=toChange*2;
    node.cost+=2*toChange*node.a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ll a,b,c;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        nodeList.pb(Node(a,b,c));
    }

    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        a--; b--;
        nodeList[b].ady.pb(&nodeList[a]);
        nodeList[a].ady.pb(&nodeList[b]);
    }
    
    bfs(nodeList[0]);

    if(nodeList[0].to[0]==0 && nodeList[0].to[0]==0){
        cout<<nodeList[0].cost<<"\n";
    }
    else{
        cout<<"-1\n";
    }
    

    return 0;
}
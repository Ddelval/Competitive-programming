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
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;


map<int,ll*> dmemory;
vector<vector<ii>> adyList;
bool visited[2000];
bool isSchool[2000];

int n_nodes,n_schools;
int schools[7];
pair<int,bool> choose[7];
long minweight;
long accumweight;


struct Cycle{
    int snode,enode;
    long weight;
};
vector<Cycle> cy;
long km;
int villagetogo;

void Dijkstra(int snode){
    int cnode;
    ll *length = new ll[n_nodes];
    priority_queue<ii, vector<ii>,greater<ii>> table;
    for(int i=0;i<n_nodes;++i){
        length[i]=INT_MAX;
        visited[i]=false;
    }
    visited[snode]=true;
    length[snode]=0;
    table.push(mp(0,snode));
    //echo_array(n_nodes,length);
    while(!table.empty()){
        if(table.top().first>length[table.top().second]){
            table.pop();
            continue;
            
        }
        cnode=table.top().second;
        table.pop();
        visited[cnode]=true;
        for(auto el:adyList[cnode]){
            if(!visited[el.first]&&length[cnode]+ el.second<length[el.first]){
                length[el.first]=length[cnode]+el.second;
                table.push(mp(length[el.first],el.first));
            }
        }
    }
    //cout<<"\n"<<snode<<":: ";
    //echo_array(n_nodes,length);
    dmemory[snode]=length;
}
void addEdge(int start,int end,int weight){
    if(start==end)return;
    int proc=0;
    for(auto it=adyList[start].begin();it!=adyList[start].end();it++){
        if(it->first==end){
            if(it->second<=weight){
                proc=1;//Do nothing
                break;
            }
            else{
                proc=2; //Remove and add
                adyList[start].erase(it);
                break;
            }
        }
    }
    if(!proc){
        adyList[start].push_back(mp(end,weight));
        adyList[end].push_back(mp(start,weight));
    }
    else if(proc==2){
        for(auto it=adyList[end].begin();it!=adyList[end].end();it++){
            if(it->first==start){
                adyList[end].erase(it);
                break;
            }
        }
        adyList[start].push_back(mp(end,weight));
        adyList[end].push_back(mp(start,weight));
    }
}

void findShortest(int snode,int fnode, int depth){
    long a;
    if(!depth){
        accumweight+=dmemory[snode][fnode];
        if(accumweight<minweight) minweight=accumweight;
        accumweight-=dmemory[snode][fnode];
        return;
    }
    for(int i=0;i<n_schools;++i){
        if(!choose[i].second){
            choose[i].second=true;
            a=dmemory[snode][choose[i].first];
            accumweight+=a;
            findShortest(choose[i].first,fnode,depth-1);
            choose[i].second=false;
            accumweight-=a;
        }
    }
}

void ChooseSE(){
    Cycle c;
    if(n_schools==1){
        c.snode=schools[0];
        c.enode=schools[0];
        c.weight=0;
        cy.push_back(c);
        return;
    }
    for(int i=0;i<n_schools;++i){
        choose[i].first=schools[i];
        choose[i].second=false;
    }
    for(int i=0;i<n_schools;++i){
        choose[i].second=true;
        for(int j=0;j<n_schools;++j){
            if(j==i)continue;
            choose[j].second=true;
            minweight=LONG_MAX;
            accumweight=0;
            findShortest(choose[i].first,choose[j].first,n_schools-2);
            c.snode=choose[i].first;
            c.enode=choose[j].first;
            c.weight=minweight;
            cy.push_back(c);
            choose[j].second=false;
            
            
        }
        choose[i].second=false;
    }
}
void findResult(){
    long mincost=LONG_MAX;
    long aux;
    int selectedN=-1;
    for(auto el:cy){
        for(int i=0;i<n_nodes;++i){
            if(!isSchool[i]){
                if(dmemory[el.snode][i]==INT_MAX||dmemory[el.enode][i]==INT_MAX)continue;
                aux=el.weight+dmemory[el.snode][i]+dmemory[el.enode][i];
                if(mincost>aux){
                    mincost=aux;
                    selectedN=i;
                }
                else if(mincost==aux){
                    if(i<selectedN){
                        selectedN=i;
                    }
                }
            }
        }
    }
    km=mincost;
    villagetogo=selectedN;
    cy.clear();
}

int main(){
    ios::sync_with_stdio(false);
    int nc,i,j;
    int a,b,c,cas;
    while(cin>>n_nodes>>nc){
        vector<ii> vi;
        adyList.assign(n_nodes,vi);
        memset(isSchool,false,2000);
        
        for(i=0;i<nc;++i){
            cin>>a>>b>>c;
            a--;
            b--;
            addEdge(a,b,c);
        }
        cin>>cas;
        for(i=0;i<cas;++i){
            cin>>n_schools;
            dmemory.clear();
            for(j=0;j<n_schools;++j){
                cin>>schools[j];
                schools[j]--;
                Dijkstra(schools[j]);
                isSchool[schools[j]]=true;
            }
            //Now we have to find the cycles
            ChooseSE();
            findResult();
            cout<<villagetogo+1<<" "<<km<<"\n";
            //Clear isSchool
            for(j=0;j<n_schools;++j){isSchool[schools[j]]=false;}
        }
        cout<<"---\n";
        
        
    }
    
}


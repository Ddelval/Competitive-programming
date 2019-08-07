/******
 Situation of this code:
 It sort of works. It is able to find a short path but it will only consider the closest node to the schools, which can lead to wrong solutions.
 The fix is to broad the algorithm. I has to calculate dijkstra fully (for the entire graph instead of for a part of it
 
 
 
 
 
 *********/





#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
ii ins;
vector<vector<ii>> adyList;
vector<int> vill;
set<int> possible;
vector<int> searchingfor;
vector<bool> visited;
vector<int> lengths;
vector<pair<int,bool>> chosen;
vector<pair<int,vector<ii>>> mindist;
vector<pair<int,vector<int>>> minpath;
int minlength;
int finalchoice;
struct Cycle{
    int start,end,weight;
};
vector<Cycle> cyclecollection;
struct Graph{
    int N,V;
    
    Graph(int nN,int nV){
        N=nN;
        V=nV;
        vector<ii> v;
        adyList.assign(N,v);
        
    }
    void addEdge(int from, int to, int weight){
        bool b;
        if(from!=to){
            b=true;
            for(auto it=adyList[from].begin(); it!=adyList[from].end()&&b;it++){
                if((*it).first==to){
                    b=false;
                }
            }
            if(b){
                adyList[from].push_back(make_pair(to,weight));
                adyList[to].push_back(make_pair(from,weight));
            }
        }
    }
    int findClosest(int a){
        int minvill=INT_MAX;
        int min=INT_MAX;
        for(auto it=adyList[a].begin();it!=adyList[a].end();it++){
            if((*it).second==min){
                if(minvill>(*it).first&&find(vill.begin(),vill.end(),(*it).first)==vill.end()){
                    minvill=(*it).first;
                    min=(*it).second;
                }
                
            }
            if((*it).second<min&&find(vill.begin(),vill.end(),(*it).first)==vill.end()){
                minvill=(*it).first;
                min=(*it).second;
            }
        }
        return minvill;
    }
    void Dijkstra(int node);
};
bool allvisited(){
    bool b=true;
    for(int i=0;i<searchingfor.size();i++){
        if(!visited[searchingfor[i]]){
            b=false;
            break;
        }
    }
    return b;
}
void Graph::Dijkstra(int snode){
    int cnode;
    visited.assign(N,false);
    lengths.assign(N,INT_MAX);
    lengths[snode]=0;
    priority_queue<pair<int,int>> table;
    table.push(make_pair(0,snode));
    visited[snode]=true;
    while(!table.empty()){
        cnode=table.top().second;
        if(table.top().first>lengths[cnode]){
            table.pop();
            continue;
        }
        table.pop();
        //visited[cnode]=true;
        if(allvisited()){
            break;
        }
        for(auto it = adyList[cnode].begin();it!=adyList[cnode].end();it++){
            if(!visited[(*it).first]&&lengths[cnode]+(*it).second<lengths[(*it).first]){
                lengths[(*it).first]=lengths[cnode]+(*it).second;
                table.push(make_pair(lengths[(*it).first],(*it).first));
            }
        }
    }
    /*if(allvisited()){
        vector<pair<int,int>> pi;
        for(int i=0;i<searchingfor.size();i++){
            
            if(searchingfor[i]!=snode){
                pi.push_back(make_pair(searchingfor[i],lengths[searchingfor[i]]));
            }
            
        }
        mindist.push_back(make_pair(snode,pi));
    }*/
    minpath.push_back(make_pair(snode,lengths));
}
/*
int optroute(int snode,int endnode){
    for(int i=0;i<mindist.size();i++){
        if(mindist[i].first==snode){
            for(int j=0;j<mindist[i].second.size();j++){
                if(mindist[i].second[j].first==endnode){
                    return mindist[i].second[j].second;
                }
            }
        }
        if(mindist[i].first==endnode){
            for(int j=0;j<mindist[i].second.size();j++){
                if(mindist[i].second[j].first==snode){
                    return mindist[i].second[j].second;
                }
            }
        }
    }
    return INT_MAX;
}*/
int optroute(int snode,int endnode){
    if(find(vill.begin(),vill.end(),snode)==vill.end()) swap(snode,endnode);
    for(int i=0;i<minpath.size();i++){
        if(minpath[i].first==snode){
            for(int j=0;j<minpath[i].second.size();++j){
                if(j==endnode){
                    return minpath[i].second[j];
                }
            }
        }
    }
    return INT_MAX;
}
/*
void calculatepath(int bnode,int snode,int accumulatedlength,int depth){
    int v;
    if(depth==vill.size()){
        accumulatedlength+=optroute(bnode,snode);
        if(accumulatedlength<minlength){
            minlength=accumulatedlength;
            finalchoice=bnode;
        }
        else if(accumulatedlength==minlength&&bnode<finalchoice){
            minlength=accumulatedlength;
            finalchoice=bnode;
        }
    }
    for(int i=0;i<chosen.size();i++){
        if(!chosen[i].second){
            chosen[i].second=true;
            v=optroute(snode,chosen[i].first);
            accumulatedlength+=v;
            calculatepath(bnode,chosen[i].first,accumulatedlength,depth+1);
            chosen[i].second=false;
            accumulatedlength-=v;
        }
    }
}*/
void calculatepath(int bnode,int snode,int accumulatedlength,int depth){
    int v;
    if(depth==vill.size()){
        Cycle c;
        c.start=bnode;
        c.end=snode;
        c.weight=accumulatedlength;
        cyclecollection.push_back(c);
        return;
    }
    if(!depth){
        for(int i=0;i<chosen.size();i++){
            if(!chosen[i].second){
                chosen[i].second=true;
                calculatepath(chosen[i].first,chosen[i].first,0,0);
                chosen[i].second=false;
            }
        }
        return;
    }
    for(int i=0;i<chosen.size();i++){
        if(!chosen[i].second){
            chosen[i].second=true;
            v=optroute(snode,chosen[i].first);
            accumulatedlength+=v;
            calculatepath(bnode,chosen[i].first,accumulatedlength,depth+1);
            chosen[i].second=false;
            accumulatedlength-=v;
        }
    }
}
void findroute(){
    chosen.clear();
    for(int i=0;i<vill.size();i++){
        chosen.push_back(make_pair(vill[i],false));
    }
    for(int i=0;i<vill.size();i++){
        if(!chosen[i].second)
        for(int j=0;j<vill.size();j++){
            
        }
        
    }
    calculatepath(0,0,0,0);
}
int main() {
    ios::sync_with_stdio(false);
    int np,nc;
    int courses;
    int a,b,c;
    while(cin>>np>>nc){
        Graph g(np,nc);
        for(int i=0;i<nc;i++){
            cin>>a>>b>>c;
            a--;
            b--;
            g.addEdge(a,b,c);
        }
        cin>>courses;
        for(int i=0;i<courses;++i){
            searchingfor.clear();
            vill.clear();
            possible.clear();
            mindist.clear();
            cin>>a;
            for(int j=0;j<a;j++){
                cin>>b;
                b--;
                vill.push_back(b);
                searchingfor.push_back(b);
            }
            for(int j=0;j<a;j++){
                c=g.findClosest(vill[j]);
                if(c!=INT_MAX) possible.insert(c);
            }
            for(auto it=possible.begin();it!=possible.end();it++){
                searchingfor.push_back(*it);
            }
            for(int i=0;i<vill.size();++i){
                g.Dijkstra(vill[i]);
            }
            minlength=INT_MAX;
            finalchoice=INT_MAX;
            //With this funcion, we calculate all the cycles. Now we have to find the final route
            findroute();
            
            cout<<finalchoice+1<<" "<<minlength<<"\n";
            
        }
        cout<<"---\n";
    }
    
    return 0;
}


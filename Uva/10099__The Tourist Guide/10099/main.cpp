// UVa Online Judge 10099: The_Tourist_Guide

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct{
    int start;
    int finish;
    int weight;
    
}path;
bool sorter(path p,path s){
    return p.weight<s.weight;
}
int main(){
    int cities;
    int edges;
    int tmp;
    int counter=1;
    int start,finish,number;
    while(1){
        bool adj[100][100]={false};
        vector <int> connectedVertices;
        vector<vector<int>> tr;
        vector<path> data;
        cin>>cities;
        cin>>edges;
        if(!(cities ||edges)){
            break;
        }
        for(int i=0;i<edges;i++){
            path p;
            cin>>tmp;
            p.start=tmp-1;
            cin>>tmp;
            p.finish=tmp-1;
            cin>>tmp;
            p.weight=tmp;
            data.push_back(p);
        }
        cin>>start;
        start--;
        cin>>finish;
        finish--;
        cin>>number;
        sort(data.begin(),data.end(),sorter);
        for(int i=0;i<cities;i++){
            vector<int>v;
            tr.push_back(v);
        }
        while (1){
            path p= data.back();
            data.pop_back();
            tr[p.start].push_back(p.finish);
            adj[p.start][p.finish]=true;
            tr[p.finish].push_back(p.start);
            adj[p.finish][p.start]=true;
            for(int i=0;i<cities;i++){
                if(adj[i][p.finish]){
                    adj[p.finish][i]=true;
                    for(int j = 0;j<tr[i].size();j++){
                        if(p.finish!=tr[i][j]&&!adj[p.finish][tr[i][j]]){
                            adj[p.finish][tr[i][j]]=true;
                            tr[p.finish].push_back(tr[i][j]);
                        }
                        if(p.start!=tr[i][j]&&!adj[p.start][tr[i][j]]){
                            adj[p.start][tr[i][j]]=true;
                            tr[p.start].push_back(tr[i][j]);
                        }
                        
                    }
                    
                }
                if(adj[i][p.start]){
                    adj[p.start][i]=true;
                    for(int j = 0;j<tr[i].size();j++){
                        if(p.start!=tr[i][j]&&!adj[p.start][tr[i][j]]){
                            adj[p.start][tr[i][j]]=true;
                            tr[p.start].push_back(tr[i][j]);
                        }
                        if(p.finish!=tr[i][j]&&!adj[p.finish][tr[i][j]]){
                            adj[p.finish][tr[i][j]]=true;
                            tr[p.finish].push_back(tr[i][j]);
                        }
                    }
                }
            }
            for(int i=0;i<tr[p.start].size();i++){
                if(!adj[tr[p.start][i]][p.start]&&tr[p.start][i]!=p.start){
                    adj[tr[p.start][i]][p.start]=true;
                    tr[tr[p.start][i]].push_back(p.start);
                    for(int j=0;j<tr[p.start].size();j++){
                        if(!adj[tr[p.start][i]][tr[p.start][j]]&&tr[p.start][i]!=tr[p.start][j]){
                            adj[tr[p.start][i]][tr[p.start][j]]=true;
                            tr[tr[p.start][i]].push_back(tr[p.start][j]);
                        }
                    }
                }
            }
            for(int i=0;i<tr[p.finish].size();i++){
                if(!adj[tr[p.finish][i]][p.finish]&&tr[p.finish][i]!=p.finish){
                    adj[tr[p.finish][i]][p.finish]=true;
                    tr[tr[p.finish][i]].push_back(p.finish);
                    for(int j=0;j<tr[p.finish].size();j++){
                        if(!adj[tr[p.finish][i]][tr[p.finish][j]]&&tr[p.finish][i]!=tr[p.finish][j]){
                            adj[tr[p.finish][i]][tr[p.finish][j]]=true;
                            tr[tr[p.finish][i]].push_back(tr[p.finish][j]);
                        }
                    }
                    
                }
            }
            if(adj[start][finish]){
                int trips=0;
                int trip2=0;
                int newnumber;
                if(number%p.weight){
                    trips = number/p.weight;
                    trips++;
                }
                else{
                    trips = number/p.weight;
                }
                while(1){
                    newnumber =number+trips;
                    
                    if(newnumber%p.weight){
                        trip2 = newnumber/p.weight;
                        trip2++;
                    }
                    else{
                        trip2 = newnumber/p.weight;
                    }
                    if(trip2==trips){
                        break;
                    }
                    trips=trip2;
                }
                
                cout<<"Scenario #"<<counter<<endl;
                cout<<"Minimum Number of Trips = "<<trip2<<endl<<endl;
                counter++;
                break;
            }
        }
    }
    
    
    
    
    
    
    return 0;
}

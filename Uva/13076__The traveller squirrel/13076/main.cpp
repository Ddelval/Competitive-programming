//  13076
//	main.cpp
//  Created by David del Val on 03/08/2019
//
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> ii;
pair<int,pair<int,int>> pai(int w, int u, int v){
	return make_pair(w,make_pair(u,v));
}
struct DisjointSets{
	int *parent, *rank;
	int n;
	//Constructor
	DisjointSets(int nn){
		n=nn;
		parent= new int[n+1];
		rank=new int[n+1];
		for(int i=0;i<=n;++i){
			rank[i]=0;
			parent[i]=i;
		}
	}
	//findFunction with compression
	int findRoot(int u){
		if(u!=parent[u]){
			parent[u]=findRoot(parent[u]);
		}
		return parent[u];
	}
	//Union by rank
	void Union(int x,int y){
		x=findRoot(x);
		y=findRoot(y);
		if(x==y){
			return;
		}
		if(rank[x]<rank[y]){
			parent[x]=y;
		}
		else if(rank[x]>rank[y]){
			parent[y]=x;
		}
		else{
			//If ranks are the same, make one root and increment its rank;
			rank[x]++;
			parent[y]=x;
		}
	}
};
vector<vector<int>>board;
vector<pair<int,int>> cut;
int main() {
	
	ios::sync_with_stdio(false);
	int i,j,a,b;
	int width,height,jump;
	int treenumber;
	int counter;
	int aux;
	int x,y;
	double dist;
	set<int>connect;
	while(cin>>height>>width>>jump){
		
		vector<int> vi;
		vi.assign(width+1,0);
		board.assign(height+1, vi);
		cin>>treenumber;
		DisjointSets ds(treenumber+2);
		cut.clear();
		for(i=0;i<treenumber;++i){
			cin>>a>>b;
			cut.push_back(make_pair(a,b));
		}
		cut.push_back(make_pair(0,0));
		cut.push_back(make_pair(height,width));
		counter=1;
		for(j=(int)cut.size()-1;j>=0;--j){
			ii tree=cut[j];
			connect.clear();
			for(int i=-jump;i<=jump;i++){
				if((i+tree.first)>=0&&(i+tree.first)<=height&&board[i+tree.first][tree.second]){
					connect.insert(ds.findRoot(board[i+tree.first][tree.second]));
				}
				if((i+tree.second)>=0&&(i+tree.second)<=width&&board[tree.first][tree.second+i]){
					connect.insert(ds.findRoot(board[tree.first][tree.second+i]));
				}
			}
			
			i=1;
			dist=sqrt(i+i);
			for(x=1;x<=jump;++x){
				for(y=1;y<=jump;++y){
					dist=sqrt(x*x+y*y);
					if(dist>jump){
						break;
					}
					if((tree.first+x)<=height&&(y+tree.second)<=width&&board[tree.first+x][tree.second+y]){
						connect.insert(ds.findRoot(board[tree.first+x][tree.second+y]));
					}
					if((tree.first+x)<=height&&(tree.second-y)>=0&&board[tree.first+x][tree.second-y]){
						connect.insert(ds.findRoot(board[tree.first+x][tree.second-y]));
					}
					if((tree.first-x)>=0&&(y+tree.second)<=width&&board[tree.first-x][tree.second+y]){
						connect.insert(ds.findRoot(board[tree.first-x][tree.second+y]));
					}
					if((tree.first-x)>=0&&(tree.second-y)>=0&&board[tree.first-x][tree.second-y]){
						connect.insert(ds.findRoot(board[tree.first-x][tree.second-y]));
					}
				}
			}
			/*
			 printf("cn: %d, node: %d %d\n",counter,tree.first,tree.second);
			 for(int i=1;i<treenumber+3;++i){
			 printf("%3d",ds.parent[i]);
			 }
			 printf("\n");*/
			if(connect.size()==1){
				ds.Union(counter, *connect.begin());
			}
			else if(connect.size()>1){
				auto it=connect.begin();
				aux=*it;
				ds.Union(aux, counter);
				for(it++;it!=connect.end();it++){
					ds.Union(*it, aux);
				}
				ds.findRoot(counter);
			}
			/*
			 for(int i=1;i<treenumber+3;++i){
			 printf("%3d",ds.parent[i]);
			 }
			 printf("\n");*/
			if(ds.findRoot(1)==ds.findRoot(2)){
				//Done
				break;
			}
			board[tree.first][tree.second]=counter;
			counter++;
		}
		if(j<0){
			cout<<"Never had the chance\n";
		}
		else{
			cout<<cut[j].first<<" "<<cut[j].second<<"\n";
		}
	}
	return 0;
}

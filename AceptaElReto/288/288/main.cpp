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
using namespace std;
struct node{
    node *p=NULL;
    bool oil=false;
    int children=0;
};
int width,height;
queue<pair<int,int>> qp;
node board[1005][1005];
int maxsize;
int counter;
int snum;
int initialBFS(int x,int y){
    pair<int,int> p;
    int ix=x,iy=y;
    int size=0;
    qp.push(make_pair(x,y));
    board[x][y].p=&board[ix][iy];
    while(!qp.empty()){
        size++;
        x=qp.front().first;
        y=qp.front().second;
        qp.pop();
        if(x>0&&!board[x-1][y].p&&board[x-1][y].oil){
            p.first=x-1;
            p.second=y;
            board[x-1][y].p=&board[ix][iy];
            qp.push(p);
        }
        if(y>0&&!board[x][y-1].p&&board[x][y-1].oil){
            p.first=x;
            p.second=y-1;
            board[x][y-1].p=&board[ix][iy];
            qp.push(p);
        }
        if(x!=height-1&&!board[x+1][y].p&&board[x+1][y].oil){
            p.first=x+1;
            p.second=y;
            board[x+1][y].p=&board[ix][iy];
            qp.push(p);
        }
        if(y!=width-1&&!board[x][y+1].p&&board[x][y+1].oil){
            p.first=x;
            p.second=y+1;
            board[x][y+1].p=&board[ix][iy];
            qp.push(p);
        }
        if(y!=width-1&&x!=height-1&&!board[x+1][y+1].p&&board[x+1][y+1].oil){
            p.first=x+1;
            p.second=y+1;
            board[x+1][y+1].p=&board[ix][iy];
            qp.push(p);
        }
        if(y!=0&&x!=height-1&&!board[x+1][y-1].p&&board[x+1][y-1].oil){
            p.first=x+1;
            p.second=y-1;
            board[x+1][y-1].p=&board[ix][iy];
            qp.push(p);
        }
        if(y!=0&&x!=0&&!board[x-1][y-1].p&&board[x-1][y-1].oil){
            p.first=x-1;
            p.second=y-1;
            board[x-1][y-1].p=&board[ix][iy];
            qp.push(p);
        }
        if(y!=width-1&&x!=0&&!board[x-1][y+1].p&&board[x-1][y+1].oil){
            p.first=x-1;
            p.second=y+1;
            board[x-1][y+1].p=&board[ix][iy];
            qp.push(p);
        }
    }
    board[ix][iy].children=size;
    return size;
    
}
int exploresec(int x,int y){
    set<node*> adyac;
    node *n;
    if(x>0&&board[x-1][y].oil){
        node *n=board[x-1][y].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y>0&&board[x][y-1].oil){
        node *n=board[x][y-1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(x!=height-1&&board[x+1][y].oil){
        node *n=board[x+1][y].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y!=width-1&&board[x][y+1].oil){
        node *n=board[x][y+1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y!=width-1&&x!=height-1&&board[x+1][y+1].oil){
        node *n=board[x+1][y+1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y!=0&&x!=height-1&&board[x+1][y-1].oil){
        node *n=board[x+1][y-1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y!=0&&x!=0&&board[x-1][y-1].oil){
        node *n=board[x-1][y-1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(y!=width-1&&x!=0&&board[x-1][y+1].oil){
        node *n=board[x-1][y+1].p;
        while(n!=n->p){
            n=n->p;
        }
        adyac.insert(n);
    }
    if(!adyac.size()){
        board[x][y].p=&board[x][y];
        board[x][y].oil=true;
        board[x][y].children=1;
        return 1;
    }
    else if(adyac.size()==1){
        node *n=(*adyac.begin());
        while(n!=n->p){
            n=n->p;
        }
        n->children++;
        board[x][y].p=*adyac.begin();
        board[x][y].oil=true;
        return n->children;
    }
    else{
        node *n;
        node *a;
        auto it=adyac.begin();
        n=*it;
        for(it++;it!=adyac.end();it++){
            a=*it;
            n->children+=a->children;
            a->p=n->p;
        }
        n->children++;
        board[x][y].oil=true;
        board[x][y].p=n->p;
        return n->children;
        
    }
    
    
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    int i,j;
    int x,y;
    int changes;
    int size;
    height=0;
    width=0;
    string s;
    while(getline(cin,s)){
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                board[i][j].p=NULL;
                board[i][j].oil=false;
                board[i][j].children=0;
            }
        }
        maxsize=0;
        snum=2;
        height=stoi(s.substr(0,s.find(' ')));
        width=stoi(s.substr(s.find(' ')));
        for(i=0;i<height;++i){
            getline(cin,s);
            for(j=0;j<width;++j){
                if(s[j]=='#'){
                    board[i][j].oil=true;
                }
            }
        }
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                if(!board[i][j].p&&board[i][j].oil){
                    size=initialBFS(i,j);
                    if(size>maxsize){
                        maxsize=size;
                    }
                }
            }
        }
        counter=2;
        cout<<maxsize;
        cin>>changes;
        if(changes){
            cout<<" ";
            for(i=0;i<changes-1;++i){
                cin>>x>>y;
                x--;
                y--;
                size=exploresec(x, y);
                if(size>maxsize){
                    maxsize=size;
                }
                cout<<maxsize<<" ";
            }
            cin>>x>>y;
            x--;
            y--;
            size=exploresec(x, y);
            if(size>maxsize){
                maxsize=size;
            }
            cout<<maxsize;
        }
        
        cout<<"\n";
        getline(cin,s);
    }
    return 0;
}


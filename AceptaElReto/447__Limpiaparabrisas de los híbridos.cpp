// AceptaElReto 447:  Limpiaparabrisas de los híbridos
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
int recip,target;
//Move from 1 to 2
struct lev{
    vector<int> l;
    lev(){
        l.assign(4,0);
    }
};
lev capacity;
lev move(lev l,int from,int to){
    l.l[to]=l.l[from]+l.l[to];
    if(l.l[to]>capacity.l[to]){
        l.l[from]=l.l[to]-capacity.l[to];
        l.l[to]=capacity.l[to];
    }
    else{
        l.l[from]=0;
    }
    return l;
    
}
lev full(lev l,int n){
    l.l[n]=capacity.l[n];
    return l;
}
lev empty(lev l,int n){
    l.l[n]=0;
    return l;
}
bool BFS2(){
    bool explored[16][16];
    for(int i=0;i<16;++i){
        for(int j=0;j<16;++j){
            explored[i][j]=false;
        }
    }
    queue<lev> ql;
    lev l,l1;
    l.l[0]=0;
    l.l[1]=0;
    explored[0][0]=true;
    ql.push(l);
    while(!ql.empty()){
        l=ql.front();
        if(l.l[0]==target||l.l[1]==target){
            return true;
        }
        ql.pop();
        
        l1=full(l,0);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
        l1=full(l,1);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
        l1=empty(l,0);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
        l1=empty(l,1);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
        l1=move(l,0,1);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
        l1=move(l,1,0);
        if(!explored[l1.l[0]][l1.l[1]]){
            explored[l1.l[0]][l1.l[1]]=true;
            ql.push(l1);
        }
    }
    
    return false;
}
bool BFS3(){
    bool explored[16][16][16];
    for(int i=0;i<16;++i){
        for(int j=0;j<16;++j){
            for(int k=0;k<16;++k){
                explored[i][j][k]=false;
            }
        }
    }
    queue<lev> ql;
    lev l,l1;
    explored[0][0][0]=true;
    ql.push(l);
    while(!ql.empty()){
        l=ql.front();
        if(l.l[0]==target||l.l[1]==target||l.l[2]==target){
            return true;
        }
        ql.pop();
        
        l1=full(l,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=full(l,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=full(l,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=empty(l,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=empty(l,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=empty(l,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,0,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,0,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,1,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,1,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,2,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
        l1=move(l,2,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]]=true;
            ql.push(l1);
        }
    }
    return false;
}

bool BFS4(){
    bool explored[16][16][16][16];
    for(int i=0;i<16;++i){
        for(int j=0;j<16;++j){
            for(int k=0;k<16;++k){
                for(int l=0;l<16;++l){
                    explored[i][j][k][l]=false;
                }
            }
        }
    }
    queue<lev> ql;
    lev l,l1;
    l.l[0]=0;
    l.l[1]=0;
    explored[0][0][0][0]=true;
    ql.push(l);
    while(!ql.empty()){
        l=ql.front();
        if(l.l[0]==target||l.l[1]==target||l.l[2]==target||l.l[3]==target){
            return true;
        }
        ql.pop();
        
        l1=full(l,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=full(l,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=full(l,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=full(l,3);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        
        l1=empty(l,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=empty(l,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=empty(l,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=empty(l,3);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        
        l1=move(l,0,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,0,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,0,3);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,1,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,1,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,1,3);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,2,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,2,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,2,3);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,3,1);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,3,0);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        l1=move(l,3,2);
        if(!explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]){
            explored[l1.l[0]][l1.l[1]][l1.l[2]][l1.l[3]]=true;
            ql.push(l1);
        }
        
    }
    
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    while(cin>>target&&target){
        cin>>recip;
        for(int i=0;i<recip;i++){
            cin>>capacity.l[i];
        }
        switch(recip){
            case 1:{
                if(capacity.l[0]==target){
                    cout<<"SI\n";
                }
                else{
                    cout<<"NO\n";
                }
                break;
            }
            case 2:{
                cout<<(BFS2()? "SI\n":"NO\n");
                break;
            }
            case 3:{
                cout<<(BFS3()? "SI\n":"NO\n");
                break;
            }
            case 4:{
                cout<<(BFS4()? "SI\n":"NO\n");
                break;
            }
        }
        
    }
    
    return 0;
}


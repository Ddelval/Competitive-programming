//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <stdio.h>
//#include <math.h>
//#include <string>
//#include <queue>
//#define INFTY 100000
//using namespace std;
//typedef pair<int,int> ii;
////int ady[100][100];
//map<int,map<int,int>> ady;
//map<int,int> snakes;
//map<int,int> stairs;
//set<int> path_ending;
////bool b_start [10001] ;
//set<int>path_starting;
////bool b_end [10001];
//int dim, n_sta, n_snak,k;
//int a,b;
//int i;
//int pos;
//
////bool closed [10001];
////int length [10001];
//map<int,int> length;
//set<int> closed;
//
//void print(){
//    printf("%d ",0);
//    for(int j=0;j<10;j++){
//        printf("%d ",j);
//    }
//    printf("\n");
//    for(int i=0;i<10;i++){
//        printf("%d ",i);
//        for(int j=0;j<10;j++){
//            printf("%d ",ady[i][j]);
//        }
//        printf("\n");
//    }
//}
//void print2(){
//    for(auto iter=length.begin();iter!=length.end();++iter){
//        printf("%6d ",(*iter).first);
//    }
//    printf("\n");
//}
//void print3(){
//    for(auto iter=length.begin();iter!=length.end();++iter){
//        if(closed.count((*iter).first)){
//            printf("%6d ",-1);
//        }
//        else{
//            printf("%6d ",(*iter).second);
//        }
//
//    }
//    printf("\n");
//}
//int dijkstra(){
//    int selectednode;
//    int min;
//    length.clear();
//    closed.clear();
//    for(auto it=path_starting.begin();it!=path_starting.end();++it){
//        length.insert(make_pair(*it,INFTY));
//    }
//    length.insert(make_pair(dim*dim, INFTY));
//    length[1]=0;
//    //print2();
//    while(true){
//        selectednode=1;
//        min=INFTY;
//        for(auto iter=length.begin();iter!=length.end();iter++){
//            if((*iter).second<min&&!closed.count((*iter).first)){
//                min=(*iter).second;
//                selectednode=(*iter).first;
//            }
//        }
//        if(selectednode==dim*dim||min==length[dim*dim]){
//            break;
//        }
//        closed.insert(selectednode);
//        //print3();
//        for(auto iter=length.begin();iter!=length.end();iter++){
//            if(closed.count((*iter).first)){
//                continue;
//            }
//            else{
//                if((ady[selectednode][(*iter).first]+length[selectednode])<(*iter).second&&ady[selectednode][(*iter).first]){
//                    length[(*iter).first]=ady[selectednode][(*iter).first]+length[selectednode];
//                    //print3();
//                }
//            }
//        }
//
//    }
//    return length[dim*dim];
//}
//double calculatedistance(int start,int end){
//    int i_start=start;
//    int t=0;
//    while(start<end){
//        t++;
//        start+=k;
//        if(start==end){
//            break;
//        }
//        while(path_ending.count(start)){
//            start--;
//            if(start==end){
//                break;
//            }
//            if(start<i_start){
//                return numeric_limits<double>::infinity();
//            }
//        }
//
//    }
//    return t;
//}
//int main() {
//    int aux;
//    map<int,int> mp;
//    ios::sync_with_stdio(false);
//    while(cin>>dim>>k>>n_sta>>n_snak&&(dim||k||n_sta||n_snak)){
//        /*if(!path_starting.empty()){
//            for(auto it=path_starting.begin();it!=path_starting.end();it++){
//                for(auto it2=path_starting.begin();it2!=path_starting.end();it2++){
//                    if(ady[*it][*it2]){
//                        ady[*it][*it2]=0;
//                    }
//                }
//            }
//        }*/
//        snakes.clear();
//        path_starting.clear();
//        path_ending.clear();
//        for(i=0;i<n_snak;++i){
//            cin>>a>>b;
//            snakes.insert(make_pair(a,b));
//            path_ending.insert(a);
//            path_starting.insert(b);
//        }
//        for(i=0;i<n_sta;++i){
//            cin>>a>>b;
//            snakes.insert(make_pair(a,b));
//            path_ending.insert(a);
//            path_starting.insert(b);
//        }
//        path_starting.insert(1);
//        path_ending.insert(dim*dim);
//        mp.clear();
//        for(auto it=path_starting.begin();it!=path_starting.end();it++){
//            mp.insert(make_pair(*it, 0));
//        }
//        for(auto it=path_starting.begin();it!=path_starting.end();it++){
//            ady.insert(make_pair(*it, mp));
//        }
//        for(auto it=path_starting.begin();it!=path_starting.end();it++){
//            for(auto i2=path_ending.begin();i2!=path_ending.end();i2++){
//                if(*it>=*i2){
//                    continue;
//                }
//                if(*i2!=dim*dim){
//                    if(snakes[*i2]==*it){
//                        ady[*it][snakes[*i2]]=0;
//                    }
//                    else{
//                        if(ady[*it][snakes[*i2]]){
//                            aux=calculatedistance(*it, *i2);
//                            if(aux<ady[*it][snakes[*i2]]){
//                                ady[*it][snakes[*i2]]=aux;
//                            }
//                        }
//                        else{
//                            ady[*it][snakes[*i2]]=calculatedistance(*it, *i2);
//                        }
//
//                        //cout<<*it<<" "<<snakes[*i2]<<" "<<calculatedistance(*it, *i2)<<"\n";
//                    }
//
//                }
//                else{
//                    if(ady[*it][*i2]){
//                        aux=calculatedistance(*it, *i2);
//                        if(aux<ady[*it][*i2]){
//                            ady[*it][*i2]=aux;
//                        }
//                    }
//                    else{
//                       ady[*it][*i2]=calculatedistance(*it, *i2);
//                    }
//
//                    //cout<<*it<<" "<<*i2<<" "<<calculatedistance(*it, *i2)<<"\n";
//                }
//
//            }
//        }
//        //print();
//        cout<<dijkstra()<<"\n";
//        //
//    }
//    return 0;
//}
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <string>
#define INFTY 100000
using namespace std;
int k,dim,s,e;
int tabler[20000];
int visited[20000];
int BFS(){
    pair<int,int> current;
    int i;
    int dest;
    int target=dim*dim;
    queue<pair<int,int>> queu;
    queu.push(make_pair(1,0));
    while(!queu.empty()){
        current=queu.front();
        queu.pop();
        for(i=k;i>=1;--i){
            if(current.first+i<=dim*dim&&!visited[current.first+i]){
                dest=tabler[current.first+i];
                visited[dest]=current.second+1;
                if(dest==target){
                    return current.second+1;
                }
                queu.push(make_pair(dest,current.second+1));
                
            }
        }
    }
    return 100000;
}
int main() {
    int i;
    int a,b;
    ios::sync_with_stdio(false);
    while(cin>>dim>>k>>s>>e&&(dim||k||s||e)){
        for(i=0;i<=dim*dim;++i){
            tabler[i]=i;
        }
        for(i=0;i<s+e;++i){
            cin>>a>>b;
            tabler[a]=b;
        }
        cout<<BFS()<<"\n";
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}

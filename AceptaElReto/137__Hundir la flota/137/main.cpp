#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    pair<int,bool> sh[10];
    int nships;
    int dim;
    int hShip;
    int vShip [128];
    int aux,a=0,b=0;
    bool malo,flag,f2;
    cin>>nships;
    while(nships){
        for(int i=0;i<nships;i++){
            cin>>sh[i].first;
            sh[i].second=true;
        }
        cin>>dim;
        hShip=0;
        malo=false;
        for(int i=0;i<dim;i++){
            vShip[i]=0;
        }
        for(a=0;a<dim;a++){
            hShip=0;
            f2=false;
            for(b=0;b<dim;b++){
                cin>>aux;
                if(aux){
                    if(vShip[b]==-1){
                        malo=true;
                        break;
                    }
                    if(a){
                        if(b){
                            if(vShip[b-1]&&vShip[b-1]!=1){
                                malo=true;
                                break;
                            }
                        }
                        if(b<dim-1){
                            if(vShip[b+1]){
                                malo=true;
                                break;
                            }
                        }
                    }
                    
                    
                    vShip[b]++;
                    hShip++;
                    
                }
                else{
                    if(vShip[b-1]==-1){
                        vShip[b-1]=0;
                    }
                    if(hShip==1){
                        hShip=0;
                    }
                    if(hShip){
                        //The end of a horizontal ship has been found;
                        flag=false;
                        for(int w=0;w<nships;w++){
                            if(sh[w].second){
                                if(sh[w].first==hShip){
                                    sh[w].second=false;
                                    flag=true;
                                    break;
                                }
                            }
                        }
                        if(!flag){
                            malo=true;
                            break;
                        }
                        for(int w=1;w<=hShip;w++){
                            vShip[b-w]=-1;
                        }
                        hShip=0;
                    }
                    if(vShip[b]>0){
                        flag=false;
                        for(int w=0;w<nships;w++){
                            if(sh[w].second){
                                if(sh[w].first==vShip[b]){
                                    sh[w].second=false;
                                    flag=true;
                                    break;
                                }
                            }
                        }
                        if(!flag){
                            malo=true;
                            break;
                        }
                        vShip[b]=-1;
                    }
                }
            }
            if(malo){
                break;
            }
            if(vShip[dim-1]==-1){
                vShip[dim-1]=0;
            }
            if(hShip>1){
                flag=false;
                for(int w=0;w<nships;w++){
                    if(sh[w].second){
                        if(sh[w].first==hShip){
                            sh[w].second=false;
                            flag=true;
                            break;
                        }
                    }
                }
                if(!flag){
                    malo=true;
                    break;
                }
                for(int w=0;w<hShip;w++){
                    vShip[dim-1-w]=-1;
                }
            }
        }
        if(!malo){
            for(int j=0;j<dim;j++){
                if(vShip[j]&&vShip[j]!=-1){
                    flag=false;
                    for(int w=0;w<nships;w++){
                        if(sh[w].second){
                            if(sh[w].first==vShip[j]){
                                sh[w].second=false;
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        malo=true;
                        break;
                    }
                }
            }
            if(!malo){
                for(int i=0;i<nships;i++){
                    if(sh[i].second){
                        malo=true;
                        break;
                    }
                }
            }
        }
        b++;
        for(;a<dim;a++){
            for(;b<dim;b++){
                cin>>aux;
            }
            b=0;
        }
        if(malo){
            cout<<"NO\n";
        }
        else{
            cout<<"SI\n";
        }
        cin>>nships;
    }
    return 0;
}

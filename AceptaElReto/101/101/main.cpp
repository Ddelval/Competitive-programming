
#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int width;
    int data[1024][1024];
    int cache;
    int temp;
    bool diabolic=true;
    bool esot = true;
    
    
    while (1){
        diabolic=true;
        esot=true;
        scanf("%d",&width);
        if(width==0){
            break;
        }
        for(int i=0;i<width;i++){
            for(int j=0;j<width;j++){
                scanf("%d",&data[i][j]);
            }
        }
        //Diabolico
        cache=-1;
        for(int i=0;i<width;i++){
            temp=0;
            for(int j=0;j<width;j++){
                temp+=data[i][j];
            }
            if(i){
                if(cache!=temp){
                    diabolic = false;
                    break;
                }
            }
            cache=temp;
        }
        if(diabolic){
            for(int i=0;i<width;i++){
                temp=0;
                for(int j=0;j<width;j++){
                    temp+=data[j][i];
                }
                
                if(cache!=temp){
                    diabolic = false;
                    break;
                }
                
                cache=temp;
            }
            if(diabolic){
                temp=0;
                for(int j=0;j<width;j++){
                    temp+=data[j][j];
                }
                
                if(cache!=temp){
                    diabolic = false;
                    
                }
                cache=temp;
                if(diabolic){
                    temp=0;
                    for(int j=0;j<width;j++){
                        temp+=data[width-1-j][j];
                    }
                    
                    if(cache!=temp){
                        diabolic = false;
                        
                    }
                    //It is diabolic
                    priority_queue<int> pq;
                    for(int i=0;i<width;i++){
                        for(int j=0;j<width;j++){
                            pq.push(data[i][j]);
                        }
                    }
                    int lim = width*width;
                    for(int i=0;i<lim;i++){
                        if(pq.top()!=lim-i){
                            esot=false;
                            break;
                        }
                        pq.pop();
                    }
                    if(esot){
                        temp=data[0][0]+data[0][width-1]+data[width-1][0]+data[width-1][width-1];
                        cache = 4*cache/width;
                        if(temp!=cache){
                            esot = false;
                            
                        }
                        if(esot){
                            
                            if(width%2){
                                width--;
                                //impar
                                temp=data[0][(width/2)]+data[width][(width/2)]+data[(width/2)][0]+data[(width/2)][width];
                                if(temp!=cache){
                                    esot = false;
                                    
                                }
                                if(esot){
                                    temp= data[(width/2)][(width/2)]*4;
                                    if(temp!=cache){
                                        esot = false;
                                        
                                    }
                                }
                                
                                
                                
                            }
                            else{
                                //par
                                temp=data[0][(width/2)]+data[width-1][(width/2)]+data[(width/2)][0]+data[(width/2)][width-1];
                                temp+=data[0][(width/2)-1]+data[width-1][(width/2)-1]+data[(width/2)-1][0]+data[(width/2)-1][width-1];
                                if(temp!=2*cache){
                                    esot = false;
                                    
                                }
                                if(esot){
                                    temp= data[(width/2)][(width/2)]+data[(width/2)][(width/2)-1]+data[(width/2)-1][(width/2)]+data[(width/2)-1][(width/2)-1];
                                    if(temp!=cache){
                                        esot = false;
                                        
                                    }
                                }
                                
                                
                                
                            }
                            
                            
                            
                            
                        }
                    }
                    
                    
                    
                    
                    
                    
                }
            }
        }
        if(esot&&diabolic){
            printf("ESOTERICO\n");
        }
        else if(diabolic){
            printf("DIABOLICO\n");
        }
        else{
            printf("NO\n");
        }
        
    }
    return 0;
}

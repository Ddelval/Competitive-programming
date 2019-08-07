// AceptaElReto 104:  Móviles
#include <iostream>
#include <queue>
typedef struct{
    int p_i;
    int p_d;
    int d_i;
    int d_d;
}mov;
using namespace std;
queue <mov> data;
int isStable(){
    mov v=data.front();
    data.pop();
    if(!v.p_i){
        v.p_i=isStable();
    }
    if(!v.p_d){
        v.p_d=isStable();
    }
    if(v.p_i*v.d_i==v.p_d*v.d_d){
        return v.p_i+v.p_d;
    }
    
    return 0;
}
int main(){
    while (1){
        mov v;
        cin>>v.p_i;
        cin>>v.d_i;
        cin>>v.p_d;
        cin>>v.d_d;
        if(!v.d_d&&!v.d_i&&!v.p_i&&!v.p_d){
            break;
        }
        data.push(v);
    }
    while(data.size()>0){
        if(isStable()){
            cout<<"SI"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    
    
    
}

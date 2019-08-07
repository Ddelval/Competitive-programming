#include <stdio.h>

int main() {
    int n[102];
    int s[102];
    int arg1;
    int arg2;
    int ady[52][102][102]={0};
    int queue[52][102]={0};
    int queueIndex=0;
    int maxlength=0;
    int finalpos =0;
    int i=0;
    int j=0;
    int x;
    int y;
    while(1){
        printf("n:");
        scanf("%d",&n[i]);
        if(n[i]==0){
            break;
        }
        scanf("%d",&s[i]);
        scanf("%d %d",&arg1,&arg2);
        while(!(arg1==0 && arg2==0)){
            ady[i][arg1-1][arg2-1]=1;
            //ady[i][arg2-1][arg1-1]=1;
            scanf("%d %d",&arg1,&arg2);
        }
        i++;
    }
    i--;
    
    while(j<=i){
        for(int u=0;u<n[j];u++){
            for(int m =0;m<n[j];m++){
                printf("%d ",ady[j][u][m]);
            }
            printf("\n");
        }
        
        for(i=0;i<n[j];i++){
            for(int w=0;w<n[j];w++){
                for(int y =0;y<n[j];y++){
                    if(w==i||y==i|| y==w){
                        
                    }else if(ady[j][w][i]&ady[j][i][y]){
                        //We process it
                        if((ady[j][w][i]+ady[j][i][y])>ady[j][w][y]){
                            ady[j][w][y]=ady[j][w][i]+ady[j][i][y];
                        }
                    }
                }
            }
        }
        
        
        
        
        
        
        /**
        queueIndex=0;
        maxlength=0;
        finalpos =s[j]-1;
        x=s[j]-1;
        y=0;
        queue[j][queueIndex]=s[j]-1;
        
        while(1){
            
            while(y<n[j]){
             
             if(ady[j][x][y]==1){
                    x=y;
                    y=-1;
                    queueIndex++;
                    queue[j][queueIndex]=x;
                    
                }
             
                y++;
            }
            
            if(x==s[j]-1&& y==n[j]){
                break;
            }
            x=queue[j][queueIndex-1];
            y=queue[j][queueIndex]+1;
            if(queueIndex>maxlength){
                maxlength=queueIndex;
                finalpos=queue[j][queueIndex];
            }
            else if(queueIndex==maxlength){
                if(queue[j][queueIndex]<finalpos){
                    finalpos=queue[j][queueIndex];
                }
            }
            queue[j][queueIndex]=0;
            queueIndex--;
            break;
        }
             
        printf("\nCase %d: The longest path from %d has length %d, finishing at %d.\n",j+1,s[j],maxlength,finalpos+1);
        
     */
        
        for(int u=0;u<n[j];u++){
            for(int m =0;m<n[j];m++){
                printf("%d ",ady[j][u][m]);
            }
            printf("\n");
        }
        j++;
    }
    

    return 0;
}

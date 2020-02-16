#include <stdio.h>

int main() {
    int n[102];
    int s[102];
    int arg1;
    int arg2;
    int ady[52][102][102]={0};
    int maxlength=0;
    int finalpos =0;
    int i=0;
    int j=0;
    int y=0;

    while(1){
        printf("n:");
        scanf("%d",&n[y]);
        if(n[y]==0){
            break;
        }
        scanf("%d",&s[y]);
        scanf("%d %d",&arg1,&arg2);
        while(!(arg1==0 && arg2==0)){
            ady[y][arg1-1][arg2-1]=1;
            scanf("%d %d",&arg1,&arg2);
        }
        y++;
    }
    y--;
   
    while(j<=y){
        maxlength=0;
        finalpos=0;
        
        /*
        for(int u=0;u<n[j];u++){
            for(int m =0;m<n[j];m++){
                printf("%d ",ady[j][u][m]);
            }
            printf("\n");
        }*/
        
        for(i=0;i<n[j];i++){
            
            for(int w=0;w<n[j];w++){
                if(i==3&&w==4){
                    
                    i=i;
                }
                for(int y =0;y<n[j];y++){
                    if(w==i||y==i|| y==w){
                        
                    }else if(ady[j][w][i]&ady[j][i][y]){
                        
                        if((ady[j][w][i]+ady[j][i][y])>ady[j][w][y]){
                            ady[j][w][y]=ady[j][w][i]+ady[j][i][y];
                        }
                    }
                }
            }
        }
        finalpos=n[j];
        for(int u=0;u<n[j];u++){
                if(ady[j][s[j]-1][u]>maxlength){
                    maxlength=ady[j][s[j]-1][u];
                    finalpos= u;
                }
            
            
        }
        printf("\n");
        printf("Length %d, and final pos: %d",maxlength,finalpos+1);
        printf("\n");
        printf("\n");
        /*for(int u=0;u<n[j];u++){
            for(int m =0;m<n[j];m++){
                printf("%d ",ady[j][u][m]);
            }
            printf("\n");
        }*/
         
        j++;
    }
    
    
    return 0;
}

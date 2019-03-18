
#include <stdio.h>
#include <stdlib.h>

char group[5];
int doubled[2];
int totalsum=0;
int i=0;
int j=0;
int cases;

int main() {
    
    scanf("%d",&cases);
    for(j=0;j<cases;j++){
        totalsum=0;
        for(i=0;i<4;i++){
            scanf("%s", &group);
            doubled[0]=(group[0]-'0')*2;
            doubled[1]=(group[2]-'0')*2;
            totalsum +=(group[1]-'0');
            totalsum +=(group[3]-'0');
            if(doubled[0]>9){
                totalsum +=1+doubled[0]%10;
            }
            else{
                totalsum+=doubled[0];
            }
            if(doubled[1]>9){
                totalsum +=1+doubled[1]%10;
            }
            else{
                totalsum+=doubled[1];
            }
            
        }
        if(totalsum%10){
            printf("Invalid\n");
        }
        else{
            printf("Valid\n");
        }
        
        
    }
    
    return(0);
}


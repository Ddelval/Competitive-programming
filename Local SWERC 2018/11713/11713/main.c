
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word1[21];
char word2[21];
int i,j,k;
int scape=1;
int cases;
int main() {
    
    scanf("%d",&cases);
    for (k=0;k<cases;k++){
        scape=1;
        
        
        scanf("%s",word1);
        scanf("%s",word2);
        
        if(strlen(word1)==strlen(word2)){
            for (i=0;i<21&&word1[i]!='\0';i++){
                if(word1[i]=='a'||word1[i]=='e'||word1[i]=='i'||word1[i]=='o'||word1[i]=='u'){
                    if(word2[i]=='a'||word2[i]=='e'||word2[i]=='i'||word2[i]=='o'||word2[i]=='u'){
                        word2[i]='2';
                        word1[i]='2';
                    }
                    else{
                        scape=0;
                        break;
                        
                    }
                }
                
            }
            for(i=0;i<21&&word1[i]!=0;i++){
                if(word1[i]==word2[i]){
                    
                }
                else{
                    scape=0;
                }
            }
        }
        else{
            scape=0;
        }
        
        
        if(scape){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    
    
    
    
    
    
    return (0);
}


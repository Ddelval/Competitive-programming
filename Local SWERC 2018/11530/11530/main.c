
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[101];
int i,j;
long sumation=0;
int cases;
char c;
int main() {
    
    scanf("%d",&cases);
    scanf("%c",&c);
    for(j=0;j<cases;j++){
        sumation=0;
        gets(line);
        for (i=0;i<101&&line[i]!='\0';i++){
            switch(line[i]){
                case 'a': case'd':  case'g': case'j': case'm': case'p': case't': case'w': case' ':
                    sumation++;
                    break;
                case 'b': case'e':  case'h': case'k': case'n': case'q': case'u': case'x':
                    sumation+=2;
                    break;
                case 'c': case'f':  case'i': case'l': case'o': case'r': case'v': case'y':
                    sumation+=3;
                    break;
                case 's':case 'z':
                    sumation+=4;
                    break;
                    
            }
            
        }
        printf("Case #%d: %ld\n",j+1,sumation);
    }
    
    return (0);
}


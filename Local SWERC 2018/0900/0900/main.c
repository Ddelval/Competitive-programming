#include <stdio.h>
#include <stdlib.h>
long calculate(int number){
    long counter=0;
    
    if(number==0){
        return 1;
    }
    else if(number==1){
        return 1;
    }
    else{
        counter+=calculate(number-2);
        counter+=calculate(number-1);
    }
    return counter;
}
int main() {
    int number;
    long output;
    while(1){
        scanf("%d",&number);
        if(number==0){
            break;
        }
        output=calculate(number);
        printf("%ld\n", output);
    }
    return (0);
}



#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h1,m1,s1;
    int tot1,tot2;
    int h2,m2,s2;
    int tim;
    double interval;
    int outtime;
    double todiv;
    int num;
    int ca;
    cin>>ca;
    for(int i=0;i<ca;i++){
        scanf("%d:%d:%d",&h1,&m1,&s1);
        scanf("%d:%d:%d",&h2,&m2,&s2);
        cin>>todiv>>num;
        tot1=s1+60*m1+60*60*h1;
        tot2=s2+60*m2+60*60*h2;
        if(num==1){
            outtime=tot1;
        }
        else if(num==todiv){
            outtime=tot2;
        }
        else if(tot1<tot2){
            tim=tot2-tot1;
            interval=tim/(todiv-1);
            outtime=tot1+(num-1)*interval;
        }
        else{
            tim=86400-tot1+tot2;
            interval=tim/(todiv-1);
            outtime=tot1+(num-1)*interval;
            outtime=outtime%86400;
        }
        printf("%.2d:%.2d:%.2d\n",(outtime/3600)%24,(outtime/60)%60,outtime%60);
        
    }
    return 0;
}


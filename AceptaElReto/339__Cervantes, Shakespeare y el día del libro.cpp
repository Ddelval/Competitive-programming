// AceptaElReto 339:  Cervantes, Shakespeare y el día del libro
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
long od,om,oy;
int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int bdm[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
/*
 long daysinyear(int d,int m){
 long days=0;
 for(int i=0;i<m;i++){
 days+=dm[i];
 }
 days+=d;
 return days;
 
 }
 void calculatedate(int d,int y,int m){
 long days=daysinyear(d, m);
 if(!(y%4)){
 if(days>0){
 om=0;
 while(days/bdm[om+1]){
 days-=bdm[om];
 om++;
 }
 od=days;
 oy=y;
 
 }
 else{
 //We have to change the year
 days+=365;
 oy=y-1;
 om=0;
 while(days/dm[om+1]){
 days-=dm[om];
 om++;
 }
 od=days;
 }
 }
 else{
 if(days>0){
 om=0;
 while(days/dm[om+1]){
 days-=dm[om];
 om++;
 }
 od=days;
 oy=y;
 
 }
 else{
 //We have to change the year
 
 if(!((y-1)%4)){
 days+=366;
 oy=y+1;
 om=0;
 while(days/bdm[om+1]){
 days-=bdm[om];
 om++;
 }
 od=days;
 }
 else{
 days+=365;
 oy=y+1;
 om=0;
 while(days/dm[om+1]){
 days-=dm[om];
 om++;
 }
 od=days;
 }
 }
 }
 
 }
 */
bool later(int d1, int m1, int y1, int d2, int m2, int y2){
    if(y2>y1){
        return true;
    }
    else if(y2<y1){
        return false;
    }
    else{
        if(m2>m1){
            return true;
        }
        else if( m2<m1){
            return false;
        }
        else{
            if(d2>=d1){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int m,d,y;
    int cas;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>d>>m>>y;
        if(later(d,m,y,4,10,1582)){
            cout<<d<<" "<<m<<" "<<y<<"\n";
            continue;
        }
        else if(later(14,9,1752,d,m,y)){
            cout<<d<<" "<<m<<" "<<y<<"\n";
            continue;
        }
        else{
            d-=10;
            if(later(29,2,1700,d,m,y)){
                d--;
            }
            if(d<1&&m!=1){
                if(!(y%4)){
                    m-=1;
                    d+=bdm[m];
                }
                else{
                    m-=1;
                    d+=dm[m];
                }
            }
            
            else if(d<1){
                y--;
                m=12;
                d+=31;
            }
        }
        cout<<d<<" "<<m<<" "<<y<<"\n";
    }
    return 0;
}

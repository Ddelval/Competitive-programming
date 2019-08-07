#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
typedef long long int lli;
//lli data[4][8];
int main() {
    ios::sync_with_stdio(false);
    lli p,m,s,d;
    //lli am,as,ad;
    lli m_ent, s_ent,d_ent;
    int cas;
    //int ctr;
    cin>>cas;
    for(int i=0;i<cas;i++){
        cin>>p>>d>>s>>m;
        /*data[0][0]=d;
        ctr=1;
        am=m;
        am-=s;
        as=s;
        data[0][7]=as;
        as-=d;
        while(as>0){
            if(as/d){
                data[0][ctr]=d;
                as-=d;
            }else{
                data[0][ctr]=as;
                as=0;
            }
            ctr++;
        }
        for(int i=1;i<5;i++){
            if(am/s){
                as=s;
                am-=s;
            }else{
                as=am;
                am=0;
            }
            data[i][7]=as;
            ctr=0;
            while(as>0){
                if(as/d){
                    data[i][ctr]=d;
                    as-=d;
                }else{
                    data[i][ctr]=as;
                    as=0;
                }
                ctr++;
            }
            
        }
         */
        m_ent=(p/m);
        if(m_ent&&!(p%m)){
            m_ent--;
        }
        p-=m_ent*m;
        
        s_ent=(p/s);
        if(s_ent&&!(p%s)){
            s_ent--;
        }
        p-=s_ent*s;
        if(s_ent==4){
            s_ent=0;
            m_ent++;
        }
        d_ent=ceil((double)p/d);
        /*if(d_ent==7){
            d_ent=0;
            s_ent++;
            if(s_ent==4){
                s_ent=0;
                m_ent++;
            }
        }*/
        cout<<m_ent<<" "<<s_ent<<" "<<d_ent<<"\n";
    }
    return 0;
}


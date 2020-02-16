// AceptaElReto 113:  Semáforos sin parar
//
//  main.cpp
//  113_2
//
//  Created by David del Val on 08/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
double remind(double a, int b){
    double c=a-(((int)(a/b)))*b;
    return c;
    
}
typedef struct{
    double dista;
    int closed;
    int open;
    int cycle;
    
}semaf;
int numsem;
int maxspeed;
vector<semaf> v;
vector<int> accumlength;
double times(double maxspeed, double minspeed,int index){
    semaf s = v[index];
    double t_2,t_1,T_2,T_1;
    double T__1,t__1;
    double maxs,mins;
    double retvalue;
    T_1=accumlength[index]/maxspeed+s.dista/maxspeed;
    t_1=accumlength[index]/minspeed+s.dista/minspeed;
    if(index==numsem-1){
        if( ((int)(T_1/s.cycle))  == ((int)(t_1/s.cycle)) ){
            T__1=remind(T_1, s.cycle);
            t__1=remind(t_1, s.cycle);
            if(T__1<=s.closed&&t__1>=s.closed){
                return s.closed+(((int)(T_1/s.cycle))*s.cycle);
            }
            else if(T__1<0.01){
                return (((int)(T_1/s.cycle))*s.cycle);
            }
            else if(t__1<0.01){
                return (((int)(t_1/s.cycle))*s.cycle);
            }
            
            /*
            //They are in the same cycle
            if(T__1==s.closed){
                //The minimum time to arrive is in the open segment
                return T_1;
            }
            else if(){
                return T_1;
            }
            else if(t__1<0.01){
                return t__1;
            }
            else if(t__1==s.closed){
                return t__1;
            }*/
            return 0;
        }
        else{
            int cycles=t_1/s.cycle;
            int Cycles=T_1/s.cycle;
            T__1=remind(T_1, s.cycle);
            t__1=remind(t_1, s.cycle);
            if(T__1<=s.closed){
                return Cycles*s.cycle+s.closed;
            }
            else if(T__1<0.01){
                return (int)T_1;
            }
            for(int i=Cycles+1;i<cycles;i++){
                T_2=s.closed+s.cycle*i;
                /*t_2=t_2=s.cycle*(i+1);
                maxs=accumlength[index+1]/T_2;
                mins=accumlength[index+1]/t_2;
                retvalue=times(maxs,mins,index+1);
                if(retvalue){
                    return retvalue;
                }*/
                return T_2;
            }
            if(t__1>=s.closed){
                return cycles*s.cycle+s.closed;
            }
            else if(t__1<0.01){
                return (int)t_1;
            }
            return 0;
        }
    }
    if( ((int)(T_1/s.cycle))  == ((int)(t_1/s.cycle)) ){
        int cycles=T_1/s.cycle;
        T__1=remind(T_1, s.cycle);
        t__1=remind(t_1, s.cycle);
        //They are in the same cycle
        if(T__1>=s.closed){
            //The minimum time to arrive is in the open segment
            T_2=T_1;
            t_2=t_1;
        }
        else if(T__1<0.01){
            T_2=T_1;
            t_2=T_1;
        }
        else{
            //The minimum time to arrive is not in the open segment
            if(t__1>=s.closed){
                //The maximum time to arrive is in the open segment
                t_2=t_1;
                T_2=s.closed+cycles*s.cycle;
            }
            else if(t__1<0.01){
                t_2=t_1;
                T_2=t_1;
            }
            else{
                return 0;
            }
        }
        maxs=accumlength[index+1]/T_2;
        mins=accumlength[index+1]/t_2;
        return times(maxs,mins,index+1);
    }
    else{
        int cycles=t_1/s.cycle;
        int Cycles=T_1/s.cycle;
        T__1=remind(T_1, s.cycle);
        t__1=remind(t_1, s.cycle);
        if(T__1>=s.closed){
            T_2=T_1;
            t_2=(Cycles+1)*(s.cycle);
            maxs=accumlength[index+1]/T_2;
            mins=accumlength[index+1]/t_2;
            retvalue=times(maxs,mins,index+1);
            if(retvalue){
                return retvalue;
            }
        }
        else if(T__1<0.01){
            T_2=T_1;
            t_2=T_1;
        }
        else{
            T_2=Cycles*s.cycle+s.closed;
            t_2=(Cycles+1)*(s.cycle);
            maxs=accumlength[index+1]/T_2;
            mins=accumlength[index+1]/t_2;
            retvalue=times(maxs,mins,index+1);
            if(retvalue){
                return retvalue;
            }
        }
            for(int i=Cycles+1;i<cycles;i++){
                T_2=s.closed+s.cycle*i;
                t_2=t_2=s.cycle*(i+1);
                maxs=accumlength[index+1]/T_2;
                mins=accumlength[index+1]/t_2;
                retvalue=times(maxs,mins,index+1);
                if(retvalue){
                    return retvalue;
                }
            }
        if(t__1>=s.closed){
            T_2=t_1;
            t_2=s.cycle*cycles;
            maxs=accumlength[index+1]/T_2;
            mins=accumlength[index+1]/t_2;
            retvalue=times(maxs,mins,index+1);
            if(retvalue){
                return retvalue;
            }
        }
        else if(t__1<0.01){
            T_2=t_1;
            t_2=t_1;
            maxs=accumlength[index+1]/T_2;
            mins=accumlength[index+1]/t_2;
            retvalue=times(maxs,mins,index+1);
            if(retvalue){
                return retvalue;
            }
        }
        return 0;
        }
    

    return 0;
}

int main(int argc, const char * argv[]) {
    double res;
    /*numsem=2;
    maxspeed=4;
    semaf s;
    s.dista=50;
    s.closed=10;
    s.open=4;
    s.cycle=s.open+s.closed;
    v.push_back(s);
    s.dista=50;
    s.closed=10;
    s.open=10;
    s.cycle=s.open+s.closed;
    v.push_back(s);
    accumlength.push_back(0);
    accumlength.push_back(50);
    accumlength.push_back(100);
    */
     /*
     
    numsem=1;
    maxspeed=10;
    semaf s;
    s.dista=10;
    s.closed=110;
    s.open=100;
    s.cycle=s.open+s.closed;
    v.push_back(s);
    accumlength.push_back(0);
    accumlength.push_back(10);
    */
    /*
    numsem=3;
    maxspeed=10;
    semaf s;
    s.dista=100;
    s.closed=31;
    s.open=1;
    s.cycle=s.open+s.closed;
    v.push_back(s);
    s.dista=1;
    s.closed=30;
    s.open=1;
    s.cycle=s.open+s.closed;
    v.push_back(s);
    v.push_back(s);
    s.dista=1;
    s.closed=31;
    s.open=1;
    s.cycle=s.open+s.closed;
    accumlength.push_back(0);
    accumlength.push_back(100);
    accumlength.push_back(101);
    accumlength.push_back(102);
     */
    bool flag;
    int accumlen;
    cin>>numsem;
    cin>>maxspeed;
    while(numsem||maxspeed){
        accumlen=0;
        v.clear();
        accumlength.clear();
        accumlength.push_back(0);
        flag=false;
        semaf s;
        for(int i=0;i<numsem;i++){
            cin>>s.dista;
            cin>>s.closed;
            cin>>s.open;
            s.cycle=s.open+s.closed;
            if(!s.open){
                flag=true;
            }
            v.push_back(s);
            accumlen+=s.dista;
            accumlength.push_back(accumlen);
        }
        if(flag){
            cout<<"IMPOSIBLE"<<endl;
            cin>>numsem;
            cin>>maxspeed;
            continue;
        }
        res=times(maxspeed, 0.5, 0);
        if(res==0){
            cout<<"IMPOSIBLE"<<endl;
        }
        else{
            cout<<res<<endl;
        }
        
        cin>>numsem;
        cin>>maxspeed;
        
    }
    
    
    
    
    
    return 0;
}

// AceptaElReto 113:  Semáforos sin parar
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <string.h>
#include <limits.h>

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
struct Semaf{
    int x;
    int totalcycle;
    int red;
    int green;
    Semaf(int cl,int op, int totalx){
        totalcycle=cl+op;
        red=cl;
        green=op;
        x=totalx;
    }
};
int semafnum, maxspeed;
double totallength;
vector<Semaf> dat;

bool checkrun(int endtime){
    double time;
    int cyclepos;
    for(int i=0;i<semafnum-1;++i){
        time=endtime*(dat[i].x/totallength);
        cyclepos=((int)time)/dat[i].totalcycle;
        time-=cyclepos*dat[i].totalcycle;
        if(time<(dat[i].red-0.01)&&time>0.01){
            return false;
        }
        
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    int c,o,gap;
    bool res;
    int mincycle;
    bool flag;
    double speed;
    Semaf last(0,0,0);
    while(cin>>semafnum>>maxspeed&&semafnum){
        dat.clear();
        totallength=0;
        flag=false;
        for(int i=0;i<semafnum-1;++i){
            cin>>gap>>c>>o;
            if(!o)flag=true;
            totallength+=gap;
            dat.push_back(Semaf(c,o,totallength));
        }
        cin>>gap>>c>>o;
        if(!o)flag=true;
        totallength+=gap;
        last=Semaf(c,o,totallength);
        
        if(flag){
            cout<<"IMPOSIBLE\n";
            continue;
        }
        
        mincycle=((int)totallength/maxspeed)/last.totalcycle;
        if(mincycle!=(totallength/maxspeed)/last.totalcycle){
            if(((int)totallength/maxspeed)<last.red){
                speed=totallength/(double)(last.totalcycle*mincycle+last.red);
                if(speed<0.1){
                    cout<<"IMPOSIBLE\n";
                    continue;
                }
                    
                res=checkrun(last.red);
                if(res){
                    cout<<last.red<<"\n";
                    continue;
                }
            }
            
            mincycle++;
        }
        res=false;
        for(int i=mincycle;;++i){
            speed=totallength/(double)(last.totalcycle*i);
            if(speed<0.1)
                break;
            res=checkrun(last.totalcycle*i);
            if(res){
                cout<<last.totalcycle*i<<"\n";
                break;
            }
            speed=totallength/(double)(last.totalcycle*i+last.red);
            if(speed<0.1)
                break;
            res=checkrun(last.totalcycle*i+last.red);
            if(res){
                cout<<last.totalcycle*i+last.red<<"\n";
                break;
            }
        }
        if(!res){
            cout<<"IMPOSIBLE\n";
        }

    }
    
    
    
    
    
    
    return 0;
}

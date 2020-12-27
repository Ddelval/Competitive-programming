#include <vector>
#include <math.h>
#include <fstream>


using namespace std;
struct Portal{
    long sx,sy,ex,ey;
    bool used;
    Portal(long a,long b, long c, long d,bool ba){
        sx=a;
        sy=b;
        ex=c;
        ey=d;
        used=ba;
    }
};
vector<Portal> data;
long dist(int i, long x,long y){
    return  abs(data[i].sx-x) +abs(data[i].sy-y);
}

typedef pair<int,int> ii;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    ifstream in("/Users/daviddelval/Desktop/In.txt");
    ofstream out("/Users/daviddelval/Desktop/Out.txt");
    long cas,width,height,portals;
    long a,b,c,d;
    long x,y;
    in>>cas;
    int count=0;
    while(cas--){
        data.clear();
        in>>width>>height;
        in>>x>>y;
        in>>portals;
        for(int i=0;i<portals;++i){
            in>>a>>b>>c>>d;
            data.push_back(Portal(a,b,c,d,false));
        }
        int totalcount=0;
        while(portals){
            //Move towards portal
            long mindis=INT_MAX;
            long minx=x,miny=y;
            long selected;
            mindis=INT_MAX;
            selected=-1;
            for(int i=0;i<data.size();++i){
                if(data[i].used)continue;
                if(dist(i,x,y)<mindis){
                    mindis=dist(i,x,y);
                    selected=i;
                    minx=data[i].sx;
                    miny=data[i].sy;
                }
                else if(dist(i,x,y)==mindis){
                    if(data[i].sx<minx){
                        mindis=dist(i,x,y);
                        selected=i;
                        minx=data[i].sx;
                        miny=data[i].sy;
                    }
                    else if(data[i].sx==minx){
                        if(data[i].sy<miny){
                            mindis=dist(i,x,y);
                            selected=i;
                            minx=data[i].sx;
                            miny=data[i].sy;
                        }
                    }
                }
            }
            totalcount+=mindis;
            totalcount%=100003;
            data[selected].used=true;
            x=data[selected].ex;
            y=data[selected].ey;
            portals--;
        }
        count++;
        out<<"Case #"<<count<<": "<<totalcount<<"\n";
        
        
        
    }
    
    
    return 0;
}

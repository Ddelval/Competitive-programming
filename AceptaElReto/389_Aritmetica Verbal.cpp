#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <climits>
#include <vector>
using namespace std;
typedef long long ll;
map<char,int> assigned;

char op[3][9];
string res;
set<char> notzero;
bool picked[10];

int multicalcul(int pos){
    ll o1=0,o2=0;
    ll coe=1;
    for(int i=8;i>=pos;--i){
        o1+=coe*assigned[op[0][i]];
        o2+=coe*assigned[op[1][i]];
        coe*=10;
    }
    ll re=((o1*o2)/(ll)pow(10,9-pos-1));
    if(pos==0){
        ll re2=o1*o2;
        string s2=to_string(re2);
        if(s2.length()!=res.length())return 99;
        vector<char> buffer;
        ll retval=re%10;
        for(int i=0;i<s2.length();++i){
            if(assigned.count(res[i])==0){
                if(!picked[s2[i]-'0']){
                    picked[s2[i]-'0']=true;
                    buffer.push_back(res[i]);
                    assigned[res[i]]=s2[i]-'0';
                }
                else{
                    retval=-1;
                    break;
                }
            }
            else if(assigned[res[i]]!=(s2[i]-'0'))retval= -1;
        }
        for(char c:buffer){
            picked[assigned[c]]=false;
            if(retval==-1)assigned.erase(c);
        }
        return retval;
    }
    return re%10;
}


bool choose(int opcode, int operand, int pos, int carry){
    if(pos<0)return true;
    if(assigned.count(op[operand][pos])){
        if(operand<2){
            return choose(opcode,operand+1,pos,carry);
        }
        else{
            int res;
            if(opcode==0)res=assigned[op[0][pos]]+assigned[op[1][pos]]+carry;
            else res=multicalcul(pos);
            if(res<0)return false;
            if(res%10==assigned[op[2][pos]]){
                return choose(opcode,0,pos-1,res/10);
            }
            else return false;
        }
    }
    else{
        if(operand<2){
            for(int i=notzero.count(op[operand][pos]);i<10;++i){
                if(picked[i])continue;
                assigned[op[operand][pos]]=i;
                picked[i]=true;
                if(choose(opcode,operand+1,pos,carry))return true;
                picked[i]=false;
            }
            assigned.erase(op[operand][pos]);
            return false;
        }
        else{
            int res;
            if(opcode==0)res=assigned[op[0][pos]]+assigned[op[1][pos]]+carry;
            else res=multicalcul(pos);
            if(res<0)return false;
            if(picked[res%10])return false;
            if(res%10==0 && notzero.count(op[operand][pos]))return false;
            assigned[op[operand][pos]]=res%10;
            picked[res%10]=true;
            bool tmp=choose(opcode,0,pos-1,res/10);
            if(!tmp)picked[res%10]=false;
            if(!tmp)assigned.erase(op[operand][pos]);
            return tmp;
        }
    }   
}



int main(){

    string o[3],p,i;
    while(cin>>o[0]>>p>>o[1]>>i>>o[2]){
        res=o[2];
        for(int i=0;i<10;++i)picked[i]=0;
        assigned.clear();
        notzero.clear();
        assigned['0']=0;

        for(int z=0;z<3;++z){
            int i=0;
            for(;i<9-min((int)o[z].length(),9);++i){
                op[z][i]='0';
            }
            notzero.insert(o[z][0]);
            for(;i<9;++i){
                op[z][i]=o[z][i-9+(int)o[z].length()];
            }
        }
        choose(p=="*",0,8,0);
        for(auto c:o[0])cout<<assigned[c];
        cout<<" "<<p<<" ";
        for(auto c:o[1])cout<<assigned[c];
        cout<<" = ";
        for(auto c:o[2])cout<<assigned[c];
        cout<<"\n";

    }
    return 0;
}
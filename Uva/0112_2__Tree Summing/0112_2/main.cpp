// UVa Online Judge 112: Tree Summing
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct node{
    vector<node> children;
    bool isroot;
    bool isleeave;
    int weight;
};
queue<int>toadd;

int findsplit(string res){
    int i;
    int appearsO=0,appearsC=0;
    for(i=0;i<res.length();i++){
        if(res[i]=='('){
            appearsO++;
        }
        else if(res[i]==')'){
            appearsC++;
        }
        if(appearsC==appearsO){
            break;
        }
    }
    return i;
}
void input(string s){
    std::ios::sync_with_stdio(false);
    if(s.length()==0){
        
    }else{
        int par =(int)count(s.begin(),s.end(),'(');
        if (par>2){
            node n;
            queue<int> buffer;
            int index=(int)s.find('(');
            string res = s.substr(index);
            int i=findsplit(res);
            int weight =stoi(s.substr(0,(s.find('('))+1));
            string res1=res.substr(1,i-1);
            input(res1);
            while(toadd.size()>0){
                buffer.push(toadd.front()+weight);
                toadd.pop();
            }
            res1=res.substr(i+2,res.size()-i-2-1);
            input (res1);
            while(toadd.size()>0){
                buffer.push(toadd.front()+weight);
                toadd.pop();
            }
            while(buffer.size()>0){
                toadd.push(buffer.front());
                buffer.pop();
            }
            
        }
        
        else{
            toadd.push(stoi(s.substr(0,s.find('('))));
            
        }
    }
    
    
    
}
int main(int argc, const char * argv[]) {
    string data,tmp;
    int appearsO,appearsC;
    while (getline(cin,data)){
        while(toadd.size()>0){
            toadd.pop();
        }
        while(true){
            //Check for parenthesis
            appearsO=(int)count(data.begin(),data.end(),'(');
            appearsC=(int)count(data.begin(),data.end(),')');
            if(appearsO==appearsC){
                break;
            }
            getline(cin,tmp);
            data.append(tmp);
        }
        std::string::iterator end_pos = std::remove(data.begin(), data.end(), ' ');
        data.erase(end_pos, data.end());
        int weight =stoi(data.substr(0,(data.find('('))));
        data=data.substr((data.find('(')+1),data.size()-2-data.find('('));
        input(data);
        
        while(toadd.size()>0){
            if(toadd.front()==weight){
                break;
            }
            toadd.pop();
        }
        if(toadd.size()>0){
            cout<<"yes"<<endl;
            
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
char board[300][300];
int width,height;
int maxlength;
int lim;
char charsout[305];
struct TrieNode{
    TrieNode *l1,*l0,*rl;
    long long counter;
    bool isEnd;
};
TrieNode * getNode(){
    TrieNode* tr= new TrieNode;
    tr->isEnd=false;
    tr->l1=NULL;
    tr->l0=NULL;
    tr->rl=NULL;
    tr->counter=0;
    return tr;
}
TrieNode* insert(TrieNode* root, string s){
    TrieNode* cnode=root;
    for(auto i:s){
        if(i=='1'){
            if(!cnode->l1){
                cnode->l1=getNode();
            }
            cnode=cnode->l1;
        }
        else{
            if(!cnode->l0){
                cnode->l0=getNode();
            }
            cnode=cnode->l0;
        }
    }
    cnode->isEnd=true;
    return cnode;
}
TrieNode* insertR(TrieNode* root, string s,TrieNode* tr){
    TrieNode* cnode=root;
    char i;
    for(int a=(int)s.length()-1;a>=0;a--){
        i=s[a];
        if(i=='1'){
            if(!cnode->l1){
                cnode->l1=getNode();
            }
            cnode=cnode->l1;
        }
        else{
            if(!cnode->l0){
                cnode->l0=getNode();
            }
            cnode=cnode->l0;
        }
    }
    cnode->isEnd=true;
    cnode->rl=tr;
    return cnode;
}
bool searchH(TrieNode* root, int sx,int sy){
    TrieNode* cnode=root;
    lim=min(width,sy+maxlength);
    for(int y=sy;y<lim;++y){
        if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
        if(cnode->isEnd) cnode->counter++;
        if(board[sx][y]=='1'){
            if(!(cnode->l1)) return false;
            cnode=cnode->l1;
        }
        else{
            if(!(cnode->l0)) return false;
            cnode=cnode->l0;
        }
    }
    if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
    if(cnode->isEnd) cnode->counter++;
    return (cnode!=NULL &&cnode->isEnd);
}
bool searchV(TrieNode* root, int sx,int sy){
    TrieNode* cnode=root;
    lim=min(height,sx+maxlength);
    for(int x=sx;x<lim;++x){
        if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
        if(cnode->isEnd) cnode->counter++;
        if(board[x][sy]=='1'){
            //if(cnode->isEnd) cnode->counter++;
            if(!(cnode->l1)) return false;
            cnode=cnode->l1;
        }
        else{
            if(!(cnode->l0)) return false;
            cnode=cnode->l0;
        }
    }
    if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
    if(cnode->isEnd) cnode->counter++;
    return (cnode!=NULL &&cnode->isEnd);
}
bool searchD1(TrieNode* root, int sx,int sy){
    TrieNode* cnode=root;
    lim=min(width-sy,height-sx);
    lim=min(lim,maxlength);
    for(int x=0;x<lim;++x){
        if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
        if(cnode->isEnd) cnode->counter++;
        if(board[sx+x][sy+x]=='1'){
            if(!(cnode->l1)) return false;
            cnode=cnode->l1;
        }
        else{
            if(!(cnode->l0)) return false;
            cnode=cnode->l0;
        }
    }
    if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
    if(cnode->isEnd) cnode->counter++;
    return (cnode!=NULL &&cnode->isEnd);
}
bool searchD2(TrieNode* root, int sx,int sy){
    TrieNode* cnode=root;
    lim=min(width-sy,height-sx);
    lim=min(lim,maxlength);
    for(;sx<height&&sy>=0;){
        if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
        if(cnode->isEnd) cnode->counter++;
        if(board[sx][sy]=='1'){
            if(!(cnode->l1)) return false;
            cnode=cnode->l1;
        }
        else{
            if(!(cnode->l0)) return false;
            cnode=cnode->l0;
        }
        sx++; sy--;
    }
    if(cnode->isEnd&&cnode->rl) cnode->rl->counter++;
    if(cnode->isEnd) cnode->counter++;
    return (cnode!=NULL &&cnode->isEnd);
}
void printtree(TrieNode *n,int charpos){
    if(n->isEnd&&n->counter){
        if(!(n->rl)){
            for(int i=0;i<charpos;++i){
                cout<<charsout[i];
            }
            cout<<" ";
            cout<<n->counter;
            cout<<"\n";
        }
        else{
            if(n->rl->rl){
                for(int i=0;i<charpos;++i){
                    cout<<charsout[i];
                }
                cout<<" ";
                cout<<n->counter;
                cout<<"\n";
            }
        }
    }
    
        charsout[charpos]='0';
        if(n->l0) printtree(n->l0,charpos+1);
        charsout[charpos]='1';
        if(n->l1) printtree(n->l1,charpos+1);
    
}
int main() {
    ios::sync_with_stdio(false);
    int i,j,words;
    bool b1,b0;
    ll n0,n1;
    string w;
    TrieNode* aux;
    TrieNode* root=getNode();
    while(cin>>width>>height){
        //Input
        root=getNode();
        maxlength=0;
        n0=0;
        n1=0;
        char c;
        n0=n1=0;
        for(i=0;i<height;++i){
            for(j=0;j<width;++j){
                cin>>board[i][j];
                if(board[i][j]!='0') n1++;
                else n0++;
            }
        }
        b1=b0=false;
        cin>>words;
        for(i=0;i<words;++i){
            cin>>w;
            if(w.length()>maxlength){
                maxlength=(int)w.length();
            }
            if(w=="0"){
                b0=true;
            }
            else if(w=="1"){
                b1=true;
                
            }
            else{
                aux=insert(root,w);
                insertR(root,w,aux);
            }
        }
        
        //Search
        for(i=0;i<height;i++){
            for(j=0;j<width;++j){
                searchH(root,i,j);
                searchV(root,i,j);
                searchD1(root,i,j);
                searchD2(root,i,j);
            }
        }
        //Look through the tree and print the results
        if(b1&&n1){
            if(!root->l1) root->l1=getNode();
            root->l1->counter=n1;
            root->l1->isEnd=true;
        }
        if(b0&&n0){
            if(!root->l0) root->l0=getNode();
            root->l0->counter=n0;
            root->l0->isEnd=true;
        }
        printtree(root,0);
        cout<<"---\n";
    }
    return 0;
}


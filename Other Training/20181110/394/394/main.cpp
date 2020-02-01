//
//  main.cpp
//  394
//
//  Created by David del Val on 09/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct node{
    int number;
    struct node *left;
    struct node *right;
};
struct node* newNode(int numb){
    struct node *r =(struct node*)malloc(sizeof(struct node));
    r->number=numb;
    r->left=NULL;
    r->right=NULL;
    return r;
}
string creat;
node *create(){
    int numb=creat[0]-'0';
    struct node* n =newNode(numb);
    if(creat.length()!=1){
        creat= creat.substr(2,creat.length()-2);
    }
    n->number=numb;
    switch(numb){
        case 1:{
            n->left=create();
            break;
            
        }
        case 2:{
            n->left=create();
            n->right=create();
            break;
            
        }
    }
    return n;
}
int maximum;
queue<node*>lastadded;
queue<node*>firstadded;
priority_queue <int>p;
int lim;
void examingraph(node *n){
    int level=0;
    while(!p.empty()){
        p.pop();
    }
    while(!lastadded.empty()){
        lastadded.pop();
    }
    while(!firstadded.empty()){
        firstadded.pop();
    }
    if(n->number==2){
        p.push(-1*n->left->number);
        p.push(-1*n->right->number);
        lastadded.push(n->left);
        lastadded.push(n->right);
        firstadded.push(n->left);
        firstadded.push(n->right);
        level++;
        while(p.top()==-2){
            lim=(int)lastadded.size();
            for(int i=0;i<lim;i++){
                p.push(-1*lastadded.front()->left->number);
                p.push(-1*lastadded.front()->right->number);
                if(lastadded.back()->number==2){
                    lastadded.push(lastadded.front()->left);
                    lastadded.push(lastadded.front()->right);
                }
                else if(lastadded.front()->number==1){
                    lastadded.push(lastadded.front()->left);
                }
                
                lastadded.pop();
            }
            level++;
        }
        if(maximum<level){
            maximum=level;
        }
        vector<node*> v;
        while(!firstadded.empty()){
            if(firstadded.front()->number){
                v.push_back(firstadded.front());
            }
            firstadded.pop();
        }
        for(int i=0;i<v.size();i++){
            examingraph(v[i]);
        }
    }
    else if(n->number==1){
        examingraph(n->left);
    }
    
    
}

int main(int argc, const char * argv[]) {
    int cases;
    getline(cin, creat);
    cases=stoi(creat);
    for(int i=0;i<cases;i++){
        maximum=0;
        getline(cin, creat);
        node* root=create();
        examingraph(root);
        cout<<maximum<<endl;
    }
    
    return 0;
}

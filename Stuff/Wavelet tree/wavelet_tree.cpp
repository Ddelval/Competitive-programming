#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



template <typename T>
struct WaveTree{
    using it= typename vector<T>::iterator;

    vector<vector<T>> C; 
    int s; //Size of the alphabet
    
    WaveTree(vector<T> &ve, int size): C(size*2),s(size){
        build(ve.begin(),ve.end(),0,s-1,1);
    }


    int inline mapRight (int node, int pos) const {
        return pos-C[node][pos];
    }
    int inline mapLeft  (int node, int pos) const {
        return C[node][pos];
    }

    
    int inline left (int node) const {return 2*node;  }
    int inline right(int node) const {return 2*node+1;}

    /**
     * @brief Build the tree
     * 
     * @param b Iterator to the first element of the inital vector that
     *          corresponds to the node that we are building
     * @param e Iterator to one element past the last element of the initial
     *          vector that corresponds to the node that we are building
     * @param L Lower limit for the values in the node
     * @param U Upper limit for the values in the node
     * @param u Node to be built
     */
    void build(it b, it e, int L, int U, int u){
        cout<<"Building node "<<u<<endl;
        for_each(b,e,[](auto t){cout<<t<<" ";});
        cout<<"\n";
        if(L==U)return;

        int m=(L+U)/2;
        vector<T> & ve=C[u];
        ve.reserve(e-b+1);

        ve.push_back(0);

        for_each(b,e,[m,&ve](auto t){ ve.push_back(ve.back()+(t<=m));});

        for(int i=1;i<ve.size();++i)cout<<ve[i]<<" ";
        cout<<"\n";

        it p = stable_partition(b,e,[m](auto i){return i<=m;});

        build(b,p,L,m,left(u));
        build(p,e,m+1,U,right(u));
    }

    


    /*
    Count occurrences of c until position i:
    ie, times that we can find c in the range [0,i]
    */
    int rank(int c, int i) const{  
        //Consider interval open to the right [0..i+1)
        i++; 
        int L=0, U=s-1, u=1;
        int M,r;

        while(L!=U){
            M=(L+U)/2;
            if(c<=M){ // All elements c are in the left child
                i=mapLeft(u,i); 
                U=M;
                u=left(u);
            }
            else{ // All elements c are in the right child
                i=mapRight(u,i); 
                L=M+1;
                u=right(u);
            }
        }
        return i;
    }

    /**
     * Find the k-th smallest element in positions [i,j]
     * k is 1 indexed (1 is the minimum element)
     */
    int quantile(int k, int i, int j) const {
        // internally we consider an interval open on the right [i,j)
        j++;
        int L=0, U=s-1;
        int u=1;
        int M;
        int ri,rj;

        while(L!=U){
            M=(L+U)/2;
            c= mapLeft(u,j)- mapLeft(u,i-1); //c is nº of elements from indexes i to j mapped to the left
            if(k<=c){
                U=M;
                i=mapLeft(u,i);
                j=mapLeft(u,j);
                u=left(u);
            }
            else{
                L=M+1;
                k-=c;
                i=mapRight(u,i);
                j=mapRight(u,j);
                u=right(u);
            }
        }
        return U;
    }
    // Number of ocurrences of values in the range [a, b] in positions [i, j]

    int range(int i,int j, int L, int U) const{
        if(b<a || j<i){
            return 0;
        }
        return range(i,j+1,0,s-1,1,L,U);
    }


    /**
     * 
     * @param i Left limit of the range
     * @param j Right limit of the range
     * @param a Lower limit of the values in the node
     * @param b Upper limit of the values in the node
     * @param u Current node in which we are searching
     * @param L Initial lower limit of the values searched
     * @param U Initial upper limit of the values searched
     * @return int 
     */
    int range(int i, int j, int a, int b, int u, int L, int U) const{
        if(b<L || U<a){
            return 0;
        }
        if(L<=a && b<=U){
            return j-i;
        }
        int M= (a+b)/2;

        return  range(mapLeft(i),  mapLeft(j) ,a ,  M,  left(u),L,U) +
                range(mapRight(i), mapRight(j),M+1, b, right(u),L,U);
    }

};



int main(){
    vector<int> ve{3, 3, 9, 1, 2, 1, 7, 6, 4, 8, 9, 4, 3, 7, 5, 9, 2, 7, 3, 5, 1, 3};

    WaveTree<int> wa{ve,9};

    cout<<wa.rank(3,14);
    

}
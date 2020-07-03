#include <bits/stdc++.h>
using namespace std;

vector<int> sort_cyclic_shifts(string const& s){
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);

    for (int i = 0; i < n;++i){
        cnt[s[i]]++;
    }
    for (int i = 1; i < alphabet;++i){
        cnt[i] += cnt[i - 1];
    }
    // cnt[i] == position in the sorted string of the occurrence of i
    for (int i = 1; i < n;++i){
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;

    for (int i = 1; i < n;++i){
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }
}

int main(){

     string s="aaba";

}
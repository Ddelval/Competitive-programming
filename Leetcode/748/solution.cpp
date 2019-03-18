class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int letters[28];
        int tru[28];
        int cmax;
        bool good;
        string out;
        for(int i=0;i<28;++i) letters[i]=0;
        for(char c:licensePlate){
            if(c>='A'&&c<='Z'){
                letters[c-'A']++;
            }
            if(c>='a'&&c<='z'){
                letters[c-'a']++;
            }
        }
        cmax=INT_MAX;
        for(string el:words){
            for(int i=0;i<28;++i){
                tru[i]=0;
            }
            for(char c:el){
                if(c>='A'&&c<='Z'){
                   tru[c-'A']++;
                }
                 if(c>='a'&&c<='z'){
                    tru[c-'a']++;
            }
            good=true;
            for(int i=0;i<28;++i){
                if(tru[i]<letters[i]){
                    //cout<<el<<":"<<i<<" ";
                    good=false;
                    break;
                }
            }
            if(good){
                if(el.length()<cmax){
                    cmax=el.length();
                    out=el;
                }
            }
        }
        }
        return out;
    }
};
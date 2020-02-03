
#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int num;
    char c;
    bool exit=true;
    int color[3];
    string picture;
    getline(cin, picture);
    num=stoi(picture);
    
    for(int i=0;i<num;i++){
        getline(cin,picture);
        exit = true;
        for(int j=0;j<picture.length();j++){
            if(picture[j]==' '){
                color[0]=stoi(picture.substr(0,j+1));
                picture=picture.substr(j+1,picture.length()-j-1);
                break;
            }
        }
        for(int j=0;j<picture.length();j++){
            if(picture[j]==' '){
                color[1]=stoi(picture.substr(0,j+1));
                picture=picture.substr(j+1,picture.length()-j-1);
                break;
            }
        }
        for(int j=0;j<picture.length();j++){
            if(picture[j]==' '){
                color[2]=stoi(picture.substr(0,j+1));
                picture=picture.substr(j+1,picture.length()-j-1);
                break;
            }
        }
        
        for(int j=0;j<picture.length();j++){
            c=picture[j];
            switch (c) {
                case 'M': color[0]--; break;
                case 'A': color[1]--; break;
                case 'C': color[2]--; break;
                case 'R': color[0]--; color[1]--;break;
                case 'V': color[1]--; color[2]--;break;
                case 'L': color[0]--; color[2]--;break;
                case 'N': color[0]--; color[1]--;color[2]--;break;
            }
            if(color[0]==-1||color[1]==-1||color[2]==-1){
                cout<<"NO"<<endl;
                exit=false;
                break;
            }
        }
        if(exit){
            cout<<"SI "<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
        }
        
    }
    return 0;
}

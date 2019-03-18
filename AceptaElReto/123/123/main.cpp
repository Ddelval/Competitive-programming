//
//  main.cpp
//  123
//
//  Created by David del Val on 14/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    char c;
    int length;
    char str[21];
    while(1){
        scanf("%s ",str);
        scanf("%c",&c);
        //cin>>v;
       // cin>>c;
        if(c=='T'){
            break;
        }
        length=(int)strlen(str);
        //root=v.substr(0,v.length()-2);
        switch(str[length-2]){
            case 'a':{
                str[length-2]=0;
                switch (c) {
                    case 'A':{
                        printf("yo %so\n",str);
                        printf("tu %sas\n",str);
                        printf("el %sa\n",str);
                        printf("nosotros %samos\n",str);
                        printf("vosotros %sais\n",str);
                        printf("ellos %san\n",str);
                        break;
                    }
                    case 'P':{
                        printf("yo %se\n",str);
                        printf("tu %saste\n",str);
                        printf("el %so\n",str);
                        printf("nosotros %samos\n",str);
                        printf("vosotros %sasteis\n",str);
                        printf("ellos %saron\n",str);
                        break;
                    }
                    case 'F':{
                        printf("yo %sare\n",str);
                        printf("tu %saras\n",str);
                        printf("el %sara\n",str);
                        printf("nosotros %saremos\n",str);
                        printf("vosotros %sareis\n",str);
                        printf("ellos %saran\n",str);
                        break;
                    }
                }
                
                
                break;
            }
            case 'e':{
                str[length-2]=0;
                switch (c) {
                        
                    case 'A':{
                        printf("yo %so\n",str);
                        printf("tu %ses\n",str);
                        printf("el %se\n",str);
                        printf("nosotros %semos\n",str);
                        printf("vosotros %seis\n",str);
                        printf("ellos %sen\n",str);
                        break;
                    }
                    case 'P':{
                        printf("yo %si\n",str);
                        printf("tu %siste\n",str);
                        printf("el %sio\n",str);
                        printf("nosotros %simos\n",str);
                        printf("vosotros %sisteis\n",str);
                        printf("ellos %sieron\n",str);
                        break;
                    }
                    case 'F':{
                        printf("yo %sere\n",str);
                        printf("tu %seras\n",str);
                        printf("el %sera\n",str);
                        printf("nosotros %seremos\n",str);
                        printf("vosotros %sereis\n",str);
                        printf("ellos %seran\n",str);
                        break;
                    }
                }
                
                
                
                break;
            }
            case 'i':{
                str[length-2]=0;
                switch (c) {
                    case 'A':{
                        printf("yo %so\n",str);
                        printf("tu %ses\n",str);
                        printf("el %se\n",str);
                        printf("nosotros %simos\n",str);
                        printf("vosotros %sis\n",str);
                        printf("ellos %sen\n",str);
                        break;
                    }
                    case 'P':{
                        printf("yo %si\n",str);
                        printf("tu %siste\n",str);
                        printf("el %sio\n",str);
                        printf("nosotros %simos\n",str);
                        printf("vosotros %sisteis\n",str);
                        printf("ellos %sieron\n",str);
                        break;
                    }
                    case 'F':{
                        printf("yo %sire\n",str);
                        printf("tu %siras\n",str);
                        printf("el %sira\n",str);
                        printf("nosotros %siremos\n",str);
                        printf("vosotros %sireis\n",str);
                        printf("ellos %siran\n",str);
                        break;
                    }
                        
                }
                
                break;
            }
                
                
        }
    }
    return 0;
}

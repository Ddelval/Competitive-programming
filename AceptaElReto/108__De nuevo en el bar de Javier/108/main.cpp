//
//  main.cpp
//  108
//
//  Created by David del Val on 06/11/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <stdio.h>
int main() {
    char    Producto[6][11]={ "*", "DESAYUNOS#", "COMIDAS#", "MERIENDAS#", "CENAS#", "COPAS#" };
    char    Categoria=' ', CRLF=' ';
    double    ImporteMax=0, ImporteMin=0, Importe=0, TotImporte=0;
    double ImpCat[6]={0,0,0,0,0,0};
    int        Max=0, Min=0, CntMax=0, CntMin=0, NumVentas=0, NumComidas=0;
    while(scanf("%c%lf%c", &Categoria, &Importe, &CRLF)!=-1 ){
        TotImporte+=Importe;
        switch(Categoria){
            case 'D': ImpCat[1]+=Importe; NumVentas++;  break;
            case 'A': ImpCat[2]+=Importe; NumVentas++;  NumComidas++; break;
            case 'M': ImpCat[3]+=Importe; NumVentas++; break;
            case 'I': ImpCat[4]+=Importe; NumVentas++; break;
            case 'C': ImpCat[5]+=Importe; NumVentas++; break;
            default:{
                CntMax=0; CntMin=0; Min=1; Max=1; ImporteMin=ImpCat[1]; ImporteMax=ImpCat[1];
                for (int i=1; i<6; i++)
                {
                    if (ImpCat[i]> ImporteMax) { ImporteMax=ImpCat[i]; Max=i; }
                    if (ImpCat[i]< ImporteMin) { ImporteMin=ImpCat[i]; Min=i; }
                }
                for (int i=1; i<6; i++)
                {
                    if (ImpCat[i]==ImporteMax) CntMax++;
                    if (ImpCat[i]==ImporteMin) CntMin++;
                }
                CntMax>1 ? printf("EMPATE#") : printf("%s", Producto[Max]);
                CntMin>1 ? printf("EMPATE#") : printf("%s", Producto[Min]);
                ImpCat[2]/NumComidas>TotImporte/NumVentas ? printf ("SI\n") : printf ("NO\n");
                for (int i=0; i<6; i++)ImpCat[i] = 0;
                TotImporte=0; NumComidas=0; NumVentas=0;
                break;
            }
        }
    }
    return 0;
}

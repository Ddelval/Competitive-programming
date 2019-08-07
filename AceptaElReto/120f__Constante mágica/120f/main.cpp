//
//  main.cpp
//  120f
//
//  Created by David del Val on 22/12/2018.
//  Copyright © 2018 David del Val. All rights reserved.
//

#include <iostream>
using namespace std;
int data[100];
int main(int argc, const char * argv[]) {
    data[3]=3;
    data[5]=10;
    data[7]=21;
    data[9]=36;
    data[11]=55;
    data[13]=78;
    data[15]=105;
    data[17]=136;
    data[19]=171;
    data[21]=210;
    data[23]=253;
    data[25]=300;
    data[27]=351;
    data[29]=406;
    data[31]=465;
    data[33]=528;
    data[35]=595;
    data[37]=666;
    data[39]=741;
    data[41]=820;
    data[43]=903;
    data[45]=990;
    data[47]=1081;
    data[49]=1176;
    data[51]=1275;
    data[53]=1378;
    data[55]=1485;
    data[57]=1596;
    data[59]=1711;
    data[61]=1830;
    data[63]=1953;
    data[65]=2080;
    data[67]=2211;
    data[69]=2346;
    data[71]=2485;
    data[73]=2628;
    data[75]=2775;
    data[77]=2926;
    data[79]=3081;
    data[81]=3240;
    data[83]=3403;
    data[85]=3570;
    data[87]=3741;
    data[89]=3916;
    data[91]=4095;
    data[93]=4278;
    data[95]=4465;
    data[97]=4656;
    data[99]=4851;
    data[1]=0;
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    while(n||k){
        cout<<((data[n]+k+n)*(data[n]+k-1+n))/2-((data[n]+k)*(data[n]+k-1))/2<<"\n";
        cin>>n>>k;
    }
    return 0;
}

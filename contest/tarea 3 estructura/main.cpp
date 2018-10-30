//
//  main.cpp
//  tarea 3 estructura
//
//  Created by Pepe Hdez hdez on 8/20/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;
struct Team{
    string Name;
    int a = 0;
    int Time = 0;
};
struct Right{
    string Name;
    int Time = 0;
    char cRight;
};
struct Wrong{
    string Name;
    char cWrong;
};
int main(){
    int nt, np, nr;
    Team arrT[20];
    struct Right *r;
    struct Wrong *w;
    int iw=0;
    int ir=0;
    string x;
    char y, z;
    int ti, te;
    cin >> nt;
    cin >> np;
    for(int i = 0; i < nt; i++){
        cin >> arrT[i].Name;
    }
    cin >> nr;
    r= new struct Right[nr];
    w= new struct Wrong[nr];
    for(int i = 0; i < nr; i++){
        cin >> x;
        cin >> y;
        cin >> ti;
        cin >> z;
        if(z == 'A'){
            r[ir].Name = x;
            r[ir].cRight = y;
            r[ir].Time = ti;
            ir++;
        }
        else
        {
            w[iw].Name = x;
            w[iw].cWrong = y;
            iw++;
        }
    }
    for(int i = 0; i<ir; i++){
        for(int j = 0; j<iw; j++){
            if(r[i].Name == w[j].Name && r[i].cRight == w[j].cWrong){
                r[i].Time+=20;
            }
        }
    }
    for(int i = 0; i<ir; i++){
        for(int j = 0; j<nt; j++){
            if(arrT[j].Name == r[i].Name){
                arrT[j].Time+=r[i].Time;
                arrT[j].a+=1;
            }
        }
    }
    struct Team TeamTemp;
    for(int i = 0; i<nt; i++){
        for(int j=1; j<nt; j++){
            if(arrT[j-1].a < arrT[j].a ||(arrT[j-1].a == arrT[j].a && arrT[j-1].Time > arrT[j].Time )){
                TeamTemp = arrT[j];
                arrT[j] = arrT[j-1];
                arrT[j-1] = TeamTemp;
            }
        }
    }
    for(int i=0; i < nt; i++){
        cout << i+1 << " " << "-" << " ";
        cout << arrT[i].Name << " ";
        cout << arrT[i].a << " ";
        if(arrT[i].Time == 0){
            cout << "-";
        }
        else{
            cout << arrT[i].Time;
        }
        cout << endl;
    }
    return 0;
}

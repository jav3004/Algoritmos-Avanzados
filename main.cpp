/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: ASUS
 *
 * Created on 27 de agosto de 2025, 14:49
 */

#include <iostream>

using namespace std;

void imprime(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int cargarack(int ini,int *paq,int *rack,int*solu,int n,int m){
    
    if(ini==n){
        imprime(solu,m);
        return 1;
    }
    for(int i=0;i<m;i++){//recorrer el arreglo de racks
        if(rack[i]-solu[i]>=paq[ini]){
            solu[i]+=paq[ini];
            if(cargarack(ini+1,paq,rack,solu,n,m)){
                return 1;
            }
            solu[i]-=paq[ini];
        }
    }
}



int main(int argc, char** argv) {
    int paq[]={2,3,1,4};
    int n = sizeof(paq)/sizeof(paq[0]);
    int rack[]={3,2,5,1,3};
    int m = sizeof(rack)/sizeof(rack[0]);
    int solu[m]{};
    cargarack(0,paq,rack,solu,n,m);
    return 0;
    
}



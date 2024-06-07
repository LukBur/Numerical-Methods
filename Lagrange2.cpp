#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main(){
    
    double x[4], f[4];
    x[0] = 27;
    x[1] = 64;
    x[2] = 125;
    x[3] = 216;

    for(int i=0; i<4; i++){
        f[i] = pow(x[i], 1/3.0);
    }

    double licznik, mianownik, L = 0;
    int l_wezlow = 0;

    for(int i=0; i<4; i++){
        cout<<"x["<<i<<"] = "<<x[i]<<"; "<<"f["<<i<<"] = "<<f[i]<<endl;
    }
    
    double punkt = 50;

    for(int i=0; i<4; i++){
        mianownik = 1;
        licznik = 1;
        for(int j=0; j<4; j++){
            if(j == i){
                j++;
            }

            licznik *= (punkt - x[j]);
            mianownik *= (x[i] - x[j]);
        }
        L += f[i]*(licznik/mianownik);
    }

    cout<<"Dla punktu "<<punkt<<" wielomian przyjmuje wartosc "<<L;
}
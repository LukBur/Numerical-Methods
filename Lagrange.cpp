#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    ifstream file;
    string line;
    int n;
    
    file.open("MN-1.txt");
    file>>n;
    
    float x[n], f[n];
    float licznik, mianownik, punkt, L = 0;
    int l_wezlow = 0;

    for(int i=0; i<n; i++){
        file>>x[i];
        file>>f[i];
        cout<<"x["<<i<<"] = "<<x[i]<<" "<<"f["<<i<<"] = "<<f[i]<<endl;
        l_wezlow++;
    }

    cout<<"liczba wezlow: "<<l_wezlow<<endl;
    cout<<"Podaj punkt: ";
    cin>>punkt;
    
    for(int i=0; i<n; i++){
        mianownik = 1;
        licznik = 1;
        for(int j=0; j<n; j++){
            if(j == i){
                j++;
            }

            licznik *= (punkt - x[j]);
            mianownik *= (x[i] - x[j]);
        }
        L += f[i]*(licznik/mianownik);
        cout<<L<<endl;

    }

    cout<<"Dla punktu "<<punkt<<" wielomian przyjmuje wartosc "<<L;
    file.close();
}
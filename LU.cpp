#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream file;
    string line;

    int n;
    
    file.open("RURL_dane2.txt");
    file>>n;

    double A[n][n], b[n], m[n][n], U[n][n], L[n][n], y[n], x[n];

    cout<<"Macierz rozszerzona: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file >> A[i][j];
            cout<<A[i][j]<<" ";
        }
        file >> b[i];
        cout<<"| "<<b[i]<<endl;
    } cout<<endl;

    double suma;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // liczenie U
            suma = 0;
            for(int k=0; k<i; k++){
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - suma;
        }

        for(int j=i; j<n; j++){

            // liczenie L
            if (i == j){
                L[i][i] = 1;    
            } else {
                suma = 0;
                for(int k=0; k<i; k++){
                    suma += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - suma) / U[i][i];
            }   
        }
    }


    cout<<"Macierz U:"<<endl;
    for(int i=0; i<n; i++){
        for(int k=0; k<i; k++){
            cout<<0<<" ";
        }
        for(int j=i; j<n; j++){
            cout<<U[i][j]<<" ";
        } cout<<endl;
    } cout<<endl;

    double blad = 1e-4;

    cout<<"Macierz L:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<L[i][j]<<" ";
        } 
        for(int k=i; k<n; k++){
            if(abs(L[i][k]) < blad) L[i][k] = 0;
            cout<<L[i][k]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"wektor Y: { ";
    for(int i=0; i<n; i++){
        suma = 0;
        y[0] = b[0];
        for(int j=0; j<i; j++){
            suma += L[i][j] * y[j];
        }
        y[i] = b[i] - suma;
        cout<<y[i]<<" ";
    }
    cout<<"}";
    cout<<endl;
    
    cout<<endl;
    
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    for(int i=0; i<n; i++){
        cout<<"x["<<i<<"]: "<<x[i]<<endl;
    }
}


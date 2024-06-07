#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream file;
    string line;

    int n;
    
    file.open("RURL_Jacobi_dane1.txt");
    file>>n;

    double A[n][n], b[n], m[n][n], y[n], x[n], D[n][n], LU[n][n];

    cout<<"Macierz rozszerzona: "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file >> A[i][j];
            cout<<A[i][j]<<" ";
        }
        file >> b[i];
        cout<<"| "<<b[i]<<endl;
    } cout<<endl;

    //LICZENIE D_INV I LU
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                D[i][j] = 1/A[i][j];
                LU[i][j] = 0;
            } else {
                LU[i][j] = A[i][j];
                D[i][j] = 0;
            }
        }
    }

    

    int pom1 = 0, pom2 = 0;
    double suma = 0.0;
    for(int i=0; i<n; i++){
        suma = 0.0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            suma += abs(A[i][j]);
        }
        if(abs(A[i][i]) >= suma){
            pom1++;
        }
        if(abs(A[i][i]) > suma){
            pom2++;
        }
    }
    if(pom1 == n && pom2 > 0){
        cout<<"Macierz slabo dominujaca"<<endl;
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        x[i] = 0;
    }

    double blad = 1e-3;

    cout<<"Macierz LU:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<LU[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Macierz D:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    } cout<<endl;

    int l_iteracji;
    cout << "Liczba iteracji: ";
    cin >> l_iteracji;
    double DLUmatrix[n][n];
    double DLUxmatrix[n];
    double Dbmatrix[n];
    bool koniec = false;
    double err_val[n];
    int t = 0;
    int l_iter = 0;
    for (int iter = 0; iter < l_iteracji; ++iter) {
        double x_new[n];

        for (int i = 0; i < n; ++i) {
            double sumDLU = 0.0;
            for(int j=0; j<n; j++){
                DLUmatrix[i][j] = 0;
                for(int k=0; k<n; k++){
                    DLUmatrix[i][j] += D[i][k]*LU[k][j];
                }
                DLUmatrix[i][j] *= -1;
            }
        }

        for(int i=0; i<n; i++){
            Dbmatrix[i] = 0;
            for(int j=0; j<n; j++){
                Dbmatrix[i] += D[i][j]*b[j];
            }
        }
        for(int i=0; i<n; i++){
            DLUxmatrix[i] = 0;
            for(int j=0; j<n; j++){
                DLUxmatrix[i] += DLUmatrix[i][j]*x[j];
            }
        }
        for(int i=0; i<n; i++){
            x_new[i] = DLUxmatrix[i] + Dbmatrix[i];
        }
        //warunek stopu
        t++;
        for(int i=0; i<n; i++){
            err_val[i] = abs(x_new[i] - x[i]);
            if(abs(x_new[i] - x[i]) < blad){
                l_iter++;
                
            }
            if(l_iter == n){
                koniec = true;
            }
        }
        for(int i=0; i<n; i++){
            x[i] = x_new[i];
        }
        if(koniec){
            cout<<"liczba iteracji: "<<t<<endl;
            cout<<"stop"<<endl;
            break;
        }
        
    }

    for(int i=0; i<n; i++){
        cout<<"x["<<i<<"] = "<<x[i]<<" - wartosc bledu: "<<err_val[i]<<endl;
    }
    
    
}


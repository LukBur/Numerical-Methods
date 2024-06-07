#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    ifstream file;
    string line;

    int n;
    
    file.open("RURL_dane4.txt");
    file>>n;

    double a[n][n], b[n], m[n][n];
    double x[n];
    vector<int> zamiany;

    for(int i=0; i<n; i++){
        x[i] = 0;
        
        for(int j=0; j<n; j++){
            file>>a[i][j];
            if(i == j && a[i][j] == 0){
                cout<<"0 na przekatnej x["<<i<<"]"<<"["<<i<<"]"<<endl;
            }
        }
        file>>b[i];

    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<" / "<<b[i];
        cout<<endl;
    }
    cout<<endl;

    double tmp;
    int max;
    for(int i=0; i<n-1; i++){
        max = i;
        for(int j=i+1; j<n; j++){
            if(abs(a[j][i]) > abs(a[max][i])){
                max = j;
            }
        }
        if(max != i){
            for(int k=0; k<n; k++){
                tmp = a[k][i];
                a[k][i] = a[k][max];
                a[k][max] = tmp;
            }
                
        }
        for (int j=i+1; j<n; j++) {
            m[j][i] = a[j][i] / a[i][i];
            for (int k=i; k<n; k++) {
                a[j][k] -= m[j][i] * a[i][k];
            }
            b[j] -= m[j][i] * b[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<" / "<<b[i];
            cout<<endl;
        }
        cout<<endl;
    }
    
    

    double suma;
    for(int i=n-1; i>=0; i--){
        suma = 0;
        for(int k=i+1; k<n; k++){
            suma += a[i][k] * x[k];
        }
        x[i] = (b[i] - suma) / a[i][i];
        
    }
    for(int i=0; i<n; i++){
        cout<<"x["<<i+1<<"] = "<<x[i]<<endl;
    }
}
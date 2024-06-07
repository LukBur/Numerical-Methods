#include<iostream>
using namespace std;

double wart_fun(double f[], int size, double val){
    double sum = 0;
    double tmp_val;

    for(int i=size; i>1; i--){
        tmp_val = val;
        for(int j=0; j<i-2; j++){
            tmp_val *= val;
        }
        sum += tmp_val*f[size-i];
    }
    sum += f[size-1];
    return sum;
}

int main(){

    int n = 4;
    double x[20];
    double X[20];
    x[0] = 6;

    double f[n] = {-1.0, 0.0, 10.0, 5.0};
    double fprim[n-1];
    for(int i=n; i>1; i--){
        fprim[n-i] = f[n-i] * (i-1);
        cout<<fprim[n-i]<<endl;
    }
    
    int size_f = sizeof(f)/sizeof(f[0]);
    int size_fprim = sizeof(fprim)/sizeof(fprim[0]);
    x[1] = x[0] - wart_fun(f, size_f, 6)/wart_fun(fprim, size_fprim, 6);
    cout<<x[1]<<endl;
    x[2] = x[1] - wart_fun(f, size_f, x[1])/wart_fun(fprim, size_fprim, x[1]);
    cout<<x[2]<<endl;
    x[3] = x[2] - wart_fun(f, size_f, x[2])/wart_fun(fprim, size_fprim, x[2]);
    cout<<x[3]<<endl;



}
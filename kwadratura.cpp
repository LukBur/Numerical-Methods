#include<iostream>
#include<math.h>
using namespace std;

void kwadratura(double a, double b, int n, double (*f)(double)){
    
    double A[n];
    double x[n];
    if(n == 2){
        A[0] = 1;
        A[1] = 1;

        x[0] = -sqrt(3)/3;
        x[1] = sqrt(3)/3;
    } else if (n == 3){
        A[0] = 5/9;
        A[1] = 8/9;
        A[2] = 5/9;

        x[0] = -sqrt(0.6);
        x[1] = 0;
        x[2] = sqrt(0.6);
    } else {
        A[0] = 0.347;
        A[1] = 0.652;
        A[2] = 0.652;

        x[0] = -(525 + 70*sqrt(30))/35;
        x[1] = -(525 - 70*sqrt(30))/35;
        x[2] = (525 - 70*sqrt(30))/35;
        x[3] = (525 + 70*sqrt(30))/35;
    }

    double sum = 0;

    for(int i=1; i<n; i++){
        sum += A[i-1]*f((a+b)/2 + (b-a)*x[i-1]/2);
    }

    sum *= (b-a)/2;
    cout<<"Kwadratura dla "<<n<<" wezlow: "<<sum<<endl;
}

int main(){

}
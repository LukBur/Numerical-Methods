#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

double w(double x){
    return pow(x,2) + 2*x + 5;
}

double exp(double x){
    return pow(M_E, x);
}

double sss(double x){
    return sin(x);
}

void sinus(){

    double x;

    double x2 = 0;
    double sinx = 0;
    double natural = 0;

    double a = 0.5, b = 2.5;
    cout<<"Calkowana funkcja: sin(x)"<<endl;
    cout<<"Przedzial calkowania: <0.5, 2.5>"<<endl;
    cout<<"Liczba przedzialow: "<<20<<endl;

    double interval = (b-a)/20;
    double xi = interval;
    double s = (b-a)/(20);
    
    // prostokąty
    for(int i = 0; i < 20; i++){
        double xi = a + i * interval + interval/2;
        sinx += sin(xi); 
    }
    sinx *= s;
    cout<<"calka sinusa prostokaty: "<<sinx<<endl;

    double fx1, fx2;
    double l = 0;

    // trapezy
    for(int i=0; i<20; i++){
        double l = a + i * interval;
        double fx1 = sin(l);
        double fx2 = sin(l + interval);
        x2 += (fx1 + fx2) * interval / 2;
    }

    cout<<"calka sinusa trapezy: "<<x2<<endl;

    double h = (b - a) / 20;
    double sum = sin(a) + sin(b);

    for(int i = 1; i < 20; i++){
        double x = a + i * h;
        if(i % 2 == 0)
            sum += 2 * sin(x);
        else
            sum += 4 * sin(x);
    }

    double result = sum * h / 3;
    cout << "Przyblizona wartosc calki metoda Simpsona: " << result << endl;
    
}

void wielomian(){
    double x;

    double x2 = 0;
    double sinx = 0;
    double natural = 0;

    double a = 0.5, b = 5;
    cout<<"Calkowana funkcja: x^2 + 2x + 5"<<endl;
    cout<<"Przedzial calkowania: <0.5, 5>"<<endl;
    cout<<"Liczba przedzialow: "<<20<<endl;

    double interval = (b-a)/20;
    double xi = interval;
    double s = (b-a)/(20);
    
    // prostokąty
    for(int i = 0; i < 20; i++){
        double xi = a + i * interval + interval/2;
        sinx += w(xi); 
    }
    sinx *= s;
    cout<<"calka sinusa prostokaty: "<<sinx<<endl;

    double fx1, fx2;
    double l = 0;

    // trapezy
    for(int i=0; i<20; i++){
        double l = a + i * interval;
        double fx1 = w(l);
        double fx2 = w(l + interval);
        x2 += (fx1 + fx2) * interval / 2;
    }

    cout<<"calka sinusa trapezy: "<<x2<<endl;

    double h = (b - a) / 20;
    double sum = w(a) + w(b);

    for(int i = 1; i < 20; i++){
        double x = a + i * h;
        if(i % 2 == 0)
            sum += 2 * w(x);
        else
            sum += 4 * w(x);
    }

    double result = sum * h / 3;
    cout << "Przyblizona wartosc calki metoda Simpsona: " << result << endl;
}

double simpson(double a, double b, int n, double (*f)(double)){
    double h = (b - a) / n;
    double sum = 0;

    for(int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = f(x); 

        double coefficient;
        if (i == 0 || i == n) {
            coefficient = 1;
        } else if (i % 2 == 1) {
            coefficient = 4;
        } else {
            coefficient = 2;
        }

        sum += coefficient * fx;
    }

    return sum * h / 3;
    cout<<endl;
}

void eksp(){
    double x;

    double x2 = 0;
    double sinx = 0;
    double natural = 0;

    double a = 0.5, b = 5;
    cout<<"Calkowana funkcja: sin(x)"<<endl;
    cout<<"Przedzial calkowania: <0.5, 5>"<<endl;
    cout<<"Liczba przedzialow: "<<20<<endl;

    double interval = (b-a)/20;
    double xi = interval;
    double s = (b-a)/(20);
    
    // prostokąty
    for(int i = 0; i < 20; i++){
        double xi = a + i * interval + interval/2;
        sinx += exp(xi); 
    }
    sinx *= s;
    cout<<"calka sinusa prostokaty: "<<sinx<<endl;

    double fx1, fx2;
    double l = 0;

    // trapezy
    for(int i=0; i<20; i++){
        double l = a + i * interval;
        double fx1 = exp(l);
        double fx2 = exp(l + interval);
        x2 += (fx1 + fx2) * interval / 2;
    }

    cout<<"calka sinusa trapezy: "<<x2<<endl;

    double h = (b - a) / 20;
    double sum = exp(a) + exp(b);

    for(int i = 1; i < 20; i++){
        double x = a + i * h;
        if(i % 2 == 0)
            sum += 2 * exp(x);
        else
            sum += 4 * exp(x);
    }

    double result = sum * h / 3;
    cout << "Przyblizona wartosc calki metoda Simpsona: " << result << endl;
}

void kwadratura(double a, double b, int n, double (*f)(double)){
    
    double A[n];
    double x[n];

    if(n == 2){
        A[0] = 1;
        A[1] = 1;

        x[0] = -sqrt(3)/3.0;
        x[1] = sqrt(3)/3.0;
    } else if (n == 3){
        A[0] = 0.55555;
        A[1] = 0.88888;
        A[2] = 0.55555;

        x[0] = -sqrt(0.6);
        x[1] = 0;
        x[2] = sqrt(0.6);
    } else {
        A[0] = 0.347;
        A[1] = 0.652;
        A[2] = 0.652;
        A[3] = 0.347;

        x[0] = -0.8611;
        x[1] = -0.3399;
        x[2] = 0.3399;
        x[3] = 0.8611;
    }

    double sum = 0;

    for(int i=0; i<n; i++){
        sum += A[i]*f((a+b)/2.0 + (b-a)*x[i]/2.0);
    }

    sum *= (b-a)/2.0;
    cout<<"Kwadratura dla "<<n<<" wezlow: "<<sum<<endl;
}

int main(){

    cout<<"sin(x)"<<endl;
    for(int i=2; i<=4; i++){
        kwadratura(0.5, 2.5, i, sss);
    }

    sinus();

    cout<<"x^2 + 2x + 5"<<endl;
    for(int i=2; i<=4; i++){
        kwadratura(0.5, 5.0, i, w);
    }

    wielomian();

    cout<<"exp(x)"<<endl;
    for(int i=2; i<=4; i++){
        kwadratura(0.5, 5.0, i, exp);
    }

    



}

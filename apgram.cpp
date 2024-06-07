#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double wspDwumian(int n, int k) {
    double binom = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        binom *= (n - i);
        binom /= (i + 1);
    }
    return binom;
}

double silnia(double x, int n) {
    double result = 1;
    for (int j = 0; j < n; ++j) {
        result *= (x - j);
    }
    return result;
}

double wielGram(int k, int n, double q) {
    double sum = 0;
    for (int s = 0; s <= k; ++s) {
        double term = pow(-1, s) * wspDwumian(k, s) * wspDwumian(k + s, s) * silnia(q, s) / silnia(n, s);
        sum += term;
    }
    return sum;
}

double approx(double x[], double y[], int size, double h, double xm, int degree, double ck[], double sk[]) {
    int n = size - 1;

    // Obliczenie sk i ck
    for (int k = 0; k <= degree; ++k) {
        ck[k] = 0;
        sk[k] = 0;
        for (int i = 0; i <= n; ++i) {
            sk[k] += pow(wielGram(k, n, i), 2);
            ck[k] += y[i] * wielGram(k, n, i);
        }
        ck[k] /= sk[k];
    }

    // wartosc funkcji aproksymującej w punkcie xm
    double q = (xm - x[0]) / h;
    double ym = 0;
    for (int k = 0; k <= degree; ++k) {
        ym += ck[k] * wielGram(k, n, q);
    }

    cout << "Liczba wezlow: " << n + 1 << endl;
    cout << "Wspolczynniki ck i sk:" << endl;
    for (int k = 0; k <= degree; ++k) {
        cout << "c" << k << " = " << ck[k] << ", s" << k << " = " << sk[k] << endl;
    }

    cout << "Wezly aproksymacji (x) i wartosci w wezlach (y) oraz obliczone wartosci funkcji aproksymujacej ym(x):" << endl;
    cout << setw(10) << "x" << setw(10) << "y" << setw(10) << "ym(x)" << endl;
    for (int i = 0; i <= n; ++i) {
        double q_i = (x[i] - x[0]) / h;
        double ym_i = 0;
        for (int k = 0; k <= degree; ++k) {
            ym_i += ck[k] * wielGram(k, n, q_i);
        }
        cout << setw(10) << x[i] << setw(10) << y[i] << setw(10) << ym_i << endl;
    }

    return ym;
}

int main() {
    const int size = 8;
    double x[size] = {1, 2, 3, 4, 5, 6, 7, 8};
    double y[size] = {2, 4, 3, 5, 6, 9, 11, 11};

    double h = x[1] - x[0];

    int degree = 2;

    double ck[degree + 1];
    double sk[degree + 1];

    double xm1 = 2.5;
    double xm2 = 6.5;

    cout << "Aproksymacja dla stopnia " << degree << ":" << endl;
    double ym1 = approx(x, y, size, h, xm1, degree, ck, sk);
    double ym2 = approx(x, y, size, h, xm2, degree, ck, sk);

    cout << "Wartosc funkcji aproksymujacej dla x = " << xm1 << " wynosi ym(x) = " << ym1 << endl;
    cout << "Wartosc funkcji aproksymujacej dla x = " << xm2 << " wynosi ym(x) = " << ym2 << endl;

    return 0;
}

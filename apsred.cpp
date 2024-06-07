#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// Funkcja do rozwiązywania układu równań metodą Gaussa
void gauss(double** A, double* b, double* x, int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= A[k][i] * x[i];
        }
    }
}

// Funkcja do obliczania współczynników wielomianu aproksymującego
void aproksymacja(double* x, double* y, double* w, int m, int degree, double* a) {
    int n = degree + 1;

    double** g = new double*[n];
    for (int i = 0; i < n; ++i) {
        g[i] = new double[n]();
    }

    double* F = new double[n]();

    // macierz g i wektor F
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[j][k] += w[i] * pow(x[i], j) * pow(x[i], k);
            }
            F[j] += w[i] * y[i] * pow(x[i], j);
        }
    }

    gauss(g, F, a, n);

    for (int i = 0; i < n; ++i) {
        delete[] g[i];
    }
    delete[] g;
    delete[] F;
}

double wiel_w_x(double* a, int degree, double x) {
    double wynik = 0;
    for (int i = 0; i <= degree; i++) {
        wynik += a[i] * pow(x, i);
    }
    return wynik;
}

int main() {
    const int n = 8;
    double x[n] = {1, 2, 3, 4, 5, 6, 7, 8};
    double y[n] = {2, 4, 3, 5, 6, 9, 11, 11};
    double w[n];
    for (int i = 0; i < n; i++) {
        w[i] = 1.0;
    }

    int degree = 2;

    // wspolczynniki wielomianu aproksymującego
    double a[degree + 1];
    aproksymacja(x, y, w, n, degree, a);

    cout << "Liczba wezlow: " << n << endl;
    cout << "Wspolczynniki wielomianu aproksymujacego:" << endl;
    for (int i = 0; i <= degree; i++) {
        cout << "a" << i << " = " << a[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        double fx = wiel_w_x(a, degree, x[i]);
        cout << setw(10) << x[i] << setw(10) << y[i] << setw(10) << fx << endl;
    }

    double test_x1 = 2.5;
    double test_x2 = 6.5;
    cout << "F(2.5) = " << wiel_w_x(a, degree, test_x1) << endl;
    cout << "F(6.5) = " << wiel_w_x(a, degree, test_x2) << endl;

    return 0;
}

#include<iostream>
#include<fstream>

using namespace std;

void forwardSubstitution(double l[][10], double b[], double y[], int n) {
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += l[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }
}

void backwardSubstitution(double u[][10], double y[], double x[], int n) {
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += u[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / u[i][i];
    }
}

void printMatrix(double matrix[][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream file("RURL_dane1.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    double a[10][10], b[10], m[10][10], u[10][10], l[10][10], y[10], x[10];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            file >> a[i][j];
            cout<<a[i][j]<<" ";
        }
        file >> b[i];
        cout<<" | "<<b[i]<<endl;
    }
    file.close();

    for (int i = 0; i < n; ++i) {
        l[i][i] = 1.0;
    }
    
    double suma;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            // Calculate U
            suma = 0;
            for(int k = 0; k < i; k++) {
                suma += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - suma;
        }

        for(int j = i; j < n; j++) {
            // Calculate L
            if (i == j) {
                l[i][i] = 1;
            } else {
                suma = 0;
                for(int k = 0; k < i; k++) {
                    suma += l[j][k] * u[k][i];
                }
                l[j][i] = (a[j][i] - suma) / u[i][i];
            }
        }
    }

    cout << "Matrix U:" << endl;
    printMatrix(u, n);

    double threshold = 1e-4;

    cout << "Matrix L:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << l[i][j] << " ";
        }
        for(int k = i; k < n; k++) {
            if(abs(l[i][k]) < threshold) l[i][k] = 0;
            cout << l[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Vector y:" << endl;
    forwardSubstitution(l, b, y, n);
    for(int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }
    cout << endl;

    cout << "Solution (x0 - xn):" << endl;
    backwardSubstitution(u, y, x, n);
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }

    return 0;
}

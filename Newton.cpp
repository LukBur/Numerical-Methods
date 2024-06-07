    #include<iostream>
    #include<fstream>

    using namespace std;

    int main(){
        ifstream file;
        string line;

        int n;
        
        file.open("MN-2-p2.txt");
        file>>n;
        
        double punkt, x[n], f[n], p[n], b[n];

        cout<<"Podaj punkt: ";
        cin>>punkt;

        for(int i=0; i<n; i++){
            file>>x[i];
            file>>f[i];
            cout<<"x["<<i<<"] = "<<x[i]<<" "<<"f["<<i<<"] = "<<f[i]<<endl;
            p[i] = 1;
            b[i] = f[i];
        }
        cout<<"Liczba wezlow: "<<n<<endl;

        //liczenie pk
        for(int i=0; i<n; i++){
            for(int k=0; k<i; k++){
                p[i] *= (punkt - x[k]);
            }
        }

        double W = 0;
        //liczenie bk
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                b[i] -= b[j]; 
                b[i] /= (x[i] - x[j]);
            }
            cout<<"b["<<i<<"] = "<<b[i]<<endl;
        }

        for(int i=0; i<n; i++){
            W += b[i] * p[i];
        }

        cout<<"Wartosc wielomianu w punkcie "<<punkt<<" wynosi: "<<W;

    }
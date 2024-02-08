#include <iostream>
using namespace std;

int main() {
    const int filas = 6;
    const int colum = 7;
    int matriz[filas][colum];
    int filaMax[filas]; 
    int filaMin[filas]; 
    float filaSum[filas] = {0.0};
    float columSum[colum] = {0.0};
    int columMax[colum]; 
    int columMin[colum]; 

    
    for (int i = 0; i < filas; ++i) {
        filaMax[i] = INT_MIN; 
        filaMin[i] = INT_MAX; 

        for (int j = 0; j < colum; ++j) {
            cout << "Ingresa el valor para la fila " << (i + 1) << ", columna " << (j + 1) << ": ";
            cin >> matriz[i][j];

            
            filaMax[i] = max(filaMax[i], matriz[i][j]);
            filaMin[i] = min(filaMin[i], matriz[i][j]);
            filaSum[i] += matriz[i][j];
            columSum[j] += matriz[i][j];

            
            if (i == 0) {
                columMax[j] = matriz[i][j];
                columMin[j] = matriz[i][j];
            } else {
                columMax[j] = max(columMax[j], matriz[i][j]);
                columMin[j] = min(columMin[j], matriz[i][j]);
            }
        }
    }

    cout << "\nResultados:\n";
    for (int i = 0; i < filas; ++i) {
        float filaProm = filaSum[i] / colum;
        cout << "Fila " << (i + 1) << ": Maximo = " << filaMax[i] << ", Minimo = " << filaMin[i]
             << ", Promedio = " << filaProm << endl;
    }

    for (int j = 0; j < colum; ++j) {
        float columProm = columSum[j] / filas;
        cout << "Columna " << (j + 1) << ": Maximo = " << columMax[j] << ", Minimo = " << columMin[j]
             << ", Promedio = " << columProm << endl;
    }

    return 0;
}



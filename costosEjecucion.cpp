#include <bits/stdc++.h>
#include <ctime>

using namespace std;
 

void ord_Burbuja(int arreglo[], int tamano) {
    int i = 0;
    int j = 0;

    for (i = 0; i < tamano - 1; i++){
        for (j = 0; j < tamano - i - 1; j++){
            if (arreglo[j] > arreglo[j + 1]){
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}
 
void ord_Quicksort(int arreglo[], int primero, int ultimo){
    int centro = (primero + ultimo) / 2;
    int pivote = arreglo[centro];
    int i = primero;
    int j = ultimo;

    do {
        while(arreglo[i] < pivote) i++;
        while(arreglo[j] > pivote) j--;

        if(i <= j){
            int temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
            i++;
            j--;
        }
    } while(i <= j);

        if(primero < j) ord_Quicksort(arreglo, primero, j);
        if(i < ultimo) ord_Quicksort(arreglo, i, ultimo);
}

void imprimir(int arreglo[], int tamano){
    int i = 0;
    for (i = 0; i < tamano; i++)
        cout << arreglo[i] << " ";
    cout << endl;
}
 

int main()
{
    int arreglo[50000];
    for(int i = 0; i < 50000; i++) arreglo[i] = (rand()%(100 - 1 + 1) + 1);
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    unsigned tiempoInicial = clock();

    // Ejecucion del ordenamiento
    cout << "Arreglo ordenado: \n";
    
    // ord_Burbuja(arreglo, tamano);

    ord_Quicksort(arreglo, 0, tamano - 1);

    // imprimir(arreglo, tamano);

    unsigned tiempoFinal = clock();

    cout << "Tiempo de ejecucion: " << (double(tiempoFinal-tiempoInicial)/CLOCKS_PER_SEC) << " s" << endl;
    return 0;
}
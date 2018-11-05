/* 47158014 */

//#include <string.h>
//#include <stdio.h>
#include "include/intervalos.h"
//#include<iostream>
//using namespace std;
/*
typedef unsigned int uint;

struct intervalo_t {
  // fin > inicio
  uint inicio;
  uint fin;
  uint volumen;
};

*/

struct intervalo_t_des {
  uint inicio;
  uint fin;
  uint volumen;
  uint pos_real;
};

void mergeSort(intervalo_t_des arreglo[], uint izq, uint der){

    if (der > izq){

        //CALCULO EL MEDIO
        uint medio = izq + (der - izq) / 2;

        //LLAMADA RECURSIVA
        mergeSort(arreglo, izq, medio);
        mergeSort(arreglo, medio +1, der);

        // CREO ARRAYS TEMPORALES PARA DIVIDIR
        uint t1 = medio - izq + 1;
        uint t2 =  der - medio;
        intervalo_t_des* Left = new intervalo_t_des[t1];
        intervalo_t_des* Right = new intervalo_t_des[t2];
        for (uint j = 0; j < t2; j++){
            Right[j] = arreglo[medio + 1+ j];
        }
        for (uint i = 0; i < t1; i++){
            Left[i] = arreglo[izq + i];
        }

        //ELIJO EL MENOR EN CADA UNO PARA EL RESULTADO
        uint i = 0, j = 0;
        while (j < t2 && i < t1)
        {
            if (Left[i].fin > Right[j].fin)
            {
                arreglo[izq] = Right[j];
                j++;
            }
            else
            {
                arreglo[izq] = Left[i];
                i++;
            }
            izq++;
        }

        //Copio lo que quedo del array sobrante
        for (uint p = i; p < t1; p++)
        {
            arreglo[izq] = Left[p];
            izq++;
        }

        for (uint p = j; p < t2; p++)
        {
            arreglo[izq] = Right[p];
            izq++;
        }

        delete[] Left;
        delete[] Right;
    }
}


/*
  Devuelve una copia de 'intervalos'.
*/
intervalo_t_des *copiar_estructura(const intervalo_t *intervalos, uint cant_intervalos) {
  intervalo_t_des *copia = new intervalo_t_des[cant_intervalos];
  for (uint i = 0; i < cant_intervalos; i++){
    copia[i].fin = intervalos[i].fin;
    copia[i].inicio = intervalos[i].inicio;
    copia[i].volumen = intervalos[i].volumen;
    copia[i].pos_real = i;
  }
  return copia;
}

void imprimir(intervalo_t_des *A, int tam){
    for (int i=0; i < tam; i++);
//        cout << A[i].fin << "\n" <<endl;
}

void imprimirBools(bool *A, int tam){
    for (int i=0; i < tam; i++);
//        cout << A[i]?1:0 << "\n" <<endl;
}

/* Devuelve un arreglo de booleanos de 'n' con TRUE en los intervalos asignados
   los cuales no se superponen. O sea son compatibles.
   La cantidad de intervalos asignados debe ser la máxima posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
   El tiempo de ejecucion de peor caso debe ser O(n*log(n)).
*/
// Idea extraida de libro
bool *max_cantidad(const intervalo_t *intervalos, uint n){
    intervalo_t_des *intervalos_temp = copiar_estructura(intervalos,n);
//    imprimir(intervalos,n);
//    imprimir(intervalos_temp,n);
    mergeSort(intervalos_temp,0,n-1);// para ordenar en n log n
//    imprimir(intervalos_temp,n);
    bool *booleanos = new bool[n];
    uint tomado = 0;
    booleanos[intervalos_temp[tomado].pos_real] = true;
    for (uint i = 1; i<n; i++){
        uint fin_del_actual = intervalos_temp[tomado].fin;
        uint inicio_del_siguiente = intervalos_temp[i].inicio;
        if (fin_del_actual <= inicio_del_siguiente){
            booleanos[intervalos_temp[i].pos_real] = true;
            tomado = i;
        }else{
            booleanos[intervalos_temp[i].pos_real] = false;
        };
    }
    delete[] intervalos_temp;
    return booleanos;
};

int p(intervalo_t_des* intervalos,const uint actual)
{
    int izq = 0;
    int der = actual - 1;
    while (izq <= der)
    {
        int med = (izq + der) / 2;
        if (intervalos[med].fin > intervalos[actual].inicio)
            der = med - 1;
        else
            if (intervalos[med + 1].fin > intervalos[actual].inicio)
                return med;
            else
                izq = med + 1;
    }
    return -1;
}

void imprimir3(uint *A, int size)
{
    for (int i=0; i < size; i++);
//        printf("%d ", A[i]);
}

uint maximo(uint uno, uint dos){
    if (uno >= dos){
        return uno;
    }else{
        return dos;
    }
}

/* Devuelve un arreglo de booleanos de 'n' con TRUE en los intervalos asignados
   los cuales no se superponen.
   La suma de los volumenes de los intervalos asignados debe ser la máxima
   posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
    El tiempo de ejecucion de peor caso debe ser O(n*log(n)).
*/
bool *max_volumen(const intervalo_t *intervalos, uint n){

//    printf("llego  \r\n");
    intervalo_t_des *arreglo = copiar_estructura(intervalos,n);
    mergeSort(arreglo,0,n-1);

    uint *tabla = new uint[n];
    bool* booleanos = new bool[n];

    tabla[0] = arreglo[0].volumen;
    for (uint i=1; i<n; i++)
    {
        booleanos[i] = false;

        uint elvolumen = arreglo[i].volumen;

        // calculo p(j)
        int pj = p(arreglo, i);
        elvolumen += (pj != -1)?tabla[pj]:0;

        // guardo los valores en la tabla de acuerdo a cual es el maximo
        if (elvolumen > tabla[i-1])
            tabla[i] = elvolumen;
        else
            tabla[i] = tabla[i-1];
    }


    // Idea extraida de Open Fing
    uint j = n-1;
    while (j > 0){
        uint incluir = arreglo[j].volumen;
        int pij = p(arreglo,j);
        uint pj = pij==-1?0:tabla[pij];
        incluir += pj;
//        cout << "valor para " << j << " es " << (incluir > tabla[n-1]-arreglo[j].volumen) << " pos real " << arreglo[j].pos_real << endl;
        if (incluir > tabla[j-1]){
            booleanos[arreglo[j].pos_real] = true;
            j = pij==-1?0:pij;
        }else
            j--;
    }

    uint suma = 0;
    booleanos[0] = false;
//    cout << "suma: " << endl;
    for (uint i=0; i<n; i++){
        suma += booleanos[arreglo[i].pos_real]?intervalos[arreglo[i].pos_real].volumen:0;
    }
//    cout << "res : " << arreglo[0].pos_real << endl;
    booleanos[arreglo[0].pos_real] = suma < tabla[n-1];
//    cout << "suma: " << suma << endl;


//    imprimir4(arreglo,n);
//    cout << "resultado: " << tabla[n-1] << endl;
//    uint resultado = tabla[n-1];

    delete[] tabla;
    delete[] arreglo;

    return booleanos;

};
/*47158014 */

#include <string.h>
#include <stdio.h>
#include "include/intervalos.h"
#include<iostream>
using namespace std;
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
  // fin > inicio
  intervalo_t* intervalo;
  uint pos_real;
};

void mergeSort(intervalo_t_des arr[], uint l, uint r){

    if (l < r){
        uint m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m +1, r);

        uint i, j, k;
        uint n1 = m - l + 1;
        uint n2 =  r - m;

        /* create temp arrays */
        intervalo_t_des* L= new intervalo_t_des[n1];
        intervalo_t_des* R = new intervalo_t_des[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i].intervalo->fin <= R[j].intervalo->fin)
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
    }
}

/* Devuelve un arreglo de booleanos de 'n' con TRUE en los intervalos asignados
   los cuales no se superponen. O sea son compatibles.
   La cantidad de intervalos asignados debe ser la máxima posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
   El tiempo de ejecucion de peor caso debe ser O(n*log(n)).
*/

bool *max_cantidad(const intervalo_t *intervalos, uint n){
    intervalo_t_des *intervalos_temp = new intervalo_t_des[n+1];
    for (uint i = 0; i<n; i++){
        *intervalos_temp[i].intervalo = intervalos[i];
        intervalos_temp[i].pos_real = i;
        cout << "llego: " << i << " << asd";
    }
    mergeSort(intervalos_temp,0,n-1);
    bool *booleanos = new bool[n+1];
//    uint ultimo = intervalos_temp[0].intervalo->fin;
    booleanos[intervalos_temp[0].pos_real] = true;
    for (uint i = 1; i<n; i++){
        uint prox_inicio = intervalos_temp[i].intervalo->inicio;
        if (intervalos_temp[i].intervalo->fin > prox_inicio)
            booleanos[intervalos_temp[i].pos_real] = false;
        else
            booleanos[intervalos_temp[i].pos_real] = true;
    }
    delete[] intervalos_temp;
    return booleanos;
};

/* Devuelve un arreglo de booleanos de 'n' con TRUE en los intervalos asignados
   los cuales no se superponen.
   La suma de los volumenes de los intervalos asignados debe ser la máxima
   posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
    El tiempo de ejecucion de peor caso debe ser O(n*log(n)).
*/
bool *max_volumen(const intervalo_t *intervalos, uint n){
/*

    OPT(0) = 0;
    OPT(1) = intervalo[1].volumen;
    OPT(i) = max { OPT(i-1) + intervalo[i].volumen, OPT(i-1) }

*/

return new bool;

};


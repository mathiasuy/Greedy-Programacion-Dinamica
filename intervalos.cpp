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

/*
  Devuelve una copia de 'intervalos'.
 */
intervalo_t_des *copiar_estructura(intervalo_t *intervalos, uint cant_intervalos) {
  intervalo_t_des *copia = new intervalo_t_des[cant_intervalos];
  for (uint i = 0; i < cant_intervalos; i++){
    copia[i].intervalo = intervalos[i];
    copia[i].pos_real = i;
  }
  return copia;
}
/* Devuelve un arreglo de booleanos de 'n' con TRUE en los intervalos asignados
   los cuales no se superponen. O sea son compatibles.
   La cantidad de intervalos asignados debe ser la máxima posible.
   'intervalos' es un arreglo con 'n' intervalo_t.
   El tiempo de ejecucion de peor caso debe ser O(n*log(n)).
*/

bool *max_cantidad(const intervalo_t *intervalos, uint n){
    intervalo_t_des *intervalos_temp = copiar_estructura(intervalos,n);
    mergeSort(intervalos_temp,0,n-1);
    bool *booleanos = new bool[n];
    uint tomado = n-1;
    booleanos[intervalos_temp[tomado].pos_real] = true;
    for (uint i = n-2; i<n; i++){
        uint inicio_del_actual = intervalos_temp[tomado].intervalo->inicio;
        uint final_del_anterior = intervalos_temp[i].intervalo->fin;
        bool seSolapa = final_del_anterior > inicio_del_actual;
        booleanos[intervalos_temp[i].pos_real] = !seSolapa;
        if (!seSolapa){
            tomado = i;
        }
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



    mergeSort()
/*

    OPT(0) = 0;
    OPT(1) = intervalo[1].volumen;
    OPT(i) = max { OPT(i-1) + intervalo[i].volumen, OPT(i-1) }

*/

return new bool;

};


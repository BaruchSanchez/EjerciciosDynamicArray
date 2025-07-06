// DynamicArray.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main()
{
    //aqui creamos el arreglo dinamico de enteros
    Arreglo<int> numeros;

    //llenamos nuestro arreglo con valores 
    numeros.push_back(1);
    numeros.push_back(2);
    numeros.push_back(3);

    //quitamos el ultimo 
    numeros.pop_back();

    //lo llenamos con mas valores
    numeros.push_back(4);
    numeros.push_back(5);

    //aqui ajustamos la memoria al tamaño actual
    numeros.shrink_to_fit();

    //si esta activado, nos dice cuantas copias se hicieron
#if COUNT_DYNAMIC_ARRAY_COPIES
    cout << "Numero de copias: " << numeros.NumCop() << endl;
#endif

    return 0;
}
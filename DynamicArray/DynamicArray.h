#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

//aqui se ejecuta o no el contador de copias
#define COUNT_DYNAMIC_ARRAY_COPIES 1

template <typename T>
class Arreglo
{
private:
    T* datos;
    int tam;
    int capacidad;

#if COUNT_DYNAMIC_ARRAY_COPIES
    int copyCounter = 0; //cuenta cuantas copias  se hace en el resize
#endif

public:
    Arreglo()
    {
        capacidad = 10;
        tam = 0;
        datos = new T[capacidad];
    }

    ~Arreglo()
    {
        delete[] datos;
    }

    //funcion para agregar un elemento al final 
    void push_back(T valor)
    {   
        //si ya no hay espacio se duplica el tamaño
        if (tam == capacidad)
        {
            capacidad *= 2;
            T* nuevo = new T[capacidad];

            // se copian todos los elementos al arreglo
            for (int i = 0; i < tam; i++)
            {
                nuevo[i] = datos[i];
#if COUNT_DYNAMIC_ARRAY_COPIES
                copyCounter++;
#endif
            }

            delete[] datos;
            datos = nuevo;
        }

        datos[tam] = valor;
        tam++;
    }

    // funcion para eliminar el ultimo elemento
    void pop_back()
    {
        if (tam > 0)
        {
            tam--;
        }
    }

    //Funcion para ajustar la capacidad del arreglo con el tamaño actual
    void shrink_to_fit()
    {
        if (capacidad > tam)
        {
            T* nuevo = new T[tam];

            for (int i = 0; i < tam; i++)
            {
                nuevo[i] = datos[i];
#if COUNT_DYNAMIC_ARRAY_COPIES
                copyCounter++;
#endif
            }

            delete[] datos;
            datos = nuevo;
            capacidad = tam;
        }
    }

    //etse operaor es para al arreglo como si fuera un arreglo normal 
    T& operator[](int i)
    {
        return datos[i];
    }

    // nos devuelve la cantidad de elementos que tiene el arreglo
    int ObtenerTam()
    {
        return tam;
    }

#if COUNT_DYNAMIC_ARRAY_COPIES

    //si esta activo devuelve cuantas copias se hicieron 
    int NumCop() const
    {
        return copyCounter;
    }
#endif
};

#endif
#include <iostream>
#include <thread>
#include <stdio.h>
#include <chrono>
#include "string"
using namespace std;

int lista[500000];   //creamos nuetra lista de 500 mil elementos como variable global

void PotenciasUnHilo( )  //función para obtener el cuadrado de los 500mil elementos de la lista
{
    for(int i=0; i<=500000; i++)
    {
        lista[i]= i*i;
        cout<<lista[i]<<endl;
    }
}

// las siguientes 4 funciones corresponden a la ejecución de la potencia de 125000 datos por cada hilo
void PotHilo1()
{
    for(int i=0; i<=125000; i++)
    {
        lista[i]= i*i;
        cout<<lista[i]<<endl;
    }
}
void PotHilo2()
{
    for(int i=125001; i<=250000; i++)
    {
        lista[i]= i*i;
        cout<<lista[i]<<endl;
    }
}
void PotHilo3()
{
    for(int i=250001; i<=375000; i++)
    {
        lista[i]= i*i;
        cout<<lista[i]<<endl;
    }
}
void PotHilo4()
{
    for(int i=375001; i<=500000; i++)
    {
        lista[i]= i*i;
        cout<<lista[i]<<endl;
    }
}

int main() {
   chrono::steady_clock UnHilo;      //se define el cronómetro para el recorrido con un hilo
   auto start = UnHilo.now();        // inicio del cronómetro
   std::thread t1(PotenciasUnHilo);  //ejecuta el recorrido con un hilo
   t1.join();
   auto end = UnHilo.now();       // final del cronómetro
   auto time_span = static_cast<chrono::duration<double>>(end - start);   // mide el tiempo en segundos entre el inicio y final del cronómetro
   cout<<"Tiempo de ejecucion: "<<time_span.count()<<" s";

   /*chrono::steady_clock CuatroHilos;   //se define el cronómetro para el recorrido con 4 hilos
   auto start = CuatroHilos.now();    // inicio del cronómetro

   std::thread t2(PotHilo1);        //las siguientes 4 lineas corresponden a la ejecución del recorrido con 4 hilos (un hilo por linea)
   std::thread t3(PotHilo2);
   std::thread t4(PotHilo3);
   std::thread t5(PotHilo4);
   t2.join(), t3.join(),t4.join(),t5.join();


   auto end = CuatroHilos.now();      // final del cronómetro
   auto time_span = static_cast<chrono::duration<double>>(end - start);   // mide el tiempo en segundos entre el inicio y final del cronómetro
   cout<<"Tiempo de ejecucion: "<<time_span.count()<<" s";*/


    return 0;
}
#ifndef Estructuras_H
#define Estructuras_H

// DEFINIR ARCHIVOS Y ESTRUCTURAS XD
#include <iostream>

using namespace std;

// DECLARAR EL ARCHIVO
const char * nombre_archivo = "archivo.dat";

// DONDE SE ALMACENARA LO ELIMINADO
const char * nombre_archivo_temp = "archivo_temp.dat";


// DECLARAR LA ESTRUCTURA
struct Traductor{
    char palabras[20];
    char traduccion[35];
    char funcionalidad[250];
};

#endif

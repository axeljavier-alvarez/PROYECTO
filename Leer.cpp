#include <iostream>
#include <stdio.h>
#include "Estructuras.cpp" 

using namespace std;

// FUNCION LEER
void Leer(){
	system("cls");
		// rb abre fichero para lectura
	FILE * archivo = fopen(nombre_archivo, "rb");
	
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	
	Traductor traductor;
	// Determinan el indice o la posicion donde esta el registro
	int id=0;
	// leer lo que esta en el archivo
	fread(&traductor,sizeof(Traductor), 1, archivo);
	cout<<"___________________________"<<endl;
	cout<<"ID "<<"|"<<"    Palabra   "<<"|"<<"  Traduccion  "
	<<"|"<<"      Funcionalidad      "<<endl;
	do{
		
	    cout<<id<<"  |   "<<traductor.palabras<<"   |   "<<traductor.traduccion
		<<"    |     "<<traductor.funcionalidad<<endl;
		// ir aumentando con este operador xd
		
		// IR CAMBIANDO DE REGISTRO
		fread(&traductor,sizeof(Traductor), 1, archivo);

		id+=1;
				// feof hasta el final del registro de los archivos

	}while(feof(archivo)==0);
	
	// cerrar ese archivo de lectura xd
	fclose(archivo);
}

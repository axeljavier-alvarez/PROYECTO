#include <iostream>
#include <stdio.h>
#include "Estructuras.cpp" 

using namespace std;
 void Actualizar(){
	FILE * archivo = fopen(nombre_archivo, "r+b"); // Lectura o escritura de un archivo binario.
	Traductor traductor;
	int id=0;
	Leer();
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
    fseek(archivo,id * sizeof(Traductor),SEEK_SET); // Posición en una linea especificamente.
	
		cout<<"Ingrese la Palabra: ";
		cin>>traductor.palabras;
		cin.ignore();
		
		cout<<"Ingrese la traduccion de la palabra: ";
		cin.getline(traductor.traduccion, 35);
		
		cout<<"Ingrese su funcionalidad: ";
		cin.getline(traductor.funcionalidad, 250);
		
		fwrite(&traductor,sizeof(Traductor), 1, archivo);
		
	fclose(archivo);
	Leer();
}

#include <iostream>
#include <stdio.h>
#include "Estructuras.cpp"

using namespace std;

void Crear(){
	// abre o crear un fichero binario
	// abrir el archivo
	FILE * archivo = fopen(nombre_archivo, "a+b");
	char res;
	// declarar
	Traductor traductor;
		
	do{
		// Limpiar el flujo del archivo
		fflush(stdin);
		
		// necesitamos el get de todo
		cout<<"Ingrese la Palabra: ";
		cin.getline(traductor.palabras, 20);
		
		cout<<"Ingrese la traduccion de la palabra: ";
		cin.getline(traductor.traduccion, 35);
		
		cout<<"Ingrese su funcionalidad: ";
		cin.getline(traductor.funcionalidad, 250);
		
		// tenemos que escribir los registros
		// bandera default 1
		fwrite(&traductor,sizeof(Traductor), 1, archivo);
		
		cout<<"Desea ingresar otra palabra(s/n): ";
		cin>>res;
		
	}while(res=='s' || res=='S');
	// cerrar el archivo
	fclose(archivo);
	
	
	// mandar a llamar a leer
	Leer();
} 

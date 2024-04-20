#include <iostream>
#include <stdio.h>
#include "Estructuras.cpp"

using namespace std;

void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE * archivo_temp = fopen(nombre_archivo_temp, "w+b");
	FILE * archivo = fopen(nombre_archivo, "rb");
	Traductor traductor;
	
	int id=0,id_n=0;
	Leer();
	cout<<"Ingrese el ID a eliminar: ";
	cin>>id;
	
	while(fread(&traductor,sizeof(Traductor), 1, archivo)){
	    	if (id_n!=id){
	    		fwrite(&traductor,sizeof(Traductor), 1, archivo_temp);
	    }
	    id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp, "rb");
	archivo = fopen(nombre_archivo, "wb");
	
	while(fread(&traductor,sizeof(Traductor), 1, archivo_temp)){
		fwrite(&traductor,sizeof(Traductor), 1, archivo);
}
	fclose(archivo);
	fclose(archivo_temp);
	Leer();
}

// REALIZADO POR GRUPO 2
// AXEL, PAULA, HENRY, ERICK
#include <iostream>
using namespace std;

// nombre del archivo no cambia en la variable
// forma dinamica no sera tamaño fijo sino puntero

const char * nombre_archivo = "archivo.dat";

struct Traductor{
	char palabras[20];
	char traduccion[35];
	char funcionalidad[250];
};

/* DECLARAR LOS METODOS LEER, CREAR, ACTUALIZAR Y BORRAR*/
// metodo de leer
void Leer();
// metodo de crear
void Crear();
void Actualizar(); //Metodo Actualizar.
// void Borrar(); //Metodo Borrar.

// MENU CON LAS OPCIONES ORDENADAS
main(){
	int opcion;
     char resp;
    do {
        cout << "\n\n\t\t\tMENU DE OPCIONES" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Leer listado de palabras"<<endl;
        cout << "\n\t2. Agregar nueva palabra al listado"<<endl;
        cout << "\n\t3. Actualizar palabras"<<endl;
        cout << "\n\t4. Borrar palabras"<<endl;
        cout << "\n\t0. Salir"<<endl;
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                Leer();
                break;
            case 2:
                Crear();
                break;
            case 3:
                Actualizar();
                break;
            case 4:
                // Borrar();
                break;
            case 0:
                cout << "Ha salido del programa";
                return 0;
            default:
                cout << "Opcion invalida, ingrese de nuevo";
                break;
        }
        
        cout << "\n\nDesea continuar (S/N)? "; // Ask the user if they want to continue
        cin >> resp;

    } while (resp == 's' || resp == 'S');
    
    
    return 0;
}

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

 void Actualizar(){
	FILE * archivo = fopen(nombre_archivo, "r+b"); // Lectura o escritura de un archivo binario.
	Traductor traductor;
	int id=0;
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


/* void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE * archivo_temp = fopen(nombre_archivo_temp, "w+b");
	FILE * archivo = fopen(nombre_archivo, "rb");
	Traductor traductor;
	
	int id=0,id_n=0;
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
} */






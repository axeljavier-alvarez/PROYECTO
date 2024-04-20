// REALIZADO POR GRUPO 2
// AXEL, PAULA, HENRY, ERICK
#include <iostream>
#include "Leer.cpp" 
#include "Crear.cpp"
#include "Borrar.cpp"
using namespace std;


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
               // Actualizar();
                break;
            case 4:
               Borrar();
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



/* void Actualizar(){
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
} */



#include <iostream>

using namespace::std;

struct nodo {
	int proceso;
	int prioridad;
	nodo* sig;
} *cabeza, *cola;

void inser_proc();
void mostrar_lista();
void procesar();


int main() {
	
	int menu_prin = 0;
	
	while ( menu_prin != 4 ){
	
	cout << "\n\nIngrese el numero correspondiente a la accion que desea realizar: \n\n";
	cout << "1). Agregar un nuevo proceso.\n"; 
	cout << "2). Atender proceso.\n";
	cout << "3). Mostrar los valores ingresados en lista.\n";
	cout << "4). Salir del programa.\n\n";
	
	cin >> menu_prin;
	
		switch (menu_prin){
		
			case 1:
				inser_proc();

			break;
			
			case 2:
				procesar();
			break;
			
			case 3:
				mostrar_lista();
			break;
			
			case 4:
				cout << "\nPrograma terminado.\n\n";
			break;
			
			default:
				cout << "\nOpcion invalida. Intente nuevamente.\n\n";
			break;
		}	
	}

    return 0;
}


void inser_proc() {
    
    nodo* nuevo = new nodo();
    cout << "Ingrese el numero correspondiente al proceso ";
    cin >> nuevo->proceso;

    cout << "Ingrese la prioridad de este proceso: ";
    cin >> nuevo->prioridad;

    if (cabeza == NULL) {
        cabeza = nuevo;
        cabeza->sig = cabeza;
        cola = nuevo; 
    } else {
        if (nuevo->prioridad < cabeza->prioridad) {
            nuevo->sig = cabeza;
            cabeza = nuevo;
        } else {
            nodo* actual = cabeza;
            nodo* actual_s = cabeza->sig;
            while (actual_s != cabeza && actual_s->prioridad <= nuevo->prioridad) {
                actual = actual->sig;
                actual_s = actual_s->sig;
            }
            actual->sig = nuevo;
            nuevo->sig = actual_s;
            if (actual_s == cabeza) {
                cola = nuevo;
            }
        }
    }
	cout << "\n\nNumero ingresado a la lista.\n\n";
}
	
void procesar(){
	if (cabeza != NULL) {
        cout << "\n\nSe ha atendido el proceso " << cabeza->proceso << " de prioridad " << cabeza->prioridad << "\n\n";

        nodo* temp = cabeza;
        cabeza = cabeza->sig; 
        cola->sig = cabeza; 

        delete temp; 
        
    } else {
    	
        cout << "\n\nNo hay procesos para atender.\n\n";
    
	}
}
		
	
void mostrar_lista(){
	
	nodo* actual = cabeza;
	
	if (cabeza != NULL){
		
		cout << "Proceso | Prioridad" << endl;
	
		do {
		
			cout << "   " << actual->proceso << "  |  " << actual->prioridad << endl;
			actual = actual->sig;
		
		} while ( actual != cabeza);

	} else {
			
		cout << "\n\nNo ha insertado ningun numero aun.\n\n";
			
	}	
}




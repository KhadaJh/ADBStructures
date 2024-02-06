#include <iostream>
#include <cstdlib>

int main () {
	
	int contin = 1;
	float num = 0;
	float max = 0;
	float min = 0;
	float prom = 0;
	int cont = -1;
	float sum = 0;
	
	std::cout << "Bienvenido. \nEl siguiente programa le pedira que ingrese una cantidad de numeros de su preferencia y al final mostrara el mayor, el menor y el promedio de la suma de todos los numeros que ingrese. \n \n";
	
	while (contin == 1) {
		
		
		std::cout << "Escriba el numero correspondiente a la accion que desee realizar.\n";
		std::cout << "1).Ingresar un nuevo numero.\n"	;
		std::cout << "0).Terminar proceso.\n";
		
		std::cin >> contin;
		
		if (contin == 1) {
		
			std::cout << "Ingresa el nuevo numero: \n";
			std::cin >> num;
			
			
			if (cont == -1){
				min = num;
				max = num;
			}
			
			if (num < min) {
				min = num;
			}
			
			if (num > max) {
				max = num;
			}
			
			sum = sum + num;
			
		}
		
		if (contin != 1 && contin != 0) {
			std::cout << "El numero ingresado no esta en las opciones. Intente otra vez. \n";
			contin = 1;
		}  
		
		cont = cont + 1;

		
		} 
		
		system ("cls");
		
		std::cout << "Ha elegido terminar el proceso\n \n";

		if (cont > 0){
			prom = sum / cont;
			
			std::cout << "Ha ingresado "<< cont << " numeros.\n";
			std::cout << "El numero menor que ha ingresado es: "<< min << ". \n";
			std::cout << "El numero mayor que ha ingresado es: "<< max << ". \n";
			std::cout << "El promedio de la suma de todos los numeros que ha ingresado es: "<< prom << ".\n" ;

		} else {
			
			std::cout << "No ingreso ningun numero, no hay resultados para mostrar.";
		}
		
		return 0;
	}


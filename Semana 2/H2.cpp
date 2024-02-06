#include <iostream>
#include <cstdlib>

int main () {

	float num_list [6] [7] ;
	float min_max [2] [7] ;
	float prom_mat [2] [7] ;
	
	std::cout << "En este programa va a llenar un total de 42 numeros de su preferencia ordenados en una matriz de 6 filas y 7 columnas. \nAl final se le mostrara el numero mayor, menor y promedio de cada fila y cada columna. \nTambien se le mostrara la matriz de manera organizada.\n ";
	
	for (int i = 0; i<6; ++i){ //con este for se recolectan los datos para la matriz
		
		for (int j = 0; j < 7; ++j) {
			
			std::cout << "\nIngrese el numero de la fila #"<< i+1 << " correspondiente a la columna #" << j+1 << ":\n";
			std::cin >> num_list [i] [j] ;

		} 
	}
	
	
	system ("cls");

	std::cout << "La siguiente es la matriz en la cual ha ingresado los numeros: \n \n";

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            std::cout << num_list[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    
	std::cout << "\n\n";

	//Mayores
	
	for (int i = 0; i < 6; ++i) {
		
        int max_fila = num_list[i][0];
        
        for (int j = 1; j < 7; ++j) {
            if (num_list[i][j] > max_fila) {
                max_fila = num_list[i][j];
            }
        }
        min_max[0][i] = max_fila;
    }
    
    for (int j = 0; j < 7; ++j) {
		
        int max_fila = num_list[0][j];
        
        for (int i = 1; i < 6; ++i) {
            if (num_list[i][j] > max_fila) {
                max_fila = num_list[i][j];
            }
        }
        min_max[1][j] = max_fila;
    }

	std::cout << "La siguiente es una matriz 2*7 en la cual se organizan los numeros mayores de cada fila y columna, donde la primera fila es para los mayores de las 6 filas y la segunda fila contiene los mayores de cada columna de las 7 en total. \n\n" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!(i == 0 && j == 6)){
			std::cout << min_max[i][j] << " ";
        	}
        }
        std::cout << std::endl;
    }
	
	
	
	//Menores
	
	for (int i = 0; i < 6; ++i) {
		
        int max_fila = num_list[i][0];
        
        for (int j = 1; j < 7; ++j) {
            if (num_list[i][j] < max_fila) {
                max_fila = num_list[i][j];
            }
        }
        min_max[0][i] = max_fila;
    }
    
    for (int j = 0; j < 7; ++j) {
		
        int max_fila = num_list[0][j];
        
        for (int i = 1; i < 6; ++i) {
            if (num_list[i][j] < max_fila) {
                max_fila = num_list[i][j];
            }
        }
        min_max[1][j] = max_fila;
    }
	
	
	std::cout << "\n\n";
	std::cout << "La siguiente es una matriz 2*7 en la cual se organizan los numeros menores de cada fila y columna, donde la primera fila es para los menores de las 6 filas y la segunda fila contiene los menores de cada columna de las 7 en total. \n\n" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!(i == 0 && j == 6)){
			std::cout << min_max[i][j] << " ";
        	}
		}
        std::cout << std::endl;
    }
    
    //Promedio
    
    
    //promedio filas
    
    for (int i = 0; i < 6; ++i) {
    	float sum = 0;
    	for (int j = 0; j < 7; ++j) {
        	sum = sum + num_list[i][j];
    	}
    	float promedio = sum / 7; // Promedio de la fila
    	prom_mat[0][i] = promedio; // Almacenar en la primera fila de prom_mat
	}

	for (int j = 0; j < 7; ++j) {
    	float sum = 0;
    	for (int i = 0; i < 6; ++i) {
        	sum = sum + num_list[i][j];
    	}
    	float promedio = sum / 6; // Promedio de la columna
    	prom_mat[1][j] = promedio; // Almacenar en la segunda fila de prom_mat
	}
    
    std::cout << "\n\n";
	std::cout << "La siguiente es una matriz 2*7 en la cual se muestra el promedio de cada fila y columna, siendo la fila #1 para las 6 filas y la fila #2 para las columnas. \n\n" << std::endl;
	
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!(i == 0 && j == 6)){
			std::cout << prom_mat[i][j] << " ";
        	}
		}
        std::cout << std::endl;
    }
    
    return 0;

}

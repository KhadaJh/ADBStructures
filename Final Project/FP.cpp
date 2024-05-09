#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <ctime>

using namespace::std;

struct nodo {
	string TeamName;
	string TeamPlayers [11];
	
	nodo* der;
	nodo* izq;
	
};

void InsTeams();
void simgame(bool y);

class teams{

private:
	nodo* raiz;

public:
	empty();
	void InsTeams() {
	
		nodo* newteam = new nodo();
	
	
	}
};


int main() {
		
    std::ifstream archivo("archivo.txt");
    std::string texto1;
    std::string texto2 [11];

    if (archivo.is_open()) {

        archivo >> texto1;
        
       	for ( int i=0 ; i<11 ; i++ ){
       		
       		archivo >> texto2 [i];
       		
		}
		

        archivo.close();

        std::cout << "Texto 1: " << texto1 << std::endl;
        
        for ( int i=0 ; i<11 ; i++ ){
        	
        std::cout << "\nTexto 2: " << texto2[i] << std::endl;
        
    	}
    	
    	
    } else {
        std::cerr << "No se pudo abrir el archivo.\n";
    }

    return 0;
}




void simgame(bool y){

	//Se establece el srand para tener numeros aleatorios dependiendo de la hora, y variables que se se usaran mas adelante pero se mantendran estaticas hasta que se usen

	srand((unsigned)time(0));
	int s=0, m=0, gol1= 0, gol2= 0, OT=1;
	bool x = true;
	double prob1 = 0.000238 * 3, prob2 = 0.000132 * 3, golprob1, golprob2;
	
	while (x == true){
		
		if ( y == true ) {	

		s = s + 3;
		
		if (golprob1 < prob1 && golprob2 < prob2) {
				
		} else {
				
			if (golprob1 < prob1) {
				
				gol1 ++;
					
			}

			if (golprob2 < prob2) {
				
				gol2 ++;
					
			}
				
		}

		golprob1 = static_cast<double>(rand()) / RAND_MAX;
    	golprob2 = static_cast<double>(rand()) / RAND_MAX;
    	
    	if (s>=60){
			
			s=0;
			m++;
		}
		
		if (m>=90){
			
			x = false;	
		}
    	
    	} else {
		
    	s = s + 3;
		
		Sleep(1);		

		if (golprob1 < prob1 && golprob2 < prob2) {
				
		} else {
				
			if (golprob1 < prob1) {
				
				gol1 ++;
					
			}

			if (golprob2 < prob2) {
				
				gol2 ++;
					
			}
				
		}

		golprob1 = static_cast<double>(rand()) / RAND_MAX;
    	golprob2 = static_cast<double>(rand()) / RAND_MAX;
    	
    	if (s>=60){
			
			s=0;
			m++;
		}
		cout << "\033[F\033[K";
		cout <<"          "<< m << ":" << s ;
		cout << "\nColombia: " << gol1 << "  " << gol2 << " :Brasil";
				

		if (m>=90){
			
			x = false;
			
			Sleep(5000);
			
		}
    		
		}
		
	}


	system ("cls");
	
	for (int i = 0 ; i < 50 ; i++){
	
		if ( y == true ) {
			
			OT = rand()% 5 + 1;
		} else {
			
			OT = rand()% 5 + 1;
			cout << "\033[F\033[K";
			cout <<"Tiempo extra: " << OT;
			Sleep(1);
		}
	} 
	
	if ( y == false){
		
		Sleep(5000);
	}
	
	OT= OT+90;
	x = true;
	
	prob1 = prob1 * 2;	
	prob2 = prob2 * 2;	
	
	while (x == true){
	
		if ( y == true ) {
			
			s = s + 3;

			golprob1 = static_cast<double>(rand()) / RAND_MAX;
    		golprob2 = static_cast<double>(rand()) / RAND_MAX;
		
			if (golprob1 < prob1 && golprob2 < prob2) {
				
			} else {
				
					if (golprob1 < prob1) {
				
						gol1 ++;
					} if (golprob2 < prob2) {
				
						gol2 ++;
					}
			}
		
			if (s>=60){
			
					s=0;
					m++;
			}
		
			if (m>=OT ){
			
				if (gol1 == gol2){
	
					golprob1 = static_cast<double>(rand()) / RAND_MAX;

						if ( golprob1 > 0.5 ) {
		
							gol1++;
						} else {
			
							gol2++;
						}
				}
		
			x = false;
			}		
			
		} else {
	
		s = s + 3;
		Sleep(1);		

		golprob1 = static_cast<double>(rand()) / RAND_MAX;
    	golprob2 = static_cast<double>(rand()) / RAND_MAX;
		
		if (golprob1 < prob1 && golprob2 < prob2) {
				
		} else {
				
			if (golprob1 < prob1) {
				
				gol1 ++;
					
			}

			if (golprob2 < prob2) {
				
				gol2 ++;
					
			}
				
		}
		
		if (s==60){
			
			s=0;
			m++;
		}
		
		cout << "\033[F\033[K";
		cout <<"          "<< m << ":" << s ;
		cout << "\nColombia: " << gol1 << "  " << gol2 << " :Brasil";
		
		if (m==OT ){
			
			if (gol1 == gol2){
	
				golprob1 = static_cast<double>(rand()) / RAND_MAX;

					if ( golprob1 > 0.5 ) {
		
						gol1++;
					} else {
			
						gol2++;
					}
					
				cout << "\033[F\033[K";
				cout <<"          "<< m << ":0";
				cout << "\nColombia: " << gol1 << "  " << gol2 << " :Brasil";
				
			}
		
			x = false;
		}
		
		}
	}
	
	if ( y == true ){
	
		system("cls");
		cout <<"Simulacion finalizada";
		cout << "\nColombia: " << gol1 << "  " << gol2 << " :Brasil";
	} else {

		Sleep(5000);
		system("cls");
		cout <<"Simulacion finalizada";
		cout << "\nColombia: " << gol1 << "  " << gol2 << " :Brasil";
		
	}
}

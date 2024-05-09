#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct nodo {
    string TeamName;
    string TeamPlayers[11];
    double probgol;
    nodo* der;
    nodo* izq;
    
    nodo(string nombre, string jugadores[], double probabilidad) : TeamName(nombre), probgol(probabilidad) {
        for (int i = 0; i < 11; ++i) {
            TeamPlayers[i] = jugadores[i];
        }
        izq = NULL;
        der = NULL;
    }
};

class teams {
private:
    nodo* raiz;

public:
    teams() : raiz(NULL) {}

    void insert(string texto1, string texto2[], double probgol) {
        int insertado = 0; 
        raiz = resurInsert(raiz, texto1, texto2, probgol, 1, insertado);
    }

    nodo* resurInsert(nodo* actual, string texto1, string texto2[], double probgol, int level, int& insertado) {
    if (actual == NULL) {
        if (level == 5 && insertado == 0) {
            insertado = 1;
            return new nodo(texto1, texto2, probgol);
        }
        return NULL;
    }

    if (level < 5) {
        actual->izq = resurInsert(actual->izq, texto1, texto2, probgol, level + 1, insertado);
        actual->der = resurInsert(actual->der, texto1, texto2, probgol, level + 1, insertado);
    }

    return actual;
}
    
    
    void mostrar(nodo* actual, int lvl) {
     	
		if(lvl < 5){
		 
        mostrar(actual->izq,lvl+1);
  		mostrar(actual->der,lvl+1);
		} else if (lvl == 5){
			
        std::cout << actual->TeamName << " ";
        return;
       	}
    }

    void mostrar() {
        mostrar(raiz, 1);
    }
};

int main() {
    std::ifstream archivo("archivo.txt");
	std::string texto1;
    std::string texto2[11];
    double probgol;	
    teams miteams;


    if (archivo.is_open()) {
    

    for (int i = 0; i < 16; i++) {
    	
        archivo >> texto1;
        for (int j = 0; j < 11; j++) {
        
		    archivo >> texto2[j];
        }
        
		archivo >> probgol;
        for (int j = 0; j < 11; j++) {
        
		    std::cout << texto2[j] << "\n";
        }
        
		std::cout << probgol << "\n\n";
        miteams.insert(texto1, texto2, probgol);

    }
	}
	
	
	miteams.mostrar();
	
    archivo.close();

    return 0;
}


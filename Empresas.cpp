#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
int main() {
	
	int datos2023[EMPRESAS][MESES];
    int datos2024[EMPRESAS][MESES];
    int datos2025[EMPRESAS][MESES];


    ifstream archivo2023("input/ingresos-2023.csv");
    ifstream archivo2024("input/ingresos-2024.csv");
    ifstream archivo2025("input/ingresos-2025.csv");

    if (!archivo2023 || !archivo2024 || !archivo2025)
    {
        cout << "Error al abrir los archivos de entrada." << endl;
        return 1;
    }

    string linea, dato;	
	
}

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
    
     for (int i = 0; i < EMPRESAS; i++)
    {
        getline(archivo2023, linea);
        stringstream ss(linea);

        for (int j = 0; j < MESES; j++)
        {
            getline(ss, dato, ',');
            datos2023[i][j] = stoi(dato);
        }
    }


    for (int i = 0; i < EMPRESAS; i++)
    {
        getline(archivo2024, linea);
        stringstream ss(linea);

        for (int j = 0; j < MESES; j++)
        {
            getline(ss, dato, ',');
            datos2024[i][j] = stoi(dato);
        }
    }


    for (int i = 0; i < EMPRESAS; i++)
    {
        getline(archivo2025, linea);
        stringstream ss(linea);

        for (int j = 0; j < MESES; j++)
        {
            getline(ss, dato, ',');
            datos2025[i][j] = stoi(dato);
        }
    }

    archivo2023.close();
    archivo2024.close();
    archivo2025.close();
	
}

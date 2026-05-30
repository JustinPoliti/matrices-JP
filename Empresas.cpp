#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int EMPRESAS = 5;
const int MESES = 12;

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
    
    ofstream resultado("output/resultado.csv");

    if (!resultado)
    {
        cout << "Error al crear el archivo de salida." << endl;
        return 1;
    }

    resultado << "Empresa,Total 2023,Total 2024,Total 2025,Total 3 Años\n";

    for (int i = 0; i < EMPRESAS; i++)
    {
        int total2023 = 0;
        int total2024 = 0;
        int total2025 = 0;

        for (int j = 0; j < MESES; j++)
        {
            total2023 += datos2023[i][j];
            total2024 += datos2024[i][j];
            total2025 += datos2025[i][j];
        }

        int totalGeneral = total2023 + total2024 + total2025;

        resultado << "Empresa " << i + 1 << ","
                  << total2023 << ","
                  << total2024 << ","
                  << total2025 << ","
                  << totalGeneral << endl;
    }

    resultado.close();

    cout << "Proceso completado archivo generado con exito" << endl;

    return 0;
}

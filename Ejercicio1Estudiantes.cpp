#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("estudiantes.txt");

    string nombre;
    double n1, n2, n3, promedio;
    int total=0, aprobados=0;
    double suma=0;

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo";
        return 1;
    }

    while (archivo >> nombre >> n1 >> n2 >> n3) {
        promedio = (n1+n2+n3)/3.0;

        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << promedio << endl;

        if (promedio >= 9) {
            cout << "Estado: Excelente" << endl;
            aprobados++;
        }
        else if (promedio >= 7) {
            cout << "Estado: Bueno" << endl;
            aprobados++;
        }
        else {
            cout << "Estado: Reprobado" << endl;
        }

        cout << "------------------" << endl;

        suma += promedio;
        total++;
    }

    cout << "Total estudiantes: " << total << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Promedio general: " << suma/total << endl;

    archivo.close();
    return 0;
}

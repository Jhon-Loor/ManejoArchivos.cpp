#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("productos.txt");

    string nombre, productoMayor;
    double precio, subtotal, mayor = 0, total = 0;
    int cantidad;

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo";
        return 1;
    }

    while (archivo >> nombre >> precio >> cantidad) {
        subtotal = precio * cantidad;

        cout << "Producto: " << nombre << endl;
        cout << "Subtotal: " << subtotal << endl;
        cout << "------------------" << endl;

        total += subtotal;

        if (subtotal > mayor) {
            mayor = subtotal;
            productoMayor = nombre;
        }
    }

    cout << "Total general: " << total << endl;
    cout << "Producto con mayor venta: " << productoMayor << endl;

    archivo.close();
    return 0;
}


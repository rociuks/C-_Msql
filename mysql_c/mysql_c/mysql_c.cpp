// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Proveedor.h"
#include <iostream>
#include <string>
using namespace  std;

void crear();
void leer();
void actualizar();
void eliminar();

int main() {

    string proveedor, nit, direccion, telefono;
    int op = 0, op1 = 0;
    //Proveedor p = Proveedor();
    //p.leer();
    switch (op) {

    case 1: system("cls");

        cout << "*Editar Proveedores**" << endl << endl;
        cout << "Crear proveedor.......................1" << endl;
        cout << "Leer proveedor........................2" << endl;
        cout << "Actualizar proveedor..................3" << endl;
        cout << "Borrar proveedor......................4" << endl;
        cout << "Regresar.............................5" << endl << endl;
        cin >> op1;

        switch (op1) {

        case 1: crear();
            cout << "Ingrese proveedor:";
            getline(cin, proveedor);
            cout << "Ingrese nit:";
            getline(cin, nit);
            cout << "Ingrese direccion:";
            getline(cin, direccion);
            cout << "Ingrese telefono:";
            getline(cin, telefono);
            Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
            p.crear();
            system("pause");
            break;
        case 2: leer();
            cout << "Lectura de proveedor:";
            cout << "Ingrese nit:";
            getline(cin, nit);
            cout << "Ingrese direccion:";
            getline(cin, direccion);
            cout << "Ingrese telefono:";
            getline(cin, telefono);
            Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
            p.leer();
            system("pause");
            break;
        case 3: actualizar();
            cout << "Actualizacion de proveedor:";
            getline(cin, proveedor);
            cout << "Ingrese nit:";
            getline(cin, nit);
            cout << "Ingrese direccion:";
            getline(cin, direccion);
            cout << "Ingrese telefono:";
            getline(cin, telefono);
            Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
            p.actualizar();
            system("pause");
            break;
        case 4:  eliminar();
            cout << "Eliminar proveedor:";
            getline(cin, proveedor);
            cout << "Ingrese nit:";
            getline(cin, nit);
            cout << "Ingrese direccion:";
            getline(cin, direccion);
            cout << "Ingrese telefono:";
            getline(cin, telefono);
            Proveedor p = Proveedor(proveedor, nit, direccion, telefono);
            p.eliminar();
            system("pause");
            break;
        }

        return 0;
    }
}
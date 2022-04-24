#pragma once
//#include "main.h"
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>
using namespace  std;
class Proveedor {
    // atributos
private: string proveedor, nit, direccion, telefono;
       // constructor
public:
    Proveedor() {}
    Proveedor(string p, string n, string dir, string tel) {
        proveedor = p;
        nit = n;
        direccion = dir;
        telefono = tel;
    }
    void setProveedor(string p) { proveedor = p; }
    void setNit(string n) { nit = n; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(string tel) { telefono = tel; }

    //get (mostrar)
    string getProveedor() { return proveedor; }
    string getNit() { return nit; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }

    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();

        cn.abrir_conexion();

        if (cn.getConectar()) {
            string  insertar = "INSERT INTO proveedores(proveedor,nit,direccion,telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
            const char* i = insertar.c_str();
            // executar el query
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso Exitoso ..." << endl;
            }
            else {
                cout << " xxx Error al Ingresar  xxx" << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();
    }


    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();

        if (cn.getConectar()) {

            cout << "------------ Datos de los Proveedores ------------" << endl;
            string consulta = "select * from id_Proveedor";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();


    }

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();

        if (cn.getConectar()) {

            cout << "------------ Actualizar Proveedores ------------" << endl;
            string consulta = "update id_Proveedor from proveedores where id_Proveedor=0";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();


    }


    void eliminar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();

        if (cn.getConectar()) {

            cout << "------------ Eliminar datos de los Proveedores ------------" << endl;
            string consulta = "delete * from proveedores where id_Proveedor=0";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << endl;
                }
            }
            else {
                cout << " xxx Datos eliminados  xxx" << endl;
            }
        }
        else {
            cout << " xxx Error al eliminar xxxx" << endl;
        }
        cn.cerrar_conexion();
    }
};
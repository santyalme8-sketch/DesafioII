#include "udeabook.h"
#include <iostream>
#include <fstream>
bool sonCadenasIguales(const char* a, const char* b) {
    if (!a || !b) return false;
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        i++;
    }
    return a[i] == b[i];
}

UdeaBook:: UdeaBook (const char* ruta){
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo." << std::endl;
    }
    else{
    int len = 0;
    while (ruta[len] != '\0') len++;

    this->rutaArchivoUsuarios = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        this->rutaArchivoUsuarios[i] = ruta[i];
    }
    }
}
UdeaBook:: UdeaBook(){
    const char defecto[] ="Usuarios.txt";
    int len = 0;
    while (defecto[len] != '\0') len++;

    this->rutaArchivoUsuarios = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        this->rutaArchivoUsuarios[i] = defecto[i];
    }
}


bool UdeaBook:: existeUsuario(const char* nom) {
    std::ifstream archivo(this->rutaArchivoUsuarios);
    if (!archivo.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo." << std::endl;
        return false;
    }
    char linea[256];
    for (; archivo.getline(linea, sizeof(linea)); ) {
        int len = 0;
        while (linea[len] != '\0') len++;
        if (len > 0 && linea[len - 1] == '\r') {
            linea[len - 1] = '\0';
        }

        if (sonCadenasIguales(linea, nom)) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
    }




int  UdeaBook:: getContadorOperaciones() {

}

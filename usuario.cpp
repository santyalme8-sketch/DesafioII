#include "usuario.h"
#include <iostream>
#include "fstream"
#include "mensaje.h"
#include "udeabook.h"
static bool sonCadenasIguales(const char* a, const char* b) {
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
class mensaje;



Usuario::Usuario(const char* nombre){
    if (nombre != nullptr) {
        int longitud = 0;
        while (nombre[longitud] != '\0') {
            longitud++;
        }

        this->nombre = new char[longitud + 1];
        for (int i = 0; i <= longitud; i++) {
            this->nombre[i] = nombre[i];
        }
    } else {
        this->nombre = nullptr;
    }

    this->albumes = nullptr;
    this-> cantAlbumes=0;
    this-> amigos=nullptr;
    this-> cantAmigos=0;
    this-> buzon=0;
    this-> albumes=0;
}
char* Usuario::Getnombre(){
    return this->nombre;
}


void Usuario::EnviarMensaje(const char* dest, const char* texto,int& contador) {
    int lenTexto = 0;
    while (texto[lenTexto] != '\0') {
        lenTexto++;
    }

    if (lenTexto > 512) {
        std::cout << "Error: El mensaje tiene " << lenTexto
                  << " caracteres y supera el maximo permitido de 512." << std::endl;
        return;
    }


    int contadorLineas = 0;
    std::ifstream Lectura("Mensajes.txt");

    if (Lectura.is_open()) {
        char linea[512];
        while (Lectura.getline(linea, sizeof(linea))) {
            contador++;
            if (linea[0] != '\0') {
                contadorLineas++;
            }
        }
        Lectura.close();
    }

    int nuevoNumero = contadorLineas + 1;

    std::ofstream Escritura("Mensajes.txt", std::ios::out | std::ios::app);
    if (!Escritura.is_open()) {
        std::cout << "Error al abrir Mensajes.txt para guardar." << std::endl;
        return;
    }
    else{
    Escritura << nuevoNumero << "."<< this->nombre << "-"<< dest << ":"<< texto << "\n";

        Escritura.close();}
}
void Usuario::LeerMensaje(int& contador) {
    if (this->cantMensajes == 0) {
        std::cout << "No tienes mensajes en el buzon." << std::endl;
        return;
    }

    std::cout << "=== TODOS LOS MENSAJES ===" << std::endl;
    for (int i = 0; i < this->cantMensajes; i++) {
        contador++;
        std::cout << this->buzon[i].getFecha() << ". "<< "De: " << this->buzon[i].getRemitente() << " -> " << this->buzon[i].getContenido() << std::endl;
    }
}

void Usuario::LeerMensaje(int inicio, int fin,int& contador) {
    std::cout << "Mensaje desde #" << inicio << " hasta #" << fin << std::endl;
    bool encontro = false;

    for (int i = 0; i < this->cantMensajes; i++) {
        contador++;
        int orden = this->buzon[i].getFecha();

        if (orden >= inicio && orden <= fin) {
            std::cout << orden << ". "<< this->buzon[i].getRemitente() << "-"<< this->buzon[i].getDestinatario() << ": "<< this->buzon[i].getContenido() << std::endl;
            encontro = true;
        }
    }

    if (!encontro) {
        std::cout << "No hay mensajes en ese intervalo." << std::endl;
    }
}
void Usuario::LeerMensaje(const char* Remitente, int& contador) {
    bool encontro = false;
    std::cout << "=== MENSAJES DE: " << Remitente << " ===" << std::endl;

    for (int i = 0; i < this->cantMensajes; i++) {
        contador++;
        if (sonCadenasIguales(this->buzon[i].getRemitente(), Remitente)) {
            std::cout << this->buzon[i].getFecha() << ". "<< this->buzon[i].getContenido() << std::endl;
            encontro = true;
        }
    }
    if (!encontro) std::cout << "No hay mensajes de " << Remitente << "." << std::endl;
}


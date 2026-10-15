#include "usuario.h"
#include <iostream>
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
void Usuario::Getnombre(){
    std::cout<<this->nombre<<std::endl;
}




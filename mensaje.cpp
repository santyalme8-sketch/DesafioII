#include "mensaje.h"


char* copiar(const char* origen) {
    if (origen == nullptr) {
        return nullptr;
    }

    int len = 0;
    while (origen[len] != '\0') {
        len++;
    }

    char* destino = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        destino[i] = origen[i];
    }
    return destino;
}


mensaje::mensaje() {
    this->remitente = nullptr;
    this->destinatario = nullptr;
    this->contenido = nullptr;
    this->fecha = 0;
}


mensaje::mensaje(const char* rem, const char* dest, const char* cont, int fec) {
    this->remitente = copiar(rem);
    this->destinatario = copiar(dest);
    this->contenido = copiar(cont);
    this->fecha = fec;
}


mensaje::~mensaje() {
    if (this->remitente != nullptr) {
        delete[] this->remitente;
    }
    if (this->destinatario != nullptr) {
        delete[] this->destinatario;
    }
    if (this->contenido != nullptr) {
        delete[] this->contenido;
    }
}

const char* mensaje::getRemitente() const {
    return this->remitente;
}

const char* mensaje::getDestinatario() const {
    return this->destinatario;
}

const char* mensaje::getContenido() const {
    return this->contenido;
}

int mensaje::getFecha() const {
    return this->fecha;
}
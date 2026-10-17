#ifndef UDEABOOK_H
#define UDEABOOK_H

class Usuario;

class UdeaBook{
private:

char* rutaArchivoUsuarios;
Usuario* usuariosRegistrados;
int cantUsuarios;
int capacidadUsuarios=1000;
int contadorOperaciones;

public:
int& refContador();
UdeaBook (const char* ruta);
UdeaBook();

bool existeUsuario(const char* nom) ;   //No hay que garantizar que se registren los usuarios. Osea que nos ahorramos la parte de registrar a usuarios bro,twin🫩✌️


void getContadorOperaciones() ;
void reinicaroperaciones();

};


#endif

#ifndef UDEABOOK_H
#define UDEABOOK_H

class Usuario;

class UdeaBook{
private:

char* rutaArchivoUsuarios;
Usuario* usuariosRegistrados;
int cantUsuarios;
int capacidadUsuarios;
int ontadorOperaciones;
public:

UdeaBook (const char* ruta);

void registrarUsuario(const char* nom, const char* clv);

bool existeUsuario(const char* nom) ;

void cargarDesdeArchivo();

void guardarEnArchivo();

int getContadorOperaciones() ;
};

#endif

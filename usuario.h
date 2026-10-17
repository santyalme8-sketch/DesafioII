#ifndef USUARIO_H
#define USUARIO_H
class album;
class mensaje;
class Amistades;

class Usuario{
private:
    char* nombre;
    int cantAlbumes;
    char* amigos;
    int cantAmigos;
    int cantMensajes;
    mensaje* buzon;
    album* albumes;
public:
    Usuario(const char* nombre);
    char* Getnombre();
    void agregarAmigo(const char* nombreAmigo);
    void EnviarMensaje(const char* dest,const char* texto);
    void EnviarMensaje(const char* dest, const char* texto, int& contador);
    void RecibirMensaje(mensaje* nuevo);
    void CargarMensajesALArchivo(int& contador);

    void LeerMensaje(int& contador);
    void LeerMensaje(const char* Remitente, int& contador);
    void LeerMensaje(int inicio, int fin, int& contador);
    void ListarAmigos();

};

#endif // USUARIO_H

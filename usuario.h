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
    mensaje* buzon;
    album* albumes;
public:
    Usuario(const char* nombre);
    const char* Getnombre();
    void crearAlbum(const char* titulo);
    void agregarAmigo(const char* nombreAmigo);
    void EnviarMensaje(const char*,const char* texto);
    void RecibirMensaje(mensaje* nuevo);
    void CargarMensajesDesdeArchivo();
    void LeerMensaje();
    void LeerMensaje(const char* Remitente);
    void ListarAmigos();

};
#endif // USUARIO_H

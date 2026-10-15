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
    void Getnombre();
    //void crearAlbum(const char* titulo) No es necesario crear albumes, solo leerlos, osea menos trabajo por hacer
    void agregarAmigo(const char* nombreAmigo);
    void EnviarMensaje(const char* dest,const char* texto);
    void RecibirMensaje(mensaje* nuevo);
    void CargarMensajesALArchivo();
    void LeerMensaje();
    void LeerMensaje(const char* Remitente);
    void LeerMensaje(int fechaini, int fechafin);
    void ListarAmigos();

};

#endif // USUARIO_H

#include <iostream>
#include "udeabook.h"
#include "usuario.h"
#include "mensaje.h"

int main() {
    UdeaBook red("Usuarios.txt");
    if (red.existeUsuario("Bal")) {
        std::cout << "Usuario Bal . Operaciones realizadas: ";
        red.getContadorOperaciones();
    }
    if (red.existeUsuario("Zrus")) {
        std::cout << "Usuario Zrus . Operaciones acumuladas: ";
        red.getContadorOperaciones();
    }
    red.reinicaroperaciones();
    red.getContadorOperaciones();
    Usuario user1("Bal");
    std::cout << "Nombre del usuario creado: ";
    user1.Getnombre();



    return 0;
}
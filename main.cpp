#include <iostream>
#include "udeabook.h"
#include "usuario.h"
#include "mensaje.h"

int main() {
    int cerrar=1;
    do{
        int cerrar=1;
    UdeaBook red("Usuarios.txt");
    red.reinicaroperaciones();

    char nombreLogin[100]={0};
    bool sesionIniciada = false;

    std::cout << "        BIENVENIDO A UDE@BOOK           " << std::endl;


    while (!sesionIniciada) {
        std::cout << "\nIngrese su nombre de usuario para iniciar sesion: ";
        std::cin >> nombreLogin;

        if (red.existeUsuario(nombreLogin)) {
            sesionIniciada = true;
            std::cout << "\n Sesion iniciada correctamente. Hola, " << nombreLogin << "!" << std::endl;
            std::cout << " Operaciones usadas para buscarte en el archivo: ";
            red.getContadorOperaciones();
        } else {
            std::cout << "\n: El usuario '" << nombreLogin << "' no existe. Intente de nuevo." << std::endl;
        }
    }

    Usuario usuarioActual(nombreLogin);



    int opcion = -1;
    do {
        std::cout << " USUARIO ACTIVO: ";
        std::cout<<usuarioActual.Getnombre()<<"\n";
        std::cout << "1. Enviar un mensaje" << std::endl;
        std::cout << "2. Leer TODOS mis mensajes" << std::endl;
        std::cout << "3. Leer mensajes de un remitente especifico" << std::endl;
        std::cout << "4. Leer mensajes por intervalo de orden (ej. del 1 al 5)" << std::endl;
        std::cout << "5. Mostrar contador de operaciones" << std::endl;
        std::cout << "6. Reiniciar contador de operaciones a 0" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            opcion = -1;
        }

        switch (opcion) {
        case 1: {
            char destinatario[100];
            char texto[513];

            std::cout << "\nIngrese el nombre del destinatario: ";
            std::cin >> destinatario;

            if (!red.existeUsuario(destinatario)) {
                std::cout << " El  destinatario '" << destinatario << "' no esta registrado." << std::endl;
            } else {
                std::cin.ignore();
                std::cout << "Escriba su mensaje (maximo 512 caracteres): ";
                std::cin.getline(texto, 513);

                usuarioActual.EnviarMensaje(destinatario, texto, red.refContador());

                std::cout << " Mensaje enviado y guardado permanentemente." << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "\n";

            usuarioActual.LeerMensaje(red.refContador());
            break;
        }
        case 3: {
            char remitenteBuscar[100];
            std::cout << "\nIngrese el nombre del remitente a filtrar: ";
            std::cin >> remitenteBuscar;

            usuarioActual.LeerMensaje(remitenteBuscar, red.refContador());
            break;
        }
        case 4: {
            int inicio = 0, fin = 0;
            std::cout << "\nIngrese el numero de mensaje inicial: ";
            std::cin >> inicio;
            std::cout << "Ingrese el numero de mensaje final: ";
            std::cin >> fin;

            usuarioActual.LeerMensaje(inicio, fin, red.refContador());
            break;
        }
        case 5: {
            std::cout << "\n Total de operaciones acumuladas: ";
            red.getContadorOperaciones();
            break;
        }
        case 6: {
            red.reinicaroperaciones();
            std::cout << "\n El contador de operaciones se ha reiniciado a: ";
            red.getContadorOperaciones();
            break;
        }
        case 0: {
            std::cout << "\nCerrando sesion... Hasta luego!" << std::endl;
            break;
        }
        default: {
            std::cout << "\n Opcion no valida. Intente nuevamente." << std::endl;
            break;
        }
        }

    } while (opcion != 0);

    std::cout<<"Quieres inicar sesión con otro usuario o cerrar la aplicación";
        std::cout<<" selecciones 1 para iniciar sesión como otro usuario\nSelecciones 0 Para cerrar la aplicación ";
    std::cin>>cerrar;
        while(cerrar!=0 && cerrar!=1){
            std::cout<<" selecciones 1 para iniciar sesión como otro usuario\nSelecciones 0 Para cerrar la aplicación ";
            std::cin>>cerrar;
        }
    } while (cerrar!=0);
    return 0;
}
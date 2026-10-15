#ifndef MENSAJE_H
#define MENSAJE_H
class mensaje {
private:
    char* remitente;
    char* destinatario;
    char* contenido;
    int fecha;

public:
    mensaje();
    mensaje(const char* rem, const char* dest, const char* cont, int fec);

    const char* getRemitente() const;
    const char* getDestinatario() const;
    const char* getContenido() const;
    int getFecha() const;
    ~mensaje();
};
#endif

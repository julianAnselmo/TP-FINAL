#ifndef LIBRERIANAVES_H_INCLUDED
#define LIBRERIANAVES_H_INCLUDED

const char archivo [] = "nave";
typedef struct
{
    int id;
    char nave[20];
    int vuelosRealizados;
    int horasDeVuelo;
    int estado;
} nave;

nave cargarId (nave A);
void cargarNave ();
nave cargarTipo (nave B);
nave cantidadVuelos (nave C);
nave horasVuelo (nave D);
nave Estado (nave E);
void mostrarDatos();
void mostrarNave(nave F);
void darDeAlta ();
void darDeBaja();
void modificacion ();
void consultaId ();

#endif // LIBRERIANAVES_H_INCLUDED

#ifndef LIBRERIAASTRONAUTA_H_INCLUDED
#define LIBRERIAASTRONAUTA_H_INCLUDED
const char nombreArchivo[]="archivoAstronautas";

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char apodo[30];
    int edad;
    char nacionalidad[30];
    char especialidad[30];//
    int horasAcumuladas;
    //misiones
    int horasEEI;
    int estado;//1-activo/2-retirado
} stAstronauta;

void cargarAstronautas();
stAstronauta cargarIndividual(stAstronauta astronauta);
stAstronauta cargarNombre(stAstronauta astronauta);
stAstronauta cargarEdad(stAstronauta astronauta);
stAstronauta cargarNacionalidad(stAstronauta astronauta);
stAstronauta cargarEspecialidad(stAstronauta astronauta);
stAstronauta cargarHoras(stAstronauta astronauta);
stAstronauta cargarEstado(stAstronauta astronauta);
void mostrarAstronautas();
void mostrarIndividual(stAstronauta astronauta);
void darAlta();
void darBaja();
void unAstronauta();
void modificarUnAstronauta();


#endif // LIBRERIAASTRONAUTA_H_INCLUDED

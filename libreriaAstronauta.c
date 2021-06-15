#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libreriaAstronauta.h"
#include "libreriaMisiones.h"
void menuAstronauta()
{
    int opcion;
    char control='s';
    while(control=='s')
    {
        printf("\n\t\t\t\t----MENU----\n");
        printf("\n\t\tIngrese el numero de la opcion que desee\n");
        printf("\n1.Cargar astronautas");
        printf("\n2.Mostrar listado de astronautas");
        printf("\n3.Dar de alta un astronauta");
        printf("\n4.Dar de baja un astronaua");
        printf("\n5.Consultar datos de un astronauta");
        printf("\n6.Modificacion de datos de un astronauta");
        printf("\n");
        scanf("%i", &opcion);
        switch(opcion)
        {
        case 1://carga de astronautas
            cargarAstronautas();
            break;
        case 2://mostrar listado de astronautas y datos
            mostrarAstronautas();
            break;
        case 3://Dar de alta un astronauta a partir de su id
            darAlta();
            break;
        case 4://Dar de baja un astronauta a partir de su id
            darBaja();
            break;
        case 5://busca un astronauta por su id y muestra sus datos
            unAstronauta();
            break;
        case 6://da la posibilidad de modificar datos particculares de un astronauta
            modificarUnAstronauta();
            break;
        }
        ///Volver al menu
        printf("\nPara volver al menu ingrese 's'. En caso contrario se cerrara el programa\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}
void cargarAstronautas()///carga de x cantidad de astronautas
{
    //Se abre e archivo en "rb" para comprobar la existencia del archivo
    FILE*archivo=fopen(nombreArchivo,"rb");

    stAstronauta astronauta;
    char control='s';

    if(archivo==NULL)
    {
        printf("Se ingresaran datos por primera vez\n");
        archivo=fopen(nombreArchivo,"wb");
    }
    else
    {
        fclose(archivo);
        printf("\nSe agregaran datos al archivo");
        archivo=fopen(nombreArchivo,"ab");
    }

    if(archivo!=NULL)
    {
        while(control=='s')
        {
            astronauta = cargarIndividual(astronauta);
            astronauta = cargarNombre(astronauta);
            astronauta = cargarEdad(astronauta);
            astronauta = cargarNacionalidad(astronauta);
            astronauta = cargarEspecialidad(astronauta);
            astronauta = cargarHoras(astronauta);
            astronauta = cargarEstado(astronauta);
            fwrite(&astronauta,sizeof(stAstronauta),1,archivo);

            printf("\nSi quiere cargar otro astronauta presione 's': ");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---\n");
}
stAstronauta cargarIndividual(stAstronauta astronauta)///carga del ID (CAMBIAR)
{
    FILE*arch=fopen(nombreArchivo,"rb");
    stAstronauta aux = astronauta;

    if(arch!=NULL)
    {
        //verificacion de id (ARREGLAR)
        printf("\nIngrese el ID: ");
        scanf("%i", &aux.id);
        while(fread(&astronauta,sizeof(stAstronauta),1,arch)>0)
        {
            if(aux.id==astronauta.id)//si el id ya existe no es valido y se pide nuevamente
            {
                printf("\nID NO VALIDO\n");
                printf("\nIngrese el ID: ");
                scanf("%i", &aux.id);
            }
        }
        astronauta.id=aux.id;
        fclose(arch);
    }
        else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
    return astronauta;
}
stAstronauta cargarNombre(stAstronauta astronauta)///carga el nombre, apellido y apodo
{
        printf("\nIngrese el NOMBRE: ");
        fflush(stdin);
        scanf("%s", astronauta.nombre);
        printf("\nIngrese el APELLIDO: ");
        fflush(stdin);
        scanf("%s", astronauta.apellido);
        printf("\nIngrese el APODO: ");
        fflush(stdin);
        scanf("%s", astronauta.apodo);
        return astronauta;
}
stAstronauta cargarEdad(stAstronauta astronauta)///carga la edad
{
        //verificacion de edad
        printf("\nIngrese la EDAD: ");
        scanf("%i", &astronauta.edad);
        while(astronauta.edad<18)//si es menor de 18 años la edad no es valida y se pide nuevamente
        {
            printf("\nEDAD NO VALIDA\n");
            printf("\nIngrese la EDAD: ");
            scanf("%i", &astronauta.edad);
        }
        return astronauta;
}
stAstronauta cargarNacionalidad(stAstronauta astronauta)///carga nacionalidad
{
        printf("\nIngrese la NACIONALIDAD: ");
        fflush(stdin);
        scanf("%s", astronauta.nacionalidad);
        return astronauta;
}
stAstronauta cargarEspecialidad(stAstronauta astronauta)///carga espacialidad
{
            printf("\nIngrese la ESPECIALIDAD: ");
        fflush(stdin);
        scanf("%s", astronauta.especialidad);
        return astronauta;
}
stAstronauta cargarHoras(stAstronauta astronauta)///carga horas de vuelo y horas eei
{
            printf("\nIngrese las HORAS DE VUELO: ");
        scanf("%i", &astronauta.horasAcumuladas);
        printf("\nIngrese las HORAS EN EEI: ");
        scanf("%i", &astronauta.horasEEI);
        return astronauta;
}
stAstronauta cargarEstado(stAstronauta astronauta)///carga estado
{
        printf("\nIngrese el ESTADO del astronauta |1 activo/2 retirado|");
        scanf("%i", &astronauta.estado);
        //verificacion del estado
        while(astronauta.estado!=1 && astronauta.estado!=2)//si no es lo que se habilita no se ingresa y se pide nuevamente
        {
            printf("\nESTADO NO VALIDO");
            printf("\nIngrese el ESTADO del astronauta |1 activo/2 retirado|");
            scanf("%i", &astronauta.estado);
        }
        return astronauta;
    }
void mostrarAstronautas()///muestra listado de astronautas
{
    FILE*archivo=fopen(nombreArchivo,"rb");
    stAstronauta astronautas;

    if(archivo!=NULL)
    {
        while(fread(&astronautas,sizeof(stAstronauta),1,archivo)>0)
        {
            mostrarIndividual(astronautas);//funcion de muestra
        }
        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
}
void mostrarIndividual(stAstronauta astronauta)///muestra de un solo astronauta
{
    printf("\n------------------------");
    printf("\nID: %i", astronauta.id);
    printf("\nNOMBRE Y APELLIDO: %s %s", astronauta.nombre,astronauta.apellido);
    printf("\nAPODO: %s",astronauta.apodo);
    printf("\nEDAD: %i",astronauta.edad);
    printf("\nNACIONALIDAD: %s",astronauta.nacionalidad);
    printf("\nESPECIALIDAD: %s",astronauta.especialidad);
    printf("\nHORAS DE VUELO: %i",astronauta.horasAcumuladas);
    printf("\nHORAS EN EEI: %i",astronauta.horasEEI);
    printf("\nESTADO: ");
    if(astronauta.estado==1)
        printf("activo\n");
    else
        printf("retirado\n");
    printf("------------------------");
}
void darAlta()///dar de alta un astronauta buscado por su ID
{
    FILE*archivo=fopen(nombreArchivo,"r+b");
    stAstronauta astronauta;
    int identificacion, flag=0;

    if(archivo!=NULL)
    {
        printf("\nIngrese el ID del astronauta que desea dar de alta: ");
        scanf("%i", &identificacion);

        while(flag==0 && fread(&astronauta,sizeof(stAstronauta),1,archivo)>0)
        {
            if(astronauta.id==identificacion)
            {
                if(astronauta.estado==2)
                {
                    printf("\nSe dara de alta al astronauta: %s %s ",astronauta.nombre,astronauta.apellido);
                    astronauta.estado=1;

                    fseek(archivo,sizeof(stAstronauta)*(-1),SEEK_CUR);
                    fwrite(&astronauta,sizeof(stAstronauta),1,archivo);
                    flag=1;
                }
                else
                {
                    printf("\nEl astronauta ya estaba dado de alta\n");
                    flag=1;
                }
            }
        }
        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
}
void darBaja()///dar de baja un astronauta buscado por su ID
{
    FILE*archivo=fopen(nombreArchivo,"r+b");
    stAstronauta astronauta;
    int identificacion, flag=0;

    if(archivo!=NULL)
    {
        printf("\nIngrese el ID del astronauta que desea dar de baja: ");
        scanf("%i", &identificacion);

        while(flag==0 && fread(&astronauta,sizeof(stAstronauta),1,archivo)>0)
        {
            if(astronauta.id==identificacion)
            {
                if(astronauta.estado==1)
                {
                    astronauta.estado=2;
                    printf("\nSe dara de baja al astronauta: %s %s ",astronauta.nombre,astronauta.apellido);

                    fseek(archivo,(-1)*sizeof(stAstronauta),SEEK_CUR);
                    fwrite(&astronauta,sizeof(stAstronauta),1,archivo);
                    flag=1;
                }
                else
                {
                    printf("\nEl astronauta ya esta dado de baja\n");
                    flag=1;
                }
            }
        }
        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
}
void unAstronauta()///mostrar los datos de un astronauta buscado por su ID
{
    FILE * archivo = fopen(nombreArchivo,"rb");
    stAstronauta astronauta;
    char control = 's';
    int identificacion;
    if(archivo!=NULL)
    {
        while(control=='s')
        {
            int flag=0;
            printf("\nIngrese el ID del astronauta que desea consultar: ");
            scanf("%i", &identificacion);
            while(fread(&astronauta,sizeof(stAstronauta),1,archivo)>0)
            {
                if(astronauta.id==identificacion)
                {
                    mostrarIndividual(astronauta);
                    flag=1;
                }
            }
            if(flag==0)//si el ID no es compatible con ninguna astronauta
            {
                printf("\nEl ID ingresado no corresponde a ningun astronauta\n");
            }

            printf("\nSi desea continuar con la busqueda presione 's'. En caso contrario presione cualquier tecla\n");
            fflush(stdin);
            scanf("%c", &control);
            fseek(archivo,0,SEEK_SET);//el indicador de posicion vuelve a la posicion inicial
        }
        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
}
void modificarUnAstronauta()///modifica un dato elegido de un astronauta buscado por su ID
{
    FILE * archivo=fopen(nombreArchivo,"r+b");
    stAstronauta astronauta;
    int identificacion,flag=0,modificar,hVuelos=0, hEEI=0;
    if(archivo!=NULL)
    {
        printf("\nIngrese el ID del astronauta: ");
        scanf("%i", &identificacion);

        while(flag==0 && fread(&astronauta,sizeof(stAstronauta),1,archivo)>0)
        {
            if(astronauta.id==identificacion)
            {
                printf("\n %s %s\n",astronauta.nombre,astronauta.apellido);
                printf("\nIngrese el numero correspondiente a lo que desea modificar: ");
                printf("\n1.Modificar NOMBRE, APELLIDO y APODO");
                printf("\n2.Modificar EDAD");
                printf("\n3.Modificar NACIONALIDAD");
                printf("\n4.Modificar ESPECIALIDAD");
                printf("\n5.Modificar Horas DE VUELOS Y HORAS EN EEI");
                printf("\n");
                scanf("%i", &modificar);
                switch(modificar)
                {
                case 1:
                    astronauta=cargarNombre(astronauta);
                    break;
                case 2:
                    astronauta=cargarEdad(astronauta);
                    break;
                case 3:
                    astronauta=cargarNacionalidad(astronauta);
                    break;
                case 4:
                    astronauta=cargarEspecialidad(astronauta);
                    break;
                case 5:
                    printf("\nIngrese la cantidad de horas de vuelo que se incrementaran: ");
                    scanf("%i", &hVuelos);
                    printf("\nIngrese la cantidad de horas en EEI");
                    scanf("%i", &hEEI);

                    astronauta.horasAcumuladas=astronauta.horasAcumuladas + hVuelos;
                    astronauta.horasEEI=astronauta.horasEEI + hEEI;
                    break;
                default:
                    printf("\nEl valor ingresado no pertenece a las opciones");
                }
                fseek(archivo,(-1)*sizeof(stAstronauta),SEEK_CUR);
                fwrite(&astronauta,sizeof(stAstronauta),1,archivo);
                flag=1;
            }
        }


        fclose(archivo);
    }
    else
        printf("\n\t\t---Hubo un ERROR al abrir el archivo---");
}

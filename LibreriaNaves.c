#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibreriaNaves.h"
void menuNaves()
{
    int numero;
    char continuar = 's';


    while (continuar == 's')
    {
        printf("Ingrese el numero que desea visualizar: ");
        printf("1_Cargar la nave");
        printf("2_Mostrar listado de naves");
        printf("3_Dar de alta una nave");
        printf("4_Dar de baja una nave");
        printf("5_Modificar un dato de la nave");
        printf("6_Consultar id de una nave");
        scanf("%i", &numero);

        switch (numero)
        {
        case 1:
            cargarNave();
            break;

        case 2:
            mostrarDatos();
            break;

        case 3:
            darDeAlta();
            break;

        case 4:
            darDeBaja();
            break;

        case 5:
            modificacion();
            break;

        case 6:
            consultaId();
            break;
        }
        printf("Si desea continuar ingrese S: ");
        fflush(stdin);
        scanf("%c", &continuar);
    }
}
nave cargarId (nave A)
{
    int id;

    FILE * arch = fopen(archivo, "rb");
    if (arch != NULL)
    {
        printf("Ingrese el id: ");
        scanf("%i", &id);

        while (fread(&A, sizeof (nave), 1, arch)> 0)
        {
            if (id == A.id)
            {
                printf("Error cargue denuevo un valor: ");
                scanf("%i", &id);
            }
        }
        A.id = id;
        fclose(arch);
    }
    else
    {
        printf("El archivo no pudo ser abierto");
    }
    return A;
}
void cargarNave ()
{
    char continuar = 's';
    nave aux;

    FILE * arch = fopen(archivo, "ab");
    if (arch != NULL)
    {
        while (continuar == 's')
        {
            aux = cargarId(aux);
            aux = cargarTipo(aux);
            aux = cantidadVuelos(aux);
            aux = horasVuelo(aux);
            aux = Estado(aux);
            fwrite(&aux, sizeof(nave), 1, arch);


            printf("Si desea continuar ingrese S: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
    }
    else
    {
        printf("El archivo no pudo ser abierto");
    }
}
nave cargarTipo (nave B)
{
    char tipo [20];

    printf("Ingresar tipo de nave: ");
    fflush(stdin);
    gets(tipo);

    while (strcmpi(tipo, "starship")!=0 && strcmpi(tipo, "falcon 9")!=0 && strcmpi(tipo, "falcon heavy")!=0)
    {
        printf("Error ingrese Starship o Falcon 9 o Falcon Heavy");
        printf("\nIngresar tipo de nave: ");
        fflush(stdin);
        gets(tipo);
    }
    strcpy(B.nave, tipo);
    return B;
}
nave cantidadVuelos (nave C)
{
    printf("Ingrese la cantidad de vuelos: ");
    scanf("%i", &C.vuelosRealizados);
    return C;
}
nave horasVuelo (nave D)
{
    printf("Ingrese las horas de vuelo: ");
    scanf("%i", &D.horasDeVuelo);
    return D;
}
nave Estado (nave E)
{
    printf("Ingrese el estado de la nave (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja): ");
    scanf("%i", &E.estado);

    while (E.estado != 0 && E.estado != 1 && E.estado != 2 && E.estado != 3)
    {
        printf("Error ingrese un valor valido");
        scanf("%i", &E.estado);
    }
    return E;
}
void mostrarDatos()
{
    nave aux;
    FILE * arch = fopen(archivo, "rb");
    if (arch != NULL)
    {
        while (fread(&aux, sizeof (nave), 1, arch) > 0)
        {
            mostrarNave(aux);
        }
        fclose(arch);
    }
}
void mostrarNave(nave F)
{
    printf("El ID de la nave es: %i", F.id);
    printf("El tipo de nave es: %s", F.nave);
    printf("La cantidad de vuelos realizados fue de: %i", F.vuelosRealizados);
    printf("Las horas de vuelo acumuladas fue de: %i", F.horasDeVuelo);
    printf("El estado de la nave fue de: %i", F.estado);
}
void darDeAlta ()
{
    int id;
    nave aux;
    int flag = 0;
    printf("Ingrese el id de la nave que quiere dar de alta: ");
    scanf("%i", &id);

    FILE * arch = fopen(archivo, "r+b");
    if (arch != NULL)
    {
        while (flag == 0 && fread (&aux, sizeof(nave), 1, arch) > 0)
        {
            if (id == aux.id)
            {
                if (aux.estado == 0)
                {
                    aux.estado = 1;
                    fseek(arch, sizeof(nave)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(nave), 1, arch);
                    flag = 1;
                }
                else
                {
                    printf("Su nave no puede darse de alta");
                }
            }
        }
        fclose(arch);
    }
}
void darDeBaja ()
{
    int id;
    nave aux;
    int flag = 0;
    printf("Ingrese el id de la nave que quiere dar de baja: ");
    scanf("%i", &id);

    FILE * arch = fopen(archivo, "r+b");
    if (arch != NULL)
    {
        while (flag == 0 && fread (&aux, sizeof(nave), 1, arch) > 0)
        {
            if (id == aux.id)
            {
                if (aux.estado == 0 || aux.estado == 1)
                {
                    aux.estado = 3;
                    fseek(arch, sizeof(nave)*-1, SEEK_CUR);
                    fwrite(&aux, sizeof(nave), 1, arch);
                    flag = 1;
                }
                else
                {
                    printf("Su nave no puede darse de baja");
                }
            }
        }
        fclose(arch);
    }
}
void modificacion ()
{
    int id;
    nave aux;
    int num;
    int horasExtraVuelo;
    int cantidadExtraVuelo;

    int flag = 0;

    printf("Ingrese el id de la nave que quiere modificar datos: ");
    scanf("%i", &id);

    FILE * arch = fopen(archivo, "r+b");
    if (arch != NULL)
    {
        while (flag == 0 && fread (&aux, sizeof(nave), 1, arch) > 0)
        {
            if (id == aux.id)
            {
                printf("Ingrese el numero de la opcion que quiere modificar: ");
                printf("1_ Cantidad de vuelos realizados");
                printf("2_Horas de vuelo realizadas");
                scanf("%i", &num);
                switch(num)
                {
                case 1:
                    printf("Ingrese la cantidad de vuelos realizados extra: ");
                    scanf("%i", &cantidadExtraVuelo);
                    aux.vuelosRealizados = aux.vuelosRealizados + cantidadExtraVuelo;
                    printf("La cantidad de vuelos realizados actualmente es de: %i", aux.vuelosRealizados);
                    break;

                case 2:
                    printf("Ingrese la cantidad de horas realizados extra: ");
                    scanf("%i", &horasExtraVuelo);
                    aux.horasDeVuelo = aux.horasDeVuelo + horasExtraVuelo;
                    printf("La cantidad de vuelos realizados actualmente es de: %i", aux.horasDeVuelo);
                    break;

                default:
                    printf("El valor ingresado es incorrecto");
                }

                fseek(arch, sizeof(nave)*-1, SEEK_CUR);
                fwrite(&aux, sizeof(nave), 1, arch);
                flag = 1;
            }
        }
        fclose(arch);
    }
}
void consultaId ()
{
    int id;
    nave aux;
    int flag = 0;
    printf("Ingrese el id de la nave que quiere consultar: ");
    scanf("%i", &id);

    FILE * arch = fopen(archivo, "rb");
    if (arch != NULL)
    {
        while (flag == 0 && fread (&aux, sizeof(nave), 1, arch) > 0)
        {
            if (id == aux.id)
            {
                mostrarNave(aux);
                flag = 1;
            }
        }
        fclose(arch);
    }
}

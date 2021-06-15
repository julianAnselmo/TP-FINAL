#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaAstronauta.h"
#include "LibreriaNaves.h"
void main()
{
    int numero;

    printf("Elija la opcion que desee: ");
    printf("1_Menu astronautas");
    printf("2_Menu naves");
    printf("3_Menu misiones");
    scanf("%i", &numero);

    switch (numero)
    {
        case 1: menuAstronauta();
        break;

        case 2: menuNaves();
        break;
    }
}



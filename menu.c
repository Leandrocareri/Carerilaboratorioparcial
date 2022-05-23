#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "validaciones.h"

char menu()
{

    char opcion;
    system("cls");
    printf("     *** SERVICE DE NOTEBOOKS ***\n\n");
    printf("A- Alta notebook\n");
    printf("B- Modificar notebook\n");
    printf("C- Baja notebook\n");
    printf("D- Listar notebooks\n");
    printf("E- Listar marcas\n");
    printf("F- Listar tipos\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Listar notebooks por tipo\n");
    printf("K- Listar notebooks por marca\n");
    printf("L- Informar notebook mas barata\n");
    printf("M- Listar notebooks por marcas\n");
    printf("N- Informar cantidad de notebooks por tipo y marca\n");
    printf("O- Informar marca mas elegida\n");
    printf("Z- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);
    if(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D' && opcion!='E' && opcion!='F' && opcion!='G'
            && opcion!='H' && opcion!='I' && opcion!='Z' && opcion!='J' && opcion!='K'&& opcion!='L'&& opcion!='M'&& opcion!='N'&& opcion!='O')
    {
        printf("Opcion incorrecta, elija una opcion valida\n");
        system("pause");
    }
    return opcion;

}


int menuModificar()
{
    int opcion;
    printf(" \n   ***  Campos a modificar  ***\n\n");
    printf("1_ Precio\n");
    printf("2_ Id tipo\n");
    printf("3_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,3);
    return opcion;
}


int menuTipos()
{
    int opcion;
    printf(" \n   ***  Tipos de notebooks ***\n\n");
    printf("1_ Gamer\n");
    printf("2_ Disenio\n");
    printf("3_ Ultrabook\n");
    printf("4_ Normalita\n");
    printf("5_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,5);
    return opcion;
}

int menuMarca()
{
    int opcion;
    printf(" \n   ***  Marcas de notebooks ***\n\n");
    printf("1_ Compaq\n");
    printf("2_ Asus\n");
    printf("3_ Acer\n");
    printf("4_ HP\n");
    printf("5_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,5);
    return opcion;
}



int menuMarcaYTipo()
{
    int opcion;
    printf(" \n   ***  Marcas y tipos de notebooks ***\n\n");
    printf(" \n   Elija marca de notebook \n\n");
    printf("1_ Compaq\n");
    printf("2_ Asus\n");
    printf("3_ Acer\n");
    printf("4_ HP\n");
    printf("5_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,5);
    return opcion;
}


int menuTipoEnMarca()
{
    int opcion;
    printf(" \n   ***  Marcas y tipos de notebooks ***\n\n");
    printf(" \n   Elija tipo de notebook \n\n");
    printf("1_ Gamer\n");
    printf("2_ Disenio\n");
    printf("3_ Ultrabook\n");
    printf("4_ Normalita\n");
    printf("5_ Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);
    validarNumero(&opcion,1,5);
    return opcion;
}

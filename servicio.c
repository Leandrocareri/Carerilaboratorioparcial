#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "fecha.h"
#include "validaciones.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"

int hardcodearServicios(eServicio lista[],int tam)
{
    int todoOk=0;
    eServicio cargadas[]=
    {
        {20000,"Bateria",2250},
        {20001,"Display",10300},
        {20002,"Mantenimiento",4400},
        {20003,"Fuente",5600},
    };
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i]=cargadas[i];
        }
        todoOk=1;
    }
    return todoOk;
}

int listarServicios (eServicio servicios[], int tam)
{
    int todoOk = 0;
    if(servicios != NULL && tam > 0)
    {
        system("cls");
        printf("           ***     Listado de Servicios     ***\n\n");
        printf("     Id                  Descripcion        Precio\n");
        printf("---------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("   %5d    %25s       %5.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");
        system("pause");
        todoOk = 1;
    }
    return todoOk;
}


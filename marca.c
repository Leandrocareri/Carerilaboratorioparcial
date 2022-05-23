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


int hardcodearMarcas(eMarca lista[],int tam)
{
    int todoOk=0;
    eMarca cargadas[]={
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
    };

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i]=cargadas[i];
        }
        todoOk=1;
    }
    return todoOk;
}

int listarMarcas(eMarca marcas[], int tam){
int todoOk = 0;
    if(marcas != NULL && tam > 0){
        system("cls");
        printf("   *** Listado de Marcas  ***\n\n");
        printf("     Id            Descripcion\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %20s\n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");
        system("pause");
        todoOk = 1;
    }
 return todoOk;
}

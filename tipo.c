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


int listartipos (eTipo tipos[], int tam){
int todoOk = 0;
    if(tipos != NULL && tam > 0){
        system("cls");
        printf("   *** Listado de Tipos  ***\n\n");
        printf("     Id            Descripcion\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %20s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        system("pause");
        todoOk = 1;
    }
 return todoOk;
}


int hardcodearTipos(eTipo tipos[],int tam)
  {
       int todoOk=0;
    eTipo cargadas[]={
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
    };

    if(tipos!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            tipos[i]=cargadas[i];
        }
        todoOk=1;
    }
    return todoOk;
  }

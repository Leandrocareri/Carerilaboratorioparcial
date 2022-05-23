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

int altaTrabajo(eTrabajo listaTrabajos[], int tamTr,int* pNumTrabajo, eNotebook listaNotebooks[], int tamNotebook,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int indice=*pNumTrabajo-1;;
    int idNote;
    int auxEnt;
    eTrabajo trabajoNuevo;
    eFecha fecha;
    if(listaTrabajos!=NULL && tamTr>0 && pNumTrabajo!=NULL && listaNotebooks!=NULL && tamNotebook>0)
    {
        listarNotebook(listaNotebooks,tamNotebook,clientes,tamClientes);
        printf("\nIngrese el id de la notebook para servicio: ");
        scanf("%d",&idNote);
        for(int i=0; i<tamNotebook; i++)
        {
            if(idNote==listaNotebooks[i].id && listaNotebooks[i].isEmpty==0)
            {
                trabajoNuevo.idNotebook=idNote;
                break;
            }
            else
            {
                printf("Error al cargar trabajo, id no encontrado\n");
            }
        }

        printf("Ingrese id de servicio a realizar \n 20000 Bateria \n 20001 Display\n 20002 Mantenimiento\n 20003 Fuente\n");
        scanf("%d",&auxEnt);
        validarNumero(&auxEnt,20000,20003);
        trabajoNuevo.idServicio=auxEnt;

        printf("Ingrese dia de servicio: \n");
        scanf("%d", &fecha.dia);
        printf("Ingrese mes de servicio: \n");
        scanf("%d", &fecha.mes);
        printf("Ingrese anio de servicio: \n");
        scanf("%d", &fecha.anio);
        if(validarFecha(fecha))
        {
            trabajoNuevo.fechaIngreso=fecha;
        }

        trabajoNuevo.isEmpty=0;
        trabajoNuevo.id= *pNumTrabajo;
        *pNumTrabajo=*pNumTrabajo+1;
        listaTrabajos[indice]=trabajoNuevo;
        todoOk=1;
    }
    else
    {
        printf("Error al cargar trabajo\n");
    }

    return todoOk;
}

int mostrarTrabajo(eTrabajo vec, int tam)
{
    int todoOk=0;
    {
        printf("   %4d           %5d          %5d       %02d/%02d/%d  \n",
               vec.id,
               vec.idNotebook,
               vec.idServicio,
               vec.fechaIngreso.dia,
               vec.fechaIngreso.mes,
               vec.fechaIngreso.anio
                  );

        todoOk=1;
    }
    return todoOk;
}


int listarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk=0;
    int flag=0;
    if(vec != NULL && tam>0)
    {
        system("cls");
        printf("     ***  Listado de Trabajos   ***  \n\n");
        printf("---------------------------------------\n\n");
        printf(" id Trabajo  id Notebook  id Servicio       Fecha \n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                 mostrarTrabajo(vec[i], tam);
                 flag++;
            }

        }
        system("pause");

        if(flag == 0)
        {
            printf("       No hay trabajos en el sistema");
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}


int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk=0;
    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

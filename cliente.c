#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"

int cargarNombre(eCliente clientes[],int tamClientes, int id, char nombre[])
{
    int todoOk=0;

    if(clientes!=NULL && tamClientes>0 && nombre!=NULL && id>=40000)
        for(int i=0;i<tamClientes;i++)
    {
        if(clientes[i].id==id)
        {
            strcpy(nombre,clientes[i].nombre);
            break;
        }
       todoOk=1;
    }
    return todoOk;
}

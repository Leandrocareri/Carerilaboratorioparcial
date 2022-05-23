#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "fecha.h"
#include "validaciones.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "cliente.h"
#include "trabajo.h"




int buscarLugarLibre(eNotebook vec[], int tam, int* pIndex,eCliente clientes[], int tamClientes,int* pNumCliente)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && clientes!=NULL && tamClientes>0 && pNumCliente!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int altaNotebook(eNotebook vec[], int tam, int* pNumeroNote,eCliente clientes[], int tamClientes,int* pNumCliente)
{
    int todoOk = 0;
    int indice;
    char auxCad[20];
    char auxChar;
    int auxNum;
    float auxFloat;
    eNotebook nuevaNotebook;
    eCliente nuevoCliente;

    if(vec != NULL && tam > 0 && pNumeroNote != NULL && clientes!=NULL && tamClientes>0 && pNumCliente!=NULL)
    {
        if( buscarLugarLibre(vec, tam, &indice,clientes,tamClientes,pNumCliente) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema para cargar otra notebook\n");
            }
            else
            {
                printf("Ingrese el modelo de la notebook: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Modelo demasiado largo. Reingrese modelo: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaNotebook.modelo, auxCad);

                printf("Ingrese id de marca:\n 1000 Compaq\n 1001 Asus\n 1002 Acer\n 1003 HP\n");
                scanf("%d", &auxNum);
                if(validarNumero(&auxNum,1000,1999))
                {
                    nuevaNotebook.idMarca=auxNum;
                }

                printf("Ingrese nombre del cliente: ");
                fflush(stdin);
                gets(auxCad);
                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevoCliente.nombre, auxCad);


                printf("Ingrese sexo del cliente (f o m): ");
                fflush(stdin);
                scanf("%c",&auxChar);
                auxChar=toupper(auxChar);
                while(auxChar!='M' && auxChar!='F')
                {
                    printf("Error, ingrese un sexo valido: ");
                    fflush(stdin);
                    scanf("%c",&auxChar);
                }
                nuevoCliente.sexo=auxChar;


                printf("Ingrese id de tipo:\n 5000 Gamer\n 5001 Disenio\n 5002 Ultrabook\n 5003 Normalita\n");
                scanf("%d", &auxNum);
                if(validarNumero(&auxNum,5000,5999))
                {
                    nuevaNotebook.idTipo=auxNum;
                }

                printf("Ingrese precio: ");
                scanf("%f", &auxFloat);
                if(validarPrecio(&auxFloat,0))
                {
                    nuevaNotebook.precio=auxFloat;
                }


                nuevoCliente.id=*pNumCliente;
                nuevaNotebook.idCliente=nuevoCliente.id;
                clientes[*pNumCliente-50000]=nuevoCliente; //esta revisar!!!!!
                *pNumCliente=*pNumCliente+1;
                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id= *pNumeroNote;
                *pNumeroNote = *pNumeroNote + 1;
                vec[indice] = nuevaNotebook;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}



int mostrarNotebook(eNotebook notebooks, int tam,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    char nombreCliente[20];

    if(clientes!=NULL && tamClientes>0)
    {
        cargarNombre(clientes,tamClientes,notebooks.idCliente,nombreCliente);
        {
            printf("  %5d       %4d         %4d    %20s    %5.2f   %20s\n",

                   notebooks.id,
                   notebooks.idMarca,
                   notebooks.idTipo,
                   notebooks.modelo,
                   notebooks.precio,
                   nombreCliente
                  );
            todoOk = 1;
        }
    }

    return todoOk;
}


int listarNotebook(eNotebook vec[], int tam,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int flag=0;
    if(vec != NULL && tam>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("     ***  Listado de Notebooks   ***  \n\n");
        printf("---------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio     Cliente\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebook(vec[i], tam,clientes,tamClientes);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int buscarNotebook(eNotebook lista[],int tam, int id, int* pIndex)
{
    int todoOk=0;
    if(lista!=NULL && tam>0 && pIndex!=NULL && id>=40000)
    {
        *pIndex=-1;
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0 && lista[i].id==id)
            {
                *pIndex=i;
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}



int inicializarNotes(eNotebook lista[], int tam,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    if(lista!=NULL && tam>0 && clientes!=NULL && tamClientes>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;

}



int bajaNotebook(eNotebook lista[], int tam,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    if(lista!=NULL && tam>0 && clientes!=NULL && tamClientes>0)
    {
        listarNotebook(lista,tam,clientes,tamClientes);
        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);
        if(buscarNotebook(lista,tam,id,&indice))
        {
            if(indice==-1)
            {
                printf("No hay notebook con esa id\n");
            }
            else
            {
                mostrarNotebook(lista[indice],tam,clientes,tamClientes);
                printf("Confirma baja de notebook? \n");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma=toupper(confirma);
                if(confirma!='S')
                {
                    printf("Baja cancelada\n");
                }
                else
                {
                    lista[indice].isEmpty=1;
                    printf("Baja realizada con exito\n");
                }
                todoOk=1;

            }
            todoOk=1;
        }
        else
        {
            printf("Ocurrio un problema al buscar la notebook\n");
        }
        todoOk=1;

    }

    return todoOk;

}



int modificarNotebook(eNotebook lista[],int tam,eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int indice;
    int id;
    char salir='N';
    float auxFloat;
    int auxNum;

    if(lista!=NULL && tam>0 && clientes!=NULL && tamClientes>0)
    {
        listarNotebook(lista,tam,clientes,tamClientes);
        printf("Ingrese id de notebook a modificar: \n");
        scanf("%d",&id);
        if(buscarNotebook(lista,tam,id,&indice))
        {
            if(indice==-1)
            {
                printf("No hay notebook con esa id\n");
            }
            else
            {
                mostrarNotebook(lista[indice],tam,clientes,tamClientes);

                do
                {
                    switch(menuModificar())
                    {
                    case 1:
                        printf("Ingrese el nuevo precio: \n");
                        scanf("%f",&auxFloat);
                        validarPrecio(&auxFloat,0);
                        lista[indice].precio=auxFloat;
                        printf("Se ha modificado el precio con exito\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo id de tipo:\n 5000 Gamer\n 5001 Disenio\n 5002 Ultrabook\n 5003 Normalita\n");
                        scanf("%d",&auxNum);
                        validarNumero(&auxNum,5000,5999);
                        lista[indice].idTipo=auxNum;
                        printf("Se ha modificado el tipo con exito\n");
                        break;
                    case 3:
                        salir='S';
                        break;
                    }
                }
                while((salir=!'S'));
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar el id");
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks de tipo gamer   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idTipo==5000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks de tipo Disenio   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idTipo==5001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks de tipo Ultrabook   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idTipo==5002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks de tipo Ultrabook   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idTipo==5003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int listarPorTipo(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    char salir='N';
    int todoOk=0;
    do
    {
        switch(menuTipos(notebooks,tam, clientes, tamClientes))
        {
        case 1:
            listarGamer(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 2:
            listarDisenio(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 3:
            listarUltrabook(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 4:
            listarNormalita(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 5:
            salir='S';
            todoOk=1;
            break;
        }
    }
    while((salir=!'S'));
    return todoOk;
}



int  listarCompaq(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks marca Compaq   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int  listarAsus(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks marca Asus   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarAcer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks marca Acer   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int  listarHp(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks marca HP  ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int listarPorMarca(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    char salir='N';
    int todoOk=0;
    do
    {
        switch(menuMarca(notebooks,tam, clientes, tamClientes))
        {
        case 1:
            listarCompaq(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 2:
            listarAsus(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 3:
            listarAcer(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 4:
            listarHp(notebooks,tam,clientes,tamClientes);
            system("pause");
            break;
        case 5:
            salir='S';
            todoOk=1;
            break;
        }
    }
    while((salir=!'S'));
    return todoOk;
}


int informarNoteBarata(eNotebook notebooks[],int tam,eCliente clientes[],int tam_clientes)
{
    int todoOk=0;
    float precioBarato;
    int bandera=0;

    if(notebooks!=NULL && tam>0 && clientes!=NULL && tam_clientes>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && (notebooks[i].precio<precioBarato || bandera==0))
            {
                precioBarato=notebooks[i].precio;
                bandera=1;
            }
        }

        printf("      ***   Notebooks mas baratas ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        if(bandera==0)
        {
            printf("No hay notebooks cargadas en sistema\n");
        }
        else
        {
            for(int i=0; i<tam; i++)
            {
                if(!notebooks[i].isEmpty && notebooks[i].precio==precioBarato)
                {
                    mostrarNotebook(notebooks[i],tam,clientes,tam_clientes);
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}



int listarSeparadasMarcas(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes)
{
    int todoOk=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Listado de notebooks por marcas ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
            }
        }
        todoOk=1;
    }

    return todoOk;
}


int listarMarcaYTipo(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    char salir='N';
    int todoOk=0;
    do
    {
        switch(menuMarcaYTipo())
        {
        case 1:
            switch(menuTipoEnMarca())
            {
            case 1:
                listarCompaqGamer(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 2:
                listarCompaqDisenio(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 3:
                listarCompaqUltrabook(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 4:
                listarCompaqNormalita(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            }
            break;
        case 2:
            switch(menuTipoEnMarca())
            {
            case 1:
                listarAsusGamer(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 2:
                listarAsusDisenio(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 3:
                listarAsusUltrabook(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 4:
                listarAsusNormalita(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            }
            break;
        case 3:
            switch(menuTipoEnMarca())
            {
            case 1:
                listarAcerGamer(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 2:
                listarAcerDisenio(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 3:
                listarAcerUltrabook(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 4:
                listarAcerNormalita(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            }
            break;
        case 4:
            switch(menuTipoEnMarca())
            {
            case 1:
                listarHpGamer(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 2:
                listarHpDisenio(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 3:
                listarHpUltrabook(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            case 4:
                listarHpNormalita(notebooks,tam,clientes,tamClientes);
                system("pause");
                break;
            }
            break;
        case 5:
            salir='S';
            todoOk=1;
            break;
        }
    }
    while((salir=!'S'));
    return todoOk;
}



int  listarCompaqGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks Gamer Compaq    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000 && notebooks[i].idTipo==5000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarCompaqDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Disenio  Compaq    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000 && notebooks[i].idTipo==5001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarCompaqUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Ultrabook  Compaq    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000 && notebooks[i].idTipo==5002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarCompaqNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Normalita  Compaq    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1000 && notebooks[i].idTipo==5003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarAsusGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Gamer   Asus    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001 && notebooks[i].idTipo==5000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarAsusDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Disenio  Asus    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001 && notebooks[i].idTipo==5001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarAsusUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Ultrabook  Asus   ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001 && notebooks[i].idTipo==5002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarAsusNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Normalita  Asus    ***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1001 && notebooks[i].idTipo==5003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarAcerGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Gamer Acer***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002 && notebooks[i].idTipo==5000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarAcerDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Disenio Acer***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002 && notebooks[i].idTipo==5001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("\nLa cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarAcerUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Ultrabook Acer***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002 && notebooks[i].idTipo==5002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarAcerNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Normalita Acer***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1002 && notebooks[i].idTipo==5003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}



int  listarHpGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Gamer  HP***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003 && notebooks[i].idTipo==5000)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarHpDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Disenio  HP***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003 && notebooks[i].idTipo==5001)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}

int  listarHpUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Ultrabook  HP***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003 && notebooks[i].idTipo==5002)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}


int  listarHpNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contador=0;

    if(notebooks!=NULL&&tam>0&&clientes!=NULL&&tamClientes>0)
    {
        system("cls");

        printf("      ***   Notebooks  Gamer  HP***\n");
        printf("------------------------------------------\n\n");
        printf(" id        id Marca       id Tipo                Modelo     Precio            Cliente\n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!notebooks[i].isEmpty && notebooks[i].idMarca==1003 && notebooks[i].idTipo==5003)
            {
                mostrarNotebook(notebooks[i],tam,clientes,tamClientes);
                contador++;
            }
        }
        printf("La cantidad que hay es %d", contador);
        todoOk=1;
    }
    return todoOk;
}



int marcaMasElegida(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes)
{
    int todoOk=0;
    int contadorAsus=0;
    int contadorHp=0;
    int contadorAcer=0;
    int contadorCompaq=0;

    if(notebooks!=NULL && tam>0 && clientes!= NULL && tamClientes>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(notebooks[i].idMarca==1000)
            {
                contadorCompaq++;
            }
        }

        for(int i=0;i<tam;i++)
        {
            if(notebooks[i].idMarca==1001)
            {
                contadorAsus++;
            }
        }

         for(int i=0;i<tam;i++)
        {
            if(notebooks[i].idMarca==1001)
            {
                contadorAcer++;
            }
        }

         for(int i=0;i<tam;i++)
        {
            if(notebooks[i].idMarca==1001)
            {
                contadorHp++;
            }
        }

        if(contadorAcer>=contadorAsus &&contadorAcer>=contadorCompaq && contadorAcer>=contadorHp)
        {
            printf("La marca mas elegida es Acer con %d unidades\n",contadorAcer);
        }

        if(contadorAsus>=contadorAcer &&contadorAsus>=contadorCompaq && contadorAsus>=contadorHp)
        {
            printf("La marca mas elegida es Asus con %d unidades\n",contadorAsus);
        }
        if(contadorCompaq>=contadorAsus &&contadorCompaq>=contadorAcer && contadorCompaq>=contadorHp)
        {
            printf("La marca mas elegida es Compaq con %d unidades\n",contadorCompaq);
        }
          if(contadorHp>=contadorAsus &&contadorHp>=contadorAcer && contadorHp>=contadorCompaq)
        {
            printf("La marca mas elegida es Hp con %d unidades\n",contadorHp);
        }

        todoOk=1;
    }
return todoOk;

}

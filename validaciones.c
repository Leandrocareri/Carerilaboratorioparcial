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
#include "trabajo.h"


int validarNumero(int* pNumero, int minimo, int maximo)
{
    int todoOk=0;
        while(*pNumero<minimo || *pNumero>maximo)
        {
            printf("Error, ingrese un numero valido: ");
            scanf("%d", &*pNumero);
        }
        todoOk=1;
        return todoOk;
}

int validarPrecio(float* pNumero, float min)
{
    int todoOk=0;
    while(*pNumero<min)
    {
        printf("Error, ingrese precio valido: ");
        scanf("%f", &*pNumero);
    }
    todoOk=1;
    return todoOk;
}


int confirmarSalida(char* pSalir)
{
    int todoOk=0;
    char respuesta;
    printf("Confirma la salida S / N: \n");
 //   system("pause");
    scanf("%c", &respuesta);
    scanf("%c", &respuesta);
    respuesta=toupper(respuesta);
    if(respuesta!='S' && respuesta!='N')
    {
        printf("Error, ingrese una respuesta valida\n");
    }
    else
    {
        *pSalir=respuesta;
        todoOk=1;
    }
    return todoOk;
}


int validarFecha(eFecha unaFecha)
{
    int todoOk=0;
    if(unaFecha.anio>2022 || unaFecha.anio<2000)
    {
        printf("Anio equivocado, vuelva a ingresar la fecha");
    }
    else
    {
        if(unaFecha.mes>0 && unaFecha.mes<13)
        {
            switch(unaFecha.mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(unaFecha.dia<1 || unaFecha.dia>31)
                {
                    printf("Dia incorrecto, vuelva a ingresar fecha \n");
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(unaFecha.dia<1 || unaFecha.dia>30)
                {
                    printf("Dia incorrecto, vuelva a ingresar fecha \n");
                }
                break;
            case 2:
                if(unaFecha.dia<1 || unaFecha.dia>28)
                {
                    printf("Dia incorrecto, vuelva a ingresar la fecha \n");
                }
            }
        }
        else
        {
            printf("Mes incorrecto, vuelva a ingresar la fecha \n");
        }
        todoOk=1;
    }
    return todoOk;
}


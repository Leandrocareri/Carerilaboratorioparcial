#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id; //comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int hardcodearServicios(eServicio lista[],int tam);
int listarServicios (eServicio servicios[], int tam);

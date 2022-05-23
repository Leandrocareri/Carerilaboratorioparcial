#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id; // comienza en 1000
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED


int listarMarcas(eMarca marcas[], int tam);
int hardcodearMarcas(eMarca lista[],int tam);

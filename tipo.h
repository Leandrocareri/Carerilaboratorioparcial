#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id; //comienza en 5000
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int hardcodearTipos(eTipo tipos[],int tam);
int listartipos (eTipo tipos[], int tam);

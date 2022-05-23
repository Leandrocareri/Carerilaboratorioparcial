#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id; //autoincremental
    int idNotebook; //debe existir, validar
    int idServicio; //debe existir, validar
    eFecha fechaIngreso; //validar
    int isEmpty;
}eTrabajo;


int altaTrabajo(eTrabajo listaTrabajos[], int tamTr,int* pNumTrabajo, eNotebook listaNotebooks[], int tamNotebook,eCliente clientes[], int tamClientes);
int mostrarTrabajo(eTrabajo vec, int tam);
int listarTrabajos(eTrabajo vec[], int tam);
int inicializarTrabajos(eTrabajo vec[], int tam);


#endif // TRABAJO_H_INCLUDED

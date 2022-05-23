#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "cliente.h"


typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int idCliente;
    int isEmpty; //No pedido
}eNotebook;


#endif // NOTEBOOK_H_INCLUDED


int listarNotebook(eNotebook vec[], int tam,eCliente clientes[], int tamClientes);
int buscarLugarLibre(eNotebook vec[], int tam, int* pIndex,eCliente clientes[], int tamClientes,int* pNumCliente);
int altaNotebook(eNotebook vec[], int tam, int* pNumeroNote,eCliente clientes[], int tamClientes,int* pNumCliente);
int mostrarNotebook(eNotebook notebooks, int tam,eCliente clientes[], int tamClientes);
int inicializarNotes(eNotebook lista[], int tam,eCliente clientes[], int tamClientes);
int bajaNotebook(eNotebook lista[], int tam,eCliente clientes[], int tamClientes);
int buscarNotebook(eNotebook lista[],int tam, int id, int* pIndex);
int modificarNotebook(eNotebook lista[],int tam,eCliente clientes[], int tamClientes);
int listarPorTipo(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int listarPorMarca(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int informarNoteBarata(eNotebook notebooks[],int tam,eCliente clientes[],int tam_clientes);
int listarSeparadasMarcas(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int listarCompaqGamer(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int listarCompaqDisenio(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int listarCompaqUltrabook(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int listarCompaqNormalita(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int listarMarcaYTipo(eNotebook notebooks[],int tam,eCliente clientes[],int tamClientes);
int  listarAsusNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAsusUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAsusGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAsusDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAcerNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAcerGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAcerDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarAcerUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarHpUltrabook(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarHpDisenio(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarHpGamer(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int  listarHpNormalita(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);
int marcaMasElegida(eNotebook notebooks[], int tam, eCliente clientes[], int tamClientes);




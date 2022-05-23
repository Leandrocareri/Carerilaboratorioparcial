#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

int cargarNombre(eCliente clientes[],int tamClientes, int id, char nombre[]);


#endif // CLIENTE_H_INCLUDED

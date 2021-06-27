#ifndef EJERCICIO3Y4_H
#define EJERCICIO3Y4_H

#include <stdbool.h>

typedef struct _nodo NODO;
typedef int INFO;

struct _nodo{
	INFO info;
	NODO *sig; //apuntador al siguiente nodo
};

typedef struct _lista LISTA;

struct _lista{
	NODO *head; //Ambos apuntadores
	NODO *tail;
	int num;
};

//PROTOTIPOS:
NODO* crear_nodo(INFO info);
LISTA *crear_lista();
bool insetar_inicio(LISTA *l, INFO info);
bool insertar_fin(LISTA *l, INFO info);
bool insertar(LISTA* l, INFO info, int pos);
bool es_vacia(LISTA *l);
bool vaciar(LISTA *l);
void imprimir_lista(LISTA *l);

#endif

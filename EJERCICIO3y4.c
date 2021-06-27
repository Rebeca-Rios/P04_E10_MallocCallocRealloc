#include "EJERCICIO3Y4.h"
#include <stdio.h> //NULL
#include <stdlib.h>

NODO* crear_nodo(INFO info){
	
	//NODO* t = (NODO*)malloc(sizeof(NODO));
	NODO* t = (NODO*)calloc(1, sizeof(NODO));
	
	if(t != NULL){
		//se imprime la dirección de memoria al que apunta t->sig y el valor de t->info
		printf("\n\t[dir sig:%p, val info:%d]", t->sig, t->info);
	}
	t->sig = NULL;
	t->info = info;
	return t;
}

LISTA *crear_lista(){
	LISTA* l = (LISTA*) malloc(sizeof(LISTA));
	l->head = l->tail = NULL;
	l->num = 0;
	return l;
}

bool insertar_inicio(LISTA *l, INFO info){
	NODO* nuevo = crear_nodo(info);
	if(l->head == NULL  &&  l->tail == NULL){
		l->head = l->tail = nuevo;
		l->num++;
		return true;
	} else{
		nuevo->sig = l->head;
		l->head = nuevo;
		l->num++;
		return true;
	}
	return false;
}

bool insertar_fin(LISTA *l, INFO info){
	NODO* nuevo = crear_nodo(info);
	if(l->head == NULL  &&  l->tail == NULL){
		l->head = l->tail = nuevo;
		l->num++;
		return true;
	} else{
		l->tail->sig = nuevo;
		l->tail = nuevo; //l->tail = l->tail->siguiente
		l->num++;
		return true;
	}
	return false;
}

bool insertar(LISTA* l, INFO info, int pos){
	if(pos == 0) return insertar_inicio(l, info);
	else if (pos == l->num) return insertar_fin(l, info);
	else if(pos > 0  &&  pos < l->num){
		NODO* nuevo = crear_nodo(info);
		NODO* temporal = l->head;
		for(int tpos = 0; tpos < pos-1; tpos++)
			temporal = temporal->sig;
		nuevo->sig = temporal->sig;
		temporal->sig = nuevo;
		l->num++;
		return true;		
	}
}

bool es_vacia(LISTA *l){
	if(l->head == NULL  &&  l->head == l->tail) return true;
	return false;
}

bool vaciar(LISTA *l){
	if(es_vacia(l)) return false;
	NODO* temporal = l->head;
	while(temporal != NULL){ //while(temporal != l->tail){
		l->head = temporal->sig;
		free(temporal);
		temporal = l->head;
	}
	l->head = l->tail = NULL;
	l->num = 0;
	return true;
}

void imprimir_lista(LISTA *l){
	printf("\n\n\n\tDespues de asignar un valor\n");
	for(NODO* t = l->head; t != NULL; t = t->sig){
		//se imprime la dirección de memoria al que apunta t->sig y el valor de t->info
		//Ambos datos ya fueron modificados para crear la lista
		printf("\n\t[dir sig:%p, val info:%d]", t->sig, t->info);
	}
}

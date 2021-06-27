#include "ejercicio3y4.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	LISTA *l1; //una es apuntador, la otra no
	
	l1 = crear_lista();
	
	insertar(l1, 0, 0);
	insertar(l1, 1, 1);
	insertar(l1, 3, 2);
	insertar(l1, 5, 3);
	
	imprimir_lista(l1);
	
	printf("\n");
	
	vaciar(l1);
	
	free(l1);
	
	return (EXIT_SUCCESS);
}

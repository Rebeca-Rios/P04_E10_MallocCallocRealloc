#include <stdio.h>
#include <stdlib.h> //malloc
#include <locale.h>

int main(int argc, char **argv){
	setlocale(LC_CTYPE, "");

	//EJEMPLO 02
	printf("\n\tEJEMPLO 02\n");
	int *array = NULL, num, cont;
	printf("\n\t¿Cuántos elementos tiene el arreglo?\t");
	scanf("%d", &num);
	array = (int*)calloc(num, sizeof(int)); //calloc resive dos parámetros, la cantidad de elementos y el tamaño de uno de ellos. Garantiza que va a estar iniciado en 0
	if(array != NULL){ //para preguntar si calloc sí asigno espacio
		printf("\n\tVector reservado:\n");
		for(cont = 0; cont < num; cont++){
			printf("\t\t\tvalor:%d  -  dir:%p\n", *(array+cont), array+cont); //cuando es un arreglo, las direcciones son continuas
		}
		printf("\n\n\tLa memoria será liberada\n");
		free(array);
	}
	return 0;
}

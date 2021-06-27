#include <stdio.h>
#include <stdlib.h> //malloc
#include <locale.h>

int main(int argc, char **argv){
	setlocale(LC_CTYPE, "");
	int *array = NULL, num, cont;
	printf("\n\t�Cu�ntos elementos tiene el arreglo?\t");
	scanf("%d", &num);
	array = (int*)realloc(array, num*sizeof(int)); //sustituimos calloc por realloc
	if(array != NULL){ //para preguntar si calloc s� asigno espacio
		printf("\n");
		for(cont = 0; cont < num; cont++){
			printf("\t\tIngresa el elemento: %d\t", cont+1);
			scanf("%d", (array+cont));
		}
		printf("\n\tVector reservado:\n");
		for(cont = 0; cont < num; cont++){
			printf("\t\t\tvalor:%d  -  dir:%p\n", *(array+cont), array+cont); //cuando es un arreglo, las direcciones son continuas
		}
		printf("\n");
		
		num *= 2; //se multiplica num por 2 y se almacena en num
		array = (int*)realloc(array, num*sizeof(int)); //recibe el arreglo y el tama�o al doble. Regresa un apuntador al nuevo arreglo. Tambi�n puede hacerse m�s peque�o
		if(array != NULL){
			printf("\n\n");
			for(; cont < num; cont++){ //para que inicie en el valor que tiene num
				printf("\t\tIngresa el elemento: %d\t", cont+1);
				scanf("%d", (array+cont));
			}
			printf("\n\tVector reservado:\n");
			for(cont = 0; cont < num; cont++){
				printf("\t\t\tvalor:%d  -  dir:%p\n", *(array+cont), array+cont); //cuando es un arreglo, las direcciones son continuas
			}
			printf("\n");
		}
		printf("\n\tLa memoria ser� liberada\n");
		free(array);
	}
}

#include <stdio.h>
#include <stdlib.h> //malloc
#include <locale.h>

int main(int argc, char **argv){
	setlocale(LC_CTYPE, "");

	//EJEMPLO 02
	printf("\n\tEJEMPLO 02\n");
	int *array = NULL, num, cont;
	printf("\n\t�Cu�ntos elementos tiene el arreglo?\t");
	scanf("%d", &num);
	array = (int*)calloc(num, sizeof(int)); //calloc resive dos par�metros, la cantidad de elementos y el tama�o de uno de ellos. Garantiza que va a estar iniciado en 0
	if(array != NULL){ //para preguntar si calloc s� asigno espacio
		printf("\n\tVector reservado:\n");
		for(cont = 0; cont < num; cont++){
			printf("\t\t\tvalor:%d  -  dir:%p\n", *(array+cont), array+cont); //cuando es un arreglo, las direcciones son continuas
		}
		printf("\n\n\tLa memoria ser� liberada\n");
		free(array);
	}
	return 0;
}

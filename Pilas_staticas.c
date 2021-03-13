/*
 Nombre:Kevin Badillo Mora
 Matricula: 201733435
 Objetivo: Uso de estuctura Pila Estatica
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct {
 	int index;//index
 	int array[MAX];//arreglo y el MAX el tamaño deñ arreglo 
}PILA;//Alias

//-----------------Funciones------------
//Crear pila
void new_pila(PILA *Pila){
	Pila->index = -1;
}

//EMPTY
bool empty(PILA *Pila){
	if(Pila->index == -1){
		return true;
	}else{
		return false;
	}
}

//FULL
bool full(PILA *Pila){
	if(Pila->index == MAX-1 ){
		return true;
	}else{
		return false;
	}
}

//PUSH
void push(PILA *Pila,int valor){
	if(!full(Pila)){
		Pila->index++;
		Pila->array[Pila->index] = valor;
		printf("Ingresado correctamente");
	}else{
		printf("El arreglo esta lleno \n");
	}
}

//POP
void pop(PILA *Pila){
	if(empty(Pila)){
		printf("El arreglo esta vacio\n");
	}else{
		int eliminar = Pila->index;
		Pila->index--;
		printf("Se a eliminado: %d \n",eliminar);
	}
}

//FRONT
int front(PILA *Pila){
	return Pila->array[Pila->index];
}

//SHOW
void show_array(PILA *Pila,int longitud){
	int contador = 0;
	while(contador <= longitud-1){
		printf("valor %d : %d \n",contador+1, Pila->array[contador]);
		contador++;
	}
}

//-----------------Main-----------------
int main(){

	PILA Pila;
	new_pila(&Pila);//creamos una pila para demostrar que esta vacia
	int exit,num,longitud = 0;
	do{
		int op;
		system("cls");
		printf("Estructura de datos(Pilas) \n");
		printf("1.-Alta del elemento\n");//push
		printf("2.-Baja del elemento\n");//pop
		printf("3.-Elemento que esta en cima\n");//front
		printf("4.-Mostrar datos\n");//empty/full
		fflush(stdin);
		scanf("%d",&op);

		switch(op){
			case 1:
				system("cls");
				printf("\t---PUSH---\n");

				printf("Ingrese elementos, -1 para terminar: ");
                fflush(stdin);
                    scanf("%d",&num);
             
                    while(num != -1){
                    	if(longitud <= MAX-1){
	                        push(&Pila,num);
	                        longitud++;
	                        printf("\n");
	                        printf("Ingrese elementos, -1 para terminar: ");
	                        scanf("%d",&num);
                    	}else{
                    		break;
                    	}
                    }

                    printf("\nDatos ingresados\n");
                    show_array(&Pila,longitud);
				break;
			case 2:
				system("cls");
				printf("\t---POP---\n");
					pop(&Pila);
					longitud--;

				printf("Dato Eliminado\n");
				show_array(&Pila,longitud);
				break;
			case 3:
				system("cls");
				printf("\t---FRONT---\n");
				printf("DATOS DEL array\n");
				show_array(&Pila,longitud);
				printf("\n\n");
				printf("El ultimo es: %i\n",front(&Pila));
				break;
			case 4:
				system("cls");
				printf("\t---Mostrar datos (Empty/Full)---\n");
					if(full(&Pila)){
						printf("El arra esta lleno (FULL)\n");
						show_array(&Pila,longitud);
					}else{
						if(empty(&Pila)){
							printf("El array esta vacio (EMPTY) \n");
						}else{
							show_array(&Pila,longitud);
						}
					}
				break;
			default:
				printf("ERROR! Opcion invalida\n");
				break;
		}
		printf("Realizar otra operacion (si=1/no=0)\n");
		fflush(stdin);
		scanf("%d",&exit);
	}while(exit == 1);
	printf("Gracias por usar el programa\n");
return 0; 
}
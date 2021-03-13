/*
Materia: Estructura de datos
Metodo: Arboles Binarios
Nombre: Kevin Badillo Mora
Matricula: 201733435*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int valor;
	struct nodo *left;//define el puntero siguiente izquierdo si el valor es menor a la raiz
	struct nodo *right;//define el puntero siguiente derecho si el valor es mayor a la raiz
	struct nodo *padre;//define el padre del nodo que ingresemos o eliminemos
}Nodo;

typedef Nodo *tpuntero;//Puntero al tipo de dato Nodo para no utilizar punteros de punteros

Nodo* CrearNodo(int val,tpuntero padre);
static void insertarValorPadre(tpuntero *cabeza,tpuntero padre,int valor);
void insertarValor(tpuntero *cabeza,int valor);
bool Existe(tpuntero *cabeza,int valor);
void DeterminarExistencia(tpuntero cabeza,int valor);
//----------------Recorrido(Pre/Ino/Pos)-------------
void Preorden(tpuntero *cabeza);
void Inorden(tpuntero *cabeza);
void Postorden(tpuntero *cabeza);
//---------------------Eliminar----------------------
void BuscarNodoAEliminar(tpuntero *cabeza,int valor,tpuntero padre);
void vaciarArbol(tpuntero *cabeza);
void validar(tpuntero *cabeza,int cont);
//------------------Mostrar nodos hojas--------------
void mostrarNodosHojas(tpuntero *cabeza);
//-----------------Mostrar Niveles-------------------
void mostrarNiveles(tpuntero *cabeza,int nivel);
//----------------Mostrar no terminales--------------
void NodosNoTerminales(tpuntero *cabeza,tpuntero padre,int n);
//----------------Mostrar generaciones---------------
void mostrarGeneracion(tpuntero cabeza,int nivel);
//----------------Mostrar Arbol Decendente-----------
void mostrarArbolDecendente(tpuntero cabeza,int nivel);

int main(){
	//prueba git
	int out, op,num,op_r, mantener_arbol;
	int next = 1,cont = 0, c_niveles = 0,k,num_n = 0;
	tpuntero cabeza;//Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
	cabeza = NULL;//Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista
    
	do{	
		int out_2 = 1;
		system("cls");
		printf("\t ---ARBOLES BINARIOS--- \n");
		printf("1.- Insertar valores\n");
		printf("2.- Buscar existencia de un valor\n");
		printf("3.- Eliminar\n");
		printf("4.- Recorrido\n");
		printf("5.- Mostrar hojas\n");
		printf("6.- Mostrar nodos NO terminales\n");
		printf("7.- Mostrar nodos de una generacion o nivel en particular\n");
		printf("8.- Mostrar Arbol\n");
		printf("9.- Mostrar Abol de forma Decendente\n");
		printf("10.- Vaciar arbol\n");
		printf("11.- Salir\nOpcion: ");
		scanf("%d",&op);

		switch(op){
			case 1:
				if(cabeza == NULL){
					system("cls");
					printf("\t --[INSERTAR NUEVOS VALORES]--\n");
					printf("Ingresa el elemento, -1 para terminar: ");
	                fflush(stdin);
	                scanf("%d",&num);

                 
               	 	while(num!=-1){
                		cont = cont+1;
                    	if(!Existe(&cabeza,num)){
					        insertarValor(&cabeza,num);
		            	}else{
					        printf("\n\t--[El numero %d ya existe en el arbol]--\n\n",num);
					   	}
                    	printf("Ingresa el elemento, -1 para terminar: ");
                    	fflush(stdin);
                    	scanf("%d",&num);
                	}
                	printf("-------------------------------------------------\n");
                	printf("\n\t--[Valores Ingresados Correctamente]--\n\n");
                	mostrarNiveles(&cabeza,1);
            	}else{
            		system("cls");
            		printf("\t---[EL ARBOL YA A SIDO INICIALIZADO]---\n\n");
            		mostrarNiveles(&cabeza,1);
            		printf("-------------------------------------------------\n");

		            	printf("Eliminar Arbol para ingresar nuevos valores?: (si=1/no=0)\n");
		           		scanf("%d",&mantener_arbol);

		           		switch(mantener_arbol){
		            		case 1:
		            			validar(&cabeza,cont);
		            			printf("Valores del Arbol eliminados Exitosamente!!\n");
		            			printf("Regrese al Menu para ingresar valores Nuevos\n");
		            			break;
		            		case 0:
			           				system("cls");
			           				printf("\t   ---[ARBOL YA EXISTENTE]---\n\n");
			           				mostrarNiveles(&cabeza,1);
									printf("\n\t --[CONTINUE INGRESANDO LOS VALORES]--\n");
									printf("Ingresa el elemento, -1 para terminar: ");
					                fflush(stdin);
					                scanf("%d",&num);
					                 
					               	 	while(num!=-1){
					                		cont = cont+1;
					                		if(!Existe(&cabeza,num)){
					                    		insertarValor(&cabeza,num);
					                    	}else{
					                    		printf("\n\t--[El numero %d ya existe en el arbol]--\n\n",num);
					                    	}
					                    	printf("Ingresa el elemento, -1 para terminar: ");
					                    	fflush(stdin);
					                    	scanf("%d",&num);
					                	}
					                	printf("-------------------------------------------------\n");
					                	printf("\n\t---[Valores Ingresados Correctamente]--\n\n");
					                	mostrarNiveles(&cabeza,1);
		           				break;
		           			default:
		            				printf("ERROR,opcion invalida\n");
		            		}
            	}
				//--------------------------------------------------
				printf("\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 2:
				system("cls");
				printf("\t--[BUSCAR EXISTENCIA]--\n\n");
				mostrarNiveles(&cabeza,1);
				printf("-------------------------------------------------\n");
				printf("Ingrese el valor a buscar, -1 para terminar: ");
                fflush(stdin);
                scanf("%d",&num);
                 
                while(num!=-1){
 					DeterminarExistencia(cabeza,num);
                    printf("Ingrese el valor a buscar, -1 para terminar: ");
                    fflush(stdin);
                    scanf("%d",&num);
				}
				//--------------------------------------------------
				printf("\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 3:
				system("cls");
				if(cabeza != NULL){
					printf("\t --[ELIMINAR]--\n");
					printf("\t --Arbol Actual--\n\n");
					mostrarNiveles(&cabeza,1);
					printf("-------------------------------------------------\n");
					printf("Ingrese el valor que quiera eliminar, -1 para terminar: ");
	                fflush(stdin);
	                scanf("%d",&num);
	                 
	                while(num!=-1){
	                	if(Existe(&cabeza,num)){
	 						BuscarNodoAEliminar(&cabeza,num,NULL);
	 					}else{
	 						printf("El numero %d NO!! existe en el arbol\n",num);
	 					}
	                    printf("Ingrese el valor que quiere eliminar, -1 para terminar: ");
	                    fflush(stdin);
	                    scanf("%d",&num);
					}
					printf("-------------------------------------------------\n");
					printf("\n\t--[Valores eliminados Exitosamente!!]--\n\n");
					mostrarNiveles(&cabeza,1);
				}else{
					printf("---[ARBOL NO INICIALIZADO]---");
				}
				//--------------------------------------------------
				printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 4:
				do{
					    printf("\n");
					    printf("\t --[RECORRIDO]--\n");
						printf("\t1.-Preorden\n");
						printf("\t2.-Inorden\n");
						printf("\t3.-Postorden\n");
						printf("\t4.- <-- BACK\n\tOpcion: ");
						scanf("%d",&op_r);

						switch(op_r){
							case 1:
								system("cls");
								printf("\t--[PREORDEN]--\n\n");
								Preorden(&cabeza);
								printf("\n");
								break;
							case 2:
								system("cls");
								printf("\t--[INORDEN]--\n\n");
								Inorden(&cabeza);
								printf("\n");
								break;
							case 3:
								system("cls");
								printf("\t--[Postorden]--\n\n");
								Postorden(&cabeza);
								printf("\n");
								break;
							case 4:
								out_2 -= 1;
								break;
							default:
								printf("ERROR,OPCION INVALIDA!!!\n");
							}
					}while(out_2 == 1);
					out = 1;
				break;
			case 5:
				system("cls");
				printf("\t---[MOSTRAR NODOS HOJAS]---\n\n");
				mostrarNiveles(&cabeza,1);
				printf("-------------------------------------------------\n\n");
				printf("\t   ");
				clock_t inicio,fin; //variables para medir tiempo
  				inicio=fin=clock();
				mostrarNodosHojas(&cabeza);
				fin=clock();
				printf("El tiempo de ejecucion de esa parte es %lf",((fin-inicio)/(double)CLOCKS_PER_SEC));
				//--------------------------------------------------
				printf("\n\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 6:
				system("cls");
				printf("\t---[MOSTRAR NODOS HOJAS NO TERMINALES]---\n\n");
				mostrarNiveles(&cabeza,1);
				printf("-------------------------------------------------\n\n");
				printf("\t   ");
				NodosNoTerminales(&cabeza,NULL,0);
				//--------------------------------------------------
				printf("\n\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 7:
				system("cls");
				printf("\t---[MOSTRAR N0DOS POR GENERACION]---\n\n");
				printf("\t   ---[ARBOL]---\n");
				mostrarNiveles(&cabeza,1);

				if(cabeza != NULL){
					printf("---------------------------------------------------\n");
					printf("Ingrese el nivel o generacion que desea mostrar: ");
					scanf("%d",&k);
					printf("\n\t");
					mostrarGeneracion(cabeza,k);
				}else{
					printf("---[El ARBOL NO EXISTE!!]---\n");
				}
				//--------------------------------------------------
				printf("\n\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 8:
				system("cls");
				printf("\t--[MOSTRAR ARBOL CON NIVELES]--\n\n");
				mostrarNiveles(&cabeza,1);
				//--------------------------------------------------
				printf("--------------------------------------------------");
				printf("\n\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 9:
				system("cls");
				printf("\t---[MOSTRAR ARBOL DECENDENTE]---\n\n");
				printf("\t   ---[ARBOL]---\n");

				if(cabeza != NULL){
					mostrarNiveles(&cabeza,1);
					printf("Ingrese el nivel de donque quiere decender: \n");
					fflush(stdin);
					scanf("%d",&num_n);

					while(num_n != 0){ 
						printf("Nivel %d : ",num_n);
						mostrarArbolDecendente(cabeza,num_n);
						printf("\n");
						num_n = num_n - 1;
					}
				}else{
					printf("---[El ARBOL NO EXISTE!!]---\n");
				}
				//--------------------------------------------------
				printf("\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);

				break;
			case 10:
				printf("\t---[ARBOL VACIADO]---");
				validar(&cabeza,cont);
				//--------------------------------------------------
				printf("\nDesea regresar al Menu?(si=1/no=0): ");
                fflush(stdin);
                scanf("%d",&out);
				break;
			case 11:
				printf("\t---[GRACIAS POR USAR EL PROGRAMA]---\n");
				out = 0;
				break;
			default:
				printf("ERROR!!, opcion invalida\n");
				system("PAUSE");
				out = 1;
		}
	}while(out == 1);
	if(cabeza != NULL){
		validar(&cabeza,cont);
		printf("\t     --[ARBOL ELIMINADO]--\n");
	}
	return 0;
}
//--------------------------------------------------INSERTAR VALORES-----------------------------------------------------
Nodo* CrearNodo(int val,tpuntero padre){
	Nodo* nuevoValor; 
	nuevoValor = (Nodo *) malloc(sizeof(Nodo));
	nuevoValor->valor = val;
	nuevoValor->left = NULL;
	nuevoValor->right = NULL;
	nuevoValor->padre;
	return nuevoValor;
}

static void insertarValorPadre(tpuntero *cabeza,tpuntero padre,int valor){
	if(*cabeza != NULL){
		int valorRaiz = (*cabeza)->valor;
		if(valor < valorRaiz){
			insertarValorPadre(&(*cabeza)->left,(*cabeza),valor);
		}else{
			insertarValorPadre(&(*cabeza)->right,(*cabeza),valor);
		}
	}else{
		*cabeza = CrearNodo(valor,padre);
	}
}

void insertarValor(tpuntero *cabeza,int valor){
	insertarValorPadre(&(*cabeza),NULL,valor);
}

//------------------------------------------------EXISTENCIAS-------------------------------------------------------------
bool Existe(tpuntero *cabeza,int valor){
	if(*cabeza == NULL){
		return false;
	}else if(valor == (*cabeza)->valor){
			return true;
		}else if(valor < (*cabeza)->valor){
				return Existe(&(*cabeza)->left,valor);
			}else{
				return Existe(&(*cabeza)->right,valor);
			}
}

void DeterminarExistencia(tpuntero cabeza,int valor){
	if(Existe(&cabeza,valor)){
		printf("\n\t---[El valor %d SI existe en el arbol]---\n\n",valor);
	}else{
		printf("\n\t---[El valor %d NO existe en el arbol]---\n\n",valor);
	}
}

//-----------------------------------------------------RECORRIDO---------------------------------------------------------

void Preorden(tpuntero *cabeza){
	if(*cabeza != NULL){
		printf(" -[%d]-",(*cabeza)->valor);
		Preorden(&(*cabeza)->left);
		Preorden(&(*cabeza)->right);
	}
}

void Inorden(tpuntero *cabeza){
	if(*cabeza != NULL){
		Inorden(&(*cabeza)->left);
		printf(" [%d]- ",(*cabeza)->valor);
		Inorden(&(*cabeza)->right);
	}
}

void Postorden(tpuntero *cabeza){
	if(*cabeza != NULL){
		Postorden(&(*cabeza)->left);
		Postorden(&(*cabeza)->right);
		printf("-[%d]-",(*cabeza)->valor);
	}
}

//-----------------------------------------------------ELIMINAR----------------------------------------------------------
void destruirNodo(tpuntero *nodo){
	printf("Nodo a destruir = %d\n",(*nodo)->valor );
	(*nodo)->left = NULL;
	(*nodo)->right = NULL;
	free(nodo);
}

static void Remplazar(tpuntero *nodo_encontrado, tpuntero nuevoNodo, tpuntero padre){
	//si es NULL, entonces es un nodo hoja a eliminar
	if(nuevoNodo == NULL){
		if((*nodo_encontrado)->valor < padre->valor){//el ultimo es izquierda
			destruirNodo(&(*nodo_encontrado));
			 padre->left = nuevoNodo;  
		}else if((*nodo_encontrado)->valor > padre->valor){// el ultimo es dercha
			destruirNodo(&(*nodo_encontrado));
			padre->right = nuevoNodo;	
		}
	}

	if(nuevoNodo != NULL){
		if((*nodo_encontrado)->valor < padre->valor){//el ultimo es izquierda
			destruirNodo(&(*nodo_encontrado));
			 padre->left = nuevoNodo;  
		}else if((*nodo_encontrado)->valor > padre->valor){// el ultimo es dercha
			destruirNodo(&(*nodo_encontrado));
			padre->right = nuevoNodo;	
		}		
	}
}

//buscamos el minimo si el valor a eliminar es la Raiz pasando como parametro la derecha para buscar el minimo izquierdo
static Nodo* nodoMinimo(tpuntero ultimo){
	if(ultimo == NULL){
		return NULL;
	}
	if(ultimo->left){
		return nodoMinimo(ultimo->left);
	}else{
		return ultimo;
	}
}

static void nodoPadre(tpuntero *ultimo,tpuntero padre){//a partir de la derecha buscamos la izquierda
	if((*ultimo)->left){
		nodoPadre(&(*ultimo)->left,(*ultimo));
	}else{
		Remplazar(&(*ultimo),NULL,padre);
	}
}

static void EliminarNodo(tpuntero *nodo_encontrado,tpuntero padre){
	if((*nodo_encontrado)->left && (*nodo_encontrado)->right){//si el nodo encontrado a eliminar tiene dos hijos
		tpuntero aux_nodo = *nodo_encontrado;
		tpuntero minimo = nodoMinimo((*nodo_encontrado)->right);
		(*nodo_encontrado)->valor = minimo->valor;
		nodoPadre(&aux_nodo->right,aux_nodo);//contador para padre
		 
		//para ambos es 2
	}else if((*nodo_encontrado)->left){//si el nodo encontrado a eliminar tiene un hijo izquierdo
		Remplazar(&(*nodo_encontrado),(*nodo_encontrado)->left,padre);

	}else if((*nodo_encontrado)->right){//si el nodo encontrado a eliminar tiene un hijo derecho
		Remplazar(&(*nodo_encontrado),(*nodo_encontrado)->right,padre);
	}else{
		Remplazar(&(*nodo_encontrado),NULL,padre);
	}
}

void BuscarNodoAEliminar(tpuntero *cabeza,int valor,tpuntero padre){
	if(*cabeza == NULL){
		return;
	}else if(valor < (*cabeza)->valor){
		BuscarNodoAEliminar(&(*cabeza)->left,valor,(*cabeza));
	}else if(valor > (*cabeza)->valor){
		BuscarNodoAEliminar(&(*cabeza)->right,valor,(*cabeza));
	}else{
		EliminarNodo(&(*cabeza),padre);

	}
}
//--------------------------------------------------VACIAR ARBOL---------------------------------------------------------
void vaciarArbol(tpuntero *cabeza){ 
	if(*cabeza != NULL){	
		if((*cabeza)->left && (*cabeza)->right){
			vaciarArbol(&(*cabeza)->left);      
			vaciarArbol(&(*cabeza)->right);     
		}else if((*cabeza)->left){
			vaciarArbol(&(*cabeza)->left);
		}else if((*cabeza)->right){
			vaciarArbol(&(*cabeza)->right);
		}else{
			tpuntero actual = *cabeza;
			free(actual);
			actual = NULL;
			*cabeza = actual;
		}
	}else{
		printf("\t---[ARBOL NO INICIALIZADO]---\n");
	}
}

void validar(tpuntero *cabeza,int cont){
	int next = 0;
	while(next != cont){
		if(*cabeza != NULL){
			vaciarArbol(&(*cabeza));
			next = next+1;
		}else{
			next = 0;
			next = cont;
		}

	}
}

//------------------------------------------------MOSTRAR HOJAS----------------------------------------------------------
void mostrarNodosHojas(tpuntero *cabeza){
	if(*cabeza != NULL){
		if((*cabeza)->left && (*cabeza)->right){
			mostrarNodosHojas(&(*cabeza)->left);      
			mostrarNodosHojas(&(*cabeza)->right);     
		}else if((*cabeza)->left){
			mostrarNodosHojas(&(*cabeza)->left);
		}else if((*cabeza)->right){
			mostrarNodosHojas(&(*cabeza)->right);
		}else{
			tpuntero nodo_num = *cabeza;
			printf("[%d]",nodo_num->valor);
		}
	}else{
		printf("\t---[ARBOL NO INICIALIZADO]---\n");
	}
}
//--------------------------------------------MOSTRAR NODOS NO TERMINALES-------------------------------------------------
void NodosNoTerminales(tpuntero *cabeza,tpuntero padre,int n){

	int pass = n;
	if(padre == NULL){
			if((*cabeza)->left && (*cabeza)->right){
				NodosNoTerminales(&(*cabeza)->left,(*cabeza),1);      
				NodosNoTerminales(&(*cabeza)->right,(*cabeza),1);     
			}else if((*cabeza)->left){
				NodosNoTerminales(&(*cabeza)->left,(*cabeza),1);
			}else if((*cabeza)->right){
				NodosNoTerminales(&(*cabeza)->right,(*cabeza),1);
			}
			
		}

		if(pass == 1){
			if((*cabeza)->left && (*cabeza)->right){
				printf("[%d]",(*cabeza)->valor);
				NodosNoTerminales(&(*cabeza)->left,(*cabeza),pass);      
				NodosNoTerminales(&(*cabeza)->right,(*cabeza),pass);     
			}else if((*cabeza)->left){
				printf("[%d]",(*cabeza)->valor);
				NodosNoTerminales(&(*cabeza)->left,(*cabeza),pass);
			}else if((*cabeza)->right){
				printf("[%d]",(*cabeza)->valor);
				NodosNoTerminales(&(*cabeza)->right,(*cabeza),pass);
			}
		}
}
//------------------------------------------MOSTRAR ARBOL(NIVELES)-------------------------------------------------------
void tabulador(int nivel){
	int n = 0;
	while(n != nivel){
		printf("\t");
		n = n+1;
	}
}

void mostrarNiveles(tpuntero *cabeza,int nivel){// AQUI!
	if(*cabeza!=NULL){
		if((*cabeza)->left && (*cabeza)->right){//Si los nodo siguientes(izquierda/derecha) de actual existen
			tabulador(nivel);
			printf("N%d:[%d]------%c\n",nivel,(*cabeza)->valor,191);
			nivel+=1;
			mostrarNiveles(&(*cabeza)->left,nivel);//aplicamos Recursividad para llegar al ultimo nodo,donde sus nodos siguientes(izq/der)
			mostrarNiveles(&(*cabeza)->right,nivel);//para mostrar las hojas
		}else if((*cabeza)->left){
			tabulador(nivel);
			printf("N%d:[%d]------%c\n",nivel,(*cabeza)->valor,191);
			nivel+=1;
			mostrarNiveles(&(*cabeza)->left,nivel);
		}else if((*cabeza)->right){
			tabulador(nivel);
			printf("N%d:[%d]------%c\n",nivel,(*cabeza)->valor,191);
			nivel+=1;
			mostrarNiveles(&(*cabeza)->right,nivel);
		}else{
			tabulador(nivel);
			printf("N%d:[%d]\n",nivel,(*cabeza)->valor);
		}	
	}else{
		printf("\t---[ARBOL NO INICIALIZADO]---\n");
	}
}
//----------------------------------------------MOSTRAR NODOS POR NIVELES-------------------------------------------------
void mostrarGeneracion(tpuntero cabeza,int nivel){
	tpuntero izquierda = cabeza, derecha = cabeza;
	if(nivel != 1 && cabeza != NULL){
		izquierda = izquierda->left;
		derecha = derecha->right;
		nivel = nivel-1;
		mostrarGeneracion(izquierda,nivel);
		mostrarGeneracion(derecha,nivel);
	}else if(cabeza != NULL){
		printf("[%d]",izquierda->valor);
	} 
}
//---------------------------------------------MOSTRAR DE FORMA DECENDENTE------------------------------------------------

void mostrarArbolDecendente(tpuntero cabeza,int nivel){
	tpuntero izquierda = cabeza, derecha = cabeza;
	if(nivel != 1 && cabeza != NULL){
		izquierda = izquierda->left;
		derecha = derecha->right;
		nivel = nivel-1;
		mostrarArbolDecendente(izquierda,nivel);
		mostrarArbolDecendente(derecha,nivel);
	}else if(cabeza != NULL){

			printf("[%d]",izquierda->valor);
		
	} 
}
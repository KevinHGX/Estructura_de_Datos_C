/*
Materia: Estructura de datos
Metodo: Lista enlazada
Nombre: Kevin Badillo Mora
Matricula: 201733435*/

//para ejecutar en terminal comando: gcc 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct snodo{ //snodo es el nombre de la estructura
    int valor;
    struct snodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es la declaracion de estructura
 
typedef tnodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros

//-------------------------------------------------
void PUSH_PILA(tpuntero *cabeza, int e);         //
void FRONT_PILA(tpuntero *cabeza);               // PILAS
void POP_PILA(tpuntero *cabeza);                 //
//-------------------------------------------------
//-------------------------------------------------
void PUSH_COLA(tpuntero *cabeza,int e);          //
void FRONT_COLA(tpuntero *cabeza,int tam);       // COLAS
void POP_COLA(tpuntero *cabeza,int tam);         //
//------------------------------------------------
//--------------------------------------------------------
void PUSH_ENTRE_NODOS(tpuntero *cabeza,int e,int n);     // (INSERTAR/ELIMINAR) ENTRE NODOS
void POP_ENTRE_NODOS(tpuntero *cabeza,int n,int tam);    //
//--------------------------------------------------------
//----------------------------------------------------------
void ORDENAMIENTO_NODOS(tpuntero *cabeza);                 //
void BUSQUEDA_NODO(tpuntero *cabeza,int n,int tam);        //
int CONTADOR_NODO(tpuntero *cabeza);                       // FUNCIONES EXTRAS
void IMPRIMIR_LISTA(tpuntero cabeza);                      //
void MOSTRAR_LISTA(tpuntero cabeza);                       //
void BORRAR_LISTA (tpuntero *cabeza);                      //
void MOSTRAR_AGREGADO(tpuntero *cabeza, int index,int tam);//
void IMAGEN(int res);                                      //
//----------------------------------------------------------
int main(){
    
    int e,op,res,tam;
    tpuntero cabeza; //Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
    cabeza = NULL; //Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista
    
    do{
        int op_index = 0,n = 0;
        system("cls");
        printf("\t---LISTA ENLAZADA---\n\n");
        printf("\t---PILAS---\n");
        printf("1.-Ingresar al principio de la Lista\n");
        printf("2.-Elemento que esta al Inicio\n");//agregar funcion
        printf("3.-Eliminar el primer dato de la Lista\n");
        printf("\n\t---COLAS---\n");
        printf("4.-Ingresar al final de la Lista\n");
        printf("5.-Elementos que estan al Inicio y Final\n");//agregar funcion
        printf("6.-Eliminar al final de la Lista\n");
        printf("\n\t---ENTRE NODOS---\n");
        printf("7.-Ingresar entre los valores de la Lista\n");
        printf("8.-Eliminar entre los nodos\n");
        printf("\n\t---FUNCIONES EXTRAS---\n");
        printf("9.-Ordenar nodos\n");
        printf("10.-Busqueda de valores\n");
        printf("11.-Mostrar nodos\n");
        printf("12.-Salir\nOpcion: ");
        fflush(stdin);
        scanf("%d",&op);

        switch(op){
    
            case 1:
                    system("cls");
                    printf("\t---INGRESAR AL PRINCIPIO---\n");
                    printf("Ingrese elementos, -1 para terminar: ");
                    fflush(stdin);
                    scanf("%d",&e);
                 
                    while(e!=-1){
                        PUSH_PILA(&cabeza, e);
                        printf ("Ingresado correctamente");
                        printf ("\n");
                        printf("Ingrese elementos, -1 para terminar: ");
                        scanf("%d",&e);
                    }

                    printf("\nDatos ingresados\n");
                    IMPRIMIR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                break;
            case 2:
            		system("cls");
            		printf("\t---FRONT PILA---\n");
            		MOSTRAR_LISTA(cabeza);
            		printf("\n\n");
            		FRONT_PILA(&cabeza);
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                break;
            case 3:
                   	system("cls");
                    printf("\t---ELIMINAR AL PRINCIPIO---\n\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\tLongitud: %d",CONTADOR_NODO(&cabeza));
                    printf("\n\n");
                    POP_PILA(&cabeza);
                    printf("Eliminacion exitosa!!\n\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res); 
                break;
            case 4:
            		system("cls");
                    printf("\t---INGRESAR AL FINAL---\n");
                    printf("Ingrese elementos, -1 para terminar: ");
                    fflush(stdin);
                    scanf("%d",&e);
             
                    while(e!=-1){
                        PUSH_COLA(&cabeza,e);
                        printf ("Ingresado correctamente");
                        printf ("\n");
                        printf("Ingrese elementos, -1 para terminar: ");
                        scanf("%d",&e);
                    }
                    printf("\nDatos ingresados\n");
                    IMPRIMIR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);      
                break;
            case 5:
            		system("cls");
            		printf("\t---FRONT COLA---\n");
            		MOSTRAR_LISTA(cabeza);
            		printf("\n\n");
            		tam = CONTADOR_NODO(&cabeza);
            		FRONT_COLA(&cabeza,tam);
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res); 
                break;
            case 6:
            		system("cls");
                    printf("\t---ELIMINAR AL FINAL---\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---",CONTADOR_NODO(&cabeza));
                    printf("\n\n");
                    tam = CONTADOR_NODO(&cabeza);
                    POP_COLA(&cabeza,tam);
                    printf("Eliminacion exitosa!!\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                break;
            case 7:
            		system("cls");
                    printf("\t---INGRESAR ENTRE LOS NODOS---\n\n");
                    printf("Datos de la lista: \n");

                    MOSTRAR_LISTA(cabeza);

                    printf("\nElija a partir de que posicion quiere ingresar\nOpcion: ");
                    fflush(stdin);
                    scanf("%d",&op_index);

                    while(op_index != 0){
                            printf("Ingrese dato: ");
                            fflush(stdin);
                            scanf("%d",&e);
                            PUSH_ENTRE_NODOS(&cabeza,e,op_index);
                            printf("\n\n");
                            tam = CONTADOR_NODO(&cabeza);
                            MOSTRAR_AGREGADO(&cabeza,op_index,tam);
                            printf("\nIngresado correctamente\n");
                            printf("\nSi desea agregar otro valor, ingrese el indice\nDe lo contrario para salir ingrese 0\nOpcion: ");
                            fflush(stdin);
                            scanf("%d",&op_index);
                           }

                    system("cls");
                    printf("\nDatos Actualizados\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\n\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                    
                break;
            case 8:
            		system("cls");
                    printf("\t---ELIMINAR ENTRE LOS NODOS---\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\n");
    
                    tam = CONTADOR_NODO(&cabeza);

                    if(tam>2){
                        printf("\nElija a partir de que posicion(indice) quiere Eliminar\nOpcion: ");
                        fflush(stdin);
                        scanf("%d",&op_index);
                            POP_ENTRE_NODOS(&cabeza,op_index,tam);
                            printf("Eliminacion exitosa!!\n");
                            MOSTRAR_LISTA(cabeza);
                            printf("\n\t  ---[ Longitud: %d ]---",CONTADOR_NODO(&cabeza));
                    }else{
                        printf("No pudes quitar nodo si la longitud es : %d\n",tam);
                    }
                    //------------------------------------------------------------
                    printf("\n\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                    
                break;
            case 9:
             		system("cls");
                    printf("\t---ORDENAMIENTO---\n\n");
                    printf("LISTA ORIGINAL\n");
                    MOSTRAR_LISTA(cabeza);
                    ORDENAMIENTO_NODOS(&cabeza);
                    printf("LISTA ORDENADA\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                    
                break;
            case 10:
            		system("cls");
                    printf("\t\t---BUSQUEDA_NODO---\n\n");
                    IMPRIMIR_LISTA(cabeza);
                    tam = CONTADOR_NODO(&cabeza);
                    printf("\nIngrese el valor que desea buscar. \nvalor: ");
                    fflush(stdin);
                    scanf("%d",&n);
                    BUSQUEDA_NODO(&cabeza,n,tam);
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
                   
                break;
            case 11:
           	 		system("cls");
                    printf("\t---LISTA---\n\n");
                    MOSTRAR_LISTA(cabeza);
                    printf("\n\t  ---[ Longitud: %d ]---\n",CONTADOR_NODO(&cabeza));
                    //------------------------------------------------------------
                    printf("\nDesea realizar nuevamente el programa?(si=1/no=0): ");
                    fflush(stdin);
                    scanf("%d",&res);
            	break;
            case 12:
             		printf("\t\t\t  ---[ GRACIAS POR USAR EL PROGRAMA ]---\n");
                    res = 0;
                    IMAGEN(res);
            	break;
            default:
                printf("ERROR OPCION INVALIDA");
            }

    }while(res==1);
    //-----------------------------------------------
    printf ("\n\t\t   ---[ LIBERACION DE MEMORIA - NODOS DESTRUIDOS ]---\n");
    BORRAR_LISTA(&cabeza);
return 0;
}
 //---------------------------------------FUNCIONES---------------------------------------------------------
 //----------------------------------PILA (PUSH/FRONT/POP)-----------------------------------------------
 
void PUSH_PILA(tpuntero *cabeza, int e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(tnodo)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor = e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza        
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado                
}

void FRONT_PILA(tpuntero *cabeza){
	if(*cabeza != NULL){
		tpuntero Inicio = *cabeza; 
		printf("El primer valor(nodo) en la Pila es: %d ",Inicio->valor);//Retornamos el primer valor
	}else{
		printf("Lista no inicializada\n");
	}
}

void POP_PILA(tpuntero *cabeza){
    if(*cabeza != NULL){//si cabeza no es NULL
        tpuntero eliminar = *cabeza;//"eliminar" toma el valor de cabeza
        printf("El valor a eliminar es: %d \n",eliminar->valor);
        *cabeza = (*cabeza)->sig;//Cabeza ahora avanza una posicion
        free(eliminar);//se libera la memoria de "eliminar(primer nodo)"
    }else{
        printf("Lista no inicializada\n");
    }
}

//-----------------------------------COLA (PUSH/FRONT/POP)------------------------------------------------

void PUSH_COLA(tpuntero *cabeza,int e){
    tpuntero final, aux;//Creamos nuevo nodo
    final = malloc(sizeof(tnodo));//Utilizamos malloc para reservar memoria para ese nodo
    final->valor = e;//ingresamos el valor al Nodo rescien creado
    final->sig = NULL;//asignamos el siguiente nodo como NULL

    if(*cabeza == NULL){//Preguntamos si la cabeza esta vacia pra asignar el primer nodo
        *cabeza = final;//Cabeza pasa a ser el ultimo nodo creado
    }else{
        aux = *cabeza;//aux pasa a ser la lista que se crea anterior mente ya que la lista no esta vacia
        //[1]->[4]->[6]->[7]->[NULL]
        while(aux->sig != NULL){//Recorrido de los nodos
            aux = aux->sig;
        }
        aux->sig = final;//Asignamos el valor al siguiente nodo   
    }
}

void FRONT_COLA(tpuntero *cabeza,int tam){
	if(*cabeza != NULL){
		tpuntero Inicio = *cabeza;
			printf("El primero valor(nodo) de la Cola es: %d \n",Inicio->valor);//mostramos el primer valor
		tpuntero Final = *cabeza;
		int posicion = 1;
		while(posicion != tam-1 &&Final->sig){//Si Final es diferente de NULL, nos recorremos al siguiente valor
			Final = Final->sig;//hasta encontrar NULL y mostrar asi el ultimo valor
			posicion = posicion+1;
		}

		printf("El ultimo valor(nodo) de la Cola es: %d \n",Final->sig->valor);
	}else{
		printf("Lista no inicializada\n");
	}
}

void POP_COLA(tpuntero *cabeza,int tam){
    if(*cabeza != NULL){
        tpuntero eliminar = *cabeza;
        int posicion = 1;
        //[1]->[2]->[3]->[4] tam=4
        // penultimo es 3 (3 = 4-1)
        while(posicion != tam-1 && eliminar->sig){//nos ubicamos en el penultimo nodo
            eliminar = eliminar->sig;//asigno el siguiente nodo
            posicion = posicion+1;//
        }
        
        printf("El valor a eliminar es: %d\n\n",eliminar->sig->valor);
            free(eliminar->sig);//liberamos el nodo
            eliminar->sig = NULL;//asignamos que sea null
    }else{
        printf("Lista no inicializada\n");
    }
}
//--------------------------------------ENTRE LOS NODOS(PUSH/POP)-----------------------------------------------
void PUSH_ENTRE_NODOS(tpuntero *cabeza,int e,int n){
    tpuntero middle;//creacion del nodo
    middle = malloc(sizeof(tnodo));//Utilizamos malloc para reservar memoria para ese nodo
    middle->valor = e;//ingresamos el valor al Nodo rescien creado
    middle->sig = NULL;//asignamos el siguiente nodo como NULL

    if(*cabeza == NULL){
        *cabeza = middle;
    }else{
        /*                  |->[nuevo valor]<-|
        valores --> [2],[7],|                 |,[8]
        posicion     1   2           3           4
         */
        tpuntero rigth = *cabeza;//aux pasa a ser la lista que se crea anteriormente ya que la lista no esta vacia
        int posicion = 1;
        while(posicion != n && rigth->sig){//Recorrido de los nodos
            rigth = rigth->sig;//me posiciono en el siguiente nodo
            posicion = posicion+1;
        }
        //1=[8]
        middle->sig = rigth->sig;//Conectamos por la derecha

        rigth->sig = middle;//Conectamos por la izquierda

    }
}

void POP_ENTRE_NODOS(tpuntero *cabeza,int n,int tam){
        if(*cabeza != NULL){
            if(n == 1){
                tpuntero eliminar = *cabeza;//"eliminar" toma el valor de cabeza
                printf("El valor a eliminar es: %d \n\n",eliminar->valor);
                *cabeza = (*cabeza)->sig;//Cabeza ahora avanza una posicion
                free(eliminar);//se libera la memoria de "eliminar(primer nodo)"
            }else if(n < tam){
                tpuntero puntero = *cabeza;
                int posicion = 1;
                while(posicion < (n-1)){
                        puntero = puntero->sig;
                        posicion++;
                }
                tpuntero eliminar = puntero->sig;
                puntero->sig = eliminar->sig;
                printf("El valor a eliminar es: %d \n\n",eliminar->valor);
                free(eliminar);
            }
        }else{
            printf("Lista no inicializada\n");
        } 
}

//-------------------------------------ORDENAMINETO DE NODOS---------------------------------------------
void ORDENAMIENTO_NODOS(tpuntero *cabeza){
    if(*cabeza != NULL){
        tpuntero I, J;
        int temporal = 0;
        //[1][2][3]
        I = *cabeza;
        while(I != NULL){
            J = I->sig ;//asignamos el nodo siguiente a J
            while(J != NULL){
                if(I->valor > J->valor){//Comparamos si el primer valor(I) es mayor a segundo(J)

                    temporal = I->valor;
                    I->valor = J->valor;
                    J->valor = temporal;
                 }
                 J = J->sig;
            }
            I = I->sig;
        }
    }else{
        printf("Lista no inicializada\n");
    }
}
//-------------------------------------BUSQUEDA DE NODOS-------------------------------------------------
void BUSQUEDA_NODO(tpuntero *cabeza,int n,int tam){
    tpuntero Numero = *cabeza;
    int cont = 0;    
    if(*cabeza != NULL){
        printf("\nPOSICION : VALOR\n");
        int posicion = 1;

        while(posicion<=tam){//(1<=4)
            
            while(n == Numero->valor){
                printf("     %d ===> %d \n",posicion,Numero->valor);
                cont = cont+1;
                break;
                }
                Numero = Numero->sig;
                posicion = posicion+1;
            }
    }else{
        printf("Lista no inicializada\n");
    }

    if(cont == 0){
            printf("El numero %d no se encuetra en la lista!!\n",n);
        }
}
//---------------------------------LONGITUD DE LA LISTA DE NODOS---------------------------------------
int CONTADOR_NODO(tpuntero *cabeza){
    tpuntero recorrido = *cabeza;
    int longitud = 0;//contador o tamaño
    while(recorrido != NULL){
        recorrido = recorrido->sig;//Asigno el siguiente nodo
        longitud = longitud+1;
    }
    return longitud;
}
//---------------------------------MOSTRAR DATOS DENTRO DE LOS NODOS-----------------------------------
void IMPRIMIR_LISTA(tpuntero cabeza){
    printf("\t---[");
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("[%d],",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
    printf("]---\n");
}

void MOSTRAR_LISTA(tpuntero cabeza){
    int index = 1;
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("El valor esta en la posicion %d : [%d]\n",index,cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
        index = index+1;
    }
}
//---------------------------------------MOSTRAR AGREGADO-----------------------------------------------
void MOSTRAR_AGREGADO(tpuntero *cabeza, int index,int tam){
	tpuntero recorrido = *cabeza;
	int posicion = 1;
    while(recorrido != NULL){ //Mientras cabeza no sea NULL
    	if(posicion == (index+1)){
    		printf("El valor esta en la posicion %d : [%d] <-- Nuevo Valor\n",posicion,recorrido->valor); //Imprimimos el valor del nodo
       		recorrido = recorrido->sig; //Pasamos al siguiente nodo
        	posicion = posicion+1;
    	}else{
        	printf("El valor esta en la posicion %d : [%d]\n",posicion,recorrido->valor); //Imprimimos el valor del nodo
       		recorrido = recorrido->sig; //Pasamos al siguiente nodo
        	posicion = posicion+1;
    	}
	}
}

//---------------------------------------LIBERAR LOS NODOS-----------------------------------------------
void BORRAR_LISTA(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}

//---------------------------------------IMAGEN DE DESPEDIDA (GATO)--------------------------------------
void IMAGEN(int res){
	if(res == 0){
				printf("\t                    ..::.                        ..                  \n");
				printf("\t                  .:   :::.                   ..::::                 \n");
             	printf("\t                .:     ::::.                .:     ::                \n");
             	printf("\t               .:       ::::::::.......   .:       :::               \n");
             	printf("\t             .:              :::::::::::::::       ::::              \n");
             	printf("\t            .:                                      :::.             \n");
             	printf("\t          .:                                        :::::            \n");
             	printf("\t       .::::.                               .::::.     ::::          \n");
				printf("\t     .:      ::    ::::             ::::  .:      ::      ::.        \n");
				printf("\t    .   * *   ::   ::::  .. ... ..  ::::  :   * *   ::      ::.      \n");
				printf("\t    :   * [@]             '::'::'         :   * [@]           :::    \n");
				printf("\t    :                                      :                   ::::  \n");
				printf("\t_____:._____________________________________::__________________:::: \n");
	}

}
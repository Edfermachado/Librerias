#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
		
		typedef struct COLA{

			int length;
			NODE* first;
			NODE* last;

			}COLA;


		void create_c(COLA* cola){
			
			cola->first=NULL;
			cola->last=NULL;
			cola->length = 0;
		
			}
		void insert_c(COLA *cola, int item){
			NODE* new_node = (NODE*)malloc(sizeof(NODE*));
			if(new_node == NULL){printf("Error: No hay suficiente espacio");
				}else{
				
				new_node->info = item;
				new_node->next = NULL;
				if(cola->last == NULL){
				cola->first = new_node;
				}else{
				cola->last->next = new_node;
				}
				cola->last = new_node;
				cola->length++;

				}
			}
		void show_first_c(COLA *cola){
				
				printf("El primero de la cola es: %d\n", cola->first->info);
			
				}
		void show_last_c(COLA *cola){
				printf("El ultimo de la cola es: %d\n", cola->last->info);
				}
		int take_last_c(COLA *cola){
				if(cola->first != NULL){
					return(cola->last->info);
					}else{return(-1);}
			
			}
		int take_first_c(COLA *cola){
				
				if(cola->last!=NULL){
					return(cola->first->info);
					}else{return(-1);}
				}

		void dequeue_c(COLA *cola) {
   			 if (cola->first != NULL) {
        		NODE *temp = cola->first;
       			 cola->first = cola->first->next;
       			 free(temp);
       			 cola->length--;

        		 if (cola->first == NULL) {
            		// Si la cola se ha vuelto vacía, también actualizamos el puntero "last"
            		cola->last = NULL;
        					}
    				} else {
       				printf("No se puede desencolar, la cola está vacía.\n");
    						}
					}

			int length_c(COLA *cola){
					return(cola->length);
					}
				

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nodo.c"
	 /*typedef struct NODE{
		int info;
		struct NODE* next;
	}NODE; */

	typedef struct LIST{
		int length;
		struct NODE* head; //Nodo cabecera
		}LIST;

	void create_list(LIST *list){
		
		//inicializa el tamaño de la lista
		list->length = 0;
		
		//crear el nodo cabecera y apuntadar el primer nodo a NULL
		list->head =(NODE *)malloc(sizeof(NODE));
		list->head->next = NULL;
	}
	
	void insert_list(LIST *list, int item){
		
		NODE* new_node = (NODE *)malloc(sizeof(NODE));
		NODE* aux = list->head;
		new_node->info=item;
		new_node->next=NULL;
		//Insertar el nuevo nodo al principio de la lista
		//new_node->next = list->head->next;
		//list->head->next=new_node;
		if(list->length == 0){
		list->head->next = new_node;
		}else{
			while(aux->next!=NULL){
				aux = aux->next;
			}
			aux->next = new_node;
		
			}
		list->length++;
	}
	
	int consult_list(LIST *list, int pos){
		//Apunta currente justo despues del nodo cabecera para tener el nodo real
		NODE* current = list->head->next;
		int n,i;
		n= pos;
		for(i=1;i<n;i++){
		current = current -> next;
		}
		return(current -> info);
	}
	void remove_item_list(LIST *list, int item){
		NODE* current = list->head->next;
		NODE* previous = list->head;

		while(current != NULL){
		
			if(item == current -> info){
				previous->next = current->next;
				free(current);
				list->length--;
				current = previous->next;
				}else{
				previous = current;
				current = current->next;
					}
		}
	}
	void show_list(LIST *list){
	NODE *current = list->head->next;// comenzar desde el primer nodo
	while(current!=NULL){
	printf("%d ", current->info);
	current = current->next;
			    }
		printf("\n");
	}
	int empty_list(LIST *list){
		if(list->length == 0){
		return(1);
		}else{return(0);
			 }
			}
	void insert_pos_list(LIST *list, int pos, int item){
		if(pos<0 || pos>list->length){
		printf("Posicion no valida\n");
		}else{
		
		NODE *current = list->head->next;
		NODE *previous = list->head;
		NODE *new_node =(NODE*)malloc(sizeof(NODE));
		new_node->info = item;
		int i;
		for(i=1;i<pos;i++){
			previous = current;
			current = current->next;
			}
		//inserto el nuevo nodo
		previous->next = new_node;
		new_node->next = current;
		
			list->length++;
			}
			
		}
	void destroy_list(LIST *list){
		NODE* current = list->head->next;
		NODE* aux;
		while(current != NULL){
		aux=current;
		current = current->next;
		free(aux);
		}
		list->length = 0;
		list->head->next = NULL;
	}
	void modify_item_list(LIST *list, int pos, int item){
		if(pos<0 || pos>list->length){
			printf("Posicion invalida\n");
		}else{NODE *current = list->head->next;
		int i;
		for(i=1;i<pos;i++){
		current = current ->next;
		}
		current->info=item;
			}
		}
	void show_pos_item_list(LIST *list, int item){
			
			NODE* current = list->head->next;
			while(current != NULL){
			if(current->info == item){
			printf("%d\n", current->info);}
			current = current->next;
			}
				}
	//Me dice si el item se repite
	int repeat_item_list(LIST *list, int item){
		NODE *current = list->head->next;
		int band = 0;
		while(current != NULL || band<2){
			if(current->info == item){
				band++;
				}
			current = current->next;
			}
			if(band > 1){
			return (1);
			}else{
			return 0;
			}
		}
	void remove_pos_item_list(LIST*list, int pos){
			
			if(pos<0||pos>=list->length){
			printf("Posicion invalida");
			}else{
			NODE* current = list->head->next;
			NODE* aux= list->head;
			int i;
			for(i=1;i<pos;i++){
				aux = current;
				current =  current->next;
			}
				aux->next = current->next;
				free(current);
				list->length--;
				}
			}
	int length_list(LIST *list){
			return(list->length);
			}

	void insert_last_list(LIST *list, int item){
		
		NODE* new_node = (NODE *)malloc(sizeof(NODE));
		//NODE* aux = list->head;
		new_node->info=item;
		new_node->next=NULL;

		new_node->next = list->head->next;
		list->head->next=new_node;

		list->length++;
	}
	void merge_list(LIST *result, LIST *list1, LIST *list2){
			NODE *current1 = list1->head->next;
			NODE *current2 = list2->head->next;
			
			while(current1 != NULL){
				insert_list(result,current1->info);
				current1 = current1->next;
				}
			while(current2 != NULL){
				insert_list(result,current2->info);
				current2 = current2->next;
				}
			}

	void sort_up_list(LIST *list){
				
    NODE *current = list->head->next;  // Nodo actual
    NODE *sorted = NULL;  // Nodo que representa la lista ordenada

    while (current != NULL) {
        NODE *next = current->next;  // Guarda el siguiente nodo antes de cambiar la referencia

        // Si la lista ordenada está vacía o el elemento actual es menor al primero de la lista ordenada
        if (sorted == NULL || current->info <= sorted->info) {
            // Mueve el nodo actual al principio de la lista ordenada
            current->next = sorted;
            sorted = current;
        } else {
            // Busca la posición correcta en la lista ordenada e inserta el nodo actual
            NODE *temp = sorted;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;  // Avanza al siguiente nodo en la lista original
  
    // Asigna la lista ordenada a la lista original
    list->head->next = sorted;
}
 			}
void sort_down_list(LIST *list) {
    NODE *current = list->head->next;  // Nodo actual
    NODE *sorted = NULL;  // Nodo que representa la lista ordenada

    while (current != NULL) {
        NODE *next = current->next;  // Guarda el siguiente nodo antes de cambiar la referencia

        // Si la lista ordenada está vacía o el elemento actual es mayor al primero de la lista ordenada
        if (sorted == NULL || current->info >= sorted->info) {
            // Mueve el nodo actual al principio de la lista ordenada
            current->next = sorted;
            sorted = current;
        } else {
            // Busca la posición correcta en la lista ordenada e inserta el nodo actual
            NODE *temp = sorted;
            while (temp->next != NULL && temp->next->info > current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;  // Avanza al siguiente nodo en la lista original
    }

    // Asigna la lista ordenada a la lista original
    list->head->next = sorted;
}
	void swap_pos_list(LIST *list, int pos1, int pos2){
			NODE *current1 = list->head->next;
			NODE *current2 = list->head->next;
				int i,j,aux,length;

				length = list->length;
				
				if(pos1<=length && pos2<=length){
				for(i=1;i<pos1;i++){
					current1=current1->next;
					}
				aux = current1->info;
					
				for(j=1;j<pos2;j++){
					current2=current2->next;
					}
				current1->info = current2->info;
				current2->info = aux;
				}

					}
	void mix_list(LIST *list){
			int i, length, lower_bound, upper_bound;
			length = list->length;
			lower_bound = 1;
			upper_bound = length;
			srand(time(NULL));
			for(i=1;i<length;i++){
	swap_pos_list(list,(rand()%(upper_bound-lower_bound+1)+lower_bound),(rand()%(upper_bound-lower_bound+1)+lower_bound));
				}
			
			}

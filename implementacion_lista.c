#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
	/* typedef struct NODE{
		int info;
		struct NODE* next;
	}NODE; */

	typedef struct LIST{
		int length;
		struct NODE* head; //Nodo cabecera
		}LIST;
	
	void create_list(LIST *list);
	void insert_list(LIST *list, int item);
	int consult_list(LIST *list, int pos);
	void remove_item_list(LIST *list, int item);
	void show_list(LIST *list);
	int empty_list(LIST *list);
	void insert_pos_list(LIST *list, int pos, int item);
	void destroy_list(LIST *list);
	void modify_item_list(LIST *list, int pos, int item);
	void show_pos_item_list(LIST *list, int item);
	int repeat_item_list(LIST *list, int item);
	void remove_pos_item_list(LIST *list, int pos);
	int length_list(LIST *list);
int main(){
	LIST list1;
	create_list(&list1);
	printf("Esta vacia: %d \n", empty_list(&list1));
	insert_list(&list1,5);
	insert_list(&list1,6);
	insert_list(&list1,5);
	//printf("Antes de eliminar el 5: \n");
	show_list(&list1);
	//remove_item_list(&list1,5);
	//printf("Despues de eliminar el 5: \n");
	//show_list(&list1);
	//printf("No está vacia: %d\n", empty_list(&list1));
	//printf("Inserto nuevo elemento:\n");
	//insert_pos_list(&list1,2,5);
	//show_list(&list1);
	//destroy_list(&list1);
	//insert_list(&list1,1);
	//show_list(&list1);
	//modify_item_list(&list1,1,1);
	//show_list(&list1);
	//printf("Posiciones \n");
	//show_pos_item_list(&list1, 5);
	//printf("Posicion repetida de 5: %d\n", repeat_item_list(&list1,5));
	printf("El tamaño de la lista es:%d\n", length_list(&list1));
	printf("Eliminar 6\n");
	remove_pos_item_list(&list1,2);
	show_list(&list1);
	printf("El tamaño de la lista es: %d\n", length_list(&list1));
}

	void create_list(LIST *list){
		
		//inicializa el tamaño de la lista
		list->length = 0;
		
		//crear el nodo cabecera y apuntadar el primer nodo a NULL
		list->head =(NODE *)malloc(sizeof(NODE));
		list->head->next = NULL;
	}
	
	void insert_list(LIST *list, int item){
		
		NODE* new_node = (NODE *)malloc(sizeof(NODE));
		new_node->info=item;
		//Insertar el nuevo nodo al principio de la lista
		new_node->next = list->head->next;
		list->head->next=new_node;
		
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
	printf("\n");
	current = current->next;
			    }
	}
	int empty_list(LIST *list){
		NODE *current = list->head->next;
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

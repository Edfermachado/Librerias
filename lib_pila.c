#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
	
	typedef struct PILA{
			int length;
			struct NODE* top;
			}PILA;
	
	void create_p(PILA *pila){
			pila->length = 0;
			pila->top = NULL;
			}
	void push_p(PILA *pila,int item){
		NODE* new_node = (NODE *)malloc(sizeof(NODE));
		if(new_node==NULL){
			printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
			return;
			}
		new_node->next=pila->top;
		pila->top=new_node;
		new_node->info = item;
		pila->length++;
	}
	int top_p(PILA *pila){
		if(pila->top != NULL){
			return pila->top->info;
			}else{
			printf("La pila esta vacia\n");
				}
	}
	int length_p(PILA *pila){
			return pila->length;
			}
	void pop_p(PILA *pila){
		if(pila->top == NULL){
			printf("La pila esta vacia");
			}else{
			NODE *temp = pila->top;
			pila->top=pila->top->next;
			free(temp);
			pila->length--;
			}
		}
	int empty_p(PILA *pila){
		if(pila->top==NULL){
			return(1);
			}else{
			return(0);
			}
		
			}
	void show_top(PILA *pila){
			if(pila->top==NULL){
			printf("La pila esta vacia\n");
			}else{
			printf("El tope es: %d\n", pila->top->info);
			}
		}

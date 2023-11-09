#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
	
	typedef struct PILA{
			int length;
			struct NODE* top;
			}PILA;
	void create_pila(PILA *pila);
	void push_p(PILA *pila, int item);
	int top_p(PILA *pila);
	int length_p(PILA *pila);
	void pop_p(PILA *pila);
	int empty_p(PILA *pila);
	
int main(){
		PILA pila1;
		create_pila(&pila1);
		push_p(&pila1,5);
		printf("Tope actual: %d\n",top_p(&pila1));
		push_p(&pila1,7);
		printf("El tamaño de la lista es: %d\n",length_p(&pila1));
		pop_p(&pila1);
		push_p(&pila1,9);
		printf("El tope de la lista es: %d\n",top_p(&pila1));
		printf("Lista vacia(1), lista no vacia(0): %d\n", empty_p(&pila1));

return 0;
}
	void create_pila(PILA *pila){
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

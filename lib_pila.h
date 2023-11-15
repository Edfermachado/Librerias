#ifndef LIB_PILA_H
#define LIB_PILA_H
#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
	
	typedef struct PILA{
			int length;
			struct NODE* top;
			}PILA;

	void create_p(PILA *pila);
	void push_p(PILA *pila, int item);
	int top_p(PILA *pila);
	int length_p(PILA *pila);
	void pop_p(PILA *pila);
	int empty_p(PILA *pila);
	void show_top(PILA *pila);
#endif	

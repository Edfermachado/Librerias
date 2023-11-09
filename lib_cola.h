#ifndef LIB_COLA_H
#define LIB_COLA_H
#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
		
		typedef struct COLA{

			int length;
			NODE* first;
			NODE* last;

			}COLA;

		void create_c(COLA *cola);
		void insert_c(COLA *cola, int item);
		void show_first_c(COLA *cola);
		void show_last_c(COLA *cola);
		int take_last_c(COLA *cola);
		int take_first_c(COLA *cola);
		void  dequeue_c(COLA *cola);
#endif

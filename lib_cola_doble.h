#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"
		
		typedef struct COLA{

			int length;
			NODE* first;
			NODE* last;

			}COLA;


		void create_cd(COLA* cola);
		void insert_cd(COLA *cola, int item);
		void show_first_cd(COLA *cola);
		void show_last_cd(COLA *cola);
		int take_last_cd(COLA *cola);
		int take_first_cd(COLA *cola);
		void dequeue_cd(COLA *cola);
		int length_cd(COLA *cola);
		void insert_last_cd(COLA *cola, int item);
		void dequeue_last_cd(COLA *cola);

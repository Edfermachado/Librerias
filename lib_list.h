#ifndef LIB_LIST_H
#define LIB_LIST_H
#include <stdio.h>
#include <stdlib.h>

	/* typedef struct NODE{
		int info;
		struct NODE* next;
	}NODE;*/

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

#endif

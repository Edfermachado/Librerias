#ifndef LIB_LIST_H
#define LIB_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "nodo.c"

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
	void insert_last_list(LIST *list, int item);
	void merge_list(LIST *result, LIST *list1, LIST *list2);
	void sort_up_list(LIST *list);
	void sort_down_list(LIST *list);
	void swap_pos_list(LIST *list, int pos1, int pos2);
	void mix_list(LIST *list);
#endif

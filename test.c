#include <stdio.h>
#include "lib_list.h"
#include "lib_pila.h"
#include "lib_cola.h"

int main(){
	
	LIST list1;
	PILA pila1;
	COLA cola1;
	create_list(&list1);
	insert_list(&list1,8);
	show_list(&list1);
	create_p(&pila1);
	push_p(&pila1,7);
	printf("El top es: %d\n",top_p(&pila1));
	show_top(&pila1);
	create_c(&cola1);
	insert_c(&cola1, 66);
	show_first_c(&cola1);
return 0;
}

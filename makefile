OBJS = test3.o lib_list.o lib_cola.o lib_pila.o
CFLAGS = -g -Wall


programa: $(OBJS)
	gcc -o programa $(OBJS)
#tes3 es el nombre del programa a ejecutar
test3.o: test3.c lib_list.c lib_list.h lib_cola.c lib_cola.h lib_pila.c lib_pila.h

clean:

	rm -f programa $(OBJS)
	rm -f *~ core $(ODIR)/*.o $(INCDIR)/*~

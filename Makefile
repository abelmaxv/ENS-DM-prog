CC = gcc
COPT = -Wall -Wextra -Werror -Wshadow -ansi -pedantic -std=c11


betree : btree.c
	$(CC) $(COPT) btree.c -o btree

module : module.ml 
	ocamlopt module.ml -o module

CC = gcc
COPT = -Wall -Wextra -Werror -Wshadow -ansi -pedantic -std=c11


betree : btree
	$(CC) $(COPT) btree.c -o btree

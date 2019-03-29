##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 
##

SRC = main.c function.c function2.c display.c checking.c ia.c loop_function.c

OBJ = main.o function.o function2.o display.o checking.o ia.o loop_function.o

CFLAGS = -W -Wall -Wextra

all: compi

compi: $(OBJ)
	gcc $(OBJ) -o matchstick

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm matchstick

re : clean fclean all
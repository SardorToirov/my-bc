CC = gcc
CFLAGS =  -Wall -Wextra -Werror
SOURCES = my_bc.c my_execute.c main.c
TARGET = my_bc

$(TARGET):$(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ 
 
.PHONY: fclean

fclean:
	@rm -r $(TARGET)
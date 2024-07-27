#________________________________________________________________
# VARIABLES
#
# CURRENT ASSIGNMENT
HW   = HW03
NAME = select

# FILENAMES
EXECUTABLE = test_$(NAME)
SRC_C      = $(NAME).c test_$(NAME).c test_utils.c
SUBMIT_FILES = $(SRC_C) $(NAME).h special_test_cases.h test_utils.h credit.txt answers.txt Makefile

# SYSTEM
SHELL  = /bin/bash
CC     = gcc
CFLAGS = -g -std=c11 -Wall -Wshadow -Wvla -Werror -pedantic

#________________________________________________________________
# RULES
#
$(EXECUTABLE): $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) -o $(EXECUTABLE) 

test:  $(EXECUTABLE)
	./$(EXECUTABLE)

valgrind:  $(EXECUTABLE)
	valgrind --leak-check=full --track-origins=yes ./$(EXECUTABLE)

submit: $(SUBMIT_FILES)
	368submit $(HW) $(SUBMIT_FILES)

clean:
	rm -v -f $(EXECUTABLE)

.PHONY: test valgrind submit clean

# MAKEFILE_V2
# vim: set noexpandtab tabstop=4  filetype=make:

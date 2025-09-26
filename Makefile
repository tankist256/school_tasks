# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -c

# Source directory
SRC_DIR = .

# Output directory
OBJ_DIR = obj

# List of source files
SOURCES =  4.2stringope.c \
           4.3wordsearch.c \
           5.1simpleflags.c \
           5.2flagswvalue.c \
           5.3mixargpars.c \
           5.4configover.c \
           6.1filedisp.c \
           6.2simpfilestat.c \
           6.3filesearch.c \
           fileoptool.c

# Generate object file names in obj folder
OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Default target
all: $(OBJECTS)

# Rule to compile each .c file to a .o file in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# Clean target to remove object files
clean:
	rm -f $(OBJ_DIR)/*.o

# Phony targets
.PHONY: all clean
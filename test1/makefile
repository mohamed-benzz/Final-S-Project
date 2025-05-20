# Compiler and Assembler
CC = gcc
NASM = nasm

# Flags
CFLAGS = -O2 -Wall -I../includes         # Use ../includes for headers
NASMFLAGS = -f elf64 -I../includes       # Use ../includes for macros

# Executable name
TARGET = bench

# Source files (relative to test1/)
C_SRCS = main.c ../includes/libcc.c
ASM_SRCS = ../includes/libasm.asm       # ✅ Use only this one

# Header dependencies (relative to test1/)
C_HEADERS = ../includes/libcc.h ../includes/libasm.h
ASM_HEADERS = ../includes/lib.enc

# Object files
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.asm=.o)
OBJS = $(C_OBJS) $(ASM_OBJS)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# Compile C files
%.o: %.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble ASM files
%.o: %.asm $(ASM_HEADERS)
	$(NASM) $(NASMFLAGS) $< -o $@

# Clean
clean:
	rm -f *.o ../includes/*.o ../src/*.o $(TARGET)


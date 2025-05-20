CC = gcc
ASM = nasm
CFLAGS = -Wall -O2 -fPIC
LDFLAGS =

# Source and object files
C_SRC = c_lib/c_lib.c
C_OBJ = c_lib.o
C_LIB = libcfuncs.a

ASM_SRC = asm_lib/max.asm asm_lib/gcd.asm asm_lib/ispalindrome.asm
ASM_OBJ = max.o gcd.o ispalindrome.o
ASM_LIB = libasmfuncs.a

MAIN = main1
TARGET = main1

all: $(TARGET)

# Compile C library
$(C_LIB): $(C_OBJ)
        ar rcs $@ $^

# Compile NASM objects and archive
$(ASM_LIB): $(ASM_OBJ)
        ar rcs $@ $^

# Compile C source
c_lib.o: c_lib/c_lib.c c_lib/c_lib.h
        $(CC) $(CFLAGS) -c $< -o $@

# Compile NASM source files
max.o: asm_lib/max.asm asm_lib/asm_lib.h
        $(ASM) -f elf64 $< -o $@

gcd.o: asm_lib/gcd.asm asm_lib/asm_lib.h
        $(ASM) -f elf64 $< -o $@

ispalindrome.o: asm_lib/ispalindrome.asm asm_lib/asm_lib.h
        $(ASM) -f elf64 $< -o $@

# Compile main1.c and link all
$(TARGET): main1.c $(C_LIB) $(ASM_LIB)
        $(CC) $(CFLAGS) $< -L. -lcfuncs -lasmfuncs -o $@

clean:
        rm -f *.o *.a $(TARGET)







CC ?= gcc
#CFLAGS ?= -O2 -g 
CFLAGS ?= -O2 -pedantic -Wall -march=native

SRC := $(shell echo src/*.c)
OBJ := $(SRC:.c=.o)

default: all
all: CMath

clean:
	rm -f CMath ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

CMath: cmath.c ${OBJ}
	${CC} ${CFLAGS} $^ -o $@

.PHONY: all clean

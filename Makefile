COMPILER = gcc
FLAGS= --std=gnu99 -Wall  -funsigned-char -Wundef -Wsign-compare  -Wstrict-prototypes 
LDFLAGS=

FLAGS+= `xml2-config --cflags`
LDFLAGS+= `xml2-config --libs`

all: a 

clean:
	rm a

a: a.c a.h base64.h Makefile 
	@$(COMPILER) $(FLAGS) a.c $(LDFLAGS) -o a



.PHONY : clean all


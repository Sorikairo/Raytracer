##
## Makefile for tds in /home/fourri_l/Projects/lib/tds
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Thu Feb 27 10:30:21 2014 Laurent Fourrier
## Last update Thu Mar 13 16:35:52 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

SRCDIR	=	src

LIBDIR	=	lib

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-I$(LIBDIR)/include \
		-iquote$(INCDIR)

SRC	=	$(SRCDIR)/append.c \
		$(SRCDIR)/destroy.c \
		$(SRCDIR)/get_block.c \
		$(SRCDIR)/get_next.c \
		$(SRCDIR)/get_type.c \
		$(SRCDIR)/get_var.c \
		$(SRCDIR)/new.c \
		$(SRCDIR)/tcs/block.c \
		$(SRCDIR)/tcs/magic.c \
		$(SRCDIR)/tcs/parse.c \
		$(SRCDIR)/tcs/read_ascii.c \
		$(SRCDIR)/tcs/var.c \
		$(SRCDIR)/tcs/types/ascii.c \
		$(SRCDIR)/tcs/types/float32.c \
		$(SRCDIR)/tcs/types/float64.c \
		$(SRCDIR)/tcs/types/int16.c \
		$(SRCDIR)/tcs/types/int32.c \
		$(SRCDIR)/tcs/types/int8.c \
		$(SRCDIR)/tds/block.c \
		$(SRCDIR)/tds/default.c \
		$(SRCDIR)/tds/next_keyword.c \
		$(SRCDIR)/tds/parse.c \
		$(SRCDIR)/tds/var.c \
		$(SRCDIR)/tds/types/ascii.c \
		$(SRCDIR)/tds/types/float32.c \
		$(SRCDIR)/tds/types/float64.c \
		$(SRCDIR)/tds/types/int16.c \
		$(SRCDIR)/tds/types/int32.c \
		$(SRCDIR)/tds/types/int8.c \
		$(SRCDIR)/wtcs/block.c \
		$(SRCDIR)/wtcs/compile.c \
		$(SRCDIR)/wtcs/magic.c \
		$(SRCDIR)/wtcs/var.c \
		$(SRCDIR)/wtcs/write_ascii.c \
		$(SRCDIR)/wtcs/types/ascii.c \
		$(SRCDIR)/wtcs/types/float32.c \
		$(SRCDIR)/wtcs/types/float64.c \
		$(SRCDIR)/wtcs/types/int16.c \
		$(SRCDIR)/wtcs/types/int32.c \
		$(SRCDIR)/wtcs/types/int8.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtds.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

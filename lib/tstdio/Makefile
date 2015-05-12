##
## Makefile for tstdio in /home/fourri_l/Projects/lib/tstdio
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Sat Dec 28 13:58:13 2013 Laurent Fourrier
## Last update Mon Feb  3 11:27:14 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR)

SRC	=	$(SRCDIR)/in_char.c \
		$(SRCDIR)/in_line.c \
		$(SRCDIR)/out_char.c \
		$(SRCDIR)/out_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtstdio.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

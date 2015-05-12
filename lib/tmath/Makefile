##
## Makefile for tmath in /home/fourri_l/Projects/lib/tmath
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Wed Dec  4 11:13:08 2013 Laurent Fourrier
## Last update Wed Mar 12 16:10:20 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR)

SRC	=	$(SRCDIR)/create_vec.c \
		$(SRCDIR)/is_numeric.c \
		$(SRCDIR)/solve_quadra.c \
		$(SRCDIR)/strtoi.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtmath.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all

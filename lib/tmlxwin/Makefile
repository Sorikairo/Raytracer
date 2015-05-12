##
## Makefile for tmlxwin in /home/fourri_l/Projects/lib/tmlxwin
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Mon Feb  3 13:25:20 2014 Laurent Fourrier
## Last update Sat Mar 15 16:38:24 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR) \
		-I$(LIBDIR)/include

SRC	=	$(SRCDIR)/create.c \
		$(SRCDIR)/destroy.c \
		$(SRCDIR)/drawbuffer.c \
		$(SRCDIR)/swapbuffers.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtmlxwin.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

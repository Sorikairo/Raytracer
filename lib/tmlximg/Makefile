##
## Makefile for tmlximg in /home/fourri_l/Projects/lib/tmlximg
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Mon Feb  3 11:30:25 2014 Laurent Fourrier
## Last update Mon Feb  3 13:17:00 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR) \
		-I$(LIBDIR)/include

SRC	=	$(SRCDIR)/clear.c \
		$(SRCDIR)/create.c \
		$(SRCDIR)/new_imgcoord.c \
		$(SRCDIR)/put_pixel.c \
		$(SRCDIR)/put_rect.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtmlximg.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

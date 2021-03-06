##
## Makefile for rt in /home/fourri_l/Projects/MUL_2013_rtracer
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Wed Jun 04 15:26:05 2014 Laurent Fourrier
## Last update Sun Jun  8 23:23:59 2014 Barneaud Viveka
##
## Makefile automatically generated by TPrCfg

CC	=	cc

RM	=	rm -rf

SRCDIR	=	src

LIBDIR	=	lib

INCDIR	=	include

CFLAGS	=	-Wall -pedantic	\
		-iquote$(INCDIR)	\
		-l/usr/lib	\
		-I$(LIBDIR)/tds/include	\
		-I$(LIBDIR)/tio/include	\
		-I$(LIBDIR)/tlist/include	\
		-I$(LIBDIR)/tmath/include	\
		-I$(LIBDIR)/tmlxwin/include	\
		-I$(LIBDIR)/tmlximg/include	\
		-I$(LIBDIR)/rt_ext/include `pkg-config --cflags --libs gtk+-2.0`	\
		-I$(LIBDIR)/tsys/include	\
		-I$(LIBDIR)/tutils/include	\

LDFLAGS	= \
		-lm	\
		-ltds -L$(LIBDIR)/tds/	\
		-ltio -L$(LIBDIR)/tio/	\
		-ltlist -L$(LIBDIR)/tlist/	\
		-ltmath -L$(LIBDIR)/tmath/	\
		-ltmlxwin -L$(LIBDIR)/tmlxwin/	\
		-ltmlximg -L$(LIBDIR)/tmlximg/	\
		-lmlx -lXext -lX11 -lpthread -lm -L$(LIBDIR)/rt_ext/ `pkg-config --cflags --libs gtk+-2.0`	\
		-ltsys -L$(LIBDIR)/tsys/	\
		-ltutils -L$(LIBDIR)/tutils/	\

SRC_RT	=	$(SRCDIR)/scene/add_object.c	\
		$(SRCDIR)/scene/add_light.c	\
		$(SRCDIR)/rotate_caster.c	\
		$(SRCDIR)/intersection.c	\
		$(SRCDIR)/matrice_calcul.c	\
		$(SRCDIR)/parsing/parse_object.c	\
		$(SRCDIR)/parsing/parse_caster_color.c	\
		$(SRCDIR)/parsing/get_tds_def.c	\
		$(SRCDIR)/parsing/parse_object_angle.c	\
		$(SRCDIR)/parsing/parse_scene.c	\
		$(SRCDIR)/parsing/parse_object_radius.c	\
		$(SRCDIR)/parsing/parse_object_model.c \
		$(SRCDIR)/parsing/tds.c	\
		$(SRCDIR)/parsing/parse_caster.c	\
		$(SRCDIR)/parsing_obj/add_double_triangle_obj.c	\
		$(SRCDIR)/parsing_obj/add_simple_triangle_obj.c	\
		$(SRCDIR)/parsing_obj/add_to_list_point.c	\
		$(SRCDIR)/parsing_obj/add_to_list_text.c	\
		$(SRCDIR)/parsing_obj/check_poly.c	\
		$(SRCDIR)/parsing_obj/cpy_struct.c	\
		$(SRCDIR)/parsing_obj/creat_obj.c	\
		$(SRCDIR)/parsing_obj/free_list.c	\
		$(SRCDIR)/parsing_obj/get_next_line.c	\
		$(SRCDIR)/parsing_obj/get_the_nbr.c	\
		$(SRCDIR)/parsing_obj/init_struct.c	\
		$(SRCDIR)/parsing_obj/list_poly.c	\
		$(SRCDIR)/parsing_obj/next_point_poly.c	\
		$(SRCDIR)/parsing_obj/read_inf.c	\
		$(SRCDIR)/parsing_obj/x_malloc.c	\
		$(SRCDIR)/norme_function.c	\
		$(SRCDIR)/inter_object.c	\
		$(SRCDIR)/inter_triangle.c	\
		$(SRCDIR)/utils/redraw_hook.c	\
		$(SRCDIR)/utils/xmalloc.c	\
		$(SRCDIR)/modify_color.c	\
		$(SRCDIR)/angle.c	\
		$(SRCDIR)/main.c	\
		$(SRCDIR)/init_temp_pos.c	\
		$(SRCDIR)/init_intersection.c	\
		$(SRCDIR)/render_pixel.c	\
		$(SRCDIR)/get_nearest.c	\
		$(SRCDIR)/brightness.c	\
		$(SRCDIR)/reset_eye.c	\
		$(SRCDIR)/window/main/bind_server.c	\
		$(SRCDIR)/window/main/main.c	\
		$(SRCDIR)/window/main/menu.c	\
		$(SRCDIR)/window/main/notebook.c	\
		$(SRCDIR)/window/main/open.c	\
		$(SRCDIR)/window/main/progress_bar.c	\
		$(SRCDIR)/window/main/save_as.c	\
		$(SRCDIR)/cluster/Server/main.c	\
		$(SRCDIR)/cluster/Server/concat.c	\
		$(SRCDIR)/cluster/Client/xfunct.c	\
		$(SRCDIR)/cluster/Server/xfunct.c	\
		$(SRCDIR)/cluster/Server/read_socket.c	\
		$(SRCDIR)/cluster/Server/rm_client.c	\
		$(SRCDIR)/cluster/Server/manage_client.c	\
		$(SRCDIR)/cluster/Client/my_strendcmp.c	\
		$(SRCDIR)/cluster/Server/get_next_line.c	\
		$(SRCDIR)/cluster/Server/launch.c	\
		$(SRCDIR)/cluster/Server/str_to_wtab.c	\
		$(SRCDIR)/cluster/Client/parse_file.c	\

SRC_CLI	=	$(SRCDIR)/cluster/Client/main.c	\
		$(SRCDIR)/cluster/Client/xfunct.c	\
		$(SRCDIR)/cluster/Server/concat.c	\
		$(SRCDIR)/cluster/Client/my_strendcmp.c	\
		$(SRCDIR)/cluster/Server/xfunct.c		\
		$(SRCDIR)/cluster/Server/get_next_line.c	\
		$(SRCDIR)/cluster/Client/parse_file.c	\
		$(SRCDIR)/scene/add_light.c	\
		$(SRCDIR)/rotate_caster.c	\
		$(SRCDIR)/intersection.c	\
		$(SRCDIR)/matrice_calcul.c	\
		$(SRCDIR)/parsing/parse_object.c	\
		$(SRCDIR)/parsing/parse_caster_color.c	\
		$(SRCDIR)/parsing/get_tds_def.c	\
		$(SRCDIR)/parsing/parse_object_angle.c	\
		$(SRCDIR)/parsing/parse_scene.c	\
		$(SRCDIR)/parsing/parse_object_radius.c	\
		$(SRCDIR)/parsing/parse_object_model.c \
		$(SRCDIR)/parsing/tds.c	\
		$(SRCDIR)/parsing/parse_caster.c	\
		$(SRCDIR)/parsing_obj/add_double_triangle_obj.c	\
		$(SRCDIR)/parsing_obj/add_simple_triangle_obj.c	\
		$(SRCDIR)/parsing_obj/add_to_list_point.c	\
		$(SRCDIR)/parsing_obj/add_to_list_text.c	\
		$(SRCDIR)/parsing_obj/check_poly.c	\
		$(SRCDIR)/parsing_obj/cpy_struct.c	\
		$(SRCDIR)/parsing_obj/creat_obj.c	\
		$(SRCDIR)/parsing_obj/free_list.c	\
		$(SRCDIR)/parsing_obj/get_next_line.c	\
		$(SRCDIR)/parsing_obj/get_the_nbr.c	\
		$(SRCDIR)/parsing_obj/init_struct.c	\
		$(SRCDIR)/parsing_obj/list_poly.c	\
		$(SRCDIR)/parsing_obj/next_point_poly.c	\
		$(SRCDIR)/parsing_obj/read_inf.c	\
		$(SRCDIR)/parsing_obj/x_malloc.c	\
		$(SRCDIR)/norme_function.c	\
		$(SRCDIR)/inter_object.c	\
		$(SRCDIR)/inter_triangle.c	\
		$(SRCDIR)/utils/redraw_hook.c	\
		$(SRCDIR)/utils/xmalloc.c	\
		$(SRCDIR)/modify_color.c	\
		$(SRCDIR)/angle.c	\
		$(SRCDIR)/init_temp_pos.c	\
		$(SRCDIR)/init_intersection.c	\
		$(SRCDIR)/render_pixel.c	\
		$(SRCDIR)/get_nearest.c	\
		$(SRCDIR)/brightness.c	\
		$(SRCDIR)/reset_eye.c	\
		$(SRCDIR)/scene/add_object.c	\

OBJ_RT	=	$(SRC_RT:.c=.o)

OBJ_CLI	=	$(SRC_CLI:.c=.o)

NAME_RT	=	rt

NAME_CLI=	client

all: libs $(NAME_RT) $(NAME_CLI)

$(NAME_RT): $(OBJ_RT)
	$(CC) -o $(NAME_RT) $(OBJ_RT) $(LDFLAGS)

$(NAME_CLI):	$(OBJ_CLI)
	$(CC) -o $(NAME_CLI) $(OBJ_CLI) $(LDFLAGS)

libs:
	cd $(LIBDIR)/tds && make
	cd $(LIBDIR)/tio && make
	cd $(LIBDIR)/tlist && make
	cd $(LIBDIR)/tmath && make
	cd $(LIBDIR)/tmlxwin && make
	cd $(LIBDIR)/tmlximg && make
	cd $(LIBDIR)/tsys && make
	cd $(LIBDIR)/tutils && make

clean:
	$(RM) $(OBJ_CLI)
	$(RM) $(OBJ_RT)
	cd $(LIBDIR)/tds && make clean
	cd $(LIBDIR)/tio && make clean
	cd $(LIBDIR)/tlist && make clean
	cd $(LIBDIR)/tmath && make clean
	cd $(LIBDIR)/tmlxwin && make clean
	cd $(LIBDIR)/tmlximg && make clean
	cd $(LIBDIR)/tsys && make clean
	cd $(LIBDIR)/tutils && make clean

fclean: clean
	$(RM) $(NAME_CLI)
	$(RM) $(NAME_RT)
	cd $(LIBDIR)/tds && make fclean
	cd $(LIBDIR)/tio && make fclean
	cd $(LIBDIR)/tlist && make fclean
	cd $(LIBDIR)/tmath && make fclean
	cd $(LIBDIR)/tmlxwin && make fclean
	cd $(LIBDIR)/tmlximg && make fclean
	cd $(LIBDIR)/tsys && make fclean
	cd $(LIBDIR)/tutils && make fclean

re: fclean all

.PHONY: all libs clean fclean re

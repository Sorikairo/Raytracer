/*
** tds.h for tds in /home/fourri_l/Projects/lib/tds
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 18 13:48:53 2014 Laurent Fourrier
** Last update Tue Mar 25 09:11:19 2014 Laurent Fourrier
*/

#ifndef TDS_H_
# define TDS_H_

# include <tio.h>

# define TDS_KEYWORD_BUFFER	32

# define TDS_SIZE_UNKWN		0

# define TDS_TYPE_UNKWN		0
# define TDS_TYPE_BLOCK		1
# define TDS_TYPE_BLOCK_END	2
# define TDS_TYPE_INT8		8
# define TDS_TYPE_INT16		9
# define TDS_TYPE_INT32		10
# define TDS_TYPE_STR		11
# define TDS_TYPE_FLT32		12
# define TDS_TYPE_FLT64		13

# define TCS_MAGIC_BE		0x5443532A
# define TCS_MAGIC_LE		0x2A534354

typedef struct		s_tds_type
{
  char			bytecode;
  char			*name;
  int			size;
  void			*(*func_get_tds)(char *line);
  void			*(*func_get_tcs)(char *data);
  void			*(*func_wr_tcs)(void *data);
}			t_tds_type;

typedef struct		s_tds_var
{
  char			type;
  char			*name;
  void			*data;
  struct s_tds_var	*next;
}			t_tds_var;

typedef struct		s_tds_block
{
  char			*name;
  t_tds_var		*var_list;
  struct s_tds_block	*next;
}			t_tds_block;

typedef struct		s_tds
{
  t_tds_block		*block_list;
}			t_tds;

/*
** TDS Interpreter
*/
t_tds		tds_parse(t_file *file);
int		tds_parser_default(t_file *file, t_tds *tds);
int		tds_parser_block(t_file *file, t_tds *tds);
int		tds_parser_var(t_file *file, t_tds *tds);

void		*tds_type_int8(char *line);
void		*tds_type_int16(char *line);
void		*tds_type_int32(char *line);
void		*tds_type_ascii(char *line);
void		*tds_type_float32(char *line);
void		*tds_type_float64(char *line);

char		*tds_next_keyword(t_file *file);

/*
** TCS Interpreter
*/
t_tds		tcs_parse(t_file *file);
int		tcs_parser_magic(t_file *file, t_tds *tds);
int		tcs_parser_block(t_file *file, t_tds *tds);
int		tcs_parser_var(t_file *file, t_tds *tds);

void		*tcs_type_int8(char *data);
void		*tcs_type_int16(char *data);
void		*tcs_type_int32(char *data);
void		*tcs_type_ascii(char *data);
void		*tcs_type_float32(char *data);
void		*tcs_type_float64(char *data);

char		*tcs_read_ascii(t_file *file);

/*
** TDS Compiler
*/
int		tcs_compile(t_file *file, t_tds *tds);
int		tcs_write_magic(t_file *file, t_tds *tds);
int		tcs_write_block(t_file *file, t_tds_block *block);
int		tcs_write_var(t_file *file, t_tds_var *var);

void		*tcs_wtype_int8(void *data);
void		*tcs_wtype_int16(void *data);
void		*tcs_wtype_int32(void *data);
void		*tcs_wtype_ascii(void *data);
void		*tcs_wtype_float32(void *data);
void		*tcs_wtype_float64(void *data);

void		tcs_write_ascii(t_file *file, char *ascii);

/*
** TDS Getters
*/
t_tds_block	*tds_get_next_block(t_tds_block *block, char *name);
t_tds_var	*tds_get_next_var(t_tds_var *var, char *name);

t_tds_block	*tds_get_first_block(t_tds *tds);
t_tds_block	*tds_get_last_block(t_tds *tds);
t_tds_var	*tds_get_first_var(t_tds_block *block);
t_tds_var	*tds_get_last_var(t_tds_block *block);

t_tds_type	tds_get_type_from_name(char *name);
t_tds_type	tds_get_type_from_bytecode(char bytecode);

/*
** TDS Setters
*/
t_tds		*tds_append_block(t_tds *tds, t_tds_block *block);
t_tds_block	*tds_append_var(t_tds_block *block, t_tds_var *var);

/*
** TDS Utils
*/
t_tds_var	*tds_new_var();
t_tds_block	*tds_new_block();
void		tds_destroy_var(t_tds_var *var);
void		tds_destroy_block(t_tds_block *block);
void		tds_destroy(t_tds *tds);

#endif

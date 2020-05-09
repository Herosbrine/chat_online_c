/*
** Grégoire et ounis, PROJECT, 2019
** undefined
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>

typedef struct s_data t_data;
struct s_data {
    int size;
    int *x;
    int *y;
    char *buffer;
    char *map;
    char *map2;
    int *space;
    char **tab;
    int first_nbr;
    int secnd_nbr;
    int scnd_col_1;
    int scnd_col_2;
    int third_col_1;
    int third_col_2;
    int four_col_1;
    int four_col_2;
    int bol;
    int bolean;
    int pid_term2;
    int first1_nbr;
    int j;
    int last_numbr_list;
    int first_number_list;
    int first_letter;
    int last_letter;
};

//  EVAL_EXPR.C
int eval_expr(char const *str);

//  CALCUL.C
char infin_basic_ope(char const *str, char *result, int i, int a);
char infin_ope(char const *str, char *result, int i, int a);

//  PARENTHESES.C
int manage_parentheses(char *str, char *stk, int i);

//  MANAGES_ERRORS.C
int manage_ope(char const *str, int i);
int manage_errors(char const *str);

// DO_OP.C
int do_op(char *nb1, char *nb2, char *signe);
int value_k(char *expr);
char *find_nb1(char * expr, int k);
char *find_nb2(char * expr, int k);
char *find_signe(char * expr, int k);

// INFIN_ADD.C
char *infin_add(char *nb1, char *nb2);

// OTHER FUNCTIONS
int my_strlen(char const *str);
int my_put_nbr(int nbr);
void my_putchar(char c);
int my_getnbr(char *str);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_put_nbr2(unsigned int nbr);

//octal
int my_put_octal(unsigned nbr);
int my_put_hexa(unsigned nbr);
int my_put_space(int i, char const *format);
int my_flag(int i, va_list paramsinfos, char const * format, ...);
int my_printf(char const * format, ...);
int my_printf2(int *i, va_list paramsinfos, char const * format, ...);
int my_put_hexa_min(unsigned nbr);
int my_put_binary(unsigned int nbr);
void info_file(char *filepath);

//PROG_CHAT
int write_server(int *sock, char *pseudo);
int client_app(char *adresse_ip, char *pseudo);
void end_connection(int sock);

#endif
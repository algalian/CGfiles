

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <ctype.h>
# include <stdbool.h>
# include <signal.h>
# include <stdint.h>
# include <time.h>
# include "libft/libft.h"
#include <inttypes.h>
#include <errno.h>
#include <stddef.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif





enum state { FIELD_START, IN_FIELD, IN_QUOTED, IN_QUOTED_ESC };


typedef enum e_col_type {
    COL_STRING,
    COL_LDOUBLE
} t_col_type;

typedef struct s_column_spec {
    const char *header_name;   /* Column name in file */
    t_col_type  type;          /* How to parse it */
    size_t      offset;        /* offsetof(t_channel, field) */
    bool        required;      /* Is column mandatory */
} t_column_spec;



/* ===================== PARSER INTERFACE ===================== */

typedef enum e_parse_error {
    PARSE_OK = 0,
    PARSE_EOF,
    PARSE_UNTERMINATED_QUOTE,
    PARSE_ALLOC_FAIL
} t_parse_error;

typedef enum e_sniff_status {
    SNIFF_OK = 0,
    SNIFF_ERR_OPEN,
    SNIFF_ERR_EMPTY,
    SNIFF_ERR_AMBIGUOUS
} t_sniff_status;

typedef struct s_parser {
    FILE *fp;
    char delimiter;
    const char *sheet_name;
    int (*open)(struct s_parser *, const char *);
    t_parse_error (*read_header)(struct s_parser *, char ***, int *);
    t_parse_error (*read_row)(struct s_parser *, char ***, int *);
    void (*close)(struct s_parser *);
} t_parser;


/* ===================== API ===================== */
void use_csv_parser(t_parser *p);
void use_tsv_parser(t_parser *p);
int load(const char *filepath);
int make_parser_for_file(const char *filename, t_parser *out);
t_parse_error read_delimited_record(FILE *fp,char delimiter,char ***out_cells,int *out_count);
int tokenize_csv_line(const char *buffer, char delimiter,char ***out_cells, int *out_count,int *out_in_quotes);
int tokenize_tsv_line(const char *buffer, char ***out_cells, int *out_count);
t_sniff_status sniff_delimiter(const char *path, char *out_delim);

void free_cells(char **cells, int count);
int parse_long_double(const char *s, long double *out, int row, const char *col_name);
void use_xlsx_parser(t_parser *p);



//-------------------------------------//


#endif
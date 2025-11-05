

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

/* ************************************************************************** */
/*                                GET_NEXT_LINE                               */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_to_stash(int fd, char *stash);
char	*ft_get_line(char *stash);
char	*ft_new_stash(char *stash);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

/* ************************************************************************** */
/*                                MATRIX.C                                    */
/* ************************************************************************** */

typedef struct column
{
	double *values;
	int row_count;
}	t_column;

int			combinations(int n);
t_column	*read_csv(char *filename);

#endif
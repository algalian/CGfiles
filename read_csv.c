#include"matrix.h"



t_column *read_csv(char *filename) 
{
    t_column *c;
    int fd;
    int i;
    char *line;
    char *endptr;

    fd = open(filename, O_RDONLY);
    i = 0;
    c = malloc(sizeof(t_column));
    if(!c)
    {
        perror("error generating column struct\n");
        exit(1);
    }
    while(1)
    {
		line = get_next_line(fd);
        if (line == NULL)
		{
			break ;
		}
		free(line);
        i++;
	}
    printf("lines %i\n", i);
    close(fd);
    c->values = malloc(sizeof(double)*i);
    if (!c->values)
    {
        perror("malloc error generating values of column\n");
        exit(1);
    }
    c->row_count = i;
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("error opening file\n");
        exit(1);
    }
    while(i < c->row_count)
    {
        line = get_next_line(fd);
        c->values[i] = strtod(line, &endptr);
        free(line);
        i++;
    }
    close(fd);
    return(c);
}
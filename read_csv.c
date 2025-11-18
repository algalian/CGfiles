#include"matrix.h"



static bool is_line_empty(char *s)
{
    int i;

    i = 0;
    while(s[i] && isprint(s[i]))
        i++;
    if(i == 0)
        return(true);
    return(false);
    
}

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
        fprintf(stderr, "Error: cannot open file '%s'\n", filename);
        exit(1);
    }
    while(1)
    {
		line = get_next_line(fd);
        if (line == NULL)
		{
			break;
		}
        //printf("%s\n", line);
		free(line);
        i++;
	}
    printf("lines %i\n", i);
    close(fd);
    if (i == 0) {
        fprintf(stderr, "Error: file '%s' is empty\n", filename);
        exit(1);
    }
    c->values = malloc(sizeof(double) * i);
    if (!c->values)
    {
        fprintf(stderr, "Error: malloc failed for column values\n");
        exit(1);
    }
    c->row_count = i;
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "Error: cannot reopen file '%s'\n", filename);
        exit(1);
    }

    while(i < c->row_count)
    {
        line = get_next_line(fd);
        if(is_line_empty(line) == true)
        {
            fprintf(stderr, "Error: line %i is empty\n",  i);
            exit(1);
        }
        c->values[i] = strtod(line, &endptr);
        while (*endptr != '\0' && isspace((unsigned char)*endptr))
            endptr++;
        if (endptr == line) 
        {
            fprintf(stderr, "Error: line %d is not a number: '%s'\n", i+1, line);
            exit(1);
        }
        if (*endptr != '\0') 
        {
            fprintf(stderr, "Error: line %d contains invalid characters: '%s'\n", i+1, line);
            exit(1);
        }
        /*if (errno == ERANGE)  TODO
        {
            fprintf(stderr, "Error: line %d number out of representable range: '%s'\n", i+1, line);
            exit(1);
        }*/
        free(line);
        i++;
    }
    close(fd);
    return(c);
}
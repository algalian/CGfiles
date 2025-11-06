#include"matrix.h"


int combinations(int n)
{   
    return((int)(tgamma(n+1) / (tgamma(n-1) * 2)));
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

int main()
{
    t_column *column;
    double *m;
    double *output;
    int size;
    int output_size;
    int i;
    int j;
    int k;
    

    column = read_csv("input.csv");
    if(!column)
    {
        perror("error generating colummn struct");
        return(2);
    }
    m = column->values;
    size = column->row_count;
    output_size = combinations(size);
    output = malloc(sizeof(double) * output_size);
    if (!output)
    {
        fprintf(stderr, "malloc error\n");
        return (1);
    }
    i = 0;
    k = 0;
    printf("combinations: %i\n", output_size);
    while(i < size - 1)
    {
        j = i;
        while(j < size- 1)
        {
            output[k] = m[i] * m[j + 1];
            printf("%f\n", output[k]);
            j++;
            k++;
        }
        i++;
    }
    // TODO: The new values will have to be deployed somewhere else
    free(output);
    free(column->values);
    free(column);
    return(0);
}
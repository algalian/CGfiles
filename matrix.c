#include"matrix.h"


int combinations(int n)
{   
    return((int)(tgamma(n+1) / (tgamma(n-1) * 2)));
}

t_column *read_csv(char *filename) 
{

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
    // TODO: The new values will have to be deployed to somewhere else
    free(output);
    free(column->values);
    free(column);
    return(0);
}
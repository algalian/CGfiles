#include"matrix.h" 

int combinations(int n)
{   
    return((int)(tgamma(n+1) / (tgamma(n-1) * 2)));
}


int write_csv(t_column *c)
{
    int i;
    int j;
    int k;
    int size;
    double *output;
    int output_size;
    double *m;

    m = c->values;
    size = c->row_count;
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
    free(output);
    return(0);
}
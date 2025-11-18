#include"matrix.h"


int combinations(int n) 
{ 
    return((int)(tgamma(n+1) / (tgamma(n-1) * 2))); 
}

t_column *transform(t_column *input)
{
    int i;
    int j;
    int k;
    int size;
    t_column *output;
    int output_size;
    double *m;

    m = input->values;
    size = input->row_count;
    output_size = combinations(size);
    output = malloc(sizeof(t_column));
    output->row_count = output_size;
    output->values = malloc(sizeof(double) * output_size);
    if (!output || !output->values)
    {
        fprintf(stderr, "malloc error\n");
        return (NULL);
    }
    i = 0;
    k = 0;
    printf("combinations: %i\n", output_size);
    while(i < size - 1)
    {
        j = i;
        while(j < size- 1)
        {
            if((m[i] < 0 || m[i] > 1) || m[j+1] < 0 || m[j+1] > 1)
            {   
                fprintf(stderr, "value %i (or the next one) is not a probability\n", i);
                return(NULL);
            }
            output->values[k] = m[i] * m[j + 1];
            printf("%f\n", output->values[k]);
            j++;
            k++;
        }
        i++;
    }
    return(output);
}
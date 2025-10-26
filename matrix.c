#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>

int combinations(int n)
{   
    return((int)(tgamma(n+1) / (tgamma(n-1) * 2)));
}

int main(int argc, char **argv)
{
    double m[] = {0.5, 0.3, 0.4, 0.2};
    double *output;
    int size;
    int output_size;
    int i;
    int j;
    int k;

    //array and size will have to come from somewhere else. Hard-coded for now.
    size = 3;
    output_size = combinations(size + 1);
    output = malloc(sizeof(double) * output_size);
    if (!output)
    {
        write(2, "malloc error", sizeof("malloc error"));
        return(1);
    }
    i = 0;
    k = 0;
    while(i < size)
    {
        j = i;
        while(j < size)
        {
            output[k] = m[i] * m[j + 1];
            printf("%f\n", output[k]);
            j++;
            k++;
        }
        i++;
    }
    // free and leave. It will have to be deployed to somewhere else
    free(output);
    return(0);
}
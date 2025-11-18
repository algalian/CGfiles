#include"matrix.h" 



int write_csv(t_column *output, char *filename)
{
    FILE *fp = fopen(filename, "w");
    int i;

    if (!fp)
    {
        return (1);
    }
    i = 0;
    while (i < output->row_count)
    {    
        fprintf(fp, "%f\n", output->values[i]);
        i++;
    }
    fclose(fp);
    return(0);
}
#include"matrix.h" 



int write_csv(t_column *output)
{
    FILE *fp = fopen("output.csv", "w");
    int i;

    if (!fp)
    {
        perror("fopen");
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
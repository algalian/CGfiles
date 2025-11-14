#include"matrix.h"



int main()
{
    t_column *column;

    column = read_csv("input.csv");
    if(!column)
    {
        perror("error generating colummn struct");
        return(2);
    }

    if(write_csv(column) != 0)
    {   
        perror("error exporting info to file");
        return(1);        
    }
    free(column->values);
    free(column);
    return(1);

}


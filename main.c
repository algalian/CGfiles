#include"matrix.h"



int main()
{
    t_column *input;
    t_column *output;

    input = read_csv("input.csv");
    if(!input)
    {
        perror("error generating colummn struct");
        return(2);
    }
    output = transform(input);
    if(!output)
    {
        perror("error processing data");
        return(3);
    }
    if(write_csv(output) != 0)
    {   
        perror("error exporting info to file");
        return(1);        
    }
    free(input->values);
    free(input);
    free(output->values);
    free(output);
    return(1);

}


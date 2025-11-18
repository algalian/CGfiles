#include"matrix.h"



int main(int argc, char **argv)
{
    t_column *input;
    t_column *output;

    if (argc != 3)
    {
        fprintf(stderr,
            "Input error.\nUsage: %s <input_file> <output_file>\n",
            argv[0]
        );
        return 4;
    }

    input = read_csv(argv[1]);
    if (!input)
    {
        fprintf(stderr, "Error: unable to read input file '%s'\n", argv[1]);
        return 2;
    }

    output = transform(input);
    if (!output)
    {
        fprintf(stderr, "Error: unable to process data\n");
        return 3;
    }

    if (write_csv(output, argv[2]) != 0)
    {
        fprintf(stderr, "Error: unable to write output file '%s'\n", argv[2]);
        return 1;
    }

    free(input->values);
    free(input);
    free(output->values);
    free(output);

    return 0;
}

#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 3) 
	{
		fprintf(stderr, "Usage: %s <input_file> <name_of_first_column>\n", argv[0]);
		return EXIT_FAILURE;
	}
	load_table(argv[1], argv[2]);
	return(0);
}
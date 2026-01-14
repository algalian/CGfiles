#include "matrix.h"

int main(int argc, char **argv)
{
	if (argc < 2) 
	{
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	load(argv[1]);
	return(0);
}
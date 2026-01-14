#include"matrix.h"

static int row_matches_key(char **row,int count, const char *key)
{
    int j;

    j = 0;
    while(j < count)
    {
        if(strcmp(row[j],key) == 0)
        {
			return(1);
		}
        j++;
    }
    return (0);
}


int load_table(const char *filepath, const char *key)
{
	t_parser p;
	t_parse_error err;
	char **header;
	int hcount;
	int row_num;
	int i;

	if (make_parser_for_file(filepath, &p) != 0) 
	{
		fprintf(stderr,"Error: cannot determine file format for '%s'\n", filepath);
		return -1;
	}
	p.sheet_name = "Hoja1";
	if (p.open(&p, filepath) != 0) 
	{
		fprintf(stderr, "Error: cannot open '%s'\n", filepath);
		return -1;
	}
	header = NULL;
	hcount = 0;
	row_num = 0;
	while (row_num < 100) 
	{
		err = p.read_row(&p, &header, &hcount);
		row_num++;
		if (err == PARSE_EOF) 
		{
			fprintf(stderr,"Error: header not found in '%s'\n",filepath);
			p.close(&p);
			return -1;
		}

		if (err != PARSE_OK) 
		{
			fprintf(stderr, "Error: parse failure before header (row %d)\n", row_num);
			p.close(&p);
			return -1;
		}
		if (row_matches_key(header, hcount, key) == 1)
		{
			break;
		}
		/*i = 0;
		while(i < hcount)
		{
			printf("%s ", header[i]);
			i++;
		}*/
		//printf("\n%i\n", hcount);
		free_cells(header, hcount);
		header = NULL;
		hcount = 0;
	}
	p.close(&p);
	return(0);

}


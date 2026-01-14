#include"matrix.h"



int load(const char *filepath)
{
    t_parser p;
    t_parse_error err;

    if (make_parser_for_file(filepath, &p) != 0) 
    {
        fprintf(stderr,"Error: cannot determine file format for '%s'\n", filepath);
        return -1;
    }
    p.sheet_name = "Hoja1";
    //printf("proceeding to open file\n");
    if (p.open(&p, filepath) != 0) 
    {
        fprintf(stderr, "Error: cannot open '%s'\n", filepath);
        return -1;
    }
    //printf("file opened\n");

}
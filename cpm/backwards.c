

/*
Made by: Alex Hamill
*/
#include <stdio.h>


reverse(c)
char *c;
{ 
    int i;
    i=0;
    int o;
    o = 0;
    char backwards[1000];
    
    while (c[i] != '\0'){
        i++;
    }

    i--;
    while (i >= 0){
        backwards[o] = c[i];
        i--;
        o++;
    }
    backwards[o] = '\0';
    for(i = 0; i <= o; i++){
        c[i] = backwards[i];
    }
}

main(argc, argv)
int argc;
char **argv;
{
    FILE *infp, *outfp;
    int p;
    int linesum;
    char line[1000];
    int i;
    linesum = 0;

    if (argc != 3) {
        printf("Usage: add <infile> <outfile>\n");
        return;
    }
    if ((infp = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        return;
    }
    
    if ((outfp = fopen(argv[2], "w")) == NULL) {
        printf("Can't open %s\n", argv[2]);
        fclose(infp);
        return;
    }

    while ((p = fgetc(infp)) != EOF) {
        if(p == '\n'){
            line[linesum] = '\0';
            reverse(line);
            
            for(i = 0; i < linesum; i++){
                fputc(line[i], outfp);
                putchar(line[i]);
            }
            linesum = 0;
            fputc('\n', outfp);
            putchar('\n');
        }else{
            line[linesum] = p;
            linesum++;
        }

    }

    line[linesum] = '\0';
    reverse(line);
    
    for(i = 0; i < linesum; i++){
        fputc(line[i], outfp);
        putchar(line[i]);
    }
    linesum = 0;
    fputc('\n', outfp);
    putchar('\n');

    fclose(infp);
    fclose(outfp);
    printf("done!:)\n");
}
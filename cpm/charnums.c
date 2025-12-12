/*
Made by: Alex Hamill
*/

#include <stdio.h>

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
            fprintf(outfp, "%d ", linesum);
            fputc(' ', outfp);
            printf("%d", linesum);
            putchar(' ');
            
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

    fprintf(outfp, "%d ", linesum);
    fputc(' ', outfp);
    printf("%d", linesum);
    putchar(' ');
    
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
#include <stdio.h>


isdigit(c)
char c;
{
    return c >= '0' && c <= '9';
}

main(argc, argv)
int argc;
char **argv;
{
    int i;
    int sum;
    
    sum = 0;
    
    for (i = 1; i < argc; i++) {
        if (isdigit(argv[i])) {
            sum = sum + argv[i]-'0';
        }
        else {
            printf("OOPS! %s is not a number\n", argv[i]);
            return;
        }
    }
    
    printf("Sum is %d\n", sum);
}
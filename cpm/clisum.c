#include <stdio.h>


isdigit(c)
char c;
{
    return c >= '0' && c <= '9';
}

convert(s)
char *s;
{
    int result;
    int i;
    result = 0;
    i = 0;
    while (s[i] != '\0') {
        if (!isdigit(s[i])) {
            return -1;
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return result;
}

main(argc, argv)
int argc;
char **argv;
{
    int i;
    int sum;
    
    sum = 0;
    
    for (i = 1; i < argc; i++) {
        if(convert(argv[i]) < 0) {
            printf("OOPS! %s is not a number\n", argv[i]);
            return;
        }
        if (isdigit(argv[i][0])) {
            sum = sum + convert(argv[i]);
        }
        else {
            printf("OOPS! %s is not a number\n", argv[i]);
            return;
        }
    }
    
    printf("Sum is %d\n", sum);
}
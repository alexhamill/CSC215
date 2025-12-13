/*
Made by: Alex Hamill
*/

#include <stdio.h>


strcat(s, t) 
char *s, *t; 
{
    int i, j;
    i = j = 0;
    while (*(s + i) != '\0'){ 
        i++;
    }
    while((*(s + i) = *(t + j)) != '\0'){
        i++;
        j++;
    }

}

atoi(s) 
char *s ;
{
    while( *s >= '0' && *s <= '9' ){ 
        return (*s - '0') + 10 * atoi(s + 1); 
    }
}


/* itoa: convert n to characters in s */
itoa(n, s)
int n;
char *s;
{
    int sign;
    char *p = s;
    sign = n;
    if (n < 0) {
        n = -n;
    }
    while (1) {
        *p++ = n % 10 + '0';
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    if (sign < 0) {
        *p++ = '-';
    }
    *p = '\0';
    {
        char *start = s;
        char *end = p - 1;
        char c;
        while (start < end) {
            c = *start;
            *start++ = *end;
            *end-- = c;
        }
    }
}




int main()
{
   char str1[10];
   char str2[3];
   str1[0]='a';
   str1[1]='b';
   str1[2]='\0';
   str2[0]='c';
   str2[1]='\0';
   strcat(str1,str2);
   printf("cat test should be abc:  %s",str1);


    char numstr[4];
    numstr[0]='1';
    numstr[1]='2';
    numstr[2]='3';
    numstr[3]='\0';
    int num;
    num = atoi(numstr);
    printf("\natoi test should be 123: %d\n", num);

    char strnum[10];
    itoa(-456, strnum);
    printf("itoa test should be -456: %s\n", strnum);




}

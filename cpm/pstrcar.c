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
char *s;
{
    int n, sign;
    n = 0;
    sign = 1;
    
    while (*s == ' ' || *s == '\t' || *s == '\n')
        s++;
    
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') {
        s++;
    }
    
    while (*s >= '0' && *s <= '9') {
        n = n * 10 + (*s - '0');
        s++;
    }
    
    return sign * n;
}


itoa(n, s)
int n;
char *s;
{
    int sign;
    char *p;
    char *start;
    char *o;
    char c;
    
    p = s;
    sign = n;
    if (n < 0) {
        n = -n;
    }
    
    do {
        *p++ = n % 10 + '0';
        n /= 10;
    } while (n > 0);
    
    if (sign < 0) {
        *p++ = '-';
    }
    *p = '\0';
    
    start = s;
    o = p - 1;
    while (start < o) {
        c = *start;
        *start++ = *o;
        *o-- = c;
    }
}

reverse(c)
char *c;
{ 
    int i, o;
    char backwards[1000];
    
    i = 0;
    o = 0;
    
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


main()
{
   char str1[10];
   char str2[3];
   char numstr[4];
   int num;
   char strnum[10];
   char revstr[6];
   
   str1[0]='a';
   str1[1]='b';
   str1[2]='\0';
   str2[0]='c';
   str2[1]='\0';
   strcat(str1,str2);
   printf("cat test should be abc:  %s\n",str1);

   numstr[0]='1';
   numstr[1]='2';
   numstr[2]='3';
   numstr[3]='\0';
   num = atoi(numstr);
   printf("\natoi test should be 123: %d\n", num);

   itoa(-456, strnum);
   printf("itoa test should be -456: %s\n", strnum);

   revstr[0]='h';
   revstr[1]='e';
   revstr[2]='l';
   revstr[3]='l';
   revstr[4]='o';
   revstr[5]='\0';
   reverse(revstr);
   printf("reverse test should be olleh: %s\n", revstr);
}